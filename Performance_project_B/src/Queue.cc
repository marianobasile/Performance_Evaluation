//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Queue.h"

namespace performance_project_b {

Define_Module(Queue);

Queue::Queue() {
    queue = NULL;
    message = NULL;
}

void Queue::initialize() {
    free = true;
    queue = new cQueue();
}

void Queue::handleMessage(cMessage *msg) {

    if(msg->isName("newCustomer"))

        handleNewCustomer(msg);
    else
        handleNotify(msg);
}

void Queue::handleNewCustomer(cMessage *msg) { 

    queue->insert(msg);
    if(free){
        free=false;
        message = (cMessage*)queue->pop();
        send( message, "queueOut");
    }
}

void Queue::handleNotify(cMessage *msg) {

    free=true;
    delete msg;
    send( new cMessage("dispatcherNotify"), "queueServiceOut");
    if(queue->getLength()>0){
        free=false;
        message = (cMessage*)queue->pop();
        send( message, "queueOut");
    }
}

Queue::~Queue() {
    delete queue;
}

} //namespace
