#include "deque.h"

void deque_create(node** head, node** tail) {
    *head = *tail = malloc(sizeof(node));
    (*head)->is_zero_element = true;
    (*tail)->is_zero_element = true;
}

void deque_push_tail(node** tail, node element) {
    if (!deque_is_empty(*tail)) {
        node* newNode = (node*) malloc(sizeof(node));
        newNode->value = element.value;
        newNode->prev_node = *tail;
        (*tail)->next_node = newNode;
        *tail = newNode;
    }
}

void deque_pop_tail(node** tail, node* element) {
    if (!(*tail)->is_zero_element) {
        *element = **tail;
        if ((*tail)->prev_node != NULL) {
            *tail = (*tail)->prev_node;
            free((*tail)->next_node);
            (*tail)->next_node = NULL;
        }
    } else {
        if ((*tail)->prev_node != NULL) {
            *tail = (*tail)->prev_node;
            free((*tail)->next_node);
            (*tail)->next_node = NULL;
            deque_pop_tail(tail, element);
        }
    }
}

void deque_pop_head(node** head, node* element) {
    if (!(*head)->is_zero_element) {
        *element = **head;
        if ((*head)->next_node != NULL) {
            *head = (*head)->next_node;
            free((*head)->prev_node);
            (*head)->prev_node = NULL;
        }
    } else {
        if ((*head)->next_node != NULL) {
            *head = (*head)->next_node;
            free((*head)->prev_node);
            (*head)->prev_node = NULL;
            deque_pop_head(head, element);
        }
    }
}

void deque_push_head(node** head, node element) {
    if (!deque_is_empty(*head)) {
        node* newNode = (node*) malloc(sizeof(node));
        newNode->next_node = *head;
        newNode->value = element.value;
        (*head)->prev_node = newNode;
        *head = newNode;
    }
}

void deque_destroy(node* head, node* tail) {
    while (head != tail) {
        head = head->next_node;
        free(head->prev_node);
        head->prev_node = NULL;
    }
}

bool deque_is_empty(node* address) {
    if (address == NULL) {
        return true;
    } else {
        return false;
    }
}
