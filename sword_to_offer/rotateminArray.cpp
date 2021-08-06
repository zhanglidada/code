#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minArray(vector<int>& numbers) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (numbers[mid] < numbers[right])
        right = mid;  // 因为mid可能为最小的元素，所以不能舍弃mid
      else if (numbers[mid] > numbers[right])
        left = mid + 1;
      else if (numbers[mid] == numbers[right])
        right --;  // 说明此时有重复元素，right左移
    }
    return numbers[left];
  }
};
int main() {
  return 0;
}