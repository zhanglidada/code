#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <list>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief 
 * 实现两个函数，分别用来序列化和反序列化二叉树。
 * 
 * 二叉树的序列化本质上是对二叉树的结构进行编码
 * 
 */

/***************************************************************
 * 使用先序遍历的方式，序列化二叉树
 * 
 * 1）空值使用none保存
 * 2）使用 ',' 隔开
***************************************************************/
class Codec {
  public:
    // 序列化二叉树
    string serialize(TreeNode* root) {
      string ret;
      rserialize(root, ret);
      return ret;
    }

    // 反序列化
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                // str中保存到','截止的字符串
                dataArray.push_back(str);
                // push后清空str
                str.clear();
            } else {
                // 持续向str中push字符
                str.push_back(ch);
            }
        }
        // push 最后的字符串
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }

    // 具体的序列化函数
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    // 反序列化，将序列化字符串转为二叉树
    TreeNode* rdeserialize(list<string>& dataArray) {
        // 当前节点为空，直接返回
        if (dataArray.front() == "None") {
          // 删除dataArray头元素
          dataArray.erase(dataArray.begin());
          return nullptr;
        }

        // 创建新节点，分别设置节点的左右孩子
        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);

        // 返回新创建的节点
        return root;
    }
};

class Codec {
 public:
    // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr)  return "";
    ostringstream out;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      TreeNode* tmp = que.front();
      que.pop();
      if (tmp) {
        out << tmp->val << " ";
        que.push(tmp->left);
        que.push(tmp->right);
      } else {
        out << "null ";
      }
    }
    return out.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "")  return nullptr;
    istringstream input(data);
    string val;
    vector<TreeNode*> vec;  // 用一个数组来保存所有树中的节点
    while (input >> val) {
      if (val == "null")
        vec.push_back(nullptr);
      else {
        vec.push_back(new TreeNode(stoi(val)));
      }
    }
    int j = 1;
    for (int i = 0; j < vec.size(); i++) {
      if (vec[i] == nullptr)  continue;
      // i每往后移动一位，j往后移动两位，所以j始终是当前i的左子下标
      if (j < vec.size())  vec[i]->left = vec[j++];
      if (j < vec.size())  vec[i]->right = vec[j++];
    }
    return vec[0];
  }
};