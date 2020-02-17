# Dynamic-Deque

Dynamic double-ended queue written in C

How to use
1. Declare queue head and tail pointers.
2. deque_create(&head, &tail);
3. deque_push_tail(&tail, element);
   deque_push_head(&head, element);
   deque_pop_tail(&tail, &element);
   deque_pop_head(&head, &element);
4. deque_destroy(head, tail);
