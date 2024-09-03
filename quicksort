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
