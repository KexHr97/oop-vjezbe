#ifndef FOOD_HPP
#define FOOD_HPP
#include <iostream>
using namespace std;
class Food {
private:
    int counter;

public:
    void changeCounter(int value) {
        counter += value;
    }

    static void printCounter() {
        cout << "Counter value: " << counter <<endl;
    }

    friend int get_counter();
};

int Food::counter = 0;

int get_counter() {
    return Food::counter;
}

#endif
