#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    // 深度优先搜索，尝试将火柴棍分配到四条边上
    bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
        // index已经到最后一个位置，说明当前已经访问过所有的火柴信息
        if (index == matchsticks.size()) {
            return true;
        }
        // 对每一根火柴都尝试将其分配到四条边上
        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            // 检查这条边的长度是否小于len，如果小于就继续访问下一个位置
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks) {
        // 计算整体长度
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        // 整体长度不是4的倍数就报错
        if (totalLen % 4 != 0) {
            return false;
        }
        // 从大到小排序
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量

        return dfs(0, matchsticks, edges, totalLen / 4);
    }
    private:
        vector<int> edges(4);
};