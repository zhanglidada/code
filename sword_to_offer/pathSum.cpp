#include <iostream>
#include <vector>
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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    recur(root, sum);
    return res;
  }
  void recur(TreeNode* root, int target) {
    if (root == nullptr)  return;
    path.push_back(root->val);
    if (root->val == target && root->left == nullptr && root->right == nullptr) {
      res.push_back(path);
      path.pop_back();
      return;
    }
    int subtarget = target - root->val;
    recur(root->left, subtarget);
    recur(root->right, subtarget);
    path.pop_back();  // 进行回溯的时候path删除当前节点值
  }
  vector<vector<int>> res;
  vector<int> path;
};