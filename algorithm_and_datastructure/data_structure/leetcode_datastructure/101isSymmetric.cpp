#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个二叉树，检查是否对称
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
 * 采用递归的方法
 * 两个子树的根节点值相同，且一个树的左子树与另一个树的右子树对称
********************************************************************************************/
class Solution {
  public:
    bool isSymmetric(TreeNode* root) {
      return check(root->left, root->right);
    }
    // 检查两个节点值是否相等
    bool check(TreeNode* node1, TreeNode* node2) {
      if (!node1 && !node2) return true;
      if (!node1 || !node2) return false;
      return node1->val == node2->val 
              && check(node1->left, node2->right) 
              && check(node1->right, node2->left);
    }
};

/*******************************************************************************************
 * Notes:
 * 使用迭代方式实现：
 * 1.使用一个队列进行辅助操作,每次提取两个节点并比较值
 * 2.队列中连续的两个节点值相等，且其子树互为镜像
********************************************************************************************/
class Solution {
  public:
    bool isSymmetric(TreeNode* root) {
      que.emplace(root->right);
      que.emplace(root->left);
      while (!que.empty()) {

        // 每次提取两个节点比较
        node1 = que.front();
        que.pop();
        node2 = que.front();
        que.pop();

        // 连续两个节点为空，忽略
        if (!node1 && !node2) continue;

        if ((!node1 || !node2) || node1->val != node2->val) return false;
        
        que.emplace(node1->left);
        que.emplace(node2->right);
        que.emplace(node1->right);
        que.emplace(node2->left);
      }
      return true;
    }
  private:
    queue<TreeNode*> que;
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
};