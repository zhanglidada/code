#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    string res;
    stack <int> nums;
    stack <string> strs;
    int num = 0;
    int len = s.size();
    
    for(int i = 0; i < len; ++ i)
    {
      // 计算数字
      if(s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + s[i] - '0';

      // num后肯定跟着 '['(题目要求) 
      }
      else if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z')) {
        // 字母添加到res后面（res不为空时是和当前res同一级的运算）
        res = res + s[i];
      }
      else if(s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
      {
        // 上一层计算的结果压栈并重置num和res
        nums.push(num);
        num = 0;
        strs.push(res); 
        res.clear();
      }
      else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
      {
        // num栈中取出之前压栈的数字
        int times = nums  .top();
        nums.pop();

        // 栈顶压的都是上一层已经计算后的值
        string str = strs.top();
        strs.pop();

        // 栈顶值加上 n * [] 内的值
        for(int j = 0; j < times; ++ j)
          str += res;

        // res最终是内层计算后的值
        res = str;
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
    Solution s;
    std::cout << s.decodeString("3[a2[c]]") << std::endl;
}