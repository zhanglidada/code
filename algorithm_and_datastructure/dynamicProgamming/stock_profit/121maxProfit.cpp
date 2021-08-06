#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* 最简单的方式，暴力计算
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int size = prices.size();
    if (size == 0)
      return 0;
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        maxProfit = max(maxProfit, prices[j] - prices[i]);
      }
    }
    return maxProfit;
  }
};  */


/* 
    一次遍历
    假设在最低点买入，那么每天都计算当前卖出获利即可
    一个minval记录当前已知的最低点，一个maxprofit记录当前可以得知的卖出最大获利
 */
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minval = INT32_MAX;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++) {
      minval = min(minval, prices[i]);
      maxprofit = max(maxprofit, prices[i] - minval);
    }
    return maxprofit;
  }
};
*/

// 使用单调栈实现，保持栈的单调递增
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty() || prices.size() == 1)  return 0;
    int maxProfit = 0;
    int bottom = 0;
    stack<int> st;
    st.push(prices[0]);
    bottom = prices[0];
    prices.emplace_back(-1);  // 哨兵元素，用于清空栈中所有元素

    // cout << "size : " << prices.size() << endl;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > st.top())
        st.push(prices[i]);
      // 当前元素小于栈顶元素，栈顶元素没有集训存在的必要，因为栈顶元素那天买入，无论后续值多大，当前元素获利一定大于栈顶元素
      else if (prices[i] < st.top()) {
        while (!st.empty() && prices[i] < st.top()) {
          // 表示st.top()所代表的值卖出的获利
          maxProfit = max(maxProfit, st.top() - bottom);
          st.pop();
        }
        if (st.empty())  bottom = prices[i];
        st.push(prices[i]);  // 表示在这天买入
      }
      // prices[i] == st.top()的时候没有必要入栈，即不执行任何操作
    }
    return maxProfit;
  }
};
*/

// 单调栈，优化 (单调栈其实也是从动态规划演变得来)
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty() || prices.size() == 1)  return 0;
    int maxProfit = 0;
    vector<int> st;  // 使用队列模拟栈
    prices.emplace_back(-1);  // 哨兵元素，用于清空栈中所有元素

    for (int i = 0; i < prices.size(); i++) {
      while (!st.empty() && prices[i] < st.back()) {
        maxProfit = max(maxProfit, st.back() - st.front());
        st.pop_back();
      }
      st.push_back(prices[i]);
    }
    return maxProfit;
  }
};  */


// 采用动态规划的方式
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2)  return 0;
    
    vector<vector<int>> dp(len, vector<int>(2, 0));
    // dp[i][0] 表示第i天结束，手上不持股的获利
    // dp[i][1] 表示第i天结束，手上持股的获利
    
    // 初始化状态转移数组
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < len; i++) {
      // dp[i][0]保存的是第i天不持股的获利
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      // 因为只允许买入一次，所以dp[i][1]其实保存的是到第i天为止最小的买入成本
      dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[len - 1][0];  // 最后一天肯定处于不持股状态
  }
};  */

// 动态规划的优化，采用滚动数组的方式：
// 因为当前状态仅仅取决于前一天的状态，所以采取滚动的方式即可
/*
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2)  return 0;
    
    vector<vector<int>> dp(2, vector<int>(2, 0));
    
    // 初始化状态转移数组
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < len; i++) {
      // dp[i][0]保存的是第i天不持股的获利
      dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + prices[i]);
      // 因为只允许买入一次，所以dp[i][1]其实保存的是到第i天为止最小的买入成本
      dp[i % 2][1] = max(dp[(i - 1) % 2][1], -prices[i]);
    }
    return dp[(len - 1) % 2][0];  // 最后一天肯定处于不持股状态
  }
};  */

// 继续优化
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len < 2)  return 0;
    
    vector<int> dp(2, 0);
    
    // 初始化状态转移数组
    dp[0] = 0;  // dp[0] 表示当天结束不持有股票
    dp[1] = -prices[0];  // 表示当天结束持有股票

    for (int i = 1; i < len; i++) {
      dp[0] = max(dp[0], dp[1] + prices[i]);
      dp[1] = max(dp[1], -prices[i]);
    }
    return dp[0];  // 最后一天肯定处于不持股状态
  }
};

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  Solution ss;
  cout << ss.maxProfit(prices);
  return 0;
}