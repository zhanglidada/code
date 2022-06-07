#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个二叉搜索树 root 和一个目标结果 k，
 * 如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * Notes:
 * 树中至少有一个节点
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
 * 首先应该想到使用hash存储访问过的节点
 * 使用深度优先搜索方式遍历树节点，最多访问一边数中所有的节点即可
********************************************************************************************/
class Solution {
  public:
    bool findTarget(TreeNode* root, int k) {
      target = k;
      return find_target_helper(root);
    }
    
    // 查找树中的目标和是否存在
    bool find_target_helper(TreeNode* node) {
      // 遍历到叶子节点仍不满足条件，返回false
      if (node == nullptr)  return false;
      // 找到树中满足条件的节点
      if (visited.count(target - node->val)) return true;
      visited.insert(node->val);
      return find_target_helper(node->left) || find_target_helper(node->right);
    }
  private:
    unordered_set<int> visited;
    int   target = 0;
};

/*******************************************************************************************
 * Notes:
 * 使用hash存储访问过的节点
 * 使用广度优先搜索方式遍历树节点，使用队列作为辅助结构
********************************************************************************************/
class Solution {
  public:
    bool findTarget(TreeNode* root, int k) {
      que.push(root);
      while (!que.empty()) {
        // 首先将队头元素出队
        curr_node = que.front();
        que.pop();

        if (visited.count(k - curr_node->val))  return true;
        visited.insert(curr_node->val);

        if (curr_node->left != nullptr) que.push(curr_node->left);
        if (curr_node->right != nullptr)  que.push(curr_node->right);
      }
      return false;
    }
  private:
    unordered_set<int> visited;
    queue<TreeNode*> que;  // 辅助队列
    TreeNode* curr_node = nullptr;
};

/*******************************************************************************************
 * Notes:
 * 深度优先 + 中序遍历 + 双指针
 * 将二叉搜索树先中序遍历，得到升序数组；使用双指针查找配对元素
********************************************************************************************/
class Solution {
  public:
    void inorderTraversal(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        vec.push_back(node->val);
        inorderTraversal(node->right);
    }

    bool findTarget(TreeNode *root, int k) {
        inorderTraversal(root);
        int left = 0, right = vec.size() - 1;
        while (left < right) {
            if (vec[left] + vec[right] == k) {
                return true;
            }
            if (vec[left] + vec[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
  private:
    vector<int> vec;
};
