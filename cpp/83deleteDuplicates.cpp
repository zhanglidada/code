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

/*
class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;

        if (head->next == nullptr)  return head;

        ListNode* curr_node = head;

        // 当前节点的下一个节点值同当前节点值一样，跳过下一个节点
        while (curr_node != nullptr && curr_node->next != nullptr)
        {
            if (curr_node->val == curr_node->next->val)
                curr_node->next = curr_node->next->next;
            else
                curr_node = curr_node->next;
        }

        return head;
    }
};
*/

// 也可以使用递归方法处理，本质上就是将链表压栈后倒序处理
class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;

        if (head->next == nullptr)  return head;

        // head的next节点就是下层递归函数返回的节点
        head->next = deleteDuplicates(head->next);
        
        return (head->next != nullptr && head->val == head->next->val) ? head->next : head;
    }
};

