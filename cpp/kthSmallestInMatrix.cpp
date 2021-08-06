#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
// 采用归并排序的算法，利用了最小堆的性质进行优化
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    struct Point {
      int val, x, y;
      // x,y 分别表示此节点在矩阵中的位置
      Point(int val, int x, int y) : val(val), x(x), y(y) {}
      bool operator> (const Point& a) const { return this->val > a.val; }
    };
    // 优先队列，底层是基于堆实现
    // 数据类型，容器类型以及比较方式。这里是升序队列，即小顶堆
    priority_queue<Point, vector<Point>, greater<Point>> que;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      // 原地进行构造并插入队列中,将矩阵每行的第一个元素分别入队列，
      // 由于matrix[0][0]必定为最小的元素，所以此时队头元素必定为matrix[0][0]
      que.emplace(matrix[i][0], i, 0);
    }
    // 只需要比较剩余的k-1个元素
    for (int i = 0; i < k - 1; i ++) {
      Point now = que.top();
      que.pop();
      if (now.y != n - 1) {
        que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
      }
    }
    return que.top().val;
  }
};  */

class Solution {
 public:
  /*
    查找范围: [left, right)
    结束条件：left == right
  */
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    int mid;
    // 二分查找的范围为[left, right]，全闭区间，这样left == right时锁定答案
    while (left < right) {
      // 在查找的过程中，mid不一定是在矩阵中的元素
      mid = (left + right) / 2;
      if (check(matrix, k, mid)) {
        // <=mid的元素数量大于等于k个时，令right=mid，即不停寻找更小的mid值，使得<=mid值的元素个数为k个
        right = mid;
      }
      else
        left = mid + 1;
    }
    return right;
  }
  // check函数计算<=给定值mid的元素数量,判断数量是否大于等于k
  bool check(vector<vector<int>>& matrix, int k, int mid) {
    int n = matrix.size();
    int i = n - 1, j = 0;
    int num = 0;
    while (i >= 0 && j < n) {
      if (matrix[i][j] <= mid) {
        num = num + (i + 1);
        j ++;
      } else {
        i --;
      }
    }
    return num >= k;
  }
};
int main() {
  vector<vector<int>> matrix = {{1,3,5,7,9,11}, {2,4,6,8,10,12}, {3,5,7,9,11,13}, {4,6,8,10,12,14}, {5,7,9,11,13,15}, {6,8,10,12,14,16}};
  Solution ss;
  cout << ss.kthSmallest(matrix, 8);
  return 0;
}