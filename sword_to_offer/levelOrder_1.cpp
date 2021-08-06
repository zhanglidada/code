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
  vector<int> levelOrder(TreeNode* root) {
    vector<int> res;
    if (root == nullptr)
      return res;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()){
      res.push_back(que.front()->val);
      TreeNode* tmp = que.front();
      que.pop();
      if (tmp->left)
        que.push(tmp->left);
      if (tmp->right)
        que.push(tmp->right);
    }
    return res;
  }
};