//
// 
//

#include "Dispatcher.h"

namespace performance_project {

Define_Module(Dispatcher);

Dispatcher :: Dispatcher() {

            exit = NULL;
}

void Dispatcher::initialize() {

        size = getParentModule()->par("n");

        exit = new bool[size];

        for(int i=0; i < size; i++)
            exit[i] = true;

}

void Dispatcher::handleMessage(cMessage *msg) {

    if(msg->isName("newCustomer"))

        handleNewCustomer(msg);
    else

        handleNotify(msg);
}

void Dispatcher::handleNewCustomer(cMessage *msg) {

    for(int i=0; i<size; i++){
        if(exit[i]){
            exit[i]=false;
            send(msg,"dispatcherOut",i);
            break;
        }
    }
}

void Dispatcher::handleNotify(cMessage *msg) {

    exit[msg->getArrivalGate()->getIndex()]=true;
    send(msg, "dispatcherServiceOut");
}

Dispatcher::~Dispatcher() {
    
    delete[] exit;
}

} //namespace
