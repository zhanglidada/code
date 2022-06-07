#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定二叉树的根节点 root ，返回节点值的中序遍历
********************************************************************************************/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*******************************************************************************************
 * Notes:
 * 二叉树的中序遍历，首先想到使用递归方式
********************************************************************************************/
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
      if (!root)  return res;
      inorderTraversal(root->left);
      res.emplace_back(root->val);
      inorderTraversal(root->right);
      return res;
    }
  private:
    vector<int> res;
};

/*******************************************************************************************
 * Notes:
 * 二叉树的中序遍历，其次想到使用迭代方式
 * 1.使用一个栈保存节点的遍历顺序
 * 2.从子树的根节点开始一直遍历到最左节点，直到当前节点的left为空，出栈
 * 3.出栈时当前节点的val进入res中，同时将其右子树的根节点入栈
 * 4.跳转到第二步
********************************************************************************************/
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
      if (root == nullptr)  return res;
      
      curr_node = root;
      // 当前节点不空或者栈不空
      while (curr_node != nullptr || !st.empty()) {
        // 从当前节点开始，一直到最左节点入栈
        while (curr_node != nullptr) {
          st.push(curr_node);
          curr_node = curr_node->left;
        }
        // 获取栈顶元素
        curr_node = st.top();
        res.emplace_back(curr_node->val);
        st.pop();
        // 开始遍历右子树
        curr_node = curr_node->right;
      }
      return res;
    }
  private:
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr_node = nullptr;
};

/*******************************************************************************************
 * Notes:
 * 二叉树的中序遍历，又是morris中序遍历，之后再详细看看
********************************************************************************************/