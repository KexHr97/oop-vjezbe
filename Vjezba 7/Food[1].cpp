#include "Food[1].hpp"
#include <iostream>
using namespace std;

int Food::counter = 0;

int Food::getCounter() {
	return counter;
}

void Food::changeCounter(int value) {
	counter += value;
}

void Food::printCounter() {
	cout << "Available food portions: " << counter << endl;
}
