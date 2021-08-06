#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if (root == nullptr)
      return res;
    que.push(root);
    while (!que.empty()) {  // 层序遍历
      int len = que.size();
      deque<int> level;
      for (int i = 0; i < len; i++) {
        TreeNode* tmp = que.front();
        que.pop();
        if (tmp->left) que.push(tmp->left);
        if (tmp->right) que.push(tmp->right);
        if (res.size() % 2 == 0) {  
          level.push_back(tmp->val);
        } else {
          level.push_front(tmp->val);
        }
      }
      res.push_back(vector<int>(level.begin(), level.end()));
    }
    return res;
  }
};  */


/*  双端队列
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    deque<TreeNode*> nodes;
    if (root == nullptr)
      return res;
    nodes.push_back(root);
    while (!nodes.empty()) {  // 层序遍历
      // 先将奇数层的从左向右打印
      vector<int> tmp;
      int len = nodes.size();
      for (int i = len - 1; i >= 0; i--) {
        TreeNode* tmpnode = nodes.back();
        nodes.pop_back();
        tmp.push_back(tmpnode->val);
        if (tmpnode->left)
          nodes.push_front(tmpnode->left);
        if (tmpnode->right)
          nodes.push_front(tmpnode->right);
      }
      res.push_back(tmp);
      if (nodes.empty())  break;

      // 开始遍历偶数层
      tmp = vector<int>();
      len = nodes.size();
      for (int i = 0; i < len; i++) {
        TreeNode* tmpnode = nodes.front();
        nodes.pop_front();
        tmp.push_back(tmpnode->val);
        if (tmpnode->right)
          nodes.push_back(tmpnode->right);
        if (tmpnode->left)
          nodes.push_back(tmpnode->left);
      }
      res.push_back(tmp);
    }
    return res;
  }
};  */

// 对偶数层进行反转
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr)  return res;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
      int len = nodes.size();
      vector<int> level;
      for (int i = 0; i < len; i++) {
        TreeNode* tmpNode = nodes.front();
        nodes.pop();
        level.push_back(tmpNode->val);
        if (tmpNode->left)  nodes.push(tmpNode->left);
        if (tmpNode->right) nodes.push(tmpNode->right);
      }
      if (res.size() % 2 == 1)
        reverse(level.begin(), level.end());
      res.push_back(level);
    }
    return res;
  }
};