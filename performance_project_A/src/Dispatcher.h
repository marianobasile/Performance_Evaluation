//
// 
// 

#ifndef __PERFORMANCE_PROJECT_A_DISPATCHER_H_
#define __PERFORMANCE_PROJECT_A_DISPATCHER_H_

#include <omnetpp.h>

namespace performance_project {


class Dispatcher : public cSimpleModule {
  
  private:
    bool *exit;
    int size;

  public:
     Dispatcher();
    ~Dispatcher();

    void handleNewCustomer(cMessage *msg);
    void handleNotify(cMessage *msg);

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

} //namespace

#endif
