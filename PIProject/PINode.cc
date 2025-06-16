#include "PINode.h"

Define_Module(PINode);

void PINode::initialize() {
    reached = false;

    if (getIndex() == 0) {
        reached = true;
        cMessage *m = new cMessage("INF");
        for (int i = 0; i < gateSize("out"); i++)
            send(m->dup(), "out", i);
        delete m;
    }
}

void PINode::handleMessage(cMessage *msg) {
    if (!reached) {

        reached = true;
        EV << "Nó[" << getIndex() << "] recebeu NOVA mensagem INF e está encaminhando para todos os vizinhos.\n";

        for (int i = 0; i < gateSize("out"); i++) {
            send(msg->dup(), "out", i);
        }
    }
    else {
        EV << "Nó[" << getIndex() << "] recebeu INF duplicada e descartou sem reenviar.\n";
    }

    delete msg;
}
