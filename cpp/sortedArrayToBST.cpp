#include <iostream>
#include <vector>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0)
      return nullptr;
    TreeNode* root = buildNode(nums, 0, nums.size() - 1);
    return root;
  }
  TreeNode* buildNode(vector<int>& nums, int left, int right) {
    if (left > right)
      return nullptr;
    // 总是选择位置左边的元素作为跟节点
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildNode(nums, left, mid - 1);
    root->right = buildNode(nums, mid + 1, right);
    return root;
  } 
};
int main() {

}