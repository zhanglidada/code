#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief 
 * 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
 * 
 * 1.可以采用深度优先遍历
 * 2.可以采用层序遍历
 */

// 1.深度优先遍历
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) 
      return 0;
    
    // 左子树深度和右子树深度的最大值 + 1
    return max(dfs(root->left), dfs(root->right)) + 1;
  }
  int dfs(TreeNode* root) {
    if (root == nullptr)  
      return 0;
    
    return max(dfs(root->left), dfs(root->right)) + 1;
  }
};

// 2.层序遍历
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr)  
      return 0;
    
    que.push(root);
    
    while (!que.empty()) {
      // 获取上一层的节点个数
      len = que.size();
      for (int i = 0; i < len; i++) {
        TreeNode* node = que.front();
        que.pop();
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
      res++;
    }
    return res;
  }
  queue<TreeNode*> que;
  int len = 0;
  int res = 0;
};