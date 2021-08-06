#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 由于二叉树中不存在相同值的元素，可以用一个hashmap保存位置信息
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; i++) {
      pos[inorder[i]] = i;
    }
    return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
  }
  TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr) {
    if (prel > prer)
      return nullptr;
    // 前序遍历的第一个节点为根节点
    TreeNode* root = new TreeNode(preorder[prel]);
    // 计算左子树的长度
    int ltreeLen = pos[preorder[prel]] - inl;
    root->left = dfs(preorder, inorder, prel + 1, prel + ltreeLen, inl, pos[preorder[prel]] - 1);
    root->right = dfs(preorder, inorder, prel + ltreeLen + 1, prer, pos[preorder[prel]] + 1, inr);
    return root;
  }
 private:
  unordered_map<int, int> pos;
};
int main() {
  return 0;
}