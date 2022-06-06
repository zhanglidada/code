#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定二叉树的根节点 root ，返回节点值的后序遍历
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
 * 后序遍历的节点顺序，采用递归方式
********************************************************************************************/
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode* root) {
      if (root == nullptr)  return res;

      postorderTraversal(root->left);
      postorderTraversal(root->right);

      res.emplace_back(root->val);
      return res;
    }
  private:
    vector<int> res;
};

/*******************************************************************************************
 * Notes:
 * 后序遍历的节点顺序，采用迭代的方式
 * 迭代方式需要一个辅助结构存储遍历过程遇到的节点，故采用栈保存中间遍历过程的节点
 * 需要注意的是根节点在出栈后还需要再次进栈,直到其右子树节点全部访问结束
********************************************************************************************/
class Solution {
  public:
    vector<int> postorderTraversal(TreeNode* root) {
      if (root == nullptr)  return res;

      curr_node = root;
      while (curr_node || !st.empty()) {
        // 类似中序遍历过程，先依次入栈左节点
        while (curr_node) {
          st.emplace(curr_node);
          curr_node = curr_node->left;
        }

        // 出栈未入res队的最左节点
        curr_node = st.top();
        st.pop();

        // 当前访问节点为叶子节点或其左右节点均访问过
        if (curr_node->right == nullptr || curr_node->right == prev_node) {
          res.emplace_back(curr_node->val);
          prev_node = curr_node;  // 设置前序节点
          curr_node = nullptr;  // 防止叶子节点访问结束后，再次进入循环
        } else {
          // 再次入栈根节点并访问其右子树
          st.emplace(curr_node);
          curr_node = curr_node->right;
        }
      }
      return res;
    }
  private:
    vector<int> res;  // 访问顺序队列
    stack<TreeNode*> st;  // 临时缓存节点栈
    TreeNode* curr_node = nullptr;  // 当前遍历过程中的节点
    TreeNode* prev_node = nullptr;  // 前序节点
};