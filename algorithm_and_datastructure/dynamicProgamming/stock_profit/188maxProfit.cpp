#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 采用动态规划的方式
/*
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if (len <= 1)  return 0;
    // n天中最多只能产生 n / 2 笔交易
    k = min(len / 2, k);
    vector<vector<int>> buy(len, vector<int>(k + 1, 0));
    vector<vector<int>> sell(len, vector<int>(k + 1, 0));

    // 第0天结束手上持有股票，且交易0次最大获利
    buy[0][0] = -prices[0];
    // 第0天结束手上不持有股票，且交易0次最大获利
    sell[0][0] = 0;

    // 初始化非法状态
    for (int j = 1; j <= k; j++) {
      // 防止溢出
      buy[0][j] = INT_MIN / 2;
      sell[0][j] = INT_MIN / 2;
    }

    for (int i = 1; i < len; i++) {
      // 特殊状态判断，buy[i][0] 表示第i天结束交易0次，手上持有股票的最大收益；即仅仅买入一次的收益
      buy[i][0] = max(buy[i - 1][0], - prices[i]);
      // 由于sell[i][j] 的状态转移包含了 j - 1 的状态，但是j == 0 时不合法，所以保持0即可
      for (int j = 1; j <= k; j++) {
        buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
        sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
      }
    }
    
    // 返回最大值，因为操作次数越多利润不一定越大
    return *max_element(sell[len - 1].begin(), sell[len - 1].end());
  }
};  */

// 动态规划的优化
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }

    int n = prices.size();
    k = min(k, n / 2);
    vector<int> buy(k + 1);
    vector<int> sell(k + 1);

    buy[0] = -prices[0];
    sell[0] = 0;
    for (int i = 1; i <= k; ++i) {
      buy[i] = sell[i] = INT_MIN / 2;
    }

    for (int i = 1; i < n; ++i) {
      // 特殊情况的判断：buy[0]为到当天为止，已经买入一次的最大利润
      buy[0] = max(buy[0], - prices[i]);
      for (int j = 1; j <= k; ++j) {
        buy[j] = max(buy[j], sell[j] - prices[i]);
        sell[j] = max(sell[j], buy[j - 1] + prices[i]);   
      }
    }
      return *max_element(sell.begin(), sell.end());
    }
};


int main() {
  int k = 2;
  vector<int> prices = {3,2,6,5,0,3};
  Solution ss;
  cout << ss.maxProfit(k, prices);
}