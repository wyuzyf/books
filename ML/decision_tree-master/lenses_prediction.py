#!usr/bin/env python
# -*- coding:utf-8 -*-

import tree_plotter
import trees

fr = open('lenses.txt')
lenses = [inst.strip().split('\t') for inst in fr.readlines()]
lensesLabels = ['age', 'prescript', 'astigmatic', 'tearRate']
lensesTree = trees.create_tree(lenses, lensesLabels)

print(lenses)
print(lensesTree)
tree_plotter.create_plot(lensesTree)     # 由ID3算法产生的决策树
