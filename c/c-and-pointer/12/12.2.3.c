/**
 * @file 12.2.3.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-13
 * 
 * 最终改进版链表指针插入
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE  1

typedef struct node_struct node;
struct node_struct 
{
  node*           link;
  int             value;
};


int node_insert (
  register node**     linkp,      /*IN: address of node link*/
  int                 new_value   /*IN: new value*/
) 
{
  register node*  current;  // 当前节点
  register node*  new;  // 新建节点

  while ((current = *linkp) != NULL && current->value < new_value)
    linkp = &current->link;  // 指向下一个节点

  // 创建新节点并赋值
  new = (node*)malloc(sizeof(node));
  if (new == NULL)
    return FALSE;
  new->value = new_value;
  
  new->link = current;
  *linkp = new;

  return TRUE;
}
