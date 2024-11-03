#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        // 定义快慢指针
        ListNode *slow = head;
        ListNode *fast = head;
        // 判断是否存在环
        bool hasCycle = false;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            // 存在环就退出
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle)
            return nullptr;

        fast = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
