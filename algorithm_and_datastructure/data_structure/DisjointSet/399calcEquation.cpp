#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

/*******************************************************************************************
Purpose:
  根据equations中的表达式，以及values中对应表达式的值，计算queries中需要求解的表达式值
Notes:
  1. 使用并查集，可以将equation中两个变量所在的集合进行合并
  2. 将不同变量的比值转换成相同变量的比值
  3. 若两个变量不在同一个集合中，返回-1.0；如果两个变量中的一个不在equation中也返回-1.0
********************************************************************************************/
class Solution {
  public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, 
                                                        vector<vector<string>>& queries) {
      int equa_size = equations.size();
      int id = 0;  // 表达式中所有节点的id，同名节点公用一个id
      vector<string> list;  // 表达式
      // 表达式的两个值
      string var1;
      string var2;
      UnionFind uf(2 * equa_size);  // 当equation中每个表达式的节点均不同

      unordered_map<string, int> hash_map;  // 变量和id的键值对
      // 表达式列表中每个节点进入hashmap中并赋予对应id
      for (int i = 0; i < equa_size; i++) {
        list = equations[i];
        var1 = list[0];
        var2 = list[1];
        // 新的变量插入map中
        if (!hash_map.count(var1)) {
          hash_map.emplace(var1, id);
          id ++;
        }
        if (!hash_map.count(var2)) {
          hash_map.emplace(var2, id);
          id++;
        }
        // 一个表达式中的两个节点为同一个集合，最终所有依赖关系均设置完成
        uf.union_set(hash_map[var1], hash_map[var2], values[i]);
      }
      
      // 查找表达式中对应的结果
      int queries_size = queries.size();
      res = vector<double>(queries.size(), 0.0);
      for (int i = 0; i < queries_size; i++) {
        list = queries[i];
        var1 = list[0];
        var2 = list[1];

        // 只要有一个变量不在equations中出现，即为-1.0
        if (hash_map.count(var1) == 0 || hash_map.count(var2) == 0)
          res[i] = -1.0;
        else {
          int id1 = hash_map[var1];
          int id2 = hash_map[var2];
          res[i] = uf.is_connected(id1, id2);
        }
      }
      return res;
    }
  private:
    // 用于处理并查集的私有类
    class UnionFind {
      public:
        UnionFind(int n) {
          parent = vector<int>(n, 0);
          weight = vector<double>(n, 0.0);
          // 初始化并查集中节点
          for (int i = 0; i < n; i++) {
            parent[i] = i;
            weight[i] = 1.0;
          }
        }

        // 合并两个并查集,注意此时满足x为表达式的分子，y为表达式的分母
        void union_set(int x, int y, double value) {
          int root_x = find(x);
          int root_y = find(y);
          if (root_x == root_y) return;

          // 合并x，y所在集合
          parent[root_x] = root_y;
          weight[root_x] = value * weight[y] / weight[x];
        }

        // 查找当前节点所在并查集中的根节点
        int find(int id) {
          // 当前非根节点
          if (id != parent[id]) {
            int father = parent[id];  // 保存当前节点的父节点id
            parent[id] = find(parent[id]);  // 递归返回时路径压缩
            weight[id] *= weight[father];  // 递归返回时计算,且其父节点weight已经计算完成
          }
          // 返回根节点
          return parent[id];
        }

        // 判断两个节点是否在同一个并查集中，并计算x/y的值
        double is_connected(int x, int y) {
          // 计算x/y之前就进行了find并路径压缩
          int root_x = find(x);
          int root_y = find(y);
          if (root_x == root_y) {
            return weight[x] / weight[y];
          } else {
            return -1.0;
          }
        }

      private:
        vector<int> parent;  // 节点的id
        vector<double> weight;  // 当前节点到根节点的有向边权值
    };

    vector<double> res;  // 
};

int main() {
  vector<vector<string>> equations = {
    {"a", "b"},
    {"b", "c"}
  };
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {
    {"a","c"},
    {"b","a"},
    {"a","e"},
    {"a","a"},
    {"x","x"}
  };

  Solution ss;
  vector<double> res =  ss.calcEquation(equations, values, queries);
  for (auto num : res) {
    cout << num << " ";
  }
  return 0;
}