#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 实现二叉树的基本操作，以二叉链表方式保存二叉树的信息
 * Notes:
 * 实现包括：建立二叉树，前序、中序、后续遍历二叉树，计算二叉树深度，统计二叉树节点数等
********************************************************************************************/


/*******************************************************************************************
 * Purpose:
 * 定义二叉树的节点类型
 * Notes:
 * 
********************************************************************************************/
typedef struct binary_treeNode_struct bt_node;  // 定义不完整声明的别名
struct binary_treeNode_struct {
  char  data;
  bt_node* left_child;
  bt_node* right_child;
};

class BinaryTree {
  public:
    BinaryTree() {
      char ch;
      while ((ch = getchar()) != '\n') {
        nodes_val.emplace_back(ch);
      }
    }
    // 创建二叉树，根据数组进行先序遍历创建
    void create_binary_tree(bt_node** T) {
      char val = nodes_val[pos++];
      if (val == '#') {
        *T = NULL;  // 当前节点为空节点
      } else {
        // 初始化节点
        *T = (bt_node*)malloc(sizeof(bt_node));
        (*T)->data = val;
        create_binary_tree(&((*T)->left_child));
        create_binary_tree(&((*T)->right_child));
      }
    }

    // 先序遍历二叉树
    void preorder_binary_tree(bt_node* T) {
      if (T == NULL) {
        cout << "#" << " ";
        return;
      }
      cout << T->data << " ";
      preorder_binary_tree(T->left_child);
      preorder_binary_tree(T->right_child);
    }

    // 中序遍历二叉树
    void inorder_binary_tree(bt_node* T) {
      if (T == NULL) {
        cout << "#" << " ";
        return;
      }
      inorder_binary_tree(T->left_child);
      cout << T->data << " ";
      inorder_binary_tree(T->right_child);
    }

    // 后序遍历二叉树
    void postorder_binary_tree(bt_node* T) {
      if (T == NULL) {
        cout << "#" << " ";
        return;
      }
      postorder_binary_tree(T->left_child);
      postorder_binary_tree(T->right_child);
      cout << T->data << " ";
      
    }

    // 二叉树拷贝
    void copy(bt_node* T, bt_node** new_T) {
      if (T == NULL)  *new_T = NULL;
      *new_T = (bt_node*)malloc(sizeof(bt_node));
      copy(T->left_child, &((*new_T)->left_child));
      copy(T->right_child, &((*new_T)->right_child));
    }

    // 二叉树深度
    int depth(bt_node* T) {
      if (T == nullptr) return 0;
      return max(depth(T->left_child), depth(T->right_child)) + 1;
    }

    // 统计二叉树的节点数
    int node_count(bt_node* T) {
      if (T == NULL)  return 0;
      return node_count(T->left_child) + node_count(T->right_child) + 1;
    }

    // 统计二叉树的叶子节点数
    int leaf_count(bt_node* T) {
      if (T == NULL)  return 0;
      if (T->left_child == NULL && T->right_child == NULL)  return 1;
      return leaf_count(T->left_child) + leaf_count(T->right_child);
    }

    // 统计二叉树度为1的节点数
    int node1_count(bt_node* T) {

    }
    
    // 输出从根节点开始所有的路径
    void print_all_path(bt_node* T) {

    }

    // 二叉树的镜像
    void reverse_tree(bt_node* T) {

    }
  private:
    vector<char> nodes_val;
    int pos = 0;  // 访问的位置

};

int main() {
  return 0;
}