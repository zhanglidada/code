#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
/*
// 序列化和反序列化
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string res;
    if (root == nullptr)  return res;
    queue<TreeNode*> list;
    list.push(root);
    while (!list.empty()) {
      TreeNode* node = list.front();
      list.pop();
      if (node != nullptr) {
        res.append(to_string(node->val) + ",");
        list.push(node->left);
        list.push(node->right);
      } else {
        res.append("null,");
      }
    }
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "")  return nullptr;
    vector<string> spl = split(data, ",");
    if (spl[0] == "null")  return nullptr;
    queue<TreeNode*> list;
    TreeNode* root = new TreeNode(stoi(spl[0]));
    list.push(root);
    int i = 1;
    //cout << spl.size() << " test ";
    while (!list.empty()) {
      TreeNode* node = list.front();
      list.pop();
      if (spl[i] != "null") {
        TreeNode* tmp = new TreeNode(stoi(spl[i]));
        node->left = tmp;
        list.push(tmp);
      }
      i++;
      if (spl[i] != "null") {
        TreeNode* tmp = new TreeNode(stoi(spl[i]));
        node->right = tmp;
        list.push(tmp);
      }
      i++;
    }
    return root;
  }
  vector<string> split(string str, string pattern) {
    vector<string> res;
    int len = str.size();
    str += pattern;
    int pos = 0;
    for (int i = 0; i < len; i++) {
      // 从str的第i个位置开始查找pattern串出现的位置
      pos = str.find(pattern, i);
      if (pos < len) {
        string substr = str.substr(i, pos - i);
        res.push_back(substr);
        i = pos + pattern.size() - 1;
      }
    }
    return res;
  }
}; */

/*
// 求数组中的逆序对
class Solution {
 public:
  // 利用归并排序，在分治的过程中不需要计算，逆序对的计算存在于合并的过程中
  int reversePairs(vector<int>& nums) {
    vector<int> tmp(nums.size());
    return mergeSort(nums, tmp, 0, nums.size() - 1);
  }
  // 每一次归并的过程中，增加一个判断
  int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right) {
    if (left >= right)  return 0;
    int mid = (left + right) / 2;
    int count = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid + 1, right);
    // 当归并的子数组已经有序，且左边全部小于右边的时候，可以直接返回
    if (nums[mid] <= nums[mid + 1])  return count;
    int i = left, j = mid + 1, st = left;
    while (i<= mid && j <= right) {
      if (nums[j] < nums[i]) {
        tmp[st++] = nums[j++];
        count += (mid - i + 1);
      } else {  // 在right part中出现和left part中大小相同的元素时，应该先将left中的元素插入
        tmp[st++] = nums[i++];
      }
    }
    while (i <= mid)  tmp[st++] = nums[i++];
    while (j <= right)  tmp[st++] = nums[j++];
    for (int i = left; i <= right; i++)  nums[i] = tmp[i];
    return count;
  }
}; */

/*
class Solution {
 public:
  // 其实就是一个求mod的运算
  int lastRemaining(int n, int m) {
    vector<int> list;
    list.push_back(-1);
    // 保证所有元素的下标都从1开始
    for (int i = 0; i < n; i++)  list.push_back(i);
    int count = n, st = 1;
    while (count > 1) {
      int flag = 1;
      while (flag < m) {
        // 从上次删除位置开始找到第一个满足条件的位置
        while (list[st] == -1) {
          st = st + 1 <= n ? st + 1 : 1;
        }
        flag++;
        st = st + 1 <= n ? st + 1 : 1;
      }
      while (list[st] == -1)  st = st + 1 <= n ? st + 1 : 1;
      list[st] = -1;
      count--;
    }
    //for (auto num : list)  cout << num << " ";
    for (int i = 1; i <= n; i++)
      if (list[i] != -1)  return list[i];
    return 0;
  }
};

int func(int a, int b) {
  // while (b != 0) {
  //   int c = (unsigned int)(a & b) << 1;
  //   a = a ^ b;
  //   b = c;
  // }

  // 高位的bit存放在内存的高位
  int c = -2;  // -2 == 11111111 11111111 11111111 11111110
  for (int i = 3; i >=0; i--){
    // 定义char类型指针指向int变量的位置
    unsigned char * ch_p = (unsigned char *)&c + i;
    unsigned char ch = *ch_p;
    for (int j = 7; j >= 0; j--) {
      if (ch & (1 << j))
        cout << "1";
      else cout << "0";
    }
    cout << " ";
  }
  return a;
}
*/
/*
class Solution {
 public:
  // 采用kmp算法
  int strStr(string txt, string pattern) {
    kmp(pattern);
    int n = txt.size(), m = pattern.size();
    int j = 0;
    // i始终向前走，不会回头
    for (int i = 0; i < n; i++) {
      j = dp[j][char_to_int(txt[i])];
      if (j == m)  return i - m + 1;
    }
    return -1;
  }
  // 核心就是kmp算法，即计算pattern的状态转移数组
  void kmp(string pattern) {
    int m = pattern.size();
    dp = vector<vector<int>>(m, vector<int>(256, 0));
    // 初始状态，状态0除了遇到pattern的第一个字符，其余都不会有转移
    dp[0][char_to_int(pattern[0])] = 1;
    int X = 0;
    // 当前状态为1，针对每个状态，都有256种不同的字符进行状态转移
    for (int i = 1; i < m; i++) {
      for (int c = 0; c < 256; c++) {
        // 因为x始终在当前位置i的后方
        dp[i][c] = dp[X][c];
      }
      dp[i][char_to_int(pattern[i])] = i + 1;
      X = dp[X][char_to_int(i)];
    }
  }
  int char_to_int(char c) {
    return c - 'a';
  }
 private:
  vector<vector<int>> dp;
}; */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
 public:
  // 对于O(nlogn)时间复杂度，首先想到的就是二分 -- > 归并排序
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)  return head;
    // 定义快慢指针来查找链表的中间节点并断开，然后归并排序
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // 奇数找中间节点，偶数找中间节点的前一个
    ListNode* tmp = slow->next;
    slow->next = nullptr;  // 从中间位置断开
    ListNode* front = sortList(head);
    ListNode* back = sortList(tmp);
    return mergeList(front, back);
  }
  ListNode* mergeList(ListNode* tmp1, ListNode* tmp2) {
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    while(tmp1 && tmp2) {
      if (tmp1->val < tmp2->val) {
        tmp->next = tmp1;
        tmp1 = tmp1->next;
      } else {
        tmp->next = tmp2;
        tmp2 = tmp2->next;
      }
      tmp = tmp->next;
    }
    tmp->next = tmp1 == nullptr ? tmp2 : tmp1;
    return head->next;
  }
};
ListNode* createList(vector<int>& nums) {
  ListNode* dummy = new ListNode(0);
  ListNode* tmp = dummy;
  for (auto num : nums) {
    ListNode* node = new ListNode(num);
    tmp->next = node;
    tmp = tmp->next;
  }
  return dummy->next;
}
void printList(ListNode* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
}
int main() {
  vector<int> nums = {4,2,1,3};
  vector<int> nums1 = {1,4};
  vector<int> nums2 = {2,3};
  ListNode* list1 = createList(nums1);
  ListNode* list2 = createList(nums2);
  Solution ss;
  ListNode* list = ss.mergeList(list1, list2);
  printList(list1);
  return 0;
}