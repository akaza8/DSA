""" r->c;c->r
    addition of matrices
    multiplication of matrices """
def pRint(k):
    for i in range(R):
        for j in range(C):
            print(k[i][j]," ")
        print()
def displayT(m1):
    for i in range(R):
        for j in range(C):
            m1[i][j]=m1[j][i]
    pRint()
#matrix1
R = int(input("enter no of rows "))
C = int(input("input(Enter no of coloumns" ))
matrix1=[]
for i in range(R):
    a = []
    for j in range(C):
        a.append(int(input))
    matrix1.append(a)
displayT()
#matrix2
print("no of rows & coloumns becomes same ")
matrix2 = []
for i in range(R):
    a = []
    for j in range(C):
        a.append(int(input()))
    matrix2.append(a)
#multiplication
matrix = []
for i in range(R):
    a = []
    for j in range(C):
        a.append(0)
    matrix.append(a)
for i in range(R):
    for j in range(C):
        matrix[i][j]+=matrix1[i][j]*matrix2[j][i]
pRint(matrix)



