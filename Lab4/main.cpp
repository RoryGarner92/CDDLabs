/*
Name: Rory Garner
Class : Software Development
Year : 4
2017- 2018
Purpose: CDD Lab 3
*/

#include "Barrier.h"
#include <thread>
#include <vector>

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/


void task(std::shared_ptr<Barrier> barrierObj){

  std::cout << "first " << std::endl;
  /*! wait for all thereads to fin before continue*/
  barrierObj->waitForAll();
  std::cout << "second" << std::endl;
  barrierObj->waitForAll();
  std::cout << "third" << std::endl;
  barrierObj->waitForAll();
  std::cout << "forth" << std::endl;
}

int main(void){

  /*threads*/
  std::vector<std::thread> threadArray(5);
  /* Pointer*/
  std::shared_ptr<Barrier> barrierObj( new Barrier);
  /*barrier counter*/
  barrierObj->setCount(threadArray.size());

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,barrierObj);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  return 0;
}
