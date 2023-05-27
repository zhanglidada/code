#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

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
      if (root == nullptr)
        return res;

      que.push(root);
      while (!que.empty()) {
        level.clear();  // 清空上次遍历的层序结果

        level_size = que.size();  // 获取当前层节点个数
        for (int i = 0; i < level_size; i++) {
          tmp_node = que.front();  // 获取队头节点
          que.pop();  // 对头元素出队
          level.push_back(tmp_node->val);
          
          if (tmp_node->left)
            que.push(tmp_node->left);

          if (tmp_node->right)
            que.push(tmp_node->right);
        }
        // 根据当前层决定是否反转当前层序遍历结果
        if (res.size() % 2 == 1)
          reverse(level.begin(), level.end());

        res.push_back(level);
      }
      return res;
    }
  private:
    vector<vector<int>> res;  // 返回结果
    vector<int> level;
    queue<TreeNode*> que;
    TreeNode* tmp_node = nullptr;
    int level_size = 0;
};