#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* 采用hash表的方式
class Solution {
  public:
    int findRepeatNumber(vector<int>& nums) {
        for (auto num : nums) {
            if (visited.count(num) > 0)
                return num;
            
            visited.insert(num);
        }
        return -1;
    }
  private:
    unordered_set<int> visited;
};  */

/* 进行原地置换
class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      // 在置换中被放在本身应该在的位置, 即在while循环中，每个nums[i]的值最终都为i
      while (nums[i] != i) {
        if (nums[i] != nums[nums[i]])
          swap(nums[i], nums[nums[i]]);
        else
          return nums[i];
      }
    }
    return -1;
  }
};  */

// 利用二分法进行查找,但是存在找不到的情况
class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    int count = 0;
    while (l < r) {
      int mid = (l + r) >> 1;
      count = 0;
      // 在整个区间中进行查找
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= l && nums[i] <= mid)
          count ++;
      }
      if (count > (mid - l + 1))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};
int main() {
  vector<int> nums = {0,1,2,0,4,5,6,7,8,9};
  Solution ss;
  cout << ss.findRepeatNumber(nums);
  return 0;
}