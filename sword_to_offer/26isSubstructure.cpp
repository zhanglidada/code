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
    
    // 比较A和B节点的同时还需要比较A->left和B, A->right和B
    return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
  }
  // 比较当前节点为根的子树A 和树B是否完全一致
  bool recur(TreeNode* A, TreeNode* B) {
    if (B == nullptr)  // 比较到了B的结尾，说明之前全部匹配成功
      return true;
    // A为空或者值不匹配，返回false
    if (A== nullptr || A->val != B->val)
      return false;
    return recur(A->left, B->left) && recur(A->right, B->right);
  }
};