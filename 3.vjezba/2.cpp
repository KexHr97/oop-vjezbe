#include "vector_functions.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vektor1;
    std::vector<int> vektor2;
    std::vector<int> vektor3;

    std::cout << "Unos vektora s određenim brojem elemenata:" << std::endl;
    unosVektora(vektor1, 5);
    ispisiVektor(vektor1);

    std::cout << "Unos vektora u određenom intervalu:" << std::endl;
    unosVektora(vektor2, 1, 10);
    ispisiVektor(vektor2);

    for (int broj : vektor1) {
        if (std::find(vektor2.begin(), vektor2.end(), broj) == vektor2.end()) {
            vektor3.push_back(broj);
        }
    }

    std::cout << "Treći vektor (elementi prvog vektora koji nisu dio drugog vektora):" << std::endl;
    ispisiVektor(vektor3);

    return 0;
}
