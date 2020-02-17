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
void deque_push_tail(node** tail, node element);

/**
 * Pops single element out of tail. 
 * If unsuccessful, returns response code to element.resp_code.
 * 
 * Usage: deque_pop_tail(&head, &tail, &element);
 */
void deque_pop_tail(node** tail, node* element);

/**
 * Pushes one element to deque's head (front).
 * 
 * Usage: deque_push_head(&head, &tail, int);
 */
void deque_push_head(node** head, node element);

/**
 * Pops single element out of head. 
 * If unsuccessful, returns response code to element.resp_code.
 * 
 * Usage: deque_pop_head(&head, &tail, &element);
 */
void deque_pop_head(node** head, node* element);

/**
 * 
 */
bool deque_is_empty(node* address);

/**
 * 
 */
void deque_destroy(node* head, node* tail);


#endif