//
// 
// 

#ifndef __PERFORMANCE_PROJECT_A_GENERATOR_H_
#define __PERFORMANCE_PROJECT_A_GENERATOR_H_

#include <omnetpp.h>
#include <simtime.h>

namespace performance_project {

/**
 * TODO - Generated class
 */
class Generator : public cSimpleModule {
	
private:
  cMessage *timeoutEvent;
  cMessage *newCustomer;
  double mean;

public:
  Generator();
  ~Generator();

  void handleTimeout(cMessage *msg);

protected:
  virtual void initialize();
  virtual void handleMessage(cMessage *msg);
};

} //namespace

#endif
