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

#ifndef __DISTANCIAS_NODE_H_
#define __DISTANCIAS_NODE_H_

#include <omnetpp.h>
#include <map>
#include <string>
#include <set>

using namespace std;

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Node : public cSimpleModule
{
  private:
    map<int, int> distances;
    map<int, int> first;
    map<int, int> level;

    set<int> set;

    int state = 0;
    bool initiated = false;


    int n;

    void sendSetForNeighbors();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
