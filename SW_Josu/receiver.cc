/*
 * receiver.cc
 *
 *  Created on: Dec 20, 2017
 *      Author: josu
 */
/*
 * receiver.cc
 *
 *  Created on: Dec 20, 2017
 *      Author: josu
 */
#include <string.h>
#include <omnetpp.h>
#include "paquete_m.h"
using namespace omnetpp;
class receiver : public cSimpleModule
{
  private:
    int counter;
    paquete * nuevoPaquete;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
// The module class needs to be registered with OMNeT++
Define_Module(receiver);
void receiver::initialize()
{

}
void receiver::handleMessage(cMessage *msg)
{
    paquete * recibido=(paquete *) msg;
    if(recibido->hasBitError())
    {
        nuevoPaquete=new paquete("NACK");
        nuevoPaquete -> setBitLength(1024);
        send(nuevoPaquete,"out");
    }
    else
    {
        nuevoPaquete=new paquete("ACK");
        nuevoPaquete -> setBitLength(1024);
        send(nuevoPaquete,"out");
    }

}



