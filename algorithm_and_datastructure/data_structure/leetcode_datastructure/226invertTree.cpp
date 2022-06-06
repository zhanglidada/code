#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
********************************************************************************************/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*******************************************************************************************
 * Notes:
 * 对一个树的节点遍历同时将其镜像插入另一个树中,采用递归方式
********************************************************************************************/
class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
      new_invert_tree(root, &new_root);
      return new_root;
    }
    // 传入指针的指针，用来修改指针的结果
    void new_invert_tree(TreeNode* root, TreeNode** new_root) {
      if (root == nullptr) {
        *new_root = nullptr;
        return;
      }
      *new_root = new TreeNode(root->val);
      new_invert_tree(root->left, &((*new_root)->right));
      new_invert_tree(root->right, &((*new_root)->left));
    }
  private:
    // 新的树节点指针
    TreeNode* new_root = nullptr;
};

// 不传递指针的指针，而是直接返回指针
class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
      return new_invert_tree(root);
    }
    // 传入需要复制的节点，将其复制返回
    TreeNode* new_invert_tree(TreeNode* root) {
      if (root == nullptr) return nullptr;

      TreeNode* new_root = new TreeNode(root->val);
      new_root->right = new_invert_tree(root->left);
      new_root->left = new_invert_tree(root->right);
      return new_root;
    }
};


/*******************************************************************************************
 * Notes:
 * 也可以采用迭代方式实现：bfs
 * 1.使用一个队列保存层序遍历节点
 * 2.节点出队时依次插入右子树，左子树中
********************************************************************************************/
class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
      if (root == nullptr)  return nullptr;

      que.emplace(root);  // 根节点入队
      
      // 每次从队列中取出一个节点并交换左右子树
      while (!que.empty()) {
        level_size = que.size();
        for (int i = 0; i < level_size; i++) {
          curr_node = que.front();
          que.pop();
          
          // 交换当前节点的左右子树
          TreeNode* tmp = curr_node->left;
          curr_node->left = curr_node->right;
          curr_node->right = tmp;

          if (curr_node->left)  que.emplace(curr_node->left);
          if (curr_node->right) que.emplace(curr_node->right);
        }
      }
      return root;
    }
  private:
    queue<TreeNode*>  que;
    int level_size = 0;
    TreeNode* curr_node = nullptr;
};