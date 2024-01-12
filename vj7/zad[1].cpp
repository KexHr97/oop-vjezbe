#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Enemy {
protected:
	string name;
	int health;
	int damage;
public:

	Enemy(string name, int health, int damage) : name(name) {
		if (health < 0) {
			throw invalid_argument("Health must be > 0!");
		}
		if (damage < 0) {
			throw invalid_argument("Damage must be > 0!");
		}
		this->health = health;
		this->damage = damage;
	}

	virtual void displayInfo() {
		cout << "Enemy: " << name << endl << "Health: " << health << endl << "Damage: " << damage << endl;
	}

	virtual void attack() {
		cout << "Enemy attacks and deals " << damage << " damage!" << endl;
	}
};


class Boss : public Enemy {
private:
	string weapon;
public:
	Boss(string name, int health, int damage, const string weapon) : Enemy(name, health, damage) {
		if (weapon.empty()) {
			throw invalid_argument("Weapon can't be empty!");
		}
		this->weapon = weapon;
	}
	void attack() override {
		cout << "Boss attacks with " << weapon << " and deals " << damage << endl;
	}
	void displayInfo() override{
		cout << "Boss: " << name << endl << "Health: " << health << endl << "Damage: " << damage << endl << "Weapon: " << weapon << endl;
	}
};


class Monster : public Enemy {
private:
	string ability;
public:
	Monster(string name, int health, int damage, const string ability) : Enemy(name, health, damage) {
		if (ability.empty()) {
			throw invalid_argument("Ability can't be empty!");
		}
		this->ability = ability;
	}
	void attack() override {
		cout << "Monster uses " << ability << endl;
	}
	void displayInfo() override{
		cout << "Monster: " << name << endl << "Health: " << health << endl << "Damage: " << damage << endl << "Ability: " << ability << endl;
	}
};

int main() {
	vector<Enemy*> enemies;
	enemies.push_back(new Boss("Dragon", 250, 70, "fire-breath"));
	enemies.push_back(new Boss("Troll", 50, 10, "club smash"));
	enemies.push_back(new Monster("Wolf", 10, 5, "bite"));
	enemies.push_back(new Monster("Vampire", 20, 10, "punch"));

	for (auto& enemy : enemies) {
		enemy->displayInfo();
		enemy->attack();
		cout << endl;
	}


	for (auto& enemy : enemies) {
		delete enemy;
	}

	return 0;
}