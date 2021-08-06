#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr)  return ans;
    bool odd = true;
    queue<TreeNode*> levelQueue;
    levelQueue.push(root);
    int levelSize = 0;
    vector<int> tmp;
    while (!levelQueue.empty()) {
      levelSize = levelQueue.size();
      tmp.clear();
      for (int i = 0; i < levelSize; i++) {
        TreeNode* node = levelQueue.front();
        tmp.push_back(node->val);  // 将每一层的节点存入一个临时vector中
        if (node->left)  levelQueue.push(node->left);
        if (node->right)  levelQueue.push(node->right);
        levelQueue.pop();
      }
      if (odd) {
        odd = false;
      } else {
        odd = true;
        reverse(tmp.begin(), tmp.end());
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};