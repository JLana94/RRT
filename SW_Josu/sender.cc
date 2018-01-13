/*
 * sender.cc
 *
 *  Created on: Dec 20, 2017
 *      Author: josu
 */
/*
 * sender.cc
 *
 *  Created on: Dec 20, 2017
 *      Author: josu
 */
#include <string.h>
#include <omnetpp.h>
#include "paquete_m.h"
using namespace omnetpp;
class sender : public cSimpleModule
{
  private:
    int counter;
    char contenido[10];
    int state_machine;
    cQueue *txQueue;
    paquete * nuevoPaquete;
    paquete * replica;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
// The module class needs to be registered with OMNeT++
Define_Module(sender);
void sender::initialize()
{
    state_machine = 0;
    txQueue = new cQueue("txQueue");
}
void sender::handleMessage(cMessage *msg)
{


    if(strcmp(msg->getName(),"source")==0)
    {
        nuevoPaquete=new paquete("sender");
        nuevoPaquete -> setBitLength(exponential(150));

        if(state_machine==0)
        {
            replica=new paquete("sender");
            replica -> setBitLength(exponential(150));
            send(nuevoPaquete,"out");
            state_machine=1;
        }
        else
        {
            txQueue-> insert(nuevoPaquete);
        }

    }
    else
    {
        if(strcmp(msg->getName(),"ACK")==0)
        {
            if(txQueue-> isEmpty()){
                 state_machine = 0;
            }
            else
            {
                 nuevoPaquete = (paquete *) txQueue -> pop();
                 send(nuevoPaquete,"out");
            }
        }
        else
        {
            replica=new paquete("sender");
            replica -> setBitLength(exponential(150));
            send(replica,"out");//Enviar el paquete que tienes de la anterior
        }


    }
}



