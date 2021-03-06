/*
Name: Rory Garner
Class : Software Development
Year : 4
2017- 2018
Purpose: CDD Lab 1
*/
#include <mutex>
#include <condition_variable>

/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Keeps track of the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
          : m_uiCount(uiCount) { };
    void Wait();
    void Signal();

};
