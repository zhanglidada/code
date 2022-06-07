#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
 * 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 
 * 如果节点不存在，则返回 null
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
 * Purpose:
 * 对二叉搜索树进行中序遍历，得到递增序列
 * 采用递归方式
********************************************************************************************/
class Solution {
  public:
    TreeNode* searchBST(TreeNode* root, int val) {
      if (root == nullptr)  return nullptr;

      if (root->val < val)
        return searchBST(root->right, val);
      else if (root->val > val) 
        return searchBST(root->left, val);
      else
        return root;
    }
};

/*******************************************************************************************
 * Purpose:
 * 对二叉搜索树进行中序遍历，得到递增序列
********************************************************************************************/
class Solution {
  public:
    TreeNode* searchBST(TreeNode* root, int val) {
      if (root == nullptr)  return nullptr;

      while (root) {
        if (val < root->val)
          root = root->left;
        else if (val > root->val)
          root = root->right;
        else
          return root;
      }

      return nullptr;
    }
};