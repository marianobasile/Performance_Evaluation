//
// 
// 

#ifndef __PERFORMANCE_PROJECT_A_QUEUE_H_
#define __PERFORMANCE_PROJECT_A_QUEUE_H_

#include <omnetpp.h>
#include <cqueue.h>

namespace performance_project {


class Queue : public cSimpleModule {
  
  private:
    cQueue *queue;
    int counter;
    cMessage *message;

  public:
    Queue();
    ~Queue();
    void forwardCustomer();
    void handleNewCustomer(cMessage *msg);
    void handleNotify(cMessage *msg);

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

} //namespace

#endif
