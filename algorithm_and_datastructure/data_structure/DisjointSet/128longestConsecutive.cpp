#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 可以采用并查集的思想
// class Solution {
//   public:
//     int longestConsecutive(vector<int>& nums) {
//       int ans = 0;  // 最长的连续数组
//       // 并查集初始化时，若有连续元素存在，则已经构建对应的一个个并查集
//       for (auto i : nums) {
//         // 数组里每个元素初始化为他的下一个数，防止根节点查找时死循环
//         father[i] = i + 1;
//       }
//       for (auto i : nums) {
//         int y = find(i + 1);  // 查找值i在并查集中的根节点
//         ans = max(ans, y - i);
//       }
//       return ans;
//     }

//     int find(int val) {
//       if (father.count(val) == 0)
//         return val;
      
//       father[val] = find(father[val]);
//       return father[val];
//     }
//   private:
//     unordered_map<int, int> father;
// };

// 采用hash表的方法
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      int longest_cons = 0;  // 最长的连续序列
      int current_cons = 0;  // 当前序列长度
      int current_num = 0;  // 当前
      for (auto num : nums)
        num_set.insert(num);

      for (auto num : nums) {
        // 当前元素前一个不在set中时才计算
        if (!num_set.count(num - 1)) {
          current_num = num;
          current_cons = 1;

          // 当前元素的下一个元素存在性判断
          while (num_set.count(current_num + 1)) {
            current_num += 1;
            current_cons += 1;
          }
          longest_cons = max(longest_cons, current_cons);
        }
      }
      return longest_cons;
    }

  private:
    unordered_set<int> num_set;
};

int main() {
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  Solution ss;
  cout << ss.longestConsecutive(nums);
  return 0;
}