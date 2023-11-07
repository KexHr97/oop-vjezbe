#include <iostream>
#include "vector_functions.hpp"

void unosVektora(std::vector<int> &vektor, int brojElemenata) {
    vektor.clear();
    for (int i = 0; i < brojElemenata; ++i) {
        int broj;
        std::cout << "Unesite element #" << i + 1 << ": ";
        std::cin >> broj;
        vektor.push_back(broj);
    }
}

void unosVektora(std::vector<int> &vektor, int donjaGranica, int gornjaGranica) {
    vektor.clear();
    int broj;
    std::cout << "Unesite elemente vektora. Unesite broj izvan granica da zavrsite unos." << std::endl;
    while (true) {
        std::cout << "Unesite broj: ";
        std::cin >> broj;
        if (broj < donjaGranica || broj > gornjaGranica) {
            break;
        }
        vektor.push_back(broj);
    }
}

void ispisiVektor(std::vector<int> &vektor) {
    std::cout << "Vektor: ";
    for (int broj : vektor) {
        std::cout << broj << " ";
    }
    std::cout << std::endl;
}
