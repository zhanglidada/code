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


int main() {
  return 0;
}