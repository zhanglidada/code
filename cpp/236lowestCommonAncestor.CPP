#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;  // p节点路径
        vector<TreeNode*> q_path;  // q 节点路径
        vector<TreeNode*> stack;   // dfs查找过程中的访问路径
        TreeNode*         pos = NULL;

        // 查找p的路径，并复制给p_path
        dfs_search(root, p, stack, p_path);
        stack.clear();  // 重置stack
        // 查找q的路径，并复制给q_path
        dfs_search(root, q, stack, q_path);

        for (int i = 0; i < p_path.size() && i < q_path.size(); i++)
        {
            // 一直遍历访问到最后一个相同的节点
            if (p_path[i] == q_path[i])
                pos = p_path[i];
        }

        return pos;
    }

    // 使用vector模仿栈
    void dfs_search(TreeNode* node, TreeNode* search, vector<TreeNode*> &stack, vector<TreeNode*> &path)
    {
        if (node == NULL)
            return;

        stack.push_back(node);  // 当前访问的节点压栈
        if (node == search)  // 判断当前节点是否为需要查找的节点
        {
            path = stack;  // 当前stack中存储的就是查找路径，复制给path并返回
            return;
        }

        // 当前节点不是需要查找的节点，继续访问其左右子树
        if (node->left != NULL)
          dfs_search(node->left, search, stack, path);
        if (node->right != NULL)
          dfs_search(node->right, search, stack, path);

        // 当前节点的左右子树中都没有要查找的节点，出栈当前节点,
        // 去上一层dfs函数中访问其右子树
        stack.pop_back();
    }
};