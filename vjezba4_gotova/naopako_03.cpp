#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void obrtaj(vector <string> &vec)
{
    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++)
    {
        reverse(vec[i].begin(), vec[i].end());
    }
}

int main()
{
    vector<string> vec{};

    vec.push_back("automobil");
    vec.push_back("novi string");
    vec.push_back("bivol");

    cout << "Prije: " << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    obrtaj(vec);

    cout << "Nakon: "  << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    return 0;
}