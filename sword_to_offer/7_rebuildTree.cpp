#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/************************************************************************
 * 1.采用递归的方式
 * 
 * 1）前序遍历结果：
 * [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ，即根节点总是前序遍历中的第一个节点
 * 
 * 2）中序遍历结果：
 * [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
 * 
 * 3）根据前序遍历结果中的根节点，定位到中序遍历中的根节点位置，可以定位左子树和右子树遍历结果
 * 
 * 优化：
 * 中序遍历过程中对根节点的定位，可以采用hash表辅助查找，保存节点值对应的位置信息
 * 
 * hash表的键值对表示：键为节点（节点的值），值为节点在中序遍历中出现的位置
 ************************************************************************/
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    // 递归前先遍历一遍中序数组，初始化hash表
    for (int i = 0; i < n; i++) {
      pos[inorder[i]] = i;
    }
    return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
  }
  TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr) {
    if (prel > prer)
      return nullptr;

    // 前序遍历的第一个节点为根节点
    TreeNode* root = new TreeNode(preorder[prel]);
    // 计算左子树的size：(根节点在中序中位置 - 1) 中序起始位置
    int position = pos[preorder[prel]];
    int ltreeLen = position - inl;
    // 左子树
    root->left = dfs(preorder, inorder, prel + 1, prel + ltreeLen, inl, position - 1);
    // 右子树
    root->right = dfs(preorder, inorder, prel + ltreeLen + 1, prer, position + 1, inr);
    return root;
  }
 private:
  unordered_map<int, int> pos;
};


/************************************************************************
 * 1.采用迭代的方法
 * 
 * 对于前序遍历中的任意两个连续节点u,v，他们有两种可能的关系：
 * 1）v是u的左孩子
 * 
 * 2）u没有左孩子，那么v是u的某个祖先节点(或者u本身)的右孩子：
 *   ·如果u没有左孩子，那么下一个节点就是u的右孩子
 *   ·如果u没有右孩子，那么向上回溯，直到遇到第一个有右孩子（且u不在其右孩子的子树中）的节点Ua,v为Ua的右孩子
 * 
 * 设计思路：
 * 1）使用栈维护「当前节点的所有还没有考虑过右儿子的祖先节点」，栈顶就是当前节点。
 * 2) 使用一个指针 index 指向中序遍历的某个位置，初始值为0。index 对应的节点是「当前节点不断往左走达到的最终节点」
 ************************************************************************/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};


int main() {
  return 0;
}