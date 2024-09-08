#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int cant_filas_1, cant_col_1_fil_2, cant_col_2;
    cin >> cant_filas_1 >> cant_col_1_fil_2 >> cant_col_2;
    ofstream matrix_1("matrix1-randomgen.txt");
    ofstream matrix_2("matrix2-randomgen.txt");
    int randomnum = rand() % 10000;

    for (int i = 0; i < cant_filas_1; i++){
        for (int j = 0; j < cant_col_1_fil_2; j++){
            matrix_1 << randomnum << " ";
            randomnum = rand() % 10000;
        }
        matrix_1 << endl;
    }
    matrix_1.close();
    for (int i = 0; i < cant_col_1_fil_2; i++){
        for (int j = 0; j < cant_col_2; j++){
            matrix_2 << randomnum << " ";
            randomnum = rand() % 10000;
        }
        matrix_2 << endl;
    }
    matrix_2.close();
    return 0;
}
