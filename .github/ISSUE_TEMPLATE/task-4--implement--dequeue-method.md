---
name: 'Task 4: Implement `APriorityQueue` `dequeue()` Member Method'
about: Task 4 for Students
title: 'Task 4: Implement `APriorityQueue` `dequeue()` Member Method'
labels: enhancement
assignees: ''

---

**Description**

The fourth task is to implement `dequeue()` but for the `APriorityQueue` class.

**Suggested Solution**

1. First test if a `dequeue()` is being attempted on an empty queue.  If the
   queue is empty, throw a `QueueEmptyException` instead of trying to
   perform the operation on an empty queue.
2. Otherwise, exchange the value at the top (or root) of the heap with the
   last value in the heap array.  The root or top of the heap is always at
   index 1 of the array.  Likewise the `size` of the queue will be the
   index of the last item in the array, since we are treating the array as a 1-based
   indexed array for this heap.
3. After exchanging the root value, which is the highest priority item we are
   dequeuing, you can reduce the size of the queue by 1.
4. Then we need to do a bottom-down re-heapify operation.  Call your
   `fixDown()` method on the heap root to re-heapify the heap.


**Additional Requirements**

- You are required to throw an appropriate exception if an attempt is made
  to dequeue from an already empty priority queue.
