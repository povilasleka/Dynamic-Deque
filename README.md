# Dynamic Deque

Dynamic double-ended queue written in C

How to use
1. Declare queue head and tail pointers. (node* head; node* tail)
2. deque_create(&head, &tail);
3. Functions you can use after creating a deque.
   * deque_push_tail(&tail, element);
   * deque_push_head(&head, element);
   * deque_pop_tail(&tail, &element);
   * deque_pop_head(&head, &element);
4. deque_destroy(head, tail);

[![Run on Repl.it](https://repl.it/badge/github/povilasleka/Dynamic-Deque)](https://repl.it/github/povilasleka/Dynamic-Deque)
