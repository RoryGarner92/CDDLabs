/*
Name: Rory Garner
Class : Software Development
Year : 4
2017- 2018
Purpose: CDD Lab 3
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 0;

void taskOne(std::shared_ptr<Semaphore> mutex){
  mutex->Wait();
  count += 1;
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  mutex->Signal();
}

int main(void){
  std::thread threadOne, threadTwo, threadThree, threadFour;
  std::shared_ptr<Semaphore> sem( new Semaphore(1));
  /**< Launch the threads  */
  threadOne=std::thread(taskOne,sem);
  threadTwo=std::thread(taskOne,sem);
  threadThree=std::thread(taskOne,sem);
  threadFour=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  threadFour.join();
  std::cout << count;
  return 0;
}
