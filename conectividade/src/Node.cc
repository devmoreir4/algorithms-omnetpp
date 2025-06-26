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

Define_Module(Node);

void Node::initialize()
{
    if (this->par("eIniciador").boolValue() == true) {
        this->iniciado = true;
        this->alcancado[this->getName()] = true;

        this->scheduleAt(simTime() + 0.1, new cMessage());
    }
}

void Node::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage() == true) {
        int portas = this->gateSize("out");

        for (int i = 0; i < portas; i++) {

            this->send(new cMessage(this->getName()), "out", i);

        }

        EV << this->getName() << " enviou seu id para todos os vizinhos.";
    } else {
        if (this->iniciado == false) {
            this->iniciado = true;
            this->alcancado[this->getName()] = true;

            int portas = this->gateSize("out");

            for (int i = 0; i < portas; i++) {

                this->send(new cMessage(this->getName()), "out", i);

            }

            EV << this->getName() << " foi iniciado" << endl;
            EV << this->getName() << " enviou seu id para todos os vizinhos." << endl;
        }

        if (this->contador.count(msg->getName()) == 0) {
            this->contador[msg->getName()] = 1;

            EV << this->getName() << " registrou " << msg->getName() << " pela primeira vez" << endl;
        } else {
            this->contador[msg->getName()]++;

            EV << this->getName() << " incrementou o contador de " << msg->getName() << " para " << this->contador[msg->getName()] << endl;
        }

        if (this->alcancado.count(msg->getName()) == 0) {

            this->alcancado[msg->getName()] = true;

            this->pai[msg->getName()] = msg->getArrivalGate()->getIndex();

            for (int i = 0; i < this->gateSize("out"); i ++) {

                if (i != this->pai[msg->getName()]) {

                    this->send(msg->dup(), "out", i);

                }

            }

            EV << msg->getName() << " alcançou " << this->getName() << endl;
            EV << this->getName() << " encaminhou msg para os vizinhos, exceto " << msg->getArrivalGate()->getIndex() << endl;

        }

        if (this->contador[msg->getName()] == this->gateSize("out")) {

            if (this->pai.count(msg->getName()) == 1) {

                this->send(msg->dup(), "out", this->pai[msg->getName()]);

                EV << this->getName() << " deu feedback sobre " << msg->getName() << " para o seu pai" << endl;

            } else {
                EV << "Todos conhecem " << this->getName() << endl;
            }
        }
    }

    delete msg;
}
