#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief 
 * 从根节点开始递归的对树进行遍历，并从叶子节点先开始反转得到镜像
 */
class Solution {
 public:
  TreeNode* mirrorTree(TreeNode* root) {
    // 为空直接返回
    if (root == nullptr)
      return nullptr;

    // 叶子节点直接返回
    if (root->left == nullptr && root->right == nullptr)
      return root;

    // 当前递归栈帧中使用的临时变量
    TreeNode* tmp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(tmp);

    return root;
  } 
};



/**
 * @brief 
 * 使用一个辅助栈，从上到下依次将每一层的节点添加到栈中
 * 从上到下依次进行反转
 */
class Solution {
 public:
  TreeNode* mirrorTree(TreeNode* root) {
    stack<TreeNode*> stacktmp;
    if (!root)
      return nullptr;

    // 根节点入栈
    stacktmp.push(root);
    while (!stacktmp.empty()) {
      // 获取栈顶元素
      TreeNode* node = stacktmp.top();
      stacktmp.pop();

      if (node->left)
        stacktmp.push(node->left);
      if (node->right)
        stacktmp.push(node->right);
      
      // 交换出栈元素的左右子树
      TreeNode* tmp = node->left;
      node->left = node->right;
      node->right = tmp;
    }
    return root;
  }
};


int main() {
  return 0;
}