#include <iostream>
#include <vector>
#include <unordered_map>
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
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 1.使用递归方式
 * 2.存储父节点
 */

/******************************************************* 
 * 1.使用递归方式
 * 
 * 1）定义函数func(x, p, q),表示以x节点为根的树中是否包含节点p或者节点q
 * 包含返回true，不包含返回false
 * 
 * 2）符合条件的公共祖先 X 满足以下条件：
 * (f(x left son, p, q) && f(x right son, p, q)) || ( (x == p || x == q) && (f(x left son, p, q) || f(x right son, p, q)) )
 * 即 x的左右子树各自包含一个节点 || x为p、q中的节点之一,且x的左右子树之一包含p、q节点之一
 * 
 * 3）自底向上从叶子节点开始访问,所有满足条件的公共祖先中一定是最深的祖先节点先被访问到
 * 
*******************************************************/
class Solution {
  public:
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;

        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        // 当前节点的左右子树各自包含一个节点 || 当前节点为p、q节点之一且左右子树之一包含另一个节点
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            // 设置最近公共祖先节点
            ans = root;
        }

        // 返回当前节点的状态，当前节点只要满足下列条件之一就为true
        return lson || rson || root->val == p->val || root->val == q->val;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
  private:
    TreeNode* ans;
};

// 剪枝，ans只要查找到后，其余递归不需要继续去做
class Solution {
  public:
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;

        if (ans != nullptr)
          return false;

        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        // 当前节点的左右子树各自包含一个节点 || 当前节点为p、q节点之一且左右子树之一包含另一个节点
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            // 设置最近公共祖先节点
            ans = root;
        }

        // 返回当前节点的状态，当前节点只要满足下列条件之一就为true
        return lson || rson || root->val == p->val || root->val == q->val;
    }

    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
  private:
    TreeNode* ans;
};

/*******************************************************
 * 2.存储父节点
 *  
 * 1）从根节点开始遍历整棵二叉树，用哈希表记录每个节点的父节点指针。
 * 2）从 p 节点开始不断往它的祖先移动，并用数据结构记录已经访问过的祖先节点。
 * 3) 再从 q 节点开始不断往它的祖先移动，如果有祖先已经被访问过，即意味着
 * 这是 p 和 q 的深度最深的公共祖先，即 LCA 节点。
 * 
 * ****************************************************/
class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      // root节点的父节点为空
      fa[root->val] = nullptr;

      // 遍历所有节点并设置每个节点的父节点值
      dfs(root);

      // 递归查找p节点的父亲节点，并设置vist标志
      while (p != nullptr) {
        vist[p->val] = true;

        // p节点向上查找父亲
        p = fa[p->val];
      }

      while (q != nullptr) {
        if (vist[q->val] == true)
          return q;

        // q节点向上查找父节点
        q = fa[q->val];
      }

      return nullptr;
    }

    // 遍历所有节点，hash map中记录所有节点的父节点
    void dfs(TreeNode* root) {
      // 遍历左子树
      if (root->left != nullptr) {
        if (fa[root->left->val] == nullptr) {
          // 设置left child节点的father为当前节点root
          fa[root->left->val] = root;
          
          // 递归左子树
          dfs(root->left);
        }
      }
      // 遍历右子树
      if (root->right != nullptr) {
        if (fa[root->right->val] == nullptr) {
          // 设置right child节点的father为当前节点root
          fa[root->right->val] = root; 

          // 递归右子树
          dfs(root->right);
        }
      }
    }
  private:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vist;
};
