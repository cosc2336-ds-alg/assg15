/** @file APriorityQueue.cpp
 * @brief Concrete array based implementation of Priority Queue ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * Implement the Queue abstraction but maintain the queue as a
 * priority queue.  This is an array based implementation.  We
 * inherit from the AQueue class and override the
 * enqueue() method to insert new values into the queue
 * based on their priority.  For this class we assume that
 * operator<() is defined for the type T being managed, and that
 * it returns true when the lhs T value is higher priority than the
 * rhs T value.
 */
#include "APriorityQueue.hpp"
#include "Job.hpp"
#include "QueueException.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// define macros to make it easier to access the base class protected
// members without all of the cruft
#define size AQueue<T>::size
#define allocationSize AQueue<T>::allocationSize
#define frontIndex AQueue<T>::frontIndex
#define backIndex AQueue<T>::backIndex
#define values AQueue<T>::values
#define growQueueIfNeeded() AQueue<T>::growQueueIfNeeded()

/**
 * @brief Default constructor
 *
 * Construct an empty queue.  The empty queue will have no allocated memory
 * nor any values.
 */
template<class T>
APriorityQueue<T>::APriorityQueue()
  : AQueue<T>()
{
}

/**
 * @brief Standard constructor
 *
 * Construct a queue of  values from a (statically) defined and
 * provided array of values.  We simply allocate a block of memory
 * dynamically large enough to hold the values, then copy the values
 * from the input parameter into our own private array of values.
 *
 * @param initSize The size of the input values were are given as well as the
 *   size of the new queue we are to construct.
 * @param initValues The (static) array of values to use to construct
 *   this Queue values with.
 */
template<class T>
APriorityQueue<T>::APriorityQueue(int initSize, T initValues[])
{
  // dynamically allocate a block of memory on the heap large enough to copy
  // the given input values into.  Our heap data structure does not use
  // index 0, so we allocate 1 more than size so we can index values from 1 to
  // size instead of the usual 0 to size-1
  size = initSize;
  allocationSize = initSize + 1;
  values = new T[allocationSize];

  // copy the values from the input paramter into our new shiny block of memory
  for (int index = 1; index <= size; index++)
  {
    values[index] = initValues[index - 1];
  }
}

/** @brief access front of proiroty queue
 *
 * Accessor method to get a copy of the item currently
 * at the front of the queue which should be processed
 * next in a queueing application.
 *
 * @returns T Returns a copy of the front item of the
 *   queue.
 *
 * @throws QueueEmptyException If an attempt is made to
 *   access front item of an empty queue, this exception
 *   is generated and thrown instead.
 */
template<class T>
T APriorityQueue<T>::front() const
{
  // if queue is empty let user know there is a problem
  // whith them trying to access an item from this queue
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <APriorityQueue>::front() attempt to get item"
        << " from empty queue, size:  " << this->size;

    throw QueueEmptyException(out.str());
  }

  // otherwise safe to return the front item.  For our heap organized
  // array, the front or highest priority item is always at the root
  // index 1 of the heap
  return values[1];
}


/**
 * @brief priority Queue to string
 *
 * Accessor method to construct and return a string representation
 * of the current values and status of this Priority Queue instance.
 *
 * @returns string Returns the string constructed with the information
 *   about this Queue.
 */
template<class T>
string APriorityQueue<T>::str() const
{
  ostringstream out;

  // stream queue information into the output stream
  out << "<queue> size: " << size << " front:[ ";

  // stream the current values of the queue to the output stream
  // the array is a circular buffer, so we use the size to
  // determine number of times loop should occur, and calculate
  // index to access as an offset from frontIndex, being careful to wrap
  // it around the buffer when it reaches the end
  // NOTE: for priority queue we are using a heap where we don't use
  // index 0 of the values array, so simply show values from index 1
  // to the last value in the heap.
  for (int index = 1; index <= size; index++)
  {
    // calculate the index in the circular buffer
    int queueIndex = (frontIndex + index) % allocationSize;

    // stream the value out
    out << values[queueIndex];

    // separate the values of the queue, last one does not need , separator
    if (queueIndex == size)
    {
      out << " ";
    }
    else
    {
      out << ", ";
    }
  }
  out << "]:back";

  // convert the string stream into a concrete string to return
  return out.str();
}

/** @brief exchange values
 *
 * Given references to two separate values, cause the values of the two
 * items to be exchanged (or swapped).
 *
 * @param valueA A reference to one of two values to be exchanged.
 * @param valueB A reference to the second of the two values to be exchanged.
 */
template<class T>
void APriorityQueue<T>::exchange(T& valueA, T& valueB)
{
  // perform the usual 3 actions to swap values A and B
  T temp = valueA;
  valueA = valueB;
  valueB = temp;
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class Queue<needed_type>
 * here of any types we are going to be instantianting with the
 * template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class APriorityQueue<int>;
template class APriorityQueue<char>;
template class APriorityQueue<string>;
template class APriorityQueue<Job>;
