#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Owner[1].hpp"
#include "Food[1].hpp"
using namespace std;

int main() {

	Food::changeCounter(10);
	Food::printCounter();

	VirtualPet* pet1 = new VirtualPet("Whiskers", "Cat");
	VirtualPet* pet2 = new VirtualPet("Buddy", "Dog");
	VirtualPet* pet3 = new VirtualPet("Alvin", "Hamster");
	VirtualPet* pet4 = new VirtualPet("Rodger", "Rabbit");

	vector<VirtualPet*> owner1Pets = { pet1, pet3 };
	Owner owner1("Ante", owner1Pets);

	vector<VirtualPet*> owner2Pets = { pet2, pet4 };
	Owner owner2("Boban", owner2Pets);

	owner1.performActions();
	owner2.performActions();

	owner1.printOwnerStatus();
	owner2.printOwnerStatus();

	Owner owner3 = owner2;
	Owner owner4(owner1);

	vector<Owner> owners = { owner1, owner2 };
	int maxHappy = -1;
	int HappyPetIndex = -1;
	for (int i = 0; i < owners.size(); ++i) {
		int currentHappy = owners[i].findHappiestPetIndex();
		if (currentHappy > maxHappy) {
			maxHappy = currentHappy;
			HappyPetIndex = i;
		}
	}
	cout << "Happiest pet index: " << HappyPetIndex << endl << endl;

	return 0;
}
