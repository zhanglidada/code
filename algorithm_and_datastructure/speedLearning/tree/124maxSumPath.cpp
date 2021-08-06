#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法,自底向上
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    maxGain(root);
    return maxValue;
  }
  // 计算二叉树中每个节点的最大贡献值
  int maxGain(TreeNode* root) {
    if (root == nullptr)  return 0;
    // 递归获得左右节点的贡献值,且只有贡献值大于0才有意义
    int leftGain = max(maxGain(root->left), 0);
    int rightGain = max(maxGain(root->right), 0);
    // 获得以此节点为根节点的最大路径和
    int priceNewPath = root->val + leftGain + rightGain;

    // 全局变量保存每次递归获得的最大值
    maxValue = max(maxValue, priceNewPath);

    // 返回此节点的贡献值
    return root->val + max(leftGain, rightGain);
  }
 private:
  int maxValue = INT32_MIN;
};
