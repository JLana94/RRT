/*
 * source.cc
 *
 *  Created on: Dec 20, 2017
 *      Author: josu
 */
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include "paquete_m.h"
using namespace omnetpp;

class source : public cSimpleModule
{
  private:
    paquete * nuevoPaquete;
    simtime_t startTime;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
// The module class needs to be registered with OMNeT++
Define_Module(source);
void source::initialize()
{
    startTime=20;
    cMessage *msg = new cMessage("source");
    scheduleAt(startTime, msg);
}
void source::handleMessage(cMessage *msg)
{
    paquete *paqSender = new paquete("source");
    paqSender -> setBitLength(1024);
    send(paqSender,"out");
    cMessage *newMsg = new cMessage("source");
    scheduleAt(simTime()+exponential(12),newMsg);
}




