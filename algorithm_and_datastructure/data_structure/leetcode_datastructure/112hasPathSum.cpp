#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定二叉树的根节点root和一个整数目标和targetSum。
 * 判断是否存在 根节点到叶子节点 的路径，路径上所有节点值相加等于目标和targetSum。
 * 如果存在，返回 true ；否则，返回 false 。
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
 * 采用递归方式实现
 * 节点的值有可能为负数，需要注意
********************************************************************************************/
class Solution {
  public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root == nullptr)  return false;

      // 当前为叶子节点且值匹配
      if (root->val == targetSum && root->left == nullptr && root->right == nullptr)
        return true;
      
      return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

/*******************************************************************************************
 * Notes:
 * 采用迭代方式实现
 * 使用一个队列辅助存储层序遍历信息，包括节点以及当前targetnum
********************************************************************************************/
class Solution {
  public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root == nullptr)  return false;

      // 首先入队根节点
      que.push(std::make_pair(root, targetSum));
      
      // 循环层序遍历
      while (!que.empty()) {
        auto [node, targetval] = que.front();
        que.pop();

        // 当且仅当为叶子节点时才判断值是否匹配
        if (node->left == nullptr && node->right == nullptr && node->val == targetval)  return true;

        if (node->left != nullptr)
          que.push(std::make_pair(node->left, targetval - node->val));
        if (node->right != nullptr)
          que.push(std::make_pair(node->right, targetval - node->val));
      }

      return false;
    }
  private:
    queue<std::pair<TreeNode*, int>> que;
};