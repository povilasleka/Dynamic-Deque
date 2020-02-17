#include "deque.h"

void deque_create(node** head, node** tail) {
    *head = *tail = NULL;
}

void deque_push_tail(node** head, node** tail, node element) {

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
    node *newNode = (node*) malloc(sizeof(node));
    newNode->prev_node = *head;
    (*head)->next_node = newNode;
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
