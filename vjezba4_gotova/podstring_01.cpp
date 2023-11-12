#include <iostream>
#include <string>

using namespace std;

int brojPojavljivanjaPodstringa(string& glavniString, string& podstring) {
    int brojac = 0;
    int pozicija = glavniString.find(podstring); 

    while (pozicija != string::npos) {
        brojac++;
        pozicija = glavniString.find(podstring, pozicija + 1);
    }

    return brojac;
}

int main() {
    string glavniString = "primjer stringa u recenici sa stringom";
    string podstring = "e";

    int brojPojavljivanja = brojPojavljivanjaPodstringa(glavniString, podstring);
    cout << "Broj pojavljivanja podstringa u glavnom stringu: " << brojPojavljivanja << endl;

    return 0;
}
