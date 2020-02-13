#include "deque.h"

void deque_create(node** head, node** tail) {
    *head = *tail = (node*) malloc(sizeof(node));
}

void deque_push_tail(node** head, node** tail, node element) {

    // If pushes first element
    if (deque_is_empty(*head, *tail)) {
        node* newHeadNode = (node*) malloc(sizeof(node));
        newHeadNode->next_node = *head;
        newHeadNode->prev_node = NULL;

        *head = newHeadNode;
    }

    node* newTailNode = (node*) malloc(sizeof(node));
    newTailNode->prev_node = *tail;
    newTailNode->next_node = NULL;
    (*tail)->value = element.value;
    (*tail)->next_node = newTailNode;
    *tail = newTailNode;

}

void deque_pop_tail(node** head, node** tail, node* element) {
    if (!deque_is_empty(*head, (*tail)->prev_node)) {
        node* previousNode = (*tail)->prev_node;
        free(*tail);
        *tail = previousNode;

        element->value = previousNode->value;
    } else {
        element->resp_code = 2;
    }
}

void deque_push_head(node** head, node** tail, node element) {

    // If pushes first element
    if (deque_is_empty(*head, *tail)) {
        node* newTailNode = (node*) malloc(sizeof(node));
        newTailNode->prev_node = *tail;
        newTailNode->next_node = NULL;

        *tail = newTailNode;
    }

    node* newNode = (node*) malloc(sizeof(node));
    newNode->next_node = *head;
    newNode->prev_node = NULL;
    (*head)->value = element.value;
    (*head)->prev_node = newNode;

    *head = newNode;

}

void deque_pop_head(node** head, node** tail, node* element) {
    if (!deque_is_empty((*head)->next_node, *tail)) {
        node* nextNode = (*head)->next_node;
        free(*head);
        *head = nextNode;

        element->value = nextNode->value;
    } else {
        element->resp_code = 2;
    }
}

void deque_destroy(node* head, node* tail) {
    while (head != tail) {
        node *temp = head;
        free(temp);
        head = temp->next_node;
    }
}

bool deque_is_empty(node* head, node* tail) {
    if (head == tail) {
        return true;
    } else {
        return false;
    }
}
