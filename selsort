#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Código selsort entregado por el profesor en clases, modificado en la parte final (el if junto con el swap)
void selsort (vector<int> &v){
    for (int e = 0; e < (v.size() - 1); e++){ // Primer índice que va revisando desde el inicio del vector hasta n-1
        int m = e; // Variable mínimo que indica el menor valor encontrado
        for (int f = e + 1; f < v.size(); f++){ // Segundo índice que va revisando desde la posición siguiente al primer índice hasta n
            if (v[f] < v[m]){
                m = f; // En caso de que el segundo índice encuentre un valor menor, la variable mínimo cambia la posición
            }
        }
        if (m != e){
            swap(v[m], v[e]); // En caso de que el mínimo no se encuentre en la posición del primer índice, se hace un swap
        }
    }
}
