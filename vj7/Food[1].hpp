#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Food {
public:
	int getCounter();
	void changeCounter(int value);
	void printCounter();

private:
	int counter;
};