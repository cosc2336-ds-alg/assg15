---
name: 'Task 3: Implement `AQueue` `enqueue()` Member Method'
about: Task 3 for Students
title: 'Task 3: Implement `AQueue` `enqueue()` Member Method'
labels: enhancement
assignees: ''

---

**Description**

Implement the missing `enqueue()` method for the `APriorityQueue` heap based
implementation of a priority queue.


**Suggested Solution**

1. Call `growQueueIfNeeded()` to ensure the `values[]` backing
   storage array for the heap is large enough to add another value
   to the end.
2. Increase the size of the queue by 1.  Since we are not using index 0
   of the `values` array, the size is also the index of the last item
   in the array being maintained as a heap.  By increasing the size by 1
   first, the `size` now also indicates the index location to add in the
   new value being enqueued.
3. Add the new indicated value being enqueued into the backing array at
   the end of the array.
4. Call your `fixUp()` method to do a bottom-up re-heapify operation, starting
   at the new value index you just added.

**Additional Requirements**

- You must reuse the `growQueueIfNeeded()` correctly to ensure the array is big
  enough, or if not will be grown to be big enough, before enqueing the value.

