#include <iostream>
#include <unorderd_map>
#include <vector>
#include <unordered_set>

class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int i = 0,j = 0;

      if (nums.size() == 0)
        return ;

      
      for (i = 0; i < nums.size(); i++) {
        // 依次将i指向的不为0的值对应位置的元素赋值到j对应的位置
        // j最终的位置就是移动后值为0的元素开始的位置
        if (nums[i] != 0)
          nums[j++] = nums[i];
      }

      while (j < nums.size()) {
        nums[j++] = 0;
      }

    }
};
