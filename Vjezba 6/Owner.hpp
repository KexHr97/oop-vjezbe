#include <iostream>
#include <vector>
#include <string>
#include <algorithm>	
#include "food.hpp"
#include "VirtualPet.hpp"
using namespace std;

class Owner {
private:
	string name;
	vector<VirtualPet*> pets;

public:
	Owner(string& ownerName, vector<VirtualPet*>& ownerPets);
	Owner(Owner& other);
	~Owner();

	void performActions();

	void printOwnerStatus();

	int findHappiestPetIndex();


	Owner(Owner&& other);
};
