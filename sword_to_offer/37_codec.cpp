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


/***************************************************************************
 * 1.使用先序遍历的方式，序列化二叉树
 * 
 * 1）空值使用none保存
 * 2）使用 ',' 隔开
***************************************************************************/
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

/****************************************************************
 * 2.使用括号表示编码 + 递归下降
 * 
 * 1）当前树为空，表示为X
 * 
 * 2）当前树不为空，表示为 （left sub tree）num（right sub tree）
 * *left sub tree 为左子树序列化后的结果
 * *right sub tree 为右子树序列化后的结果
 * *num 为当前节点的值
 * 
 * 3）采用后续遍历方式序列化二叉树
 * 
 * 4）T -> (T) num (T) | X
 * 
 * 用 T 代表一棵树序列化之后的结果，| 表示 T 的构成为 (T) num (T) 或者 X，| 左边是对 T 的递归定义，右边规定了递归终止的边界条件。
 * 在 T 的定义中，序列中的第一个字符要么是 X，要么是 (，所以这个定义是不含左递归的
 * 开始解析一个字符串时，如果开头是 X，就知道这一定是解析一个「空树」的结构，如果开头是 (，就知道需要解析 (T) num (T) 的结构，
 * 因此这里两种开头和两种解析方法一一对应，可以确定这是一个无二义性的文法，只需要通过开头的第一个字母是 X 还是 ( 来判断使用哪一种解析方法
 * 
 * 这个文法是一个LL(1)文法
******************************************************************/
class Codec {
  public:
  string serialize(TreeNode* root) {
      if (!root) {
          return "X";
      }
      auto left = "(" + serialize(root->left) + ")";
      auto right = "(" + serialize(root->right) + ")";
      return left + to_string(root->val) + right;
  }

  // 解析字符串代表的值，string to int
  inline int parseInt(const string &data, int &ptr) {
    int x = 0;
    int sgn = 1;  // 符号位
    if (!isdigit(data[ptr])) {
        sgn = -1;
        ++ptr;
    }
    while (isdigit(data[ptr])) {
        x = x * 10 + data[ptr++] - '0';
    }
    return x * sgn;
  }

  inline TreeNode* parseSubtree(const string &data, int &ptr) {
    ++ptr; // 跳过左括号
    auto subtree = parse(data, ptr);
    ++ptr; // 跳过右括号
    return subtree;
  }

  TreeNode* parse(const string &data, int &ptr) {
    // 当前节点为空，返回
    if (data[ptr] == 'X') {
        ++ptr;
        return nullptr;
    }

    auto cur = new TreeNode(0);
    // 解析左子树
    cur->left = parseSubtree(data, ptr);
    // 设置当前节点的值
    cur->val = parseInt(data, ptr);
    // 解析右子树
    cur->right = parseSubtree(data, ptr);
    return cur;
  }

  TreeNode* deserialize(string data) {
      int ptr = 0;
      // 返回反序列化后的树
      return parse(data, ptr);
  }
};