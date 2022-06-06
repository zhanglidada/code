#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 
 * 返回插入后二叉搜索树的根节点。 输入数据值原始二叉搜索树中的任意节点值都不同。
 * Notes:
 * 可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。
********************************************************************************************/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*******************************************************************************************
 * Notes:
 * 可以使用最简单的插入方式，直接递归找到需要插入的节点位置，不用考虑树的高度以及性能问题
********************************************************************************************/
// class Solution {
//   public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//       if (root == nullptr)
//         return new TreeNode(val);

//       if (val > root->val) {
//         // 当前节点的右子树为插入之后的右子树
//         root->right = insertIntoBST(root->right, val);
//       } else {
//         // 当前节点的左子树为插入之后的左子树
//         root->left = insertIntoBST(root->left, val);
//       }

//       return root;
//     }
// };


/*******************************************************************************************
 * Notes:
 * 稍微考虑一下性能问题，可以采用avl树实现：
 * 1.AVL树是一种平衡二叉树
 * 2.左右子树的高度差小于等于1
 * 3.每一个子树为平衡二叉树
 * 4.左子树高度-右子树盖度 = 平衡因子BF(balance factor)，BF取值范围为[-1, 1]
********************************************************************************************/
class Solution {
  public:
    // 节点插入
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      insert(&root, val);
      return root;
    }

    // LL型调整，右旋
    void R(TreeNode** root) {
      TreeNode* tmp = (*root)->left;
      (*root)->left = tmp->right;
      tmp->right = *root;
      *root = tmp;  // 最终的root节点指向
    }

    // RR型调整，左旋
    void L(TreeNode** root) {
      TreeNode* tmp = (*root)->right;
      (*root)->right = tmp->left;
      tmp->left = (*root);
      (*root) = tmp;
    }

    // LR型调整
    void LR(TreeNode** root) {
      L(&((*root)->left));
      R(root);
    }

    // RL型调整
    void RL(TreeNode** root) {
      R(&((*root)->right));
      L(root);
    }

    // 获取当前节点到叶子节点的深度
    int get_height(TreeNode* root) {
      if (root == nullptr)  return 0;

      return max(get_height(root->left), get_height(root->right)) + 1;
    }
    
    // 获取当前节点的平衡因子
    int get_balance(TreeNode* root) {
      return get_height(root->left) - get_height(root->right);
    }

    // 将节点插入树中
    void insert(TreeNode** root, int val) {
      // 递归到叶子节点，创建并返回
      if ((*root) == nullptr) {
        (*root) = new TreeNode(val);
        return;
      }

      if (val < (*root)->val) {
        // 插入到root的左子树中，可能not balance
        insert(&(*root)->left, val);
        // 从最后插入的节点返回，递归调整子树的平衡
        if (get_balance((*root)) == 2) {
          // LL型调整
          if (get_balance((*root)->left) == 1) {
            R(root);
          }
          // LR型调整
          else if (get_balance((*root)->left) == -1) {
            LR(root);
          }
        }
      }
      else {
        // 插入到root的右子树中，可能存在不平衡的情况
        insert(&(*root)->right, val);
        // 从最后插入的节点返回，递归调整子树的平衡
        if (get_balance((*root)) == -2) {
          // RR型调整
          if (get_balance((*root)->right) == -1) {
            L(root);
          }
          // RL型调整
          else if (get_balance((*root)->right) == 1) {
            RL(root);
          }
        }
      }
    }

    // 判断一棵树是否平衡
    bool is_balanced(TreeNode* root) {
      if (root == nullptr)  return true;
      return is_balanced(root->left) 
        && is_balanced(root->right) 
        && abs(get_height(root->left) - get_height(root->right)) <= 1;
    }

    /***************************************************************************************
     * AVL树节点的删除
     * 1.寻找删除目标
     * 2.判断删除目标的类型，并将其转换为叶子节点
     * 3.从删除节点开始，调整平衡直到根节点
     * 4.存储删除路径上的所有节点，供回溯调整使用
    ****************************************************************************************/
    bool delete_node(TreeNode** root, int key) {
      stack<TreeNode*> path;
      TreeNode* p = *root;
      TreeNode* q = nullptr;
      TreeNode* parent = nullptr;  // 当前节点的父节点

      // 用栈存储遍历轨迹
      while (p) {
        if (p->val == key)  break;
        path.push(p);
        if (key > p->val)
          p = p->right;
        else
          p = p->left;
      }

      // 删除目标不存在
      if (p == nullptr) return false;

      // 当前节点的左右节点均存在，需要找当前节点的前驱节点，并与之交换
      if (p->left && p->right) {
        parent = p;  // 保存其哪一个节点的位置
        q = p->left;  // 指向当前节点的左子树
        path.push(p);  // 继续存储路径
        while (q->right) {
          parent = q;
          path.push(q);
          q = q->right;
        }
        p->val = q->val;  // 要删除节点值改为前序节点值
        p = q;  // p指向其前序节点
      }
      
      // 当前节点只有左子树
      if (p->left) {
        q = p->left;
      }
      // 当前节点只有右子树
      else if (p->right){
        q = p->right;
      }

      // 要删除的节点为根节点
      if (path.empty()) *root = q;
      else {
        parent = path.top();
        if (parent->left == p) {
          parent->left = q;
        } else {
          parent->right = q;
        }
      }

    }

    // 对子树的平衡性进行调整
    void adjust(TreeNode* root) {

    }
};

int main() {
  Solution ss;
  
}