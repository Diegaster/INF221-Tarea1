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
        C11 = P1 + P4 - P5 + P7 #Luego se hacen las operaciones correspondientes para obtener los 4 cuadrantes 
        C12 = P3 + P5
        C21 = P2 + P4
        C22 = P1 + P3 - P2 + P6
        C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22)))) #Se mezclan los 4 cuadrantes en una matriz
        return C
