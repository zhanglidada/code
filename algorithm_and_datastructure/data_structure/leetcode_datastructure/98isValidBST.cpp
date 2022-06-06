#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 * Notes:
 * 树中节点数目范围在[1, 10^4] 内
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
 * 采用递归方式
 * Notes:
 * 二叉搜索树左子树所有节点的值均小于根节点，右子树所有节点的值均大于根节点
 * 左右子树分别也是一个二叉搜索树
********************************************************************************************/
class Solution {
  public:
    bool isValidBST(TreeNode* root) {
      return isvalid_bst_helper(root->left, INT64_MIN, root->val)
             && isvalid_bst_helper(root->right, root->val, INT64_MAX);
    }

    // 递归时需要判断节点的值是否在区间内
    bool isvalid_bst_helper(TreeNode* root, long long int lower, long long int upper) {
      if (root == nullptr)  return true;
      if (root->val >= upper || root->val <= lower) return false;
      return isvalid_bst_helper(root->left, lower, root->val)
             && isvalid_bst_helper(root->right, root->val, upper);
    }
};

/*******************************************************************************************
 * Notes:
 * 二叉搜索树的特殊性质，其中序遍历一定为升序序列
********************************************************************************************/
class Solution {
  public:
    bool isValidBST(TreeNode* root) {
      path.push(root);
      root = root->left;
      while (!path.empty() || root != nullptr) {
        while (root != nullptr) {
          path.push(root);
          root = root->left;
        }

        root = path.top();
        path.pop();
        if (inorder_val >= root->val) return false;
        inorder_val = root->val;
        root = root->right;
      }
      return true;
    }
  private:
    stack<TreeNode*> path;
    long long int inorder_val = INT64_MIN;
};