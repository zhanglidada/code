#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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
// 深度优先进行拷贝
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    return dfs(head);
  }
  Node* dfs(Node* head) {
    if (head == nullptr)
      return nullptr;
    if (visited.count(head))
      return visited[head];
    Node* copy = new Node(head->val);
    visited.insert(pair<Node*, Node*>(head, copy));
    copy->next = dfs(head->next);
    copy->random = dfs(head->random);
    return copy;
  }
 private:
   unordered_map<Node*, Node*> visited;  // 用于存储已经拷贝过的节点
};
// 采用广度优先进行遍历
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    return bfs(head);
  }
  Node* bfs(Node* head) {
    if (head == nullptr)  return head;
    queue<Node*> que;
    // 创建头节点并入队
    Node* copy = new Node(head->val);
    que.push(head);
    visited[head] = copy;
    while (!que.empty()) {
      Node* tmp = que.front();
      que.pop();
      // 若当前节点的next没有访问过，则创建新的节点并将其入队
      if (tmp->next && visited.count(tmp->next) == 0) {
        que.push(tmp->next);
        visited[tmp->next] = new Node(tmp->next->val);
      }
      if (tmp->random && visited.count(tmp->random) == 0) {
        que.push(tmp->random);
        visited[tmp->random] = new Node(tmp->random->val);
      }
      visited[tmp]->next = visited[tmp->next];
      visited[tmp]->random = visited[tmp->random];
    }
    return copy;
  }
 private:
   unordered_map<Node*, Node*> visited;  // 用于存储已经拷贝过的节点
};

// 采用迭代方式，并进行过优化
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr)
      return nullptr;
    copyNode(head);
    copyRandom(head);
    return relinkNodes(head);
  }
 private:
  void copyNode(Node* head) {
    while (head) {
      Node* copyHead = new Node(head->val);
      copyHead->next = head->next;
      head->next = copyHead;
      head = copyHead->next;
    }
  }
  void copyRandom(Node* head) {
    while (head) {
      Node* cloneNode = head->next;
      if (head->random != nullptr) {
        cloneNode->random = head->random->next;
      }
      head = cloneNode->next;
    }
  }
  Node* relinkNodes(Node* head) {
    Node* cloneHead = head->next;
    Node* cloneNode = cloneHead;
    head->next = cloneNode->next;
    head = head->next;
    while (head) {  // 因为复制过后链表中节点数目肯定为偶数
      cloneNode->next = head->next;
      head->next = head->next->next;
      head = head->next;
      cloneNode = cloneNode->next;
    }
    return cloneHead;
  }
};