#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int buyCoke(int m, int a, int b, int c, int x) {
  int ans = 0;
  while (m) {
    if (x >= 100) {
      int num = 0;
      while (c && num < x) {
        num += 100;
        c--;
        ans ++;
      }
      while (b && num < x) {
        num += 50;
        b--;
        ans++;
      }
      while (a && num < x) {
        num += 10;
        a--;
        ans++;
      }
      int res = num - x;
      while (res && res >= 50) {
        res -= 50;
        b++;
      }
      while (res && res >= 10){
        res -= 10;
        a++;
      }
    } else {  // x < 100
      int num = 0;
      while (b && num < x) {
        num += 50;
        b--;
        ans++;
      }
      while (a && num < x) {
        num += 10;
        a--;
        ans++;
      }
      int res = num - x;
      while (res && res >= 10){
        res -= 10;
        a++;
      }
    }
    m--;
  }
  return ans;
}
/******************************结束写代码******************************/


int main() {
    int res;

    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _a;
    cin >> _a;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _b;
    cin >> _b;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _c;
    cin >> _c;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _x;
    cin >> _x;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = buyCoke(_m, _a, _b, _c, _x);
    cout << res << endl;
    
    return 0;

}