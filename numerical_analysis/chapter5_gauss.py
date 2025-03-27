import random
import time


# 生成随机矩阵（值位于0～100的整数）
def generate_matrix(n):
    A = [[random.randint(0, 100) for _ in range(n)] for _ in range(n)]
    return A


# 生成随机向量（值位于0～100）
def generate_vector(n):
    b = [[random.randint(0, 100)] for _ in range(n)]
    return b


# 列主元消元法
def solve(A, b):
    n = len(A)
    # 增广矩阵
    M = [A[i] + b[i] for i in range(n)]

    # 消元
    for i in range(n - 1):
        # 选主元
        max_index = i
        for j in range(i + 1, n):
            if abs(M[j][i]) > abs(M[max_index][i]):
                max_index = j
        # 交换行
        if max_index != i:
            M[i], M[max_index] = M[max_index], M[i]

        # 消元
        for j in range(i + 1, n):
            factor = M[j][i] / M[i][i]
            M[j] = [M[j][k] - factor * M[i][k] for k in range(n + 1)]

    # 回代
    x = [0] * n
    for i in range(n - 1, -1, -1):
        x[i] = (M[i][n] - sum(M[i][j] * x[j] for j in range(i + 1, n))) / M[i][i]

    return M, x


if __name__ == "__main__":
    # 使用给定的特定矩阵和向量
    A = [
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
    b = [[-15], [27], [-23], [0], [-20], [12], [-7], [7], [10]]

    # 使用特定矩阵执行消元
    M, x = solve(A, b)

    print("\n特定矩阵的增广矩阵：")
    for row in M:
        print(row)

    print("\n方程Ax=b的解向量x*：")
    print(x)

    # 设置矩阵维数
    n = 20

    # 生成随机矩阵和向量
    A = generate_matrix(n)
    b = generate_vector(n)

    # 计时
    start = time.time()

    # 消元
    M, x = solve(A, b)
    end = time.time()

    # 输出结果
    print("随机生成的增广矩阵：")
    for row in M:
        print(row)

    print("\n方程Ax=b的解向量x*：")
    print(x)
    print("\n程序运行时间：", end - start)



