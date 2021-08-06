#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

// 采用递归的方法，回溯时将复制的链表链接起来
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr)  return head;
    // 如果当前节点已经访问过，直接将head节点对应的复制节点返回
    if (visited.count(head))  return visited[head];

    Node* node = new Node(head->val);
    visited.insert({head, node});

    node->next = copyRandomList(head->next);
    node->random = copyRandomList(head->random);

    return node;
  }
 private:
  // 保存链表中每个节点的拷贝
  unordered_map<Node*, Node*> visited;
};

// 直接采用迭代的方法
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr)  return head;
    // 先将头节点进行复制,headCopy和head一一对应
    Node* headCopy = new Node(head->val);
    visited.insert({head, headCopy});

    Node* oldHead = head; // 复制头节点的备份
    while (oldHead) {
      headCopy->next = getCloneNode(oldHead->next);
      headCopy->random = getCloneNode(oldHead->random);
      headCopy = headCopy->next;
      oldHead = oldHead->next;
    }

    return visited[head];
  }
  Node* getCloneNode(Node* head) {
    if (head == nullptr)  return head;

    if (visited.count(head))  return visited[head];
    // 没有访问过的节点，临时插入到map中
    visited.insert({head, new Node(head->val)});
    return visited[head];
  }
 private:
  // 保存链表中每个节点的拷贝
  unordered_map<Node*, Node*> visited;
};

// O(1)空间的迭代,直接在远链表上进行操作
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr)  return head;
    Node* headCopy = head;
    // 第一次循环完成节点的复制
    while (headCopy) {
      Node* node = new Node(headCopy->val);
      node->next = headCopy->next;
      headCopy->next = node;
      // 指向下一个原链表中节点
      headCopy = headCopy->next->next;
    }
    headCopy = head;
    // 第二次循环完成复制节点的random节点指向
    while (headCopy) {
      headCopy->next->random = headCopy->random == nullptr ? nullptr : headCopy->random->next;
      headCopy = headCopy->next->next;
    }
    headCopy = head;
    // 第三次循环完成next节点的正确指向
    Node* res = headCopy->next;
    while (headCopy) {
      Node* tmp = headCopy->next;
      if (tmp->next) {
        headCopy->next = tmp->next;
        tmp->next = tmp->next->next;
      } else {
        headCopy->next = nullptr;
      }
      headCopy = headCopy->next;
    }
    return res;
  }
};