#include "deque.h"
#include <stdio.h>

int main() {
    node *head, *tail;
    int elem;

    int action;

    deque_create(&head, &tail);

    while(action != 5)
    {
        printf("[1 - Push head, 2 - Push tail, 3 - Pop head, 4 - Pop tail]: ");
        scanf("%d", &action);

        node element;
        if (action == 1) {
            scanf("%d", &(element.value));
            deque_push_head(&head, &tail, element);
        }

        if (action == 2) {
            scanf("%d", &(element.value));
            deque_push_tail(&head, &tail, element);
        }

        if (action == 3) {
            deque_pop_head(&head, &tail, &element);
            printf("Pop head element: %d \n", element.value);
        }

        if (action == 4) {
            deque_pop_tail(&head, &tail, &element);
            printf("Pop tail element: %d \n", element.value);
        }
    }

    deque_destroy(head, tail);
    
}