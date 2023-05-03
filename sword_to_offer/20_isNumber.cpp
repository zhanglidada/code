#include <iostream>
#include <vector>
using namespace std;

// 空格的判断有问题
class Solution {
 public:
  bool isNumber(string s) {
    auto begin = s.begin();
    if (s.empty())  // 字符为空
      return false;
    // 如果开始字符为正负号
    if (*begin == '-' || *begin == '+') {
      begin ++;
      if (*begin == '-' || *begin == '+')
        return false;  // 连续两个正负号则返回false
      else if (*begin == ' ')
        return false;
    }
    // 符号之后需要判断是否还有数字
    if (*begin == '\0')
      return false;
    int e = 0, number = 0, dot = 0, consistence = 0;
    while (*begin != '\0') {  // 对之后的每个字符进行遍历
      // 数字
      if (*begin <= '9' && *begin >= '0') {
        begin ++;
        number ++;
      } 
      // 小数点
      else if (*begin == '.') {
        // 如果有两个小数点: 12..5  或者在e后面又小数点：12e3.4,false
        if (dot > 0 || e > 0)
          return false;
        begin ++;
        dot ++;
        if (number == 0 && *begin == '\0') {
          return false;
        }
      }
      // 空格
      else if (*begin == ' ') {
        if ((dot > 0 && number == 0) || e > 0)
          return false;
        begin ++;
        if (number > 0)
          consistence ++;
        if (consistence > 0 && (*begin >= '0' && *begin <= '9' || *begin == '.' || *begin == 'e' || *begin == 'E'))
          return false;
      }
      // e
      else if (*begin == 'e' || *begin == 'E') {
        if (number == 0 || e > 0)
          return false;
        begin++;
        e++;
        // e后面可以出现一次正负号
        if (*begin == '-' || *begin == '+') {
          begin ++;
          if (*begin == '-' || *begin == '+')
            return false;  // 连续两个正负号则返回false
          else if (*begin == ' ')
            return false;
        }
        if (*begin == '\0')  // 13e
          return false;
      }
      // 有其他字符的情况
      else {
        return false;
      }
    }
    if (number > 0)
      return true;
    return false;
  }
};
int main() {
  Solution ss;
  string s = " 96 e5  ";
  if (ss.isNumber(s))
    cout << "true";
  else
    cout << "false";
  return 0;
}


/**
 * 确定有限状态自动机
 * 1）有一种特殊的状态，被称作「初始状态」，还有一系列状态被称为「接受状态」，它们组成了一个特殊的集合。
 * 2）一个状态可能既是「初始状态」，也是「接受状态」。
 * 3）自动机最开始处于 [初始状态]，之后顺序读取字符串中的字符并根据当前的状态和读取的字符，按照事先约定的 [转移规则] 从当前状态转移到下一个状态。
 * 当字符全部读取完成后，如果自动机处于某个 [接受状态]，那么当前的字符串 [被接受]，否则当前字符串 [被拒绝]。
 * 4）如果输入的过程中某一步转移失败了，即不存在对应的「转移规则」，此时计算将提前中止。在这种情况下我们也判定该字符串「被拒绝」。
 */
class Solution {
public:
    // 状态
    enum State {
        STATE_INITIAL,            // 起始状态
        STATE_INT_SIGN,
        STATE_INTEGER,            // 中止状态
        STATE_POINT,              // 中止状态
        STATE_POINT_WITHOUT_INT,  // 不能作为终止状态
        STATE_FRACTION,           // 中止状态
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,         // 中止状态
        STATE_END                 // 中止状态
    };

    // 类型
    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL
    };

    // 当前字符类型
    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else if (ch == ' ') {
            return CHAR_SPACE;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {
                STATE_INITIAL, {
                    {CHAR_SPACE, STATE_INITIAL},
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            }, {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }, {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_END, {
                    {CHAR_SPACE, STATE_END}
                }
            }
        };

        int len = s.length();
        
        // 字符串的起始状态
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            // 获取当前字符类型
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }

        // 返回最终的结束状态
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};

