/*
 * PINode.h
 *
 *  Created on: Jul 3, 2025
 *      Author: carlos
 */

#ifndef PINODE_H_
#define PINODE_H_

#include <omnetpp.h>
using namespace omnetpp;

class PINode : public cSimpleModule
{
  private:
    bool reached;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif /* PINODE_H_ */
