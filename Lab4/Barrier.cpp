/*
Name: Rory Garner
Class : Software Development
Year : 4
2017- 2018
Purpose: CDD Lab 3
*/

#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/* Barrier constructor*/
Barrier::Barrier(){

  count = 0;
  threadNum = 0;
  turnstile = 0;
  mutex=std::make_shared<Semaphore>(1);
  barrier1=std::make_shared<Semaphore>(0);
  barrier2=std::make_shared<Semaphore>(1);

}

Barrier::Barrier(int count){

  this->count = count;
  turnstile = 0;
  threadNum = 0;
  mutex=std::make_shared<Semaphore>(1);
  barrier1=std::make_shared<Semaphore>(0);
  barrier2=std::make_shared<Semaphore>(1);
}
/*deconstructor*/
Barrier::~Barrier(){

}

/*! set count */
void Barrier::setCount(int x){

  this->count = x;
}
/*! return count */
int Barrier::getCount(){

  return this->count;
}

/*! waits for all the threads */ 
void Barrier::waitForAll(){

  if(turnstile == 0){
    first();
  }
  else{
    second();
  }

}
/*first turnstile */
void Barrier::first(){

  mutex->Wait();
  threadNum++;
  if(threadNum == count){
    barrier2->Wait();
    barrier1->Signal();
    turnstile = 1;
  }
  mutex->Signal();
  barrier1->Wait();
  barrier1->Signal();
}
/*second turnstile */
void Barrier::second(){

  mutex->Wait();
  threadNum--;
  if(threadNum == 0){
    barrier1->Wait();
    barrier2->Signal();
    turnstile = 0;
  }
  mutex->Signal();
  barrier2->Wait();
  barrier2->Signal();
}
