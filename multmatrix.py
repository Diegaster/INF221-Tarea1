import time
import numpy as np


def leer_matrix(path_archivo): #Función creada para leer ambas matrices generadas, las guarda como listas de listas
    with open(path_archivo, 'r') as archivo:
        lineas = archivo.readlines() #Primero se encarga de leer todas las lineas y guardarlas en "lineas"
    
    matriz = []
    for linea in lineas:
        fila = list(map(int, linea.strip().split())) #Luego las recorre y las guarda en la matriz
        matriz.append(fila)
    
    return matriz

def trasponerMatriz(matr, R, C): #Función que se encarga de trasponer la segunda matriz entregada
    traspuesta = [[0] * R for _ in range(C)]
    for i in range(R):
        for j in range(C):
            traspuesta[j][i] = matr[i][j]
    return traspuesta
#Código modificado desde
#https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
def mulMat_T(mat1, mat2, R1, R2, C2):
    mat2_traspuesta = trasponerMatriz(mat2, R2, C2) #Primero se encarga de llamar a la funcion que traspone la matriz
    rslt = [[0] * C2 for _ in range(R1)]
    for i in range(R1):
        for j in range(C2):
            for k in range(R2):
                rslt[i][j] += mat1[i][k] * mat2_traspuesta[j][k] #Luego obtiene el resultado con el triple ciclo for
    return rslt
#Código extraído desde
#https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
def mulMat(mat1, mat2, R1, R2, C1, C2):
    rslt = [[0] * C2 for _ in range(R1)] #Crea la matriz resultado
    for i in range(R1):
        for j in range(C2):
            for k in range(C1):
                rslt[i][j] += mat1[i][k] * mat2[k][j] #Luego obtiene el resultado con el triple ciclo for
    return rslt
#Código extraído desde
#https://www.geeksforgeeks.org/strassens-matrix-multiplication-algorithm-implementation/
def strassen(A, B):
    n = A.shape[0]
    if n == 1: #Caso base donde el tamaño de la matriz A es 1
        return A * B
    else:
        mid = n // 2
        A11, A12, A21, A22 = A[:mid, :mid], A[:mid, mid:], A[mid:, :mid], A[mid:, mid:] #Se dividen ambas matrices en 4
        B11, B12, B21, B22 = B[:mid, :mid], B[:mid, mid:], B[mid:, :mid], B[mid:, mid:]
        P1 = strassen(A11 + A22, B11 + B22) #Se calculan los 7 subproblemas de strassen
        P2 = strassen(A21 + A22, B11)
        P3 = strassen(A11, B12 - B22)
        P4 = strassen(A22, B21 - B11)
        P5 = strassen(A11 + A12, B22)
        P6 = strassen(A21 - A11, B11 + B12)
        P7 = strassen(A12 - A22, B21 + B22)
        C11 = P1 + P4 - P5 + P7 #Luego se juntan en los 4 cuadrantes 
        C12 = P3 + P5
        C21 = P2 + P4
        C22 = P1 + P3 - P2 + P6
        C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22)))) #Se mezclan los 4 cuadrantes en una matriz
        return C

def main():
    mat1 = leer_matrix('C:/Users/munoz/Desktop/proyectos/INF221/tarea1/matrix1-randomgen.txt') #IMPORTANTE: Al momento de querer ejecutar el código,
    mat2 = leer_matrix('C:/Users/munoz/Desktop/proyectos/INF221/tarea1/matrix2-randomgen.txt') #Se deben actualizar estos datos tipo string 

    R1 = len(mat1)
    C1 = len(mat1[0])
    R2 = len(mat2)
    C2 = len(mat2[0])

    if C1 != R2:
        print("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda.")
        return

    #Conversión hecha para permitir Strassen
    A = np.array(mat1)
    B = np.array(mat2)

    #Cálculo de tiempos de ejecución y printeo de las matrices resultantes
    start_time = time.time()
    result_mulMat = mulMat(mat1, mat2, R1, R2, C1, C2)
    print("Tiempo del algoritmo iterativo normal:", time.time() - start_time)
    for fila in result_mulMat:
        print(fila)
    start_time = time.time()
    result_mulMat_T = mulMat_T(mat1, mat2, R1, R2, C2)
    print("Tiempo del algoritmo iterativo normal con la matriz traspuesta:", time.time() - start_time)
    for fila in result_mulMat_T:
        print(fila)
    start_time = time.time()
    n = max(A.shape[0], A.shape[1], B.shape[0], B.shape[1])
    m = 1
    while m < n:
        m *= 2
    A_padded = np.pad(A, ((0, m - A.shape[0]), (0, m - A.shape[1])), mode='constant')
    B_padded = np.pad(B, ((0, m - B.shape[0]), (0, m - B.shape[1])), mode='constant')
    C = strassen(A_padded, B_padded)
    print("Tiempo del algoritmo Strassen:", time.time() - start_time)
    for fila in C:
        print(fila)
if __name__ == "__main__":
    main()
