#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 暴力解法
class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum = 0, limit = (target - 1) / 2; // 下取整，因为至少含有两个数字
    for (int i = 1; i <= limit; i++) {
      for (int j = i; ; j++) {
        sum += j;
        if (sum > target) {
          sum = 0;
          break;
        } else if (sum == target) {
          tmp.clear();
          for (int k = i; k <= j; k++)  
            tmp.emplace_back(k);  // 可以进行原地构造
          ans.emplace_back(tmp);
          sum = 0;
          break;
        }
      }
    }
    return ans;
  }
};

// 暴力解法的优化,数学公式的推导
class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum = 0, limit = (target - 1) / 2; // 下取整，因为至少含有两个数字
    for (int x = 1; x <= limit; x++) {
      long long delta = 1 - 4 * (x - 1ll* x * x - 2 * target);  // b^2 - 4ac
      if (delta < 0)  continue;
      int delta_sqrt = (int)sqrt(delta + 0.5);  // 由于sqrt函数的精度误差
      if (1ll * delta_sqrt * delta_sqrt == delta && (delta - 1) % 2 == 0) {
        int y = (delta_sqrt - 1) / 2;
        if (x < y) {
          tmp.clear();
          for (int i = x; i <= y; i++)
            tmp.push_back(i);
          ans.push_back(tmp);
        }
      }
    }
    return ans;
  }
};

// 双指针法，其实也是针对第一张种方法的优化
class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    int limit = (target - 1) / 2;
    for (int l = 1, r = 2; l <= target && l < r;) {
      int sum = (l + r) * (r - l + 1) / 2;
      if (sum < target)  r++;
      else if (sum > target) l++;
      else {
        tmp.clear();
        for (int i = l; i <= r; i++)
          tmp.push_back(i);
        ans.push_back(tmp);
        l++;
      }
    } 
    return ans;
  }
};