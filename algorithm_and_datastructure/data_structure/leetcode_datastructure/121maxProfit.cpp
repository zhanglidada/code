#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*******************************************************************************************
 * Purpose: 
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * Notes:
 * 只能选择 某一天 买入并在 未来的某一个不同的日子 卖出。
 * 需要返回可以从这笔交易中获取的最大利润，如果你不能获取任何利润返回0。
********************************************************************************************/

/*******************************************************************************************
 * Purpose: 
 * 求解买卖股票的最大利润
 * Notes:
 * 使用贪心算法
 * 记录一个当前位置的历史最低点，并假设每天都是卖出的最佳时间
********************************************************************************************/
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int max_profit = 0;
      int buy = prices[0];
      for (auto price : prices) {
        if (price < buy)
          buy = price;
        max_profit = max(max_profit, price - buy);
      }
      return  max_profit;
    }
};

/*******************************************************************************************
 * Purpose: 
 * 求解买卖股票的最大利润
 * Notes:
 * 使用动态规划计算
 * dp[i] 表示以i结尾的数组，可以获得的最大利润
 * dp[i] = max(dp[i - 1], prices[i] - minprice)
********************************************************************************************/
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // 边界条件
        int minprice = prices[0];
        vector<int> dp (n, 0);

        for (int i = 1; i < n; i++){
            minprice = min(minprice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[n - 1];
    }
};