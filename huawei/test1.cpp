#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getcount(string s, int v)
{
  int res = 0;

  for (auto c : s)
  {
    if (c == v + '0')
      res += 1;
  }

  return res;
}

int main ()
{
  int n,c;
  string tmp_str;
  int res = 0;

  cin >> n >> c;

  // n的值必须大于1
  if (c < 0 || c > 9 || n < 1)
  {
    cout << -1;
    return 0;
  }

  // // n的值小于1
  // if (n < 1)
  // {
  //   for (int i = 1; i >= n; i--)
  //   {
  //     tmp_str = to_string(i);
  //     res += getcount(tmp_str, c);
  //   }

  //   cout << res;
  //   return 0;
  // }

  // 从1到n的所有数字
  for (int i = 1; i <= n; i++)
  {
    tmp_str = to_string(i);
    res += getcount(tmp_str, c);
  }

  cout << res;

  return 0;
}