#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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
 * 前序遍历的节点顺序，采用递归方式
********************************************************************************************/
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      if (!root)  return res;
      res.emplace_back(root->val);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
      return res;
    }
  private:
    vector<int> res;
};

/*******************************************************************************************
 * Notes:
 * 前序遍历的节点顺序，采用迭代方式
 * 可以使用栈来实现，每次出栈的元素将其右，左节点分别入栈
********************************************************************************************/
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      if (!root)  return res;

      // 首先将根节点入栈
      st.push(root);
      while (!st.empty()) {
        curr_node = st.top();
        st.pop();
        res.emplace_back(curr_node->val);
        if (curr_node->right) st.push(curr_node->right);
        if (curr_node->left)  st.push(curr_node->left);
      }
      return res;
    }
  private:
    vector<int> res;
    stack<TreeNode*> st;  // 保存节点信息
    TreeNode* curr_node;  // 迭代过程中当前访问的树节点
};

/*******************************************************************************************
 * Notes:
 * 先序遍历访问节点并存储结果，栈中存储节点的访问顺序，出栈时访问
********************************************************************************************/
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      if (!root)  return res;
      
      curr_node = root;  // 当前节点指向根
      while (!st.empty() || curr_node != nullptr) {
        // 深度优先遍历左子树并保存遍历路径
        while (curr_node != nullptr) {
          res.emplace_back(curr_node->val);
          st.emplace(curr_node);
          curr_node = curr_node->left;
        }
        curr_node = st.top();
        st.pop();
        // 指向最左节点的右子树
        curr_node = curr_node->right;
      }

      return res;
    }
  private:
    vector<int> res;
    stack<TreeNode*> st;  // 保存节点信息
    TreeNode* curr_node;  // 迭代过程中当前访问的树节点
};

/*******************************************************************************************
 * Notes:
 * 使用morris遍历方法，只用常数时间复杂度实现前序遍历
 * 核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。
 * 
********************************************************************************************/
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode* root) {

    }
};