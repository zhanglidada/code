#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

/*******************************************************************************************
 * 1.很明显是一个图的连通性问题，最直观可以想到并查集
 * 2.可以采用图的深度优先以及广度优先进行遍历

********************************************************************************************/



/*******************************************************************************************
Purpose:
  1. 采用深度优先遍历
Notes:
  遍历每个城市以及其深度优先遍历过的城市
  没有访问过的城市重新开始深度优先遍历，并且不联通性+1

  就是求解图中的不连通子图个数
********************************************************************************************/
class Solution {
  public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      if (isConnected.empty())  return 0;
      citys = isConnected.size();
      visited = vector<bool>(citys, false);  // 初始化访问数组

      // 对每个city节点进行深度优先遍历
      for (int i = 0; i < citys; i++) {
        if (!visited[i]) {
          dfs(isConnected, i);
          isolated ++;
        }
      }
      return isolated;
    }

    void dfs(vector<vector<int>>& isConnected, int i) {
      // i节点是否连接到j节点
      for (int j = 0; j < citys; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
          visited[j] = true;
          dfs(isConnected, j);  // j节点向下是否与其它节点相连
        }
      }
    }
  private:
    int citys = 0;
    int isolated = 0;  // 不连通图的个数,即联通分量个数
    vector<bool> visited;
};


/*******************************************************************************************
Purpose:
  2. 采用广度优先遍历
Notes:
  对于每个城市，如果该城市尚未被访问过，则从该城市开始广度优先搜索，
  直到同一个连通分量中的所有城市都被访问到，即可得到一个省份
********************************************************************************************/
class Solution {
  public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      if (isConnected.empty())  return 0;

      citys = isConnected.size();
      visited = vector<bool>(citys, false);  // 初始化访问数组
      // 对每个城市进行广度优先遍历
      for (int i = 0; i < citys; i++) {
        // 当前城市没有访问过
        if (!visited[i]) {
          que.emplace(i);
          while (!que.empty()) {
            // 获取队头元素
            int k = que.front();
            que.pop();
            visited[k] = true;

            // 和当前节点有连接且未访问过的节点全部入队
            for (int j = 0; j < citys; j++) {
              if (isConnected[k][j] && !visited[j])
                que.emplace(j);
            }
          }
          
          isolated ++;
        }
      }
      return isolated;
    }
  private:
    int citys = 0;
    int isolated = 0;  // 不连通图的个数,即联通分量个数 
    vector<bool> visited;
    queue<int> que;
};


/*******************************************************************************************
Purpose:
  3. 采用并查集
Notes:
  初始时，每个城市都属于不同的连通分量。遍历矩阵，如果两个城市之间有相连关系，
  则它们属于同一个连通分量，对它们进行合并。
  遍历矩阵的全部元素之后，计算连通分量的总数，即为省份的总数
********************************************************************************************/
class Solution {
  public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      if (isConnected.empty())  return 0;
      citys = isConnected.size();
      parents = vector(citys, 0);
      make_set(citys);

      // 因为是无向图，所以仅需遍历上半图
      for (int i = 0; i < citys; i++) {
        for (int j = i; j < citys; j++) {
          if (isConnected[i][j])
            union_set(i, j);  // 合并节点
        }
      }

      // 遍历city，查询联通图个数
      for (int i = 0; i < citys; i++) {
        if (parents[i] == i)
          isolated ++;
      }
      return isolated;
    }

    int find_set(int id) {
      if (id != parents[id]) {
        parents[id] = find_set(parents[id]);  // 路径压缩
      }

      return parents[id];
    }

    // 合并集合
    void union_set(int x, int y) {
      int root_x = find_set(x);
      int root_y = find_set(y);

      if (root_x != root_y)
        parents[root_x] = root_y;
    }

    // 初始化并查集节点
    void make_set(int nums) {
      for (int i = 0; i < nums; i++)
        parents[i] = i;
    }
  private:
    vector<int> parents;
    int citys = 0;
    int isolated = 0;  // 不连通图的个数,即联通分量个数
};



int main() {
  return 0;
}