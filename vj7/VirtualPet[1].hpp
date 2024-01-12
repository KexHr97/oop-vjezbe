#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class VirtualPet{
private:
	string name;
	string type;
	int happinessPoints;
	int hungerPoints;
	bool isAwake;

public:
	VirtualPet(const string& petName, const string& petType);

	bool operator==(const VirtualPet& other) const;
	bool operator!=(const VirtualPet& other) const;
	VirtualPet& operator=(const VirtualPet& other);
	VirtualPet& operator++();
	VirtualPet operator++(int);
	bool operator<(const VirtualPet& other) const;
	bool operator>(const VirtualPet& other) const;
	bool operator<=(const VirtualPet& other) const;
	bool operator>=(const VirtualPet& other) const;
	friend ostream& operator<<(ostream& os, const VirtualPet& pet);


	void eat();
	void sleep();
	void play();

	int getHappiness() const;
	int getHunger() const;
	bool isAwakeStatus() const;
	string getName() const;
	string getType() const;

	void printPetStatus() const;
	
};
