#include "analogIn.h"
#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char* argv[]){
	int num = stoi(argv[1]);
	AnalogIn adcPin = AnalogIn(num);

	cout << "The ADC value on pin " << num << " is " << adcPin.readADCsample() << endl;

	return 0;
}
