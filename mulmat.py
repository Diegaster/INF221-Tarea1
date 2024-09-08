#Código extraído desde
#https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
def mulMat(mat1, mat2, R1, R2, C1, C2):
    rslt = [[0] * C2 for _ in range(R1)] #Crea la matriz resultado
    for i in range(R1):
        for j in range(C2):
            for k in range(C1):
                rslt[i][j] += mat1[i][k] * mat2[k][j] #Luego obtiene el resultado con el triple ciclo for
    return rslt
