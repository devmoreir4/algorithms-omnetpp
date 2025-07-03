/*
 * PIFNode.cc
 *
 *  Created on: Jul 3, 2025
 *      Author: carlos
 */


#include "PIFNode.h"

Define_Module(PIFNode);

void PIFNode::initialize() {
    reached = false;
    parentGate = -1;
    replies = 0;

    if (getIndex() == 0) {
        reached = true;

        cMessage *m = new cMessage("PROP");
        m->addPar("type") = PROP;

        for (int i = 0; i < gateSize("out"); ++i)
            send(m->dup(), "out", i);

        delete m;
    }
}

void PIFNode::handleMessage(cMessage *msg) {

    int type = msg->par("type").longValue();

    int arrival = msg->getArrivalGate()->getIndex();

    cGate *prev = msg->getArrivalGate()->getPreviousGate();

    int senderIdx = prev->getOwnerModule()->getIndex();

    int numNeighbor = gateSize("out");

    if (type == PROP) {

        if (!reached) {

            reached = true;
            parentGate = arrival;

            EV << "Nó[" << getIndex() << "] recebeu PROP de Nó[" << senderIdx
               << "]; define PAI = Nó[" << senderIdx << "].\n";

            for (int i = 0; i < numNeighbor; ++i) {

                if (i != parentGate) {
                    send(msg->dup(), "out", i);

                    cGate *nextPrev = gate("out", i)->getNextGate();
                    int childIdx = nextPrev->getOwnerModule()->getIndex();

                    EV << "Nó[" << getIndex() << "] envia PROP para Nó[" << childIdx << "] (out[" << i << "]).\n";
                }
            }
        }
        else {
            EV << "Nó[" << getIndex() << "] recebeu PROP duplicado de Nó[" << senderIdx
               << "] e ignorou.\n";

            cMessage *back = new cMessage("BACK");

            back->addPar("type") = BACK;
            send(back, "out", arrival);

            EV << "Nó[" << getIndex() << "] envia BACK imediato para Nó[" << senderIdx
               << "] (PROP duplicado).\n";
        }
    }
    else if (type == BACK) {
        replies++;

        EV << "Nó[" << getIndex() << "] recebeu BACK de Nó[" << senderIdx << "].\n";
    }

    if (reached) {
        int expectedReplies = (parentGate >= 0 ? numNeighbor - 1 : numNeighbor);

        if (replies == expectedReplies) {
            if (parentGate >= 0) {

                cMessage *back = new cMessage("BACK");

                back->addPar("type") = BACK;
                send(back, "out", parentGate);

                cGate *toParent = gate("out", parentGate)->getNextGate();
                int parentIdx = toParent->getOwnerModule()->getIndex();

                EV << "Nó[" << getIndex() << "] envia BACK para PAI Nó[" << parentIdx
                   << "] (out[" << parentGate << "]).\n";
            }
            else {
                EV << "Raiz[" << getIndex() << "] recebeu todos BACKs; PIF concluído.\n";
            }
        }
    }

    delete msg;
}
