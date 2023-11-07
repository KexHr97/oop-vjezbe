#include <iostream>
#include <vector>
using namespace std;

int& povecaj(int* niz, int index)
{
    return niz[index];
}


int main()
{
    int niz[5] = {1,2,3,4,5};
    int index = 2;

    povecaj(niz, index)++;

    for(int i = 0; i < 5; i++)
    {
        cout << niz[i]  << " ";
    }

    return 0;
}