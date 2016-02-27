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

#ifndef __PERFORMANCE_PROJECT_B_TILL_H_
#define __PERFORMANCE_PROJECT_B_TILL_H_

#include <omnetpp.h>
#include <simtime.h>

namespace performance_project_b {

class Till : public cSimpleModule {

  private:
    cMessage *timeoutEvent;
    cMessage *notifyQueue;
    simtime_t enqueingCustomerTime;
    simsignal_t startBeingServed;
    simsignal_t leaveSystem;
    double mean;
    double std;

  public:
    Till();
    ~Till();

    void handleNewCustomer(cMessage *msg);
    void handleTimeout(cMessage *msg);

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

} //namespace

#endif
