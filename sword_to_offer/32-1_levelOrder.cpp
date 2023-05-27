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

/**
 * @brief 
 * 使用一个队列辅助
 */
class Solution {
 public:
  vector<int> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return res;

    que.push(root);
    while (!que.empty()){
      // 获取队头元素
      res.push_back(que.front()->val);
      
      // 获取队头元素并出队
      tmp = que.front();
      que.pop();

      if (tmp->left)
        que.push(tmp->left);
      if (tmp->right)
        que.push(tmp->right);
    }
    return res;
  }
  private:
    vector<int> res;
    queue<TreeNode*> que;  // 辅助队列
    TreeNode* tmp = nullptr;
};