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

#include "Till.h"

namespace performance_project_b {

Define_Module(Till);

Till::Till() {
    timeoutEvent = notifyQueue = NULL;
}

void Till::initialize() {

    /*parameter for different evolution*/
    mean = par("STMean");
    std = par("STstd");

    timeoutEvent = new cMessage("beep");            //delete by till
    startBeingServed = registerSignal("startBeingServed");
    leaveSystem = registerSignal("leaveSystem");
}

void Till::handleMessage(cMessage *msg) {

    /*End service-time*/
    if(msg->isSelfMessage())

        handleTimeout(msg);
    /*new Customer enter in service*/
    else
        handleNewCustomer(msg);
}

void Till::handleNewCustomer(cMessage *msg) {

    enqueingCustomerTime = msg->getCreationTime();
    /*emit queueing-time*/
    emit(startBeingServed, msg->getArrivalTime() - enqueingCustomerTime);

    delete msg;
    //scheduleAt(simTime() + exponential(mean), timeoutEvent);
    scheduleAt( simTime() + lognormal(mean,std), timeoutEvent);
}

void Till::handleTimeout(cMessage *msg) {

    /*emit response-time*/
    emit(leaveSystem, msg->getArrivalTime() - enqueingCustomerTime);

    /*reuse the same beep*/
    timeoutEvent = msg;
    notifyQueue = new cMessage("notifyQueue");
    notifyQueue->setSchedulingPriority(0);
    send(notifyQueue,"tillServiceOut");
}


Till::~Till() {

    cancelAndDelete(timeoutEvent);
}

} //namespace
