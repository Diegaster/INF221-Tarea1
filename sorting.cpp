#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <chrono>

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
// Código merge y mergesort extraídos desde:
// https://www.geeksforgeeks.org/merge-sort/
void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1; 
    int n2 = right - mid; // Primero se crean las variables n1 y n2 en base a lo entregado como parámetro, left es el extremo izquierdo del
                        // vector en esa iteración, y right es el extremo derecho.
    vector<int> L(n1), R(n2); //Se crean los vectores L y R que van a dividir el vector en 2 

    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // Se copian todos los elementos en los vectores L y R

    int i = 0; 
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) { // Aquí se copian todos los elementos de L y R al vector original, pero mediante la comparación
        if (L[i] <= R[j]) { // L[i]<=R[j], que en caso de que el elemento de la izquierda sea menor, se copia a la izquierda.
            arr[k] = L[i];
            i++;
        } else { // Sino, se copia el elemento de la derecha a la izquierda.
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { // Si algún elemento de los vectores L y/o R no se copió, estos dos ciclos while se encargan de copiarlos correctamente
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& arr, int left, int right){
    if (left >= right) // Caso base donde retornamos en caso de que el vector sea vacío (no tiene sentido un vector que inicia en 5 y termina en 5)
        return;

    int mid = left + (right - left) / 2; // Se calcula el medio del vector
    mergesort(arr, left, mid); // Se llama recursivamente con la mitad de la izquierda
    mergesort(arr, mid + 1, right); // Se llama recursivamente con la mitad de la derecha
    merge(arr, left, mid, right); // Se llama a merge para que junte los dos subvectores en la iteración correspondiente
}
// Código division y quicksort extraídos desde 
// https://www.geeksforgeeks.org/quick-sort-algorithm/
int division(vector<int> &v, int inicio, int fin){
    int pivote = v[fin]; // Se elige de pivote el fin del vector
    int i = (inicio - 1); 
    for (int j = inicio; j <= fin - 1; j++){
        if (v[j] <= pivote){ // En caso de que se encuentre un elemento <= que el pivote, se hace swap con el elemento v[i]
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[fin]); // Se hace swap entre el pivote y v[i+1], es decir, se mueve el pivote después de los elementos más pequeños.
    return (i + 1); // Se retorna la posición actual del pivote
}
void quicksort(vector<int> &v, int inicio, int fin){
    if (inicio < fin){
        int pivote = division(v, inicio, fin); // Se obtiene la posición del pivote con division()
        quicksort(v, inicio, pivote - 1); // Se llama recursivamente con la parte que está a la izquierda del pivote
        quicksort(v, pivote + 1, fin); // Se llama recursivamente con la parte que está a la derecha del pivote
    }

}
int main(){
    vector<int> vector, vector_ss, vector_ms, vector_qs, vector_s;
    string cin_txt;
    string txt_input = "sorting-";
    cin >> cin_txt;
    txt_input += cin_txt + "-dataset.txt";
    ifstream input(txt_input);
    int num;
    while (input >> num){
        vector.push_back(num);
    }
    int tam_vector = vector.size();
    vector_ss = vector;
    vector_ms = vector;
    vector_qs = vector;
    vector_s = vector;

    auto start_ss = chrono::high_resolution_clock::now();
    selsort(vector_ss);
    auto end_ss = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_ss = end_ss - start_ss;
    cout << "Tiempo de ejecución SelSort: " << duration_ss.count() << " segundos" << std::endl;
    cout << "Vector ordenado mediante SelSort: ";
    for (auto outp:vector_ss){
        cout << outp << " ";
    }
    cout << endl;
    auto start_ms = chrono::high_resolution_clock::now();
    mergesort(vector_ms, 0, (tam_vector - 1));
    auto end_ms = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_ms = end_ms - start_ms;
    cout << "Tiempo de ejecución MergeSort: " << duration_ms.count() << " segundos" << std::endl;
    cout << "Vector ordenado mediante MergeSort: ";
    for (auto outp:vector_ms){
        cout << outp << " ";
    }
    cout << endl;
    auto start_qs = chrono::high_resolution_clock::now();
    quicksort(vector_qs, 0, (tam_vector - 1));
    auto end_qs = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_qs = end_qs - start_qs;
    cout << "Tiempo de ejecución QuickSort: " << duration_qs.count() << " segundos" << std::endl;
    cout << "Vector ordenado mediante QuickSort: ";
    for (auto outp:vector_qs){
        cout << outp << " ";
    }
    cout << endl;
    auto start_s = chrono::high_resolution_clock::now();
    sort(vector_s.begin(), vector_s.end());
    auto end_s = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_s = end_s - start_s;
    cout << "Tiempo de ejecución Sort por defecto: " << duration_s.count() << " segundos" << std::endl;
    cout << "Vector ordenado mediante Sort: ";
    for (auto outp:vector_s){
        cout << outp << " ";
    }
    cout << endl;

    return 0;
}
