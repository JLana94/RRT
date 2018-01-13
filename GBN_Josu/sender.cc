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
#include <stdio.h>
#include "paquete_m.h"
using namespace omnetpp;
class sender : public cSimpleModule
{
  private:
    int counter;
    char contenido[10];
    int state_machine;          //Ahora la maquina de estados es el que marca cuantos paquetes se han enviado -> Ventana
    char estado[8];
    char str[3];
    int numSeq;
    int numPaq;
    cQueue *txQueue;
    cQueue *enviados;
    paquete * nuevoPaquete;
    paquete * replica;
    paquete * reenvioNACK;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
// The module class needs to be registered with OMNeT++
Define_Module(sender);
void sender::initialize()
{
    state_machine = 0;
    numSeq=0;
    numPaq=0;
    txQueue = new cQueue("txQueue");
    enviados = new cQueue("enviados");
}
void sender::handleMessage(cMessage *msg)
{


    if(strcmp(msg->getName(),"source")==0)
    {
        if(numSeq==8)
            numSeq=1;
        else
            numSeq++;
        numPaq++;


        sprintf(str, "%d", numPaq);

        estado[0]='(';
        estado[1]=numSeq+'0';
        estado[2]=')';
        estado[3]=' ';
        estado[4]=str[0];
        estado[5]=str[1];
        estado[6]=str[2];



        nuevoPaquete=new paquete(estado);
        nuevoPaquete -> setBitLength(exponential(150));
        nuevoPaquete->setNumSeq(numSeq);

        if(state_machine<8)
        {
            replica=nuevoPaquete->dup();
            enviados-> insert(replica);
            send(nuevoPaquete,"out");

            state_machine++;
        }
        else
        {
            txQueue-> insert(nuevoPaquete);
        }

    }
    else
    {
        if(msg->getName()[0]=='A')
        {

            enviados -> pop();
            state_machine--;
            if(txQueue-> isEmpty()){

            }
            else
            {
                 nuevoPaquete = (paquete *) txQueue -> pop();
                 replica=nuevoPaquete->dup();
                 enviados-> insert(replica);
                 send(nuevoPaquete,"out");
                 state_machine++;
            }
        }
        else
        {
            reenvioNACK=(paquete *) enviados->pop();
            replica=reenvioNACK->dup();
            send(reenvioNACK,"out");
            enviados-> insert(replica);
        }


    }
}
