#include "vector_functions.hpp"
#include <iostream>

int main() {
    std::vector<int> vektor1;
    std::vector<int> vektor2;
    
    std::cout << "Unos vektora s određenim brojem elemenata:" << std::endl;
    unosVektora(vektor1, 5);
    ispisiVektor(vektor1);

    std::cout << "Unos vektora u određenom intervalu:" << std::endl;
    unosVektora(vektor2, 1, 10);
    ispisiVektor(vektor2);

    return 0;
}
