#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  // 保存每个节点和其他节点之间的关系
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

/*
class Solution {
 public:
  // 利用深度优先进行遍历，但是这里的节点并没有直接关联关系，而是由一个单独的neighbours来保存节点之间的关联
  Node* cloneGraph(Node* node) {
    return dfs(node);
  }
  Node* dfs(Node* node) {
    if (node == nullptr)  return nullptr;
    if (visited.find(node) != visited.end())  return visited[node];
    // 创建并插入visited中，为了深拷贝，不会克隆当前节点的邻居节点
    Node* tmp = new Node(node->val);
    visited[node] = tmp;
    for (auto next : node->neighbors)
      tmp->neighbors.push_back(dfs(next));
    return tmp;
  }
 private:
  unordered_map<Node*, Node*> visited;
}; */

class Solution {
 public:
  // 利用广度优先进行遍历，但是这里的节点并没有直接关联关系，而是由一个单独的neighbours来保存节点之间的关联
  Node* cloneGraph(Node* node) {
    if (node == nullptr)  return nullptr;
    // 拷贝第一个节点并入队
    list.push(node);
    visited[node] = new Node(node->val);
    while (!list.empty()) {
      auto tmp = list.front();
      list.pop();
      // 遍历该节点的邻居并依次入队
      for (auto next : tmp->neighbors) {
        // 如果当前节点的邻居节点是第一次访问，则创建并插入visited中
        if (visited.find(next) == visited.end()) {
          Node* copy = new Node(next->val);
          visited[next] = copy;
          list.push(next);  // 只有未访问过的节点才有push的资格
        }
        // 更新当前节点的复制节点的邻居
        visited[tmp]->neighbors.emplace_back(visited[next]);
      }
    }
    return visited[node];
  }
 private:
  unordered_map<Node*, Node*> visited;
  queue<Node*> list;
};