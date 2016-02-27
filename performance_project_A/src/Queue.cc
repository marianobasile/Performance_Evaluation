//
// 
//

#include "Queue.h"

namespace performance_project {

Define_Module(Queue);

Queue::Queue() {

    queue = NULL;
    message = NULL;
}

void Queue::initialize() {
    queue = new cQueue();
    counter = getParentModule()->par("n");
}

void Queue::handleMessage(cMessage *msg) {

    if(msg->isName("newCustomer"))
        handleNewCustomer(msg);
    else
        handleNotify(msg);
}

void Queue::forwardCustomer() {

    counter--;
    message = (cMessage*)queue->pop();
    send( message,"queueOut");
}

void Queue::handleNewCustomer(cMessage *msg) {

    queue->insert(msg);
    if(counter>0)
        forwardCustomer();
}

void Queue::handleNotify(cMessage *msg) {

    delete msg;
    counter++;
    if(queue->length()>0)
        forwardCustomer();
}

Queue::~Queue() {

    delete queue;
}

} //namespace
