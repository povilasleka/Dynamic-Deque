#include "deque.h"
#include <stdio.h>

int main() {
    node *head, *tail;
    node element;

    deque_create(&head, &tail);

    for (int i = 0; i < 10; i++) {
        element.value = i;
        deque_push_head(&head, element);
    }

    for (int i = 0; i < 10; i++) {
        deque_pop_head(&head, &element);
        printf("%d", element.value);
    }

    deque_destroy(head, tail);

    printf("%p %p", head, tail);


}