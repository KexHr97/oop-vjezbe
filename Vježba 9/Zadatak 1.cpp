//vjezba 9.
#include<iostream>

template<typename TYPE>

TYPE min(TYPE& a, TYPE& b) {
	if (a < b)
		return a;
	else
		return b;
}

int main() {
	int a = 12;
	int b = 4;
	std::string f = "Split";
	std::string d = "Zagreb";

	std::cout << "Manji od ova dva broja je: " << min(a, b) << std::endl;
	std::cout << "Leksikografski manja od ove dvije rijeci je: " << min(f, d) << std::endl;
	return 0;
}