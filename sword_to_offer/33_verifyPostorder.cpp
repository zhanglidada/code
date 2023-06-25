#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 * 
 * 本题相关背景知识：
 * 1）后续遍历的定义：[ 左子树| 右子树 | 根节点 ]
 * 2）二叉搜索树：左子树中所有节点的值 < 根节点的值 < 右子树中所有节点的值，其中左右子树也分别为二叉搜索树
 */

/***************************************************************************************
 * 1. 采用递归分治的方法
 * 通过递归判断所有子树的正确性（即其后续遍历是否满足二叉搜索树的定义）
 * 
 * 1）中止条件：
 * i >= j，说明此时子树节点数量小于1，无需判别正确性，返回true
 * 
 * 2）递归工作：
 * 
 * 2.1）划分左右子树
 * 遍历后续遍历区间[i,j]，寻找第一个大于根节点值的节点，其索引为m
 * 划分左子树为[i, m - 1],右子树为[m, j - 1],根节点为j
 * 
 * 2.2）判断子树是否为二叉搜索树
 * 
 * 2.3）计算返回值
***************************************************************************************/
class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    return recur(0, postorder.size() - 1, postorder);
  }
  // 后续遍历区间的二叉搜索树存在性判断
  bool recur(int left, int right, vector<int>& postorder) {
    // 区间遍历结束
    if (left >= right)  return true;

    int rootVal = postorder[right];
    int pos = left;
    
    // 从左到右，找第一个大于rootval的节点pos
    while (postorder[pos] < rootVal) pos++;

    int m = pos;
    
    // 判断右子树的值是否全部大于rootval
    while (postorder[pos] > rootVal) pos++;
    
    return pos == right && recur(left, m - 1, postorder) && recur(m, right - 1, postorder);
  }
};





// 采用辅助单调栈
class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    
  }
};