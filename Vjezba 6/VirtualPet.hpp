#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "food.hpp"
using namespace std;

class VirtualPet {
private:
	string name;
	string type;
	int happinessPoints;
	int hungerPoints;
	bool isAwake;

public:
	VirtualPet(string& petName, string& petType);

	void eat();
	void sleep();
	void play();

	int getHappiness();
	int getHunger();
	bool isAwakeStatus();

	void printPetStatus();

    bool operator==(VirtualPet& other);
    bool operator!=(VirtualPet& other);
    VirtualPet& operator=(VirtualPet& other);
    VirtualPet& operator++();  
    VirtualPet operator++(int); // Postfiksni inkrement
    bool operator<(VirtualPet& other);
    bool operator>(VirtualPet& other);
    bool operator<=(VirtualPet& other);
    bool operator>=(VirtualPet& other);

    friend ostream& operator<<(ostream& os, VirtualPet& pet);
};

