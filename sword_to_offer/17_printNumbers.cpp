#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 
 * 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
 *  比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 */


/*********************************************************
 * 1.全排列
 * 
*********************************************************/
class Solution {
 public:
	vector<int> printNumbers(int n) {
    if (n <= 0)
      return res;

    // 创建N位string数组
    string number(n, '0');

    // 一直循环，获取全排列串并添加number，直到越界
    while (!increment(number)) {
      saveNumber(number);
    }
    return res;
	}

  // 全排列字符串直到越界
  bool increment(string& number) {
    bool isOverflow = false;
    int nTakeOver = 0;  // 存储进位

    // 获取number的位数，即最大为几位数
    int nLength = number.size();

    for (int i = nLength - 1; i >= 0; i--) {

      // 设置第i位的值为原始值 + 进位值
      int nSum = number[i] - '0' + nTakeOver;

      // 第一次进入当前函数进行排列，需要加一，表示开始一个新的全排列
      if (i == nLength - 1)
        nSum ++;

      // 循环仅处理进位的情况
      if (nSum >= 10) {
        // 到边界情况
        if (i == 0)
          isOverflow = true;  // 越界
        else {
          nTakeOver = 1; // 有进位
          // 修改当前位的值
          number[i] = nSum - 10 + '0';
        }
      }
      else {
        // 没有进位，直接设置低位并跳出循环
        number[i] = nSum + '0';
        break;
      }
    }

    return isOverflow;
  }

  // string转number
  void saveNumber(string number) {
    bool isBegin = false;
    int sum = 0;
    for (int i = 0; i < number.size(); i++) {
      int value = number[i] - '0';
      // 从前往后第一个非0的字符出现，开始计算
      if (value)
        isBegin = true;
      if (isBegin)
        sum = sum * 10 + value;
    }
    res.push_back(sum);
  }

 private:
  // 返回结果数组
  vector<int> res;
};

/*********************************************************
 * 2.dfs
 * 
*********************************************************/
class Solution {
public:
  vector<int> printNumbers(int n) {
    // 依次获取 1位数 到 n位数
    for(int digit = 1; digit <= n; digit++)
      // 第一位数字不能为0，所以为1~9
      for(int j = 1; j <= 9; j++)
        dfs(1, digit, to_string(j)); //dfs从1开始，因为第0位已经确定了
  
  return res;
  }

  // 从第k位开始遍历,当前遍历的是n位数
  void dfs(int k, int n, string s)
  {
    // dfs到n位数末尾
    if(k == n)
    {
      res.emplace_back(stoi(s));
      return;
    }

    // 之后的每一位都可以从0 ~ 10
    for(int i = 0; i < 10; i++)
      dfs(k + 1, n, s + to_string(i));
  }
private:
  vector<int> res;
};

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