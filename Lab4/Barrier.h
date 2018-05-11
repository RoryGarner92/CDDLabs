/*
Name: Rory Garner
Class : Software Development
Year : 4
2017- 2018
Purpose: CDD Lab 3
*/

#include "Semaphore.h"
#include <iostream>
#include <stdio.h>

/*! \class Barrier
    \brief A Barrier Implementation

   Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores

*/
class Barrier
{
private:
  /*! number of threads using the barrier*/
  int count;
  /*! current thread active*/
  int threadNum;
  /*! current turnstile active*/
  int turnstile;
  /*! mutex which only allows one thread to execute at once*/
  std::shared_ptr<Semaphore> mutex;
  /*! first turnstile*/
  std::shared_ptr<Semaphore> barrier1;
  /*! second turnstile*/
  std::shared_ptr<Semaphore> barrier2;
  /*! this is the first turnstile for the barrier*/
  void first();
  /*! this is the second turnstile for the barrier*/
  void second();

public:

  Barrier();
  ~Barrier();

  Barrier(int count);
  /*! sets the count for the barrier*/ 
  void count(int count);
  /*! gets the count for the barrier*/ 
  int count();
  /*! waits for all the threads and checks which turnstile is active*/ 
  void waitForAll();
};
