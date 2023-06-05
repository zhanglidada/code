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

/**
 * @brief 
 * 找出所有 "从根节点到叶子节点" 路径总和等于给定目标和的路径
 * 
 * 返回的是从根节点到叶子节点，所以只需要从根节点开始遍历所有的路径即可
 */
class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    recur(root, sum);
    return res;
  }

  void recur(TreeNode* root, int target) {
    // 特殊情况
    if (root == nullptr)
      return;
    
    // 当前节点先push到path中
    path.push_back(root->val);

    // 满足条件的叶子节点
    if (root->val == target && root->left == nullptr && root->right == nullptr) {
      // 遍历路径push
      res.push_back(path);
      // 叶子节点的值pop，向上回溯
      path.pop_back();
      return;
    }

    // 子树target
    int subtarget = target - root->val;

    // 查找左子树和右子树
    recur(root->left, subtarget);
    recur(root->right, subtarget);

    path.pop_back();  // 进行回溯的时候path删除当前节点值
  }

private:
  vector<vector<int>> res;
  vector<int> path;
};