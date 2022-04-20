/** @file test-APriorityQueue.cpp
 * @brief Unit tests for Assignment Queues
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Tests of the array based implementation of the Priority Queue API.
 */
#include "Job.hpp"
#include "QueueException.hpp"
#include "catch.hpp"
#include <iostream>
// kludge to test private method
#define private public
#include "APriorityQueue.hpp"
using namespace std;

/** Task 1: Test bottom-up heapify
 */
/*
TEST_CASE("APriorityQueue test fixUp bottom-up heapify", "[task1]")
{
  const int N = 13; 
  char heapItems[N] = {'X', 'S', 'P', 'G', 'R', 'O', 'N', 'A', 'E', 'T', 'A', 'I', 'M'};

  // value at index 10 is not heap ordered, fix it up
  APriorityQueue<char> priorityQueue(N, heapItems);
  CHECK(priorityQueue.getSize() == N);
  CHECK(priorityQueue.str() == "<queue> size: 13 front:[ X, S, P, G, R, O, N, A, E, T, A, I, M ]:back");
  priorityQueue.fixUp(10);
  CHECK(priorityQueue.getSize() == N);
  CHECK(priorityQueue.str() == "<queue> size: 13 front:[ X, T, P, G, S, O, N, A, E, R, A, I, M ]:back");
}
*/

/** Task 2: Test top-down heapify
 */
/*
TEST_CASE("APriorityQueue test fixDown top-down heapify", "[task2]")
{
  const int N = 13; 
  char heapItems[N] = {'O', 'T', 'X', 'G', 'S', 'P', 'N', 'A', 'E', 'R', 'A', 'I', 'M'};

  // value at root/top of heap, index 1, is not heap ordered, fix down
  APriorityQueue<char> priorityQueue(N, heapItems);
  CHECK(priorityQueue.getSize() == N);
  CHECK(priorityQueue.str() == "<queue> size: 13 front:[ O, T, X, G, S, P, N, A, E, R, A, I, M ]:back");
  priorityQueue.fixDown(1);
  CHECK(priorityQueue.getSize() == N);
  CHECK(priorityQueue.str() == "<queue> size: 13 front:[ X, T, P, G, S, O, N, A, E, R, A, I, M ]:back");
}
*/

/** Task 3: Test PriorityQueue enqueue of new values onto heap
 */
/*
TEST_CASE("APriorityQueue test enqueue implementation", "[task3]")
{
    APriorityQueue<int> priorityQueue;

    // priority queue is initially empty
    CHECK(priorityQueue.isEmpty());
    CHECK(priorityQueue.getSize() == 0);
    CHECK(priorityQueue.str() == "<queue> size: 0 front:[ ]:back");

    // test case 1 insertion into empty priority queue
    priorityQueue.enqueue(5);
    CHECK_FALSE(priorityQueue.isEmpty());
    CHECK(priorityQueue.getSize() == 1);
    CHECK(priorityQueue.str() == "<queue> size: 1 front:[ 5 ]:back");
    CHECK(priorityQueue.front() == 5);

    // test case 2 new node is highest priority and should end up on front
    priorityQueue.enqueue(10);
    CHECK_FALSE(priorityQueue.isEmpty());
    CHECK(priorityQueue.getSize() == 2);
    CHECK(priorityQueue.str() == "<queue> size: 2 front:[ 10, 5 ]:back");
    CHECK(priorityQueue.front() == 10);

    // Test case 3 new node ends up somewhere in middle of the queue
    priorityQueue.enqueue(7);
    CHECK_FALSE(priorityQueue.isEmpty());
    CHECK(priorityQueue.getSize() == 3);
    CHECK(priorityQueue.str() == "<queue> size: 3 front:[ 10, 5, 7 ]:back");
    CHECK(priorityQueue.front() == 10);

    // Test case 3+/4 need to correctl handle when new node ends up on the end
    priorityQueue.enqueue(3);
    CHECK_FALSE(priorityQueue.isEmpty());
    CHECK(priorityQueue.getSize() == 4);
    CHECK(priorityQueue.str() == "<queue> size: 4 front:[ 10, 5, 7, 3 ]:back");
    CHECK(priorityQueue.front() == 10);

    priorityQueue.enqueue(1);
    CHECK_FALSE(priorityQueue.isEmpty());
    CHECK(priorityQueue.getSize() == 5);
    CHECK(priorityQueue.str() == "<queue> size: 5 front:[ 10, 5, 7, 3, 1 ]:back");
    CHECK(priorityQueue.front() == 10);
    
}
*/

/** Task 4: Test PriorityQueue dequeue of values from heap
 */
/*
TEST_CASE("APriorityQueue test dequeue implementation", "[task4]")
{
  const int N = 5; 
  int heapItems[N] = {10, 5, 7, 3, 1};

  // value at root/top of heap, index 1, is not heap ordered, fix down
  APriorityQueue<int> priorityQueue(N, heapItems);

  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 5);
  CHECK(priorityQueue.str() == "<queue> size: 5 front:[ 10, 5, 7, 3, 1 ]:back");
  CHECK(priorityQueue.front() == 10);

  // dequeue top priority item
  priorityQueue.dequeue();
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 4);
  CHECK(priorityQueue.str() == "<queue> size: 4 front:[ 7, 5, 1, 3 ]:back");
  CHECK(priorityQueue.front() == 7);
  
  priorityQueue.dequeue();
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 3);
  CHECK(priorityQueue.str() == "<queue> size: 3 front:[ 5, 3, 1 ]:back");
  CHECK(priorityQueue.front() == 5);
  
  priorityQueue.dequeue();
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 2);
  CHECK(priorityQueue.str() == "<queue> size: 2 front:[ 3, 1 ]:back");
  CHECK(priorityQueue.front() == 3);
  
  priorityQueue.dequeue();
  CHECK_FALSE(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 1);
  CHECK(priorityQueue.str() == "<queue> size: 1 front:[ 1 ]:back");
  CHECK(priorityQueue.front() == 1);
  
  priorityQueue.dequeue();
  CHECK(priorityQueue.isEmpty());
  CHECK(priorityQueue.getSize() == 0);
  CHECK(priorityQueue.str() == "<queue> size: 0 front:[ ]:back");

  CHECK_THROWS_AS(priorityQueue.front(), QueueEmptyException);
  CHECK_THROWS_AS(priorityQueue.dequeue(), QueueEmptyException);  
}
*/
