# Dynamic Deque

[![Run on Repl.it](https://repl.it/badge/github/povilasleka/Dynamic-Deque)](https://repl.it/github/povilasleka/Dynamic-Deque)

Dynamic double-ended queue written in C

How to use
1. dlink* deque = deque_create();
2. Functions you can use after creating a deque.
   * deque_push_tail(&tail, element);
   * deque_push_head(&head, element);
   * deque_pop_tail(&tail, &element);
   * deque_pop_head(&head, &element);
3. deque_destroy(head, tail);
