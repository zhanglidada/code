#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {

      // root为空直接返回
      if (root == nullptr)
        return res;
      
      // 入队root
      que.push(root);
      
      // que不为空时一直访问
      while (!que.empty()) {

        // 每次遍历前清空level
        level.clear();

        level_len = que.size();  // 获取当前层的节点个数

        for (int i = 0; i < level_len; i++) {
          tmp_node = que.front();  // 获取队头元素
          que.pop();  // 队头元素出队
          level.push_back(tmp_node->val);
          if (tmp_node->left)
            que.push(tmp_node->left);
          
          if (tmp_node->right)
            que.push(tmp_node->right);
        }

        // 添加当前层的访问顺序
        res.push_back(level);
      }

      // 返回最终结果
      return res;
    }
  private:
    vector<vector<int>> res;  // 返回值
    vector<int> level;  // 单层节点
    queue<TreeNode*> que;
    TreeNode* tmp_node = nullptr;
    int level_len = 0;
};