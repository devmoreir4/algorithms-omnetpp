#ifndef PIFNODE_H_
#define PIFNODE_H_

#include <omnetpp.h>
using namespace omnetpp;

enum MsgType { PROP = 0, BACK = 1 };

class PIFNode : public cSimpleModule
{
  private:
    bool    reached;
    int     parentGate;
    int     replies;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif /* PIFNODE_H_ */
