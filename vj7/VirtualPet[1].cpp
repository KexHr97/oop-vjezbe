#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "VirtualPet[1].hpp"
#include "Food[1].hpp"
using namespace std;

VirtualPet::VirtualPet(const string& petName, const string& petType)
	: name(petName), type(petType), happinessPoints(50), hungerPoints(50), isAwake(true) {}

void VirtualPet::eat() {
	happinessPoints += 10;
	hungerPoints -= 20;
	if (hungerPoints < 0) hungerPoints = 0;
}

void VirtualPet::sleep() {
	happinessPoints += 20;
	hungerPoints += 10;
	isAwake = false;
}

void VirtualPet::play() {
	happinessPoints += 15;
	hungerPoints += 15;

	isAwake = true;
}

int VirtualPet::getHappiness() const {
	return happinessPoints;
}

int VirtualPet::getHunger() const {
	return hungerPoints;
}

bool VirtualPet::isAwakeStatus() const {
	return isAwake;
}

string VirtualPet::getName() const {
	return name;
}

string VirtualPet::getType() const {
	return type;
}

void VirtualPet::printPetStatus() const {
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Happiness: " << happinessPoints << endl;
	cout << "Hunger: " << hungerPoints << endl;
	cout << "Awake: " << (isAwake ? "Yes" : "No") << endl;
	cout << endl;
}

bool VirtualPet::operator==(const VirtualPet& other) const {
	return name == other.name && type == other.type && happinessPoints == other.happinessPoints && hungerPoints == other.hungerPoints && isAwake == other.isAwake;
}

bool VirtualPet::operator!=(const VirtualPet& other) const {
	return !(*this == other);
}

VirtualPet& VirtualPet::operator=(const VirtualPet& other) {
	if (this != &other) {
		name = other.name;
		type = other.type;
		happinessPoints = other.happinessPoints;
		hungerPoints = other.hungerPoints;
		isAwake = other.isAwake;
	}
	return *this;
}

VirtualPet& VirtualPet::operator++() {
	hungerPoints += 5;
	Food::changeCounter(-1);
	return *this;
}

VirtualPet VirtualPet::operator++(int) {
	VirtualPet temp = *this;
	++(*this);
	return temp;
}

bool VirtualPet::operator<(const VirtualPet& other) const {
	return happinessPoints < other.happinessPoints;
}

bool VirtualPet::operator>(const VirtualPet& other) const {
	return happinessPoints > other.happinessPoints;
}

bool VirtualPet::operator<=(const VirtualPet& other) const {
	return happinessPoints <= other.happinessPoints;
}

bool VirtualPet::operator>=(const VirtualPet& other) const {
	return happinessPoints >= other.happinessPoints;
}

ostream& operator<<(ostream& os, const VirtualPet& pet) {
	os << "Name: " << pet.getName() << ", Type: " << pet.getType() << ", Happiness: " << pet.getHappiness() << ", Hunger: " << pet.getHunger() << ", Awake: " << pet.isAwakeStatus();
	return os;
}