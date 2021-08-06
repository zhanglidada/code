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
  int maxPathSum(TreeNode* root) {
    maxPathSumDFS(root);
    return maxValue;
  }

  int maxPathSumDFS(TreeNode* root) {
    // 获得经过当前节点的最大路径和，同时更新全局最大路径和
    if (root == nullptr)
      return 0;
    int left = max(0, maxPathSumDFS(root->left));
    int right = max(0, maxPathSumDFS(root->right));
    
    // 获得以此节点为根节点的路径最大值
    int currentNodePrice = root->val + left + right;
    maxValue = max(maxValue, currentNodePrice);

    // 因为路径只能在此节点的左右孩子中选择一条，不能分叉
    return root->val + max(left, right);
  }
  int maxValue = INT32_MIN;
};
int main() {
  return 0;
}