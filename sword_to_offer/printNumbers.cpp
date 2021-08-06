#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
 public:
	vector<int> printNumbers(int n) {
    if (n <= 0)
      return res;
    // 创建一个能容纳最大值的string数组
    string number(n, '0');
    // 一直循环并saveNumber，直到边界情况退出
    while (!increment(number)) {
      saveNumber(number);
    }
    return res;
	}
  // 全排列并修改number,在最大数字之后返回越界
  bool increment(string& number) {
    bool isOverflow = false;
    int nTakeOver = 0;  // 存储进位
    int nLength = number.size();
    for (int i = nLength - 1; i >= 0; i--) {
      int nSum = number[i] - '0' + nTakeOver;
      // 如果是第一位，需要加一，表示一个全排列
      if (i == nLength - 1)
        nSum ++;

      // 有进位
      if (nSum >= 10) {
        // 到边界情况
        if (i == 0)
          isOverflow = true;  // 越界
        else {
          nTakeOver = 1; // 有进位
          number[i] = nSum - 10 + '0';
        }
      } else {
        // 没有进位，直接低位+1，高位不变
        number[i] = nSum + '0';
        break;
      }
    }
    return isOverflow;
  }
  // 将increment排列修改后的number存储到res中
  void saveNumber(string number) {
    bool isBegin = false;
    int sum = 0;
    for (int i = 0; i < number.size(); i++) {
      int value = number[i] - '0';
      // 只要第一个非0值出现，就开始
      if (value)
        isBegin = true;
      if (isBegin)
        sum = sum * 10 + value;
    }
    res.push_back(sum);
  }
 private:
  vector<int> res;
};  */

/*
class Solution {
 public:
  // 最简单的判断边界问题
  vector<int> printNumbers(int n) {
    deep = n;
    path = string(n, 0);
    start = n - 1;
    dfs(0);
    vector<int> ans;
    for (auto str : res) {
      ans.push_back(atoi(str.c_str()));  // string转换成int
    }
    return ans;
  }
  void dfs(int n) {
    // 递归到最后需要返回
    if (n == deep) {
      string str = path.substr(start);
      if (str != "0")
        res.push_back(str);
      // 每次递归到最后一位的时候判断当前有效字符串中含有几个9，是否需要进位
      if (deep - start == nine)  start --;
      return;
    }
    for (auto c : loop) {
      if (c == '9')  nine ++;
      path[n] = c;
      dfs(n + 1);
    }
    nine --;
  }
 private:
  char loop[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int deep = 0;
  vector<string> res = {};
  string path;
  int start = 0;  // 确定左边界，左闭合区间
  int nine = 0;  // 判断是否需要进位，若当前位全是9的时候需要进位
};*/

class Solution {
 public:
  vector<int> printNumbers(int n) {
    if (n <= 0)  return res;
    string number = string(n, '0');
    while (!increment(number)) {
      saveNumber(number);
    }
    return res;
  }
  // 在每次调用过程中将number表示的数字进一位
  bool increment(string& number) {
    bool isOverFlow = false;  // 判断在此次调用中是否达到了最后的越界
    int nTakeOver = 0;  // 存贮进位
    int len = number.size();
    for (int i = len - 1; i >= 0; i--) {
      int num = number[i] - '0' + nTakeOver;
      // 每次首先将最低位+1
      if (i == len - 1)  num ++;
      if (num >= 10) {
        // 已经到了最高位，进位则溢出
        if (i == 0)  return true;
        nTakeOver = 1;  // 有进位
        number[i] = num - 10 + '0'; 
      } else {
        number[i] = num + '0';  // 直接修改最低位置的元素值
        break;
      }

    }
    return isOverFlow;
  }
  void saveNumber(string number) {
    bool start = false;
    int sum = 0;
    for (int i = 0; i < number.size(); i++) {
      if (number[i] != '0')  start = true;
      if (start) {
        sum = sum * 10 + (number[i] - '0');
      }
    }
    res.push_back(sum);
  }
 private:
  vector<int> res;
};
int main() {
  Solution ss;
  vector<int> res = ss.printNumbers(3);
  return 0;
}