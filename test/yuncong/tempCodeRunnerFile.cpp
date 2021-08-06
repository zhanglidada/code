class Solution {
 public:
  int banana(vector<int>& piles, int H) {
    sort(piles.begin(), piles.end());
    int sum = 0;
    int len = piles.size();
    int left = piles[0], right = piles[len - 1];
    while (left <= right) {
      sum = 0;
      int mid = (left + right) / 2;
      for (auto num : piles) {
        sum += num % mid == 0 ? num / mid : num / mid + 1;
      }
      if (sum <= H) right = mid - 1;
      if (sum > H) left = mid + 1;
    }
    return left;
  }
};