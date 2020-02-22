#include "deque.h"
#include <stdio.h>

int main() {
  dlink* deque = deque_create();
  node element;

  for(int i = 0; i < 10; i++) {
    element.value = i;
    deque_push_tail(deque, element);
  }

  for(int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      deque_pop_head(deque, &element);
    } else {
      deque_pop_tail(deque, &element);
    }

    printf("%d", element.value);
  }

  deque_destroy(deque);
}