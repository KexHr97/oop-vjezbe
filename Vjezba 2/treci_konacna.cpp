#include <iostream>
#include <vector>
using namespace std;

    

struct Vektor
{
    int* element = nullptr;
    int logicka_velicina = 1;
    int fizicka_velicina = 0;

    

    void vector_delete(){
        delete[] element;
    }

    int vector_size(){
        return fizicka_velicina;
    }

    int vector_front(){
        return element[0];
    }

    int vector_back(){
        return element[fizicka_velicina -1];
    }


    int vector_push_back(int unos){
        if (logicka_velicina <= fizicka_velicina){
            int* novi_element = new int[logicka_velicina * 2];
            for (int i = 0; i < fizicka_velicina; i++){
                novi_element[i] = element[i];
            }
            delete[] element;
            element = novi_element;
            
        }
        element[fizicka_velicina] = unos;
        fizicka_velicina++;
    }

    int vector_pop_back(){
        if (fizicka_velicina > 0){
            fizicka_velicina--;
        }
        else{
            cout << "Prazan vektor!" << endl;
        }
    }




};

int main()
{
    Vektor v;
    v.element = new int [v.logicka_velicina * 2];
    
    v.vector_push_back(1);
    v.vector_push_back(3);
    v.vector_push_back(4);

    

    cout << "Prvi: " << v.vector_front() << endl;
    cout << "zadnji: " << v.vector_back() << endl;
    cout << "Velicina: " << v.vector_size() << endl;

    v.vector_pop_back();

    cout << "Prvi: " << v.vector_front() << endl;
    cout << "zadnji: " << v.vector_back() << endl;
    cout << "Velicina: " << v.vector_size() << endl;


    v.vector_delete();

    return 0;

}