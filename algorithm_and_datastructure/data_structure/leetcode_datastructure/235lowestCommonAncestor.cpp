#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * Notes:
 * 最近公共祖先的定义为：
 * 对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先
 * 且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。
 * 
 * 1.所有节点值唯一
 * 2.p、q 为不同节点且均存在于给定的二叉搜索树中。
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
 * 根据二叉搜索树的特性，分别查找p以及q节点，并保存查找路径
 * 根据查找路径可以获得最近公共祖先
********************************************************************************************/
class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 首先找到p的路径  
        currnode = root;     
        while (currnode->val != p->val) {
            path1.emplace_back(currnode);
            if (currnode->val < p->val)  currnode = currnode->right;
            else  currnode = currnode->left;
        }
        // 当前找到的节点也要存入
        path1.emplace_back(p);

        // 其次找到q的路径  
        currnode = root;
        while (currnode->val != q->val) {
            path2.emplace_back(currnode);
            if (currnode->val < q->val)  currnode = currnode->right;
            else  currnode = currnode->left;
        }
        // 当前找到的节点也要存入
        path2.emplace_back(q);
        
        for (int i = 0; i < min(path1.size(), path2.size()); i++) {
            if (path1[i] == path2[i])
                currnode = path1[i];
            else
                break;
        }
        return currnode;
    }
  private:
    // 节点的访问路径
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    TreeNode* currnode = nullptr;
};


// 优化代码，使用一个队列
class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 首先保存查找p的路径  
        currnode = root;     
        while (currnode->val != p->val) {
            path.emplace_back(currnode);
            if (currnode->val < p->val)  currnode = currnode->right;
            else  currnode = currnode->left;
        }
        path.emplace_back(p);  // 当前找到的节点也要存入

        // 查找q的路径并与原始路径比较，最多查找p的路径
        for (pos = 0; pos < path.size(); pos++) {
            if (root != path[pos]) {
                // 此时pos上一个位置为p q的公共祖先
                break;
            }
            
            if (root->val < q->val) {
                root = root->right;
            }
            else if (root->val > q->val) {
                root = root->left;
            }
            else {
                // 此时q为p的祖先节点
                return q;
            }
        }
        return path[pos - 1];
    }
  private:
    // 节点的访问路径
    vector<TreeNode*> path;
    TreeNode* currnode = nullptr;
    int pos = 0;
};