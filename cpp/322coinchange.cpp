#include"./include/common.h"

class Solution {
public:
    // 主要还是使用动态规划的思想
    int coinChange(vector<int>& coins, int amount) {
        // best_val[i]表示凑成金额i所需的最少硬币数量。初始化为-1表示当前金额还无法被凑成。
        vector<int> best_val(amount + 1, -1);

        // 没有硬币可以凑成需要的总金额
        if (coins.size() == 0)
            return -1;

        best_val[0] = 0;  // 第0个位置的最优解是0

        // 遍历amount并计算从1开始到amount的最优解
        for (int i = 1; i <= amount; i++)
        {
            // 对于每个位置i，遍历所有的硬币，如果coins[j] < i
            // 表示位置i可以尝试获取最优解
            for (int j = 0; j < coins.size(); j++)
            {
                // 对于所有小于等于当前总额i面值的硬币，如果之前位置存在最优解，计算其值 + 1 是否小于当前位置的最优解
                if (coins[j] <= i && best_val[i - coins[j]] != -1)
                {
                    // best_val[i - coins[j]]值表示当前位置i在取硬币coins[j]后，之前那个位置i - coins[j]上的最优解
                    if (best_val[i] == -1 || best_val[i] > (best_val[i - coins[j]] + 1))
                        best_val[i] = best_val[i - coins[j]] + 1;
                }
            }
        }

        return best_val[amount];
    }
};