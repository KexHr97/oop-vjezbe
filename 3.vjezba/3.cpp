#include <iostream>
#include <vector>
using namespace std; 

void urediVektor(vector<int>& v) {
    int maxElement = v[0];
    int maxIndex = 0;


    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > maxElement) {
            maxElement = v[i];
            maxIndex = i;
        }
    }

    int suma = 0;
    for (int i = maxIndex + 1; i < v.size(); ++i) {
        suma += v[i];
    }


    v.insert(v.begin(), 0);


    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                swap(v[i], v[j]);
            }
        }
    }


    cout << "Vektor nakon sortiranja i dodavanja 0: ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Suma elemenata iza najveceg broja: " << suma << endl;
}

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    urediVektor(v);
    return 0;
}
