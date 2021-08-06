#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// 小顶堆中的排序比较
class myCompare {
 public:
  bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second > rhs.second;
  }
};
// 使用堆排序，最小堆
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hashmap;
    for (auto num : nums) {
      if (hashmap.count(num) != 0)  hashmap[num] ++;
      else  hashmap[num] = 1;
    }
    // 创建小顶堆，传入的时自定义的类对象
    priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> minque;
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
      if (minque.size() < k)
        minque.push(pair<int, int>(it->first, it->second));
      else {
        if (it->second > minque.top().second) {
          minque.pop();
          minque.push(pair<int, int>(it->first, it->second));
        }
      }
    }
    vector<int> res;
    while (!minque.empty()) {
      res.push_back(minque.top().first);
      minque.pop();
    }
    return res;
  }
};

// 采用桶排序方式，先hash获得频率，之后根据频率插入数组中(此题中每个元素的频率均不同)
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hashmap;
    vector<int> res;
    for (auto num : nums) {
      if (hashmap.count(num) != 0)  hashmap[num] ++;
      else  hashmap[num] = 1;
    }
    int maxFre = INT32_MIN;
    vector<vector<int>> buckets(nums.size() + 1);  // buckets的下标代表相应的频率
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
      buckets[it->second].push_back(it->first);
      maxFre = max(maxFre, it->second);
    }
    int sum = 0;
    // 倒序插入
    for (int i = maxFre; i >= 0; i--) {
      if (!buckets[i].empty()) {
        for (auto num : buckets[i]) {
          res.push_back(num);
          sum ++;
          if (sum >= k)  break;
        }
      }
      if (sum >= k)  break;
    }
    return res;
  }
};
