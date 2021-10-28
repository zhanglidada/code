#include <iostream>
#include <vector>
using namespace std;

// 采用动态规划的方式遍历数组
/*
class test_package_problem {
  public:
    test_package_problem(int bagwei) {
      bag_weight = bagwei;
    }

    int calc_max_value(vector<int>& weight, vector<int>& value) {
      // 获取物品的数目
      int num = weight.size();
      vector<vector<int>> dp(num, vector<int>(bag_weight + 1, 0));
      // 从后向前遍历并初始化
      for (int j = bag_weight; j >= weight[0]; j--) {
        dp[0][j]  = dp[0][j - weight[0]] + value[0];
      }

      for (int i = 1; i < num; i++ ) {
        for (int j = 1; j <= bag_weight; j++) {
          if (j < weight[i])  dp[i][j] = dp[i - 1][j];
          else {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
          }
          // cout << dp[i][j] << " ";
        }
      }
      return dp[num - 1][bag_weight];
    }
  private:
   int bag_weight = 0;
};
*/

// 采用一维数组保存背包信息
// 采用动态规划的方式遍历数组
class test_package_problem {
  public:
    test_package_problem(int bagwei) {
      bag_weight = bagwei;
    }

    int calc_max_value(vector<int>& weight, vector<int>& value) {
      // 获取物品的数目
      int num = weight.size();
      vector<int> dp(bag_weight + 1, 0);

      for (int i = 0; i < num; i++) {
        for (int j = bag_weight; j >= weight[i]; j--) {
          dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
          //cout << dp[j] << " ";
        }
        //cout << endl;
      }
      return dp[bag_weight];
    }
  private:
   int bag_weight = 0;
};


int main() {
  vector<int> weight = {1,3,4};
  vector<int> value = {15,20,30};

  test_package_problem solution(4);
  cout << solution.calc_max_value(weight, value);

}