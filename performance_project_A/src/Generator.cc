//
// 
// 

#include "Generator.h"

namespace performance_project {

Define_Module(Generator);

Generator::Generator() {
    newCustomer = timeoutEvent = NULL;
}

void Generator::initialize() {

    mean = par("IATMean");

    timeoutEvent = new cMessage("wakeup");

    scheduleAt(simTime()+ 0, timeoutEvent);
}

void Generator::handleMessage(cMessage *msg) {

    handleTimeout(msg);
}

void Generator::handleTimeout(cMessage *msg) {

    newCustomer = new cMessage("newCustomer");
    newCustomer->setSchedulingPriority(1);
    send(newCustomer,"generatorOut");

    scheduleAt(simTime() + exponential(mean), msg);
}

Generator :: ~Generator() {

    cancelAndDelete(timeoutEvent);
}

} //namespace
