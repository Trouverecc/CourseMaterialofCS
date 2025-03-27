import numpy
from numpy import linalg
import copy
import random



def randomList(dimension, limit: list):
    assert (len(limit) == 2)
    if (limit[0] > limit[1]): limit[0], limit[1] = limit[1], limit[0]
    matrix = []
    b = []
    for i in range(0, dimension):
        row = []
        for j in range(0, dimension):
            row.append(random.randint(limit[0], limit[1]))
        matrix.append(row)
        b.append(random.randint(limit[0], limit[1]))
    assert (len(matrix) == dimension and len(matrix[0]) == dimension)
    return matrix, b


# 矩阵
testx = [
    [31, -13, 0, 0, 0, -10, 0, 0, 0],
    [-13, 35, -9, 0, -11, 0, 0, 0, 0],
    [0, -9, 31, -10, 0, 0, 0, 0, 0],
    [0, 0, -10, 79, -30, 0, 0, 0, -9],
    [0, 0, 0, -30, 57, -7, 0, -5, 0],
    [0, 0, 0, 0, -7, 47, -30, 0, 0],
    [0, 0, 0, 0, 0, -30, 41, 0, 0],
    [0, 0, 0, 0, -5, 0, 0, 27, -2],
    [0, 0, 0, -9, 0, 0, 0, -2, 29]
]
testy = [-15, 27, -23, 0, -20, 12, -7, 7, 10]
testx = [[30, 33, -43, -11, -38, -29, 37, 28, 23],
         [-480, -523, 644, 128, 621, 480, -618, -489, -329],
         [60, 266, -1862, -1991, 464, 546, -968, -1567, 1652],
         [540, 624, -782, 290, -893, 123, 567, 5, -122],
         [-450, -675, 2245, 2326, -1512, 1230, -822, 129, -189],
         [-300, -120, -1114, -1295, 1946, 302, -376, -1540, -609],
         [1080, 998, 508, 2460, -1628, -1358, 2896, 2828, -2002],
         [-1080, -1408, 3340, 2267, 21, -1202, 866, -2690, -1351],
         [-300, -435, 1594, 1685, 340, 2279, -27, 2917, -2336]]

testy = [188, -3145, -4994, 680, 7845, 1876, 9712, -11599, 10127]

# 矩阵阶数
n = 20
A, b = randomList(n, [100, 10])
copyx = copy.deepcopy(testx)
copyy = copy.deepcopy(testy)
copyx = copy.deepcopy(A)
copyy = copy.deepcopy(b)

rawmax = len(A)
colmax = len(b)


def prinfResult(Matrix: list):
    print("[ ", end='')
    for elm in Matrix:
        print(" ", elm, ",", end='')
    print(" ]")


# 回代判断
def config(relist, result, rey):
    for i in range(len(relist)):
        y = 0
        for j in range(0, len(relist[i])):
            y += relist[i][j] * result[j]
        assert (abs(y - rey[i]) < 0.1)
    print("误差小于0.1")


# 列主元素
def swag(scalex, row, col):
    assert (row == col)
    if (row == rawmax - 1):
        return
    index = row
    temp = abs(scalex[row][col])
    for i in range(row + 1, rawmax):
        if (abs(scalex[i][col]) > temp):
            temp = abs(scalex[i][col])
            index = i
    if (index == row):
        return
    scalex[row], scalex[index] = scalex[index], scalex[row]
    b[row], b[index] = b[index], b[row]


# 消元
def elimitlist(scalex, row, col):
    swag(scalex, row, col)
    base = scalex[row][col]
    if (base == 0):
        print("列主元素为0")
    for i in range(row + 1, rawmax):
        if (scalex[i][col] == 0):
            continue
        temp = scalex[i][col] / base
        scalex[i][col] = 0
        for j in range(col + 1, colmax):
            scalex[i][j] -= temp * scalex[row][j]
        b[i] -= temp * b[row]
    return


# 解下三角矩阵
def funcdown(scalex: list, scaley: list):
    resultList = []
    assert (len(scalex) == len(scaley))
    for i in range(len(scaley) - 1, -1, -1):
        if (i == len(scaley) - 1):
            resultList.append(scaley[i] / scalex[i][i])
            continue
        rightValue = scaley[i]
        for j in range(i + 1, len(scaley)):
            rightValue -= scalex[i][j] * resultList[len(scaley) - j - 1]
        resultList.append(rightValue / scalex[i][i])
    resultList.reverse()
    return resultList


# 解上三角矩阵
def funcup(scalex: list, scaley: list):
    resultList = []
    assert (len(scalex) == len(scaley))
    mLen = len(scalex)
    for i in range(0, mLen):
        if (i == 0):
            resultList.append(scaley[i] / scalex[i][i])
            continue
        rightValue = scaley[i]
        for j in range(0, i):
            rightValue -= scalex[i][j] * resultList[j]
        resultList.append(rightValue / scalex[i][i])
    return resultList


# 高斯消元法
def gassinlist(scalex):
    for i in range(0, rawmax):
        elimitlist(scalex, i, i)
    result = funcdown(scalex, b)
    return result


# LU分解法
def LU(scalex):
    length = len(scalex)
    L = numpy.zeros((length, length))
    U = numpy.zeros((length, length))
    # L矩阵的列主元素均为1
    for i in range(0, length):
        L[i][i] = 1
    for i in range(0, length):
        if (i == 0):
            for j in range(0, len(scalex)):
                U[0][j] = scalex[0][j]
                if j == 0: continue
                L[j][0] = scalex[j][0] / U[0][0]
        else:
            # 先计算U矩阵
            for j in range(i, length):
                right = scalex[i][j]
                for k in range(0, i):
                    right -= L[i][k] * U[k][j]
                U[i][j] = right
            if (i == length - 1): break
            # 在计算L矩阵
            for j in range(i + 1, length):
                right = scalex[j][i]
                for k in range(0, i):
                    right -= L[j][k] * U[k][i]
                if (U[i][i] == 0):
                    print("主元素为0")
                L[j][i] = right / U[i][i]
    temp = numpy.dot(L, U)
    for i in range(len(temp)):
        for j in range(len(temp[0])):
            assert (abs(temp[i][j] - scalex[i][j]) < 0.1)
    # print("L矩阵为")
    # print(L)
    # print("U矩阵为")
    # print(U)
    y = funcup(L, copyy)
    ansy = linalg.solve(L, copyy)
    resultList = funcdown(U, y)
    ans = linalg.solve(U, y)
    return resultList


if __name__ == "__main__":
    resultList = gassinlist(A)
    print(resultList)
    config(copyx, resultList, copyy)
    res = linalg.solve(copyx, copyy)
    prinfResult(res)

    resultList = LU(copyx)
    prinfResult(resultList)
    config(copyx, resultList, copyy)
    res = linalg.solve(copyx, copyy)
    prinfResult(res)