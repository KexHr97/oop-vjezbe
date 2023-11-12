#include <iostream>
#include <string>


using namespace std;

bool jeInterpunkcija(char znak) {
    string interpunkcija = ".,;:!?";
    return interpunkcija.find(znak) != string::npos;
}

string ispraviRecenicu(string& recenica) {
    string ispravljenaRecenica;
    bool dodajRazmak = false; 

    for (char znak : recenica) {
        if (isspace(znak)) {
            dodajRazmak = true;
        } else if (jeInterpunkcija(znak)) {
            ispravljenaRecenica += znak;
            dodajRazmak = true;
        } else {
            if (dodajRazmak) {
                ispravljenaRecenica += " ";
                dodajRazmak = false;
            }
        ispravljenaRecenica += znak;
        }
    }

    return ispravljenaRecenica;
}

int main() {
    string recenica;
    cout << "Unesite recenicu: ";
    getline(cin, recenica);

    string ispravljenaRecenica = ispraviRecenicu(recenica);
    cout << "Ispravljena recenica: " << ispravljenaRecenica << endl;

    return 0;
}
