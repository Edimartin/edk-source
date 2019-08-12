/*
Library EDK - How to use Extensible Development Kit
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

/*
This tutorial show how to create a small neural network with only one exit.

-distance|Distance|-------middle1_1|Middle1|
                   \ ----middle1_2 |       |\
                    X                        \
                   / \                        --end[End]
  -height| Height |---\--middle2_1 |Middle2| /
                       -- middle2_2|       |/

*/

#include <stdio.h>
//Include the network
#include "edk/Neural/Network.h"

int main(){
    bool sBool=false;
    //Create a network for int32 numbers (bigger and smaller then zero)
    edk::neural::Network<edk::int32> net;
    //create the entrance neurons
    net.newNeuron("Distance");
    net.newNeuron("Height");
    //add the neurons weights
    net.setNeuronWeight("Distance","distance",10);
    net.setNeuronWeight("Height","height",20);
    //create the middle neurons
    net.newNeuron("Middle1");
    net.newNeuron("Middle2");
    //add the middle neurons weights
    net.setNeuronWeight("Middle1","middle1_1",1);
    net.setNeuronWeight("Middle1","middle1_2",1);
    net.setNeuronWeight("Middle2","middle2_1",2);
    net.setNeuronWeight("Middle2","middle2_2",2);
    //connect the weights to the entrance neurons
    net.setNeuronConnection("Middle1","Distance","middle1_1");
    net.setNeuronConnection("Middle1","Height","middle1_2");
    net.setNeuronConnection("Middle2","Distance","middle2_1");
    net.setNeuronConnection("Middle2","Height","middle2_2");
    //create the end neuron (to execute the action)
    net.newNeuron("End");
    //set the end neuron weights
    net.setNeuronWeight("End","end1",1u);
    net.setNeuronWeight("End","end2",1u);
    //connect the weights to the middle neurons
    net.setNeuronConnection("End","Middle1","end1");
    net.setNeuronConnection("End","Middle2","end2");

    //print the neurons
    net.print();

    //before start the simulation, you need set the entrance values
    //set the two values
    net.setValue("Distance","distance",10);
    net.setValue("Height","height",11);

    //clean the end exit variable
    sBool=false;
    //process the network from the neuron
    net.process("End",&sBool);
    //print the result (if the end neuron is true)
    printf("\nEND %s",sBool?"true":"false");

    //in the next simulation
    //set the two values
    net.setValue("Distance","distance",12);
    net.setValue("Height","height",13);
    //you can update the value before run the simulation
    net.setValue("Distance","distance",14);

    //chean the end exit variable
    sBool=false;
    //process the network to the neuron
    net.process("End",&sBool);
    //print the result (if the end neuron is true)
    printf("\nEND %s",sBool?"true":"false");

    //in the end the destructor will release the memory used
    return 0;
}
