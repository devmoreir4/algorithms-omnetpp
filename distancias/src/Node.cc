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

#include "Node.h"
#include "Message_m.h"

Define_Module(Node);

void Node::initialize()
{

    WATCH(this->initiated);
    WATCH(this->state);
    WATCH(this->n);

    WATCH_SET(this->set);

    WATCH_MAP(this->distances);
    WATCH_MAP(this->level);
    WATCH_MAP(this->first);

    if (this->par("isInitiator").boolValue() == true) {


        this->initiated = true;

        this->scheduleAfter(simTime() + 0.1, new cMessage());

    }

    this->distances[this->getId()] = 0;

    this->n = this->par("n").intValue();

    this->set.insert(this->getId());

    for (int i = 0; i < this->gateSize("edges"); i++) {

        this->level[this->gate("edges$o", i)->getIndex()] = - 1;

    }
}

void Node::sendSetForNeighbors() {
    Message *message = new Message();

    for (int id : this->set) {

        message->insertSet(id);

    }
    for (int i = 0; i < this->gateSize("edges"); i++) {

        this->send(message->dup(), "edges$o", i);

    }

    delete message;
}

void Node::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage() == true) {

        this->sendSetForNeighbors();

    } else {

        if (this->initiated == false) {

            this->initiated = true;



            this->sendSetForNeighbors();

        }

        if (this->state < this-> n - 1) {

            this->level[msg->getArrivalGate()->getIndex()]++;

            Message* message = check_and_cast<Message*>(msg);

            for (int i = 0; i < message->getSetArraySize(); i++) {

                int id = message->getSet(i);

                if (this->distances.find(id) == this->distances.end()) {

                    this->distances[id] = this->n;

                }

                if (this->distances[id] > this->level[msg->getArrivalGate()->getIndex()] + 1) {

                    this->distances[id] = this->level[msg->getArrivalGate()->getIndex()] + 1;

                    this->first[id] = msg->getArrivalGate()->getIndex();

                }

            }

            bool isSincronized = true;

            for (int i = 0; i < this->gateSize("edges"); i++) {

                int level = this->level[this->gate("edges$o", i)->getIndex()];

                if (this->state > level) {
                    isSincronized = false;
                    break;
                }

            }

            if (isSincronized == true) {

                this->state++;

                for (const auto& entry: this->distances) {

                    if (entry.second == this->state) {
                        this->set.insert(entry.first);
                    }

                }

                this->sendSetForNeighbors();

            }

        }

    }

    delete msg;
}
