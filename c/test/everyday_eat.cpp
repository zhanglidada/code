#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int rd = 0;
  int mod = 0;
  unsigned seed;
  string list;
  vector<string> meat = {"芹菜炒牛肉", "蒸排骨", "清蒸鲈鱼", "土豆烧排骨", "红烧桂鱼", "胡萝卜炖羊肉", "土豆烧鸡", "青椒蒜子牛肉", "虾仁滑蛋", "洋葱炒牛肉", "葱烧鸡腿"};
  vector<string> veg = {"牛心菜", "南瓜", "菠菜", "茼蒿", "小青菜", "红烧冬瓜", "香菇炒青菜", "洋葱炒蛋", "茄子烧豆角"};
  vector<string> spec {"黄瓜炒肉", "花菜炒肉", "胡萝卜炒肉", "四季豆炒肉", "辣椒炒蛋", "小葱跑蛋", "莴笋炒肉", "淮山炒肉", "杏鲍菇炒肉", "西红柿炒鸡蛋", "毛豆炒肉沫", "甜豆炒肉沫", "肉末烧茄子", "蒜苔炒肉", "蒜苔炒鸡杂", "平菇炒鸡蛋", "豆角肉沫"};
  vector<string> soup = {"芋头青菜汤", "青菜豆腐汤", "平菇蛋汤", "冬瓜肉片汤"};

  srand(time(NULL));

  for (int i = 0; i < 10; i++)
  {
    list.clear();

    rd = (int)rand();
    mod = meat.size();
    list += meat[rd % mod];
    list += " ";

    rd = (int)rand();
    mod = veg.size();
    list += veg[rd % mod];
    list += " ";

    rd = (int)rand();
    mod = spec.size();
    list += spec[rd % mod];
    list += " ";

    rd = (int)rand();
    mod = soup.size();
    list += soup[rd % mod];
    list += " ";

    cout << list << endl;
  }

}