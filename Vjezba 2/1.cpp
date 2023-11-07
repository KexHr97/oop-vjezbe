#include <iostream>
using namespace std;

void higher_lower(int& L, int& H, int arr[])
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if(H <= arr[i])
            H=arr[i];

        if(L >=arr[i])
            L = arr[i];
    }
}

int main()
{
    int arr[5] = {2,1,4,7,5};

    int test_lower = arr[0];
    int test_higher = arr[0];
    int& H = test_higher;
    int& L = test_lower;

    higher_lower(L, H, arr);

    cout << test_higher << "\n" << test_lower;
}