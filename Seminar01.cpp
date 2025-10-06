#include <iostream>

using namespace std;

void incPrinValoare(int x){
    x++;
}

void incPrinAdresa(int* x){
    *x = *x +1;
}

void incPrinReferinta(int& x){
    x = x +1;
}

int main(){

    int x =5;

    cout << "Val initiala a lui x: " << x<< endl;

    incPrinValoare(x);

    cout << "[Valoare] Val lui x: " << x << endl;

    incPrinAdresa(&x);

    cout << "[Adresa] Val lui x: " << x << endl;

    incPrinReferinta(x);

    cout << "[Referinta] Val lui x: " << x << endl;
    

    // int v[3];
    // int* v = (int*)malloc(3 * sizeof(int));
    int* v = new int[3];

    for(int i= 0;i<3;i++){
        cout << "v[" << i << "]=";
        cin >> v[i];
        cout << endl;
    }

    for(int i= 0;i<3;i++){
        cout << "v[" << i << "]="<<v[i] << endl;;
    }

    cout << "Primul element: " << v[0] <<endl;
    cout << "Primul element: " << *v <<endl;
    cout << "Al doilea element: " << *(v+1) <<endl;
    cout << "Al doilea element: " << v[1] <<endl;
    cout << "Al doilea element: " << 1[v] <<endl;

    int* q = new int;
    delete q;

    delete[] v;

    v = nullptr;
    q = NULL;

    return 0;
}