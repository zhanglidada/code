#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == nullptr || B == nullptr)
      return false;
    return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
  }
  // 判断树A中当前节点为根节点的子树中是否包含树B的子结构
  bool recur(TreeNode* A, TreeNode* B) {
    if (B == nullptr)  // 比较到了B的结尾，说明之前全部匹配成功
      return true;
    if (A== nullptr || A->val != B->val)
      return false;
    return recur(A->left, B->left) && recur(A->right, B->right);
  }
};