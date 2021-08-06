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
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if (root == nullptr)
      return res;
    que.push(root);
    while (!que.empty()) {  // 层序遍历
      vector<int> tmpLevel;
      int len = que.size();
      for (int i = 0; i < len; i ++) {
        TreeNode* tmpnode = que.front();
        que.pop();
        tmpLevel.push_back(tmpnode->val);
        if (tmpnode->left)
          que.push(tmpnode->left);
        if (tmpnode->right)
          que.push(tmpnode->right);
      }
      res.push_back(tmpLevel);
    }
    return res;
  }
};