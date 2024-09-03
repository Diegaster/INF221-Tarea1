#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

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
