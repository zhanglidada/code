#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个二叉树，找出其最大深度。
 * Notes:
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
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
 * 递归很简单实现
********************************************************************************************/
class Solution {
  public:
    int maxDepth(TreeNode* root) {
      if (root == nullptr)  return 0;
      return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


/*******************************************************************************************
 * Notes:
 * 使用广度优先，只需要计算广度优先的层数即可
********************************************************************************************/
class Solution {
  public:
    int maxDepth(TreeNode* root) {
      if (root == nullptr)  return 0;

      que.emplace(root);  // 入栈队首节点
      while (!que.empty()) {
        res ++;
        level_size = que.size();
        for (int i = 0; i < level_size; i++) {
          root = que.front();  // 获取队首元素
          que.pop();  // 队首元素出队
          if (root->left) que.emplace(root->left);
          if (root->right)  que.emplace(root->right);
        }
      }
      return res;
    }
  private:
    queue<TreeNode*> que;
    int level_size = 0;  // 每层节点数
    int res = 0;
};