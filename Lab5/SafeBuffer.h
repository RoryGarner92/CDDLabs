/*
Name: Rory Garner
Class : Software Development
Year : 4
2017- 2018
Purpose: CDD Lab 4
*/

#ifndef SAFEBUFFER_H
#define SAFEBUFFER_H

#include <mutex>
#include "Semaphore.h"
#include <queue>

/*!  Class used to provide safe access to a shared buffer.*/
class SafeBuffer {
 public:
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> items;
  std::shared_ptr<Semaphore> spaces;
  std::queue<char> safeBuffer;
  SafeBuffer();
  void Add(char);
  char Remove();
};

#endif //  SAFEBUFFER_H_
