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
