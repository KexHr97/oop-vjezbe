#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ukloniElement(vector<int>& vektor, int vr) {
    vektor.erase(remove(vektor.begin(), vektor.end(), vr), vektor.end());
}

int main() {
    vector<int> vektor = {1, 2, 3, 4, 5, 3, 6};
    int elementZaUklanjanje = 3;
    
    cout << "Prije:  ";
    for(int i = 0; i < vektor.size(); i++)
    {
        cout << vektor[i] << " ";
    }
    cout << endl;
    
    ukloniElement(vektor, elementZaUklanjanje);
    
    cout << "Nakon: ";
    for(int i = 0; i < vektor.size(); i++)
    {
        cout << vektor[i] << " ";
    }
    cout << endl;
    
    return 0;
}
