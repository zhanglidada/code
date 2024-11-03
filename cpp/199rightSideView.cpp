#include"./include/common.h"


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // 存放从右观察到的二叉树结果，第i层二叉树出队的同时依次更新watch[i]，直到当前层的的最后一个节点
        vector<int> watch;
        int level;  // 当前节点的层次
        TreeNode*   node = nullptr;
        
        if (root == nullptr)
            return watch;
        
        queue<pair<TreeNode*, int>> que;  // 存放层序遍历二叉树的队列，每个入队的节点保存其层次信息

        que.push(make_pair(root, 0));  // 根节点为第0层
        while (!que.empty())
        {
            node = que.front().first;  // 获得待搜索节点地址
            level = que.front().second;  // 获得待搜索节点层次
            que.pop();  // 对头元素出队
            
            // 如果取出的节点是这一层的第一个节点
            if (watch.size() <= level)
                watch.push_back(0);  // 先入队当前层节点的初始值

            // 更新watch[level]
            watch[level] = node->val;

            // 左右孩子节点的level比当前大1
            if (node->left)
                que.push(make_pair(node->left, level + 1));
            if (node->right)
                que.push(make_pair(node->right, level + 1));
        }
        return watch;
    }
};