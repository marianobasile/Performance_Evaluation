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

#include "Generator.h"

namespace performance_project_b {

Define_Module(Generator);

Generator::Generator() {
    newCustomer = timeoutEvent = NULL;
}

void Generator::initialize() {

    mean = par("IATMean");

    timeoutEvent = new cMessage("wakeup");

    scheduleAt(simTime()+ 0, timeoutEvent);
}

void Generator::handleMessage(cMessage *msg){

    handleTimeout(msg);
}

void Generator::handleTimeout(cMessage *msg){

    newCustomer = new cMessage("newCustomer");
    newCustomer->setSchedulingPriority(1);
    send(newCustomer,"generatorOut");

    scheduleAt(simTime() + exponential(mean), msg);
}

Generator :: ~Generator() {

    cancelAndDelete(timeoutEvent);
}

} //namespace
