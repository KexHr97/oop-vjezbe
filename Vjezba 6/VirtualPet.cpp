#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "VirtualPet.hpp"
#include "food.hpp"
using namespace std;

VirtualPet::VirtualPet(string& petName, string& petType)
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

int VirtualPet::getHappiness() {
	return happinessPoints;
}

int VirtualPet::getHunger() {
	return hungerPoints;
}

bool VirtualPet::isAwakeStatus() {
	return isAwake;
}

void VirtualPet::printPetStatus() {
	cout << "Name: " << name << endl; 
	cout << "Type: " << type << endl;
	cout << "Happiness: " << happinessPoints << endl;
	cout << "Hunger: " << hungerPoints << endl;
	cout << "Awake: " << (isAwake ? "Yes" : "No") << endl;
	cout << endl;
}


bool VirtualPet::operator==(const VirtualPet& other) const {
    return (this->name == other.name &&
            this->type == other.type &&
            this->happinessPoints == other.happinessPoints &&
            this->hungerPoints == other.hungerPoints &&
            this->isAwake == other.isAwake);
}

bool VirtualPet::operator!=(const VirtualPet& other) const {
    return !(*this == other);
}

VirtualPet& VirtualPet::operator=(const VirtualPet& other) {
    if (this != &other) {
        this->name = other.name;
        this->type = other.type;
        this->happinessPoints = other.happinessPoints;
        this->hungerPoints = other.hungerPoints;
        this->isAwake = other.isAwake;
    }
    return *this;
}

VirtualPet& VirtualPet::operator++() {
    this->hungerPoints -= 10;
    return *this;
}

VirtualPet VirtualPet::operator++(int) {
    VirtualPet temp = *this;
    ++(*this);
    return temp;
}

bool VirtualPet::operator<(const VirtualPet& other) const {
    return this->happinessPoints < other.happinessPoints;
}

bool VirtualPet::operator>(const VirtualPet& other) const {
    return this->happinessPoints > other.happinessPoints;
}

bool VirtualPet::operator<=(const VirtualPet& other) const {
    return this->happinessPoints <= other.happinessPoints;
}

bool VirtualPet::operator>=(const VirtualPet& other) const {
    return this->happinessPoints >= other.happinessPoints;
}

std::ostream& operator<<(std::ostream& os, const VirtualPet& pet) {
    os << "Name: " << pet.name << std::endl;
    os << "Type: " << pet.type << std::endl;
    os << "Happiness: " << pet.happinessPoints << std::endl;
    os << "Hunger: " << pet.hungerPoints << std::endl;
    os << "Awake: " << (pet.isAwake ? "Yes" : "No") << std::endl;
    return os;
}