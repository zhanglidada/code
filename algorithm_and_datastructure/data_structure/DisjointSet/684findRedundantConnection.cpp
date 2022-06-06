#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个仅存在一条冗余边的图，去除其中一条边后剩余边未一颗树
 * 
 * Notes:
 * 存在多个答案时返回数组edges中最后出现的边
********************************************************************************************/


/*******************************************************************************************
 * Purpose:
 * 采用并查集的方式实现
 * Notes:
 * 1.树的边树比节点树少1
 * 2.初始每个节点分别属于不同的联通分量
 * 3.遍历每条边，并判断边的两个节点是否属于同一个联通分量，若属于同一个联通分量，则为冗余边
 * 4.节点id从1开始，到n结束
********************************************************************************************/
class Solution {
  public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int edges_size = edges.size();
      parents = vector<int>(edges_size + 1, 0);
      res = vector<int>(2, 0);
      make_sets(edges_size + 1);
      for (auto edge : edges) {
        var1 = edge[0];
        var2 = edge[1];
        // 当前边的两个节点不在一个集合中，合并
        if (find_set(var1) != find_set(var2)) {
          union_set(var1, var2);
        } else {
          res[0] = var1;
          res[1] = var2;
        }
      }
      return res;
    }

    // 初始化并查集
    void make_sets(int num) {
      for (int i = 0; i < num; i++)
        parents[i] = i;
    }

    int find_set(int x) {
      // 当前不为根节点
      if (x != parents[x]) {
        parents[x] = find_set(parents[x]);  // 路径压缩
      }
      return parents[x];
    }

    // 合并两个节点为同一个联通分量
    void union_set(int x, int y) {
      int root_x = find_set(x);
      int root_y = find_set(y);

      if (root_x != root_y)
        parents[root_x] = root_y;
    }
  private:
    vector<int> parents;
    vector<int> res;
    // 边的两个节点
    int var1 = 0;
    int var2 = 0;
};


int main() {
  return 0;
}