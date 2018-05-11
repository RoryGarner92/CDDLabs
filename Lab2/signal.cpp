/*
Name: Rory Garner
Class : Software Development
Year : 4
2017- 2018
Purpose: CDD Lab 2
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theFirstSem, std::shared_ptr<Semaphore> theSecondSem){
  std::cout <<"A ";
  std::cout << "B "<<std::endl;
  theSecondSem->Signal();
  theFirstSem->Wait();   
  std::cout << "C ";
  std::cout << "D "<<std::endl;
  theSecondSem->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theFirstSem, std::shared_ptr<Semaphore> theSecondSem){
  theSecondSem->Wait();
  std::cout <<"E ";
  std::cout << "F "<<std::endl;
  theFirstSem->Signal();
  theSecondSem->Wait(); 
  std::cout << "G ";
  std::cout << "H "<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem0( new Semaphore);
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem0,sem1);
  threadTwo=std::thread(taskOne,sem0,sem1);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
