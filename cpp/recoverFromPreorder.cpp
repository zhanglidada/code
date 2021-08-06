#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* recoverFromPreorder(string S) {
    if (S == "")
      return nullptr;
    stack<TreeNode*> path;
    int pos = 0;
    while (pos < S.size()) {
      int level = 0;
      // 此时计算节点的深度
      while (pos < S.size() && S[pos] == '-') {
        pos ++;
        level ++;
      }
      int val = 0;
      while (pos < S.size() && S[pos] != '-') {
        val = val * 10 + (S[pos] - '0');
        pos ++;
      }
      TreeNode* tmp = new TreeNode(val);
      if (level == path.size()) {
        if (!path.empty()) {
          path.top()->left = tmp;
        }
      } else {
        // 此时为当前栈顶节点的某个前辈节点的右节点入栈
        while (path.size() > level) {
          path.pop();
        }
        path.top()->right = tmp;
      }
      path.push(tmp);
    }
    while (path.size() > 1) {
      path.pop();
    }
    // 最后返回根节点
    return path.top();
  }
};
int main() {
  return 0;
}