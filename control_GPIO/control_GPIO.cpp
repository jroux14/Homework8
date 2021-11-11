/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2018
* ISBN 9781119533160. Please see the file README.md in the repository root
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"

using namespace std;

int main(int argc, char* argv[]){

   if(argc != 4){
      cout << "Proper usage: ./control_GPIO [outNum] [STATE] [inNum]" << endl;
   }else{
      int outPin = stoi(argv[1]);
      int inPin = stoi(argv[3]);
      string state(argv[2]);
      GPIO outGPIO(outPin), inGPIO(inPin);

      outGPIO.setDirection(OUTPUT);
      if(state == "HIGH" || state == "high"){
         outGPIO.setValue(HIGH);
      }else if(state == "LOW" || state == "low"){
         outGPIO.setValue(LOW);
      }else{
         cout << "Invalid State" << endl;
      }
      cout << "The output is: " << outGPIO.getValue() << "Direction: " << outGPIO.getDirection() << endl;

      inGPIO.setDirection(INPUT);
      cout << "GPIO46 direction is: " << inGPIO.getDirection() << endl;
      cout << "The input value is: " << inGPIO.getValue() << endl;
   }
  
   return 0;
}
