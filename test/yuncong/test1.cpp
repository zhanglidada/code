#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};


class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 
   * @param root TreeNode类 
   * @return int整型vector<vector<>>
   */
  vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr)  return res;
    res.push_back({root->val});
    queue<TreeNode*> queuelevel;
    if (root->left) queuelevel.push(root->left);
    if (root->right) queuelevel.push(root->right);
    while (!queuelevel.empty()) {
      // 每一层的节点数
      int levelsize = queuelevel.size();
      vector<int> tmp;
      for (int i = 0; i < levelsize; i++) {
        TreeNode * node = queuelevel.front();
        tmp.push_back(node->val);
        if (node->left) queuelevel.push(node->left);
        if (node->right) queuelevel.push(node->right);
        queuelevel.pop();
      }
      res.push_back(tmp);
    }
    return res;
  }
};