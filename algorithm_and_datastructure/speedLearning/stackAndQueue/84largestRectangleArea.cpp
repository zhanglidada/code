#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/*
class Solution {
 public:
  // 采用暴力解法
  int largestRectangleArea(vector<int>& heights) {
    if (heights.empty())  return 0;
    int left = 0, right = 0;
    // 从每个位置开始遍历当前高度的左右边界
    for (int i = 0; i < heights.size(); i++) {
      int curHe = heights[i];
      left = i;
      while (left >= 0 && heights[left] >= curHe)  left--;
      right = i;
      while (right < heights.size() && heights[right] >= curHe)  right++;
      maxArea = max(maxArea, (right - left - 1) * curHe);
    }
    return maxArea;
  }
 private:
  int maxArea = INT32_MIN;
};  */

/*
class Solution {
 public:
  // 采用暴力解法,固定宽度，寻找最小高度
  int largestRectangleArea(vector<int>& heights) {
    if (heights.empty())  return 0;
    int left = 0, right = 0;
    for (left = 0; left < heights.size(); left++) {
      int minHeight = INT32_MAX;
      for (right = left; right < heights.size(); right++) {
        minHeight = std::min(minHeight, heights[right]);
      }
      maxArea = max(maxArea, (right - left + 1) * minHeight);
    }
    return maxArea;
  }
 private:
  int maxArea = INT32_MIN;
};  */

/*
class Solution {
 public:
  // 利用单调栈来实现
  int largestRectangleArea(vector<int>& heights) {
    if (heights.empty())  return 0;
    int len = heights.size();
    vector<int> left(len, 0);
    vector<int> right(len, 0);
    stack<int> pos;
     
    //  从左到右进行遍历,维持一个单调递增序列
    //  对于当前元素来说，影响其左侧边界的元素只有比其小的高度
     
    for (int i = 0; i < len; i++) {
      while (!pos.empty() && heights[pos.top()] >= heights[i]) {
        pos.pop();
      }
      left[i] = pos.empty() ? -1 : pos.top();
      pos.push(i);
    }
    
    //  从右到左进行遍历,维持一个单调递增序列
    //  对于当前元素来说，影响其右侧边界的元素只有比其小的高度
    pos = stack<int>();  // 置位
    for (int j = len - 1; j >= 0; j--) {
      while (!pos.empty() && heights[pos.top()] >= heights[j]) {
        pos.pop();
      }
      right[j] = pos.empty() ? -1 : pos.top();
      pos.push(j);
    }
    for (int k = 0; k < len; k++) {
      maxArea = max(maxArea, (right[k] - left[k] - 1) * heights[k]);
    }
    return maxArea;
  }
 private:
  int maxArea = INT32_MIN;
};  */

class Solution {
 public:
  // 利用单调栈来实现
  int largestRectangleArea(vector<int>& heights) {
    if (heights.empty())  return 0;
    int len = heights.size();
    vector<int> left(len, 0);
    vector<int> right(len, len);
    stack<int> pos;
    /* 
      从左到右进行遍历,维持一个单调递增序列
      对于当前元素来说，影响其左侧边界的元素只有比其小的高度
     */
    for (int i = 0; i < len; i++) {
      // 比当前元素大的元素全部出栈
      while (!pos.empty() && heights[pos.top()] >= heights[i]){
        int curPos = pos.top();  // 当前元素的出栈
        pos.pop();  // 当前元素出栈的过程中就已经获得了不一定正确的右边界
        right[curPos] = i;
      }
      left[i] = pos.empty() ? -1 : pos.top();
      pos.push(i);
    }
    for (int i = 0; i < len; i++) {
      maxArea = max(maxArea, (right[i] - left[i] - 1) * heights[i]);
    }
    return maxArea;
  }
 private:
  int maxArea = INT32_MIN;
};

int main() {
  vector<int> nums = {2,4};
  Solution ss;
  cout << ss.largestRectangleArea(nums);
}