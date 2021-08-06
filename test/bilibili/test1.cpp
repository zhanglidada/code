#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
 public:
  int GetMaxConsecutiveOnes(vector<int>& arr, int k) {
    if (arr.empty())
      return 0;
    array<int, 2> map = {0};
    int left = 0, right = 0;
    int maxCount = 0;
    for (right = 0; right < arr.size(); right++) {
      map[arr[right] - 0] ++;
      maxCount = max(maxCount, map[arr[right] - 0]);
      if (right - left + 1 - maxCount > k) {
        map[arr[left] - 0] --;
        left++;
      }
    }
    return arr.size() -left;
  }
};