#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定二叉树的根节点root，返回二叉树的层序遍历
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
 * 对于二叉树的层序遍历，使用队列作为辅助结构
********************************************************************************************/
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      if (root == nullptr)  return res;

      // 先入队根节点
      que.emplace(root);
      while (!que.empty()) {
        level_count = que.size();
        level_nodes.clear();  // 重置层序访问队列
        for (int i = 0; i < level_count; i++) {
          curr_node = que.front();
          que.pop();
          level_nodes.emplace_back(curr_node->val);
          if (curr_node->left)
            que.emplace(curr_node->left);
          if (curr_node->right)
            que.emplace(curr_node->right); 
        }
        res.emplace_back(level_nodes);
      }
      return res;
    }
  private:
    vector<vector<int>> res;  // 返回结果
    vector<int> level_nodes;  // 层序访问队列
    queue<TreeNode*> que;  // 层序节点缓存队列
    TreeNode* curr_node = nullptr;
    int level_count;  // 每层节点个数
};