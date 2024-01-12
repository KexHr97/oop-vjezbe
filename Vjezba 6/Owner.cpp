#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "food.hpp"
#include "Owner.hpp"
using namespace std;

Owner::Owner(string& ownerName, vector<VirtualPet*>& ownerPets)
	: name(ownerName), pets(ownerPets) {}

Owner::Owner(Owner& other) : name(other.name) {
	for ( auto& pet : other.pets) {
		pets.push_back(new VirtualPet(*pet));
	}
}

Owner::~Owner() {
	for (auto& pet : pets) {
		delete pet;
	}
}

void Owner::performActions() {
	for (auto& pet : pets) {
		int action = rand() % 3;
		if (action == 0) {
			pet->eat();
			//break;
		}
		else if (action == 1) {
			pet->sleep();
			//break;
		}
		else if (action == 2) {
			pet->play();
			//break;
		}
	}
}

void Owner::printOwnerStatus() {
	for ( auto& pet : pets) {
		cout << "Owner: " << name << endl;
		pet->printPetStatus();
	}
}

int Owner::findHappiestPetIndex() {
	auto maxHappinessPet = max_element(pets.begin(), pets.end(),
		[]( VirtualPet* a,  VirtualPet* b) {
		return a->getHappiness() < b->getHappiness();
	});

	return distance(pets.begin(), maxHappinessPet);
}
Owner::Owner(Owner&& other) : name(move(other.name)), pets(move(other.pets)) {
	other.pets.clear();
}
