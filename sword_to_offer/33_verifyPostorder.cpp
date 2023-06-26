#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
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


/***************************************************************************************
 * 2. 采用辅助单调栈
 * 
 * 后续遍历的倒序：[根节点 | 右子树 | 左子树]，类似于先序遍历的镜像 root->right->left
 * 
 * 1）构造一个单调递增的栈，记录遍历的元素
 *    
 * 2）在向右子树遍历的过程中，value值逐渐增大，一旦出现value值变小的情况，表示要进入左子树
 *    记录此时的节点为N
 * 
 * 3）由于左子树中的节点均小于根节点，只要栈顶元素还大于当前节点N，持续出栈，
 *    直到栈顶元素小于当前节点，或者栈顶元素为空
 * 
 * 4）此时最后出栈的那个元素为当前节点的根节点
***************************************************************************************/
// 采用辅助单调栈
class Solution {
  public:
    bool verifyPostorder(vector<int>& postorder) {
        // 单调栈使用，单调递增的单调栈
        stack<int> stk;

        // 表示上一个根节点的元素，这里可以把postorder的最后一个元素root看成无穷大节点的左孩子
        int pervElem = INT32_MAX;
        
        // 逆向遍历，就是先序遍历的镜像
        for (int i = postorder.size() - 1; i>=0; i--){
            // 左子树元素必须要小于递增栈中根节点的元素，否则就不是二叉搜索树
            if (postorder[i] > pervElem){
                return false;
            }

            while (!stk.empty() && postorder[i] < stk.top()){
                // 数组元素小于单调栈的元素了，表示往左子树走了，记录下上个根节点
                // 找到这个左子树对应的根节点，之前右子树全部弹出，不再记录，因为不可能在往根节点的右子树走了
                pervElem = stk.top();
                stk.pop();
            }
            // 这个新元素入栈
            stk.push(postorder[i]);
        }
        return true;
    }
};
