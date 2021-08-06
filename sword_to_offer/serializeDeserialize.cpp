#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
 public:
    // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr)  return "";
    ostringstream out;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      TreeNode* tmp = que.front();
      que.pop();
      if (tmp) {
        out << tmp->val << " ";
        que.push(tmp->left);
        que.push(tmp->right);
      } else {
        out << "null ";
      }
    }
    return out.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "")  return nullptr;
    istringstream input(data);
    string val;
    vector<TreeNode*> vec;  // 用一个数组来保存所有树中的节点
    while (input >> val) {
      if (val == "null")
        vec.push_back(nullptr);
      else {
        vec.push_back(new TreeNode(stoi(val)));
      }
    }
    int j = 1;
    for (int i = 0; j < vec.size(); i++) {
      if (vec[i] == nullptr)  continue;
      // i每往后移动一位，j往后移动两位，所以j始终是当前i的左子下标
      if (j < vec.size())  vec[i]->left = vec[j++];
      if (j < vec.size())  vec[i]->right = vec[j++];
    }
    return vec[0];
  }
};