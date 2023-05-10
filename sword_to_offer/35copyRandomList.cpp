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
  // 把链表看作一个图，每个节点有两条路径
  Node* dfs(Node* head) {
    if (head == nullptr)
      return nullptr;
    
    // 提前返回，保证每个节点只会被copy一次
    if (visited.count(head))
      return visited[head];  // 当前节点被访问过，直接返回当前节点的copy
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

// 采用迭代方式
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
            return head;
            
        copy_node(head);
        copy_random(head);
        return relink(head);
    }

private:
    void copy_node(Node* head)
    {
        while (head)
        {
            Node* tmp_head = new Node(head->val);
            tmp_head->next = head->next;
            head->next = tmp_head;
            head = tmp_head->next;
        }
    }

    void copy_random(Node* head)
    {
        Node* head_cp = nullptr;
        while (head != nullptr)
        {
            // 指向具体的node
            if (head->random != nullptr)
            {
                head_cp = head->next;
                head_cp->random = head->random->next;
            }
            head = head->next->next;
        }
    }

    Node* relink(Node* head)
    {
        Node* head_cp = nullptr;
        Node* res_head = head->next;
        while (head)
        {
            head_cp = head->next;
            head->next = head_cp->next;
            if (head_cp->next != nullptr)
            {
                head_cp->next = head->next->next;
            }
            head = head->next;
        }
        return res_head;
    }
};