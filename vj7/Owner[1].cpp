#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Owner[1].hpp"
using namespace std;

Owner::Owner(const string& ownerName, const vector<VirtualPet*>& ownerPets)
	: name(ownerName), pets(ownerPets) {}

Owner::Owner(const Owner& other) : name(other.name) {
	for (const auto& pet : other.pets) {
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
			break;
		}
		else if (action == 1) {
			pet->sleep();
			break;
		}
		else if (action == 2) {
			pet->play();
			break;
		}
	}
}

void Owner::printOwnerStatus() const {
	for (const auto& pet : pets) {
		cout << "Owner: " << name << endl;
		pet->printPetStatus();
	}
}

int Owner::findHappiestPetIndex() const {
	auto maxHappinessPet = max_element(pets.begin(), pets.end(),
		[](const VirtualPet* a, const VirtualPet* b) {
		return a->getHappiness() < b->getHappiness();
	});

	return distance(pets.begin(), maxHappinessPet);
}
Owner::Owner(Owner&& other) noexcept : name(move(other.name)), pets(move(other.pets)) {
	other.pets.clear();
}
