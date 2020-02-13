#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DEQUE_DATA_STRUCTURE
#define DEQUE_DATA_STRUCTURE

struct node_st {
    struct node_st* prev_node;
    struct node_st* next_node;
    int value;
    int resp_code;
};

typedef struct node_st node;

// Response codes
// 00 - action is successful.
// 01 - could not allocate memory.
// 02 - deque is empty and pop operation was not executed.


// Funkcijos


/**
 * Allocates one memory place for node type element,
 * sets tail and head to point to that memory place.
 * 
 * Usage: deque_create(&head, &tail);
 */
void deque_create(node** head, node** tail);

/**
 * Pushes one element to deque's tail (end).
 * 
 * Usage: deque_push_tail(&head, &tail, int);
 */
void deque_push_tail(node** head, node** tail, node element);

/**
 * Pops single element out of tail. 
 * If unsuccessful, returns response code to element.resp_code.
 * 
 * Usage: deque_pop_tail(&head, &tail, &element);
 */
void deque_pop_tail(node** head, node** tail, node* element);

/**
 * Pushes one element to deque's head (front).
 * 
 * Usage: deque_push_head(&head, &tail, int);
 */
void deque_push_head(node** head, node** tail, node element);

/**
 * Pops single element out of head. 
 * If unsuccessful, returns response code to element.resp_code.
 * 
 * Usage: deque_pop_head(&head, &tail, &element);
 */
void deque_pop_head(node** head, node** tail, node* element);

/**
 * 
 */
bool deque_is_empty(node *head, node *tail);

/**
 * 
 */
void deque_destroy(node* head, node* tail);


#endif