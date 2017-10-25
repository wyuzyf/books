#!usr/bin/env python
# -*- coding:utf-8 -*-
import matplotlib.pyplot as plt

# 获取叶节点数目 以便可以确定x轴的长度
def getNumLeafs(myTree):
    numLeafs = 0
    firstStr = myTree.keys()[0]
    secondDict = myTree[firstStr]
    for key in secondDict.keys():
        if type(secondDict[key]).__name__ == 'dict':   # 测试节点的数据类型是否为字典,如果不是,为叶子节点
            numLeafs += getNumLeafs(secondDict[key])
        else: numLeafs += 1
    return numLeafs

# 获取树的层次 以便可以确定y轴的高度
def getTreeDepth(myTree):
    maxDepth = 0
    firstStr = myTree.keys()[0]
    secondDict = myTree[firstStr]
    for key in secondDict.keys():
        if type(secondDict[key]).__name__ == 'dict':   # 测试节点的数据类型是否为字典,如果不是,为叶子节点
            thisDepth = 1 + getTreeDepth(secondDict[key])
        else: thisDepth = 1
        if thisDepth > maxDepth: maxDepth = thisDepth
    return maxDepth

# 定义文本框和箭头格式
decisionNode = dict(boxstyle="sawtooth", fc="0.8")
leafNode = dict(boxstyle="round4", fc="0.8")
arrow_args = dict(arrowstyle="<-")

# 该函数执行了实际的绘图功能,该函数需要一个绘图区,该区域由全局变量create_plot.ax1定义
# 绘制带箭头的注解
def plot_node(nodeTxt, centerPt, parentPt, nodeType):
    create_plot.ax1.annotate(nodeTxt, xy=parentPt, xycoords='axes fraction', xytext=centerPt,
                             textcoords='axes fraction', va="center", ha="center",
                             bbox=nodeType, arrowprops=arrow_args)
# 首先创建了一个新图形并清空绘图区,然后在绘图区上绘制两个代表不同类型的树节点,后面将用这两个节点绘制树形图
# def create_plot():
#     fig = plt.figure(1, facecolor='white')
#     fig.clf()
#     create_plot().ax1 = plt.subplot(111, frameon=False)
#     plot_node('a decision node', (0.5, 0.1), (0.1, 0.5), decisionNode)
#     plot_node('a leaf node', (0.8, 0.1), (0.3, 0.8), leafNode)
#     plt.show()

# 在父子节点间填充文本信息
def plot_midText(cntrPt, parentPt, txtString):
    xMid = (parentPt[0]-cntrPt[0])/2.0 + cntrPt[0]
    yMid = (parentPt[1]-cntrPt[1])/2.0 + cntrPt[1]
    create_plot.ax1.text(xMid, yMid, txtString, va="center", ha="center", rotation=30)

# 绘制树形图的很多工作    plot_tree.totalW 存储树的宽度   plot_tree.totalD 存储树的深度
# 用这两个变量计算树节点的摆放位置,这样可以将树绘制在水平方向和垂直方向的中心位置
def plot_tree(myTree, parentPt, nodeTxt):  # if the first key tells you what feat was split on
    # 计算树的宽和高
    numLeafs = getNumLeafs(myTree)
    depth = getTreeDepth(myTree)

    # plot_tree.xOff  plot_tree.yOff 追踪已经绘制的节点位置,以及放置下一个节点的恰当位置
    firstStr = myTree.keys()[0]           # the text label for this node should be this
    cntrPt = (plot_tree.xOff + (1.0 + float(numLeafs))/2.0/plot_tree.totalW, plot_tree.yOff)

    # 绘出子节点具有的特征值,或者沿此分支向下的数据实例必须具有的特征值。
    # 用plot_midText()计算父节点和子节点的中间位值,并在此处添加简单的文本标签信息
    plot_midText(cntrPt, parentPt, nodeTxt)
    plot_node(firstStr, cntrPt, parentPt, decisionNode)

    secondDict = myTree[firstStr]
    # 按照比例减少全局变量plot_tree.yOff,并标注此处将要绘制子节点  因为是自顶向下绘制图形,所以需要依次递减y坐标值
    plot_tree.yOff -= 1.0/plot_tree.totalD

    for key in secondDict.keys():
        if type(secondDict[key]).__name__ == 'dict':     # 不是叶子节点 递归调用plot_tree()函数
            plot_tree(secondDict[key], cntrPt, str(key))
        else:                                            # 叶子节点 在图形上画出叶子节点
            plot_tree.xOff += 1.0/plot_tree.totalW
            plot_node(secondDict[key], (plot_tree.xOff, plot_tree.yOff), cntrPt, leafNode)
            plot_midText((plot_tree.xOff, plot_tree.yOff), cntrPt, str(key))
    plot_tree.yOff += 1.0/plot_tree.totalD   # 绘制了所有子节点后,增加全局变量Y的偏移
# if you do get a dictonary you know it's a tree, and the first element will be another dict

# 主函数,调用了plot_tree()
def create_plot(inTree):
    fig = plt.figure(1, facecolor='white')
    fig.clf()
    axprops = dict(xticks=[], yticks=[])
    create_plot.ax1 = plt.subplot(111, frameon=False, **axprops)    # no ticks
    # createPlot.ax1 = plt.subplot(111, frameon=False)              # ticks for demo puropses
    plot_tree.totalW = float(getNumLeafs(inTree))
    plot_tree.totalD = float(getTreeDepth(inTree))
    plot_tree.xOff = -0.5/plot_tree.totalW
    plot_tree.yOff = 1.0
    plot_tree(inTree, (0.5, 1.0), '')
    plt.show()

# 输出预先存储的树信息,避免了每次测试代码时都要从数据中创建树的麻烦
def retrieve_tree(i):
    listOfTrees = [{'no surfacing': {0: 'no', 1: {'flippers': {0: 'no', 1: 'yes'}}}},
                   {'no surfacing': {0: 'no', 1: {'flippers': {0: {'head': {0: 'no', 1: 'yes'}}, 1: 'no'}}}}]
    return listOfTrees[i]
# retrieve_tree()主要用于测试,返回预定义的树结构。

if __name__ == '__main__':
    # print(retrieve_tree(1))
    myTree = retrieve_tree(0)
    create_plot(myTree)
    # print(getNumLeafs(myTree))    # 3
    # print(getTreeDepth(myTree))   # 2

