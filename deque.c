#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

dlink *deque_create(void)
{
  dlink *deque = malloc(sizeof(node));

  deque->head = deque->tail = malloc(sizeof(node));
  deque->head->is_zero_element = true;
  deque->errorcode = 0;

  return deque;
}

void deque_push_tail(dlink *deque, node element)
{
  if (!deque_is_empty(deque))
  {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = element.value;
    newNode->prev_node = deque->tail;
    deque->tail->next_node = newNode;
    deque->tail = newNode;
  }
}

void deque_pop_tail(dlink *deque, node *element)
{
  if (!deque->tail->is_zero_element)
  {
    *element = *(deque->tail);
    if (deque->tail->prev_node != NULL)
    {
      deque->tail = deque->tail->prev_node;
      free(deque->tail->next_node);
      deque->tail->next_node = NULL;
    }
  }
  else
  {
    if (deque->tail->prev_node != NULL)
    {
      deque->tail = deque->tail->prev_node;
      free(deque->tail->next_node);
      deque->tail->next_node = NULL;
      deque_pop_tail(deque, element);
    }
  }
}

void deque_pop_head(dlink *deque, node *element)
{
  if (!deque->head->is_zero_element)
  {
    *element = *(deque->head);
    if (deque->head->next_node != NULL)
    {
      deque->head = deque->head->next_node;
      free(deque->head->prev_node);
      deque->head->prev_node = NULL;
    }
  }
  else
  {
    if (deque->head->next_node != NULL)
    {
      deque->head = deque->head->next_node;
      free(deque->head->prev_node);
      deque->head->prev_node = NULL;
      deque_pop_head(deque, element);
    }
  }
}

void deque_push_head(dlink *deque, node element)
{
  if (!deque_is_empty(deque))
  {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next_node = deque->head;
    newNode->value = element.value;
    deque->head->prev_node = newNode;
    deque->head = newNode;
  }
}

dlink *deque_destroy(dlink *deque)
{
  while (deque->head != deque->tail)
  {
    deque->head = deque->head->next_node;
    free(deque->head->prev_node);
    deque->head->prev_node = NULL;
  }

  return NULL;
}

bool deque_is_empty(dlink *deque)
{
  if (deque->head == NULL && deque->tail == NULL)
    return true;
  else
    return false;
}
