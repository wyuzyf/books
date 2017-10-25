#!usr/bin/env python
# -*- coding:utf-8 -*-
import trees
import tree_plotter
import pickle

"""测试和存储分类器"""
# 使用决策树的分类函数
def classify(inputTree, featLabels, testVec):
    firstStr = inputTree.keys()[0]
    secondDict = inputTree[firstStr]
    # 使用index方法查找当前列表中第一个匹配firstStr变量的元素
    featIndex = featLabels.index(firstStr)   # 将标签字符串转换为索引

    # 然后递归遍历整棵树,比较testVec变量中的值与树节点的值,如果到达叶子节点,则返回当前节点的分类标签
    for key in secondDict.keys():
        if testVec[featIndex] == key:
            if type(secondDict[key]).__name__ == 'dict':
                classLabel = classify(secondDict[key], featLabels, testVec)
            else:   classLabel = secondDict[key]
    return classLabel

"""使用pickle模块存储决策树"""
# pickle序列化对象可以在磁盘上保存对象,并在需要的时候读取出来。任何对象都可以执行序列化操作
# 在硬盘上存储决策树分类器, 使得能用创建好的决策树解决分类问题
def store_tree(inputTree, filename):
    fw = open(filename, 'w')
    pickle.dump(inputTree, fw)
    fw.close()

def grab_tree(filename):
    fr = open(filename)
    return pickle.load(fr)


if __name__ == '__main__':
    myData, labels = trees.create_dataset()
    # myTree = create_tree(myData, labels)
    myTree = tree_plotter.retrieve_tree(0)
    print(myTree)
    cla1 = classify(myTree, labels, [1, 0])
    cla2 = classify(myTree, labels, [1, 1])
    print(cla1)
    print(cla2)

    store_tree(myTree, 'classifierStorage.txt')
    decisionTree = grab_tree('classifierStorage.txt')
    print(decisionTree)
