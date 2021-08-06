#include <iostream>
#include <vector>
using namespace std;

/* 采用递归分治的方法
class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    return recur(0, postorder.size() - 1, postorder);
  }
  bool recur(int left, int right, vector<int>& postorder) {
    if (left >= right)  return true;
    int rootVal = postorder[right];
    int pos = left;
    while (postorder[pos] < rootVal) pos++;
    int m = pos;
    while (postorder[pos] > rootVal) pos++;
    return pos == right && recur(left, m - 1, postorder) && recur(m, right - 1, postorder);
  }
};  */

// 采用辅助单调栈
class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    
  }
};