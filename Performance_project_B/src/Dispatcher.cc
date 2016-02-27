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

#include "Dispatcher.h"

namespace performance_project_b {

Define_Module(Dispatcher);

Dispatcher :: Dispatcher() {
    queuesLength = NULL;
}

void Dispatcher::initialize() {

        size = getParentModule()->par("n");
        queuesLength = new int[size];

        for(int i=0; i<size; i++)
            queuesLength[i] = 0;
}

void Dispatcher::handleMessage(cMessage *msg) {

        if(msg->isName("newCustomer"))

            handleNewCustomer(msg);
        else
            handleNotify(msg);
}

void Dispatcher::handleNewCustomer(cMessage *msg) {

    int min = queuesLength[0];
    int gateMin = 0;
    /*search shortest queue*/
    for(int i=1; i<size; i++)
        if(queuesLength[i]<min){
            min = queuesLength[i];
            gateMin = i;
        }
    queuesLength[gateMin]++;
    send(msg, "dispatcherOut", gateMin);
}

void Dispatcher::handleNotify(cMessage *msg){

    queuesLength[msg->getArrivalGate()->getIndex()]--;
    delete msg;

}

Dispatcher :: ~Dispatcher() {
    delete[] queuesLength;
    
}

} //namespace
