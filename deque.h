#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DEQUE_DATA_STRUCTURE
#define DEQUE_DATA_STRUCTURE

struct node_st {
    struct node_st* prev_node;
    struct node_st* next_node;

    // Value type can be changed.
    int value;

    bool is_zero_element;
};

typedef struct node_st node;

struct deque_link {
  struct node_st* head;
  struct node_st* tail;
  int errorcode;
};

typedef struct deque_link dlink;

// Funkcijos


/**
 * Allocates memory for dlink type element and sets
 * head & tail to NULL.
 * 
 * Usage: dlink* deque = deque_create();
 */
dlink* deque_create(void);

/**
 * Pushes one element to deque's tail (end).
 * 
 * Usage: deque_push_tail(&head, &tail, int);
 */
void deque_push_tail(dlink* deque, node element);

/**
 * Pops single element out of tail. 
 * If unsuccessful, returns response code to element.resp_code.
 * 
 * Usage: deque_pop_tail(&head, &tail, &element);
 */
void deque_pop_tail(dlink* deque, node* element);

/**
 * Pushes one element to deque's head (front).
 * 
 * Usage: deque_push_head(&head, &tail, int);
 */
void deque_push_head(dlink* deque, node element);

/**
 * Pops single element out of head. 
 * If unsuccessful, returns response code to element.resp_code.
 * 
 * Usage: deque_pop_head(&head, &tail, &element);
 */
void deque_pop_head(dlink* deque, node* element);

/**
 * 
 */
bool deque_is_empty(node* address);

/**
 * 
 */
void deque_destroy(dlink* deque);


#endif