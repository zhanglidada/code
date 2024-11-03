#include"./include/common.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return 0;

        if (size == 1)
            return nums[0];

        vector<int> value(size, 0);
        value[0] = nums[0];
        value[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            value[i] = max(value[i - 1], value[i - 2] + nums[i]);
        }

        return value[size -1];
    }
};