import numpy as np
import math
import copy
import random
from scipy import linalg
from numpy import random

n = 20
A = np.array([
    [31, -13, 0, 0, 0, -10, 0, 0, 0],
    [-13, 35, -9, 0, -11, 0, 0, 0, 0],
    [0, -9, 31, -10, 0, 0, 0, 0, 0],
    [0, 0, -10, 79, -30, 0, 0, 0, -9],
    [0, 0, 0, -30, 57, -7, 0, -5, 0],
    [0, 0, 0, 0, -7, 47, -30, 0, 0],
    [0, 0, 0, 0, 0, -30, 41, 0, 0],
    [0, 0, 0, 0, -5, 0, 0, 27, -2],
    [0, 0, 0, -9, 0, 0, 0, -2, 29]
])
B = np.array([[-15], [27], [-23], [0], [-20], [12], [-7], [7], [10]])

epc = 10 ** -8
row = len(A)
col = len(B)


# row = len(textx)
##col = len(texty)

def _get_D(listnext):
    D = np.zeros((row, col))
    for i in range(row):
        for j in range(col):
            if (i == j):
                D[i][j] = listnext[i][j]
    return D


def _get_L(listnext):
    L = np.zeros((row, col))
    for i in range(row):
        for j in range(col):
            if (i > j):
                L[i][j] = -listnext[i][j]
    return L


def _get_U(listnext):
    U = np.zeros((row, col))
    for i in range(row):
        for j in range(col):
            if (i < j):
                U[i][j] = -listnext[i][j]
    return U


# 矩阵转置
def _get_T(listnext):
    rowt = len(listnext)
    colt = len(listnext)
    for i in range(rowt):
        for j in range(colt):
            if (i >= j):
                temp = listnext[i][j]
                listnext[i][j] = listnext[j][i]
                listnext[j][i] = temp


def _get_0(listnext, listnext2):
    row1 = listnext.shape[0]
    col1 = listnext.shape[1]
    row2 = listnext2.shape[0]
    col2 = listnext2.shape[1]
    print(row1)
    print(col1)
    print(row2)
    print(col2)
    if (col1 != row2):
        return
    else:
        temp = np.zeros((row1, col2))
        for i in range(row1):
            for j in range(col2):
                sum = 0
                for m in range(col1):
                    sum += listnext[i][m] * listnext2[m][j]
                temp[i][j] = sum
    return temp



def gassin_serd(a, b, x, nextx, time, k):
    k = 0
    lenx = len(x)
    while (time):
        for i in range(lenx):
            sum = 0
            for j in range(i + 1, lenx):
                # if(i!=j):
                sum += x[j] * a[i][j]
            for j in range(i):
                sum += nextx[j] * a[i][j]
            nextx[i] = ((b[i] - sum) / a[i][i])
        time = time - 1
        k = k + 1
        temp = 0
        for i in range(lenx):
            if (abs(x[i] - nextx[i]) > temp):
                temp = abs(x[i] - nextx[i])
        # print("第",k,"次的误差为",temp)
        if (temp < epc):
            print("高斯-塞德尔迭代循环次数为", k)
            return nextx
        else:
            x = nextx.copy()


def SOR(a, b, x, nextx, time, k, w):
    k = 0
    lenx = len(x)
    while (time):
        for i in range(lenx):
            sum = 0
            for j in range(i, lenx):
                # if(i!=j):
                sum += x[j] * a[i][j]
            for j in range(i):
                sum += nextx[j] * a[i][j]
            nextx[i] = x[i] + w * ((b[i] - sum) / a[i][i])
        # print(nextx)
        time = time - 1
        k = k + 1
        temp = 0
        for i in range(lenx):
            if (abs(x[i] - nextx[i]) > temp):
                temp = abs(x[i] - nextx[i])
        # print("第",k,"次的误差为",temp)
        if (temp < epc):
            print("SOR循环次数为", k)
            return nextx
        else:
            x = nextx.copy()


def checkit(loads, oldlds, tol, converged):
    # 检查前后两个量的收敛性
    neq = loads.shape[0]
    big = 0.0
    converged[:] = True
    for i in range(1, neq + 1):
        if abs(loads[i - 1, 0]) > big:
            big = abs(loads[i - 1, 0])
    for i in range(1, neq + 1):
        if abs(loads[i - 1, 0] - oldlds[i - 1, 0]) / big > tol:
            converged[:] = False


if __name__ == "__main__":
    time = 500
    k = 0
    scalex = np.zeros(col)
    nextx = np.zeros(col)
    res = linalg.solve(A, B)
    print("标准结果为")
    print(res)
    D = _get_D(A)
    L = _get_L(A)
    U = _get_U(A)

    # 高斯-塞德尔迭代法
    t = D - L
    t_inv = np.linalg.inv(t)
    G = np.dot(t_inv, U)
    a, b = np.linalg.eig(G)
    p = np.max(np.abs(a))
    if (p < 1):
        print("谱半径小于1,收敛")
        res2 = gassin_serd(A, B, scalex, nextx, time, k)
        print(res2)
    # w为松弛因子
    w = 1.5
    t = D - w * L
    s = (1 - w) * D + w * U
    t_inv = np.linalg.inv(t)
    L = np.dot(t_inv, s)
    a, b = np.linalg.eig(L)
    p = np.max(np.abs(a))
    if (p < 1):
        print("谱半径小于1,收敛")
        res3 = SOR(A, B, scalex, nextx, time, k, w)
        print(res3)

    b = np.zeros(len(A))
    for i in range(len(A)):
        b[i] = B[i]
    x = np.zeros(col, dtype=float)
