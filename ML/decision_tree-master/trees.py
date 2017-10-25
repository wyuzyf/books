#!usr/bin/env python
# -*- coding:utf-8 -*-
from math import log
import operator as op

# 计算给定数据集的香农熵
def calc_shannonEnt(dataset):
    numEntries = len(dataset)    # 计算数据集中实例的总数
    labelCounts = {}
    
    # 为所有可能分类创建字典
    for eachVec in dataset:
        currentLabel = eachVec[-1]                  # key是最后一列的数值(标签)
        if currentLabel not in labelCounts.keys():  # 如果当前key不存在,则扩展字典并将其加入字典
            labelCounts[currentLabel] = 0
        labelCounts[currentLabel] += 1      # 每个键值都记录了当前类别出现的次数

    shannonEnt = 0.0
    for key in labelCounts:
        prob = float(labelCounts[key]) / numEntries    # 用所有标签的发生频率计算类别出现的概率
        shannonEnt -= prob * log(prob, 2)              # 以2为底 求对数
    return shannonEnt

# 简单鱼鉴定数据集
def create_dataset():
    dataset = [[1, 1, 'yes'],
               [1, 1, 'yes'],
               [1, 0, 'no'],
               [0, 1, 'no'],
               [0, 1, 'no']]
    labels = ['no surfacing', 'flippers']
    return dataset, labels

# 按照给定特征feature(featureAxis对应的特征)划分数据集dataset
def split_dataset(dataset, featureAxis, value):   # 待划分的数据集、划分数据集的特征、特征的返回值 (database, 0, 1)
    outDataset = []                               # 为了不修改原始数据集, 创建一个新的list对象
    for eachVec in dataset:
        if eachVec[featureAxis] == value:         # 将符合特征的数据抽取出来   [[1, 1, 'yes'], ...]
            resFeatVec = eachVec[:featureAxis]            # 把featureAxis前面的元素加入(不包括featureAxis对应的feature)
            resFeatVec.extend(eachVec[featureAxis+1:])    # 把featureAxis后面的元素加入   如:[1, 'yes']
            outDataset.append(resFeatVec)                 # [[1,'yes'], ...]
    return outDataset
# [[1, 1, 'yes'], [1, 1, 'yes'], [1, 0, 'no'], [0, 1, 'no'], [0, 1, 'no']]
# split_dataset(dataset, 0, 1)
# [[1, 'yes'], [1, 'yes'], [0, 'no']]

# 选择最好的数据集划分方式
def choose_bestFeatureToSplit(dataset):
    numFeatures = len(dataset[0]) - 1         # 数据集特征的个数
    baseEntropy = calc_shannonEnt(dataset)    # 整个数据集的原始熵,保存最初的无序度量值,用于与划分完之后的数据集计算的熵值进行比较
    bestInfoGain = 0.0
    bestFeature = -1
    # 遍历所有的特征
    for i in range(numFeatures):
        # 创建唯一的分类标签列表(同一个特征的不同值)
        featList = [example[i] for example in dataset]
        uniqueVals = set(featList)      # 集合set和列表list的不同之处仅在于set中每个值互不相同
        newEntropy = 0.0
        for value in uniqueVals:        # 计算每种划分方式的信息熵   对当前特征中的每个值划分一次数据集
            subDataset = split_dataset(dataset, i, value)
            prob = len(subDataset) / float(len(dataset))
            entropy = calc_shannonEnt(subDataset)
            newEntropy += prob * entropy
        infoGain = baseEntropy - newEntropy
        if infoGain > bestInfoGain:     # 计算最好的信息增益
            bestInfoGain = infoGain
            bestFeature = i
    return bestFeature

# 如果数据集已经处理了所有属性,但是类标签依然不是唯一的,此时我们需要决定如何定义该叶子节点。通常采用:
# 多数表决 决定该叶子节点的分类
def majority_vote(classList):
    classCount = {}           # 字典对象存储了classList中每个类标签出现的频率
    for vote in classList:
        if vote not in classCount.keys():
            classCount[vote] = 0
        classCount[vote] += 1
    sortedClassCount = sorted(classCount.iteritems(), key=op.itemgetter(1), reverse=True)
    return sortedClassCount[0][0]


# 创建树
def create_tree(dataset, labels):
    classList = [example[-1] for example in dataset]
    # 第一个递归终止条件: 所有类标签完全相同
    if classList.count(classList[0]) == len(classList):  return classList[0]
    # 第二个递归终止条件: 使用完了所有特征,仍然不能将数据集划分成仅包含唯一类别的分组
    if len(dataset[0]) == 1:  return majority_vote[classList]
    
    bestFeat = choose_bestFeatureToSplit(dataset)
    bestFeatLabel = labels[bestFeat]

    myTree = {bestFeatLabel: {}}
    del(labels[bestFeat])          # 更新labels列表
    featValues = [example[bestFeat] for example in dataset]
    uniqueVals = set(featValues)
    for value in uniqueVals:
        subLabels = labels[:]   # 复制了类标签,并将其存储在新列表变量subLabels中。为了保证每次调用函数createTree()时不改变原始列表的内容
        myTree[bestFeatLabel][value] = create_tree(split_dataset(dataset, bestFeat, value), subLabels)
    return myTree

if __name__ == '__main__':
    myData, labels = create_dataset()
    myTree = create_tree(myData, labels)
    print(myTree)

# {'no surfacing': {0: 'no', 1: {'flippers': {0: 'no', 1: 'yes'}}}}
# 第一个关键字no surfacing是第一个划分数据集的特征名称,该关键字的值也是另一个数据字典。
# 第二个关键字是no surfacing特征划分的数据集,这些关键字的值是no surfacing节点的子节点。这些值可能是类标签,也可能是另一个数据字典。
# 如果值是类标签,则该子节点是叶子节点;如果值是另一个数据字典,则子节点是一个判断节点,这种格式结构不断重复就构成了整棵树。

