#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个链表的头节点 head ，判断链表中是否有环。
 * Notes: 
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
********************************************************************************************/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*******************************************************************************************
 * Notes:
 * 首先想到的就是hash表，存储之前访问过的节点
********************************************************************************************/
class Solution {
  public:
    bool hasCycle(ListNode *head) {
      while (head != nullptr) {
        if (visited.count(head))
          return true;
        
        visited.insert(head);
        head = head->next;
      }
      return false;
    }
  private:
    // 存储之前访问过的节点
    unordered_set<ListNode*> visited;
};

/*******************************************************************************************
 * Notes:
 * 其次，想到仅仅需要判断内部是否有环，那么用快慢指针判断环即可
 * 快指针每次移动两步，慢指针每次移动一步，那么快指针会在环内追上慢指针一圈
********************************************************************************************/
class Solution {
  public:
    bool hasCycle(ListNode *head) {
      if (head == nullptr || head->next == nullptr)  return false;
      slow = head;
      fast = head->next;
      while (fast != nullptr && fast->next != nullptr) {
        if (fast == slow)
          return true;
        fast = fast->next->next;
        slow = slow->next;
      }
      return false;
    }
  private:
    ListNode* fast = NULL;
    ListNode* slow = NULL;
};