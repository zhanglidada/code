#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct ListNode
{
  ListNode* left = nullptr;
  ListNode* right = nullptr;
  int value = 0;
  ListNode (int value) {
    value = value;
  }
};

class Solution{
 public:
  Solution(int k) : size(k){}

  void set(const string& key, const string& value) {
    
  }
  pair<bool, string> get(const string& key) {

  }
  void get(vector<pair<string, string>>& all) {

  }
 private:
  int size = 0;
  int flag = 0;
  unordered_map<string, ListNode*> LRU;
};
int main() {

}