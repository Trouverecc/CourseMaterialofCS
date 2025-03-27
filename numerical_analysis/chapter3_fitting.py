import math
import matplotlib.pyplot as plt


# 定义目标函数 f(x) = 1 / (1 + c * x^2)
def target_function(x, c):
    return 1 / (1 + c * x ** 2)


# 最小二乘拟合函数
def least_squares_fit(x, fx, degree):
    n = len(x)
    # 构造 Vandermonde 矩阵
    A = [[x[i] ** j for j in range(degree + 1)] for i in range(n)]

    # 构造 A.T * A 和 A.T * fx
    ATA = [[0 for _ in range(degree + 1)] for _ in range(degree + 1)]
    ATfx = [0 for _ in range(degree + 1)]

    # 计算 ATA 矩阵和 ATfx 向量
    for i in range(degree + 1):
        for j in range(degree + 1):
            ATA[i][j] = sum(A[k][i] * A[k][j] for k in range(n))
        ATfx[i] = sum(A[k][i] * fx[k] for k in range(n))

    # 解线性方程 ATA * coeffs = ATfx, 使用高斯消去法
    coeffs = gaussian_elimination(ATA, ATfx)

    # 返回拟合多项式的系数
    return coeffs


# 高斯消去法求解线性方程组
def gaussian_elimination(A, b):
    n = len(A)
    for i in range(n):
        # 找主元
        max_row = i + max(range(n - i), key=lambda k: abs(A[i + k][i]))
        A[i], A[max_row] = A[max_row], A[i]
        b[i], b[max_row] = b[max_row], b[i]

        # 消去
        for j in range(i + 1, n):
            ratio = A[j][i] / A[i][i]
            for k in range(i, n):
                A[j][k] -= ratio * A[i][k]
            b[j] -= ratio * b[i]

    # 回代求解
    x = [0] * n
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - sum(A[i][j] * x[j] for j in range(i + 1, n))) / A[i][i]
    return x


# 使用勒让德多项式进行逼近
def legendre_polynomial_approximation(x, fx, degree):
    n = len(x)
    # 构建勒让德多项式的系数
    legendre_coeffs = [0] * (degree + 1)

    for k in range(degree + 1):
        # 计算勒让德系数
        legendre_coeffs[k] = sum(fx[i] * legendre_polynomial(x[i], k) for i in range(n)) / sum(
            legendre_polynomial(x[i], k) ** 2 for i in range(n))

    # 返回勒让德多项式逼近
    return legendre_coeffs


# 递归生成勒让德多项式
def legendre_polynomial(x, n):
    if n == 0:
        return 1
    elif n == 1:
        return x
    else:
        return ((2 * n - 1) * x * legendre_polynomial(x, n - 1) - (n - 1) * legendre_polynomial(x, n - 2)) / n


# 计算多项式值
def evaluate_polynomial(coeffs, x):
    return sum(coeffs[i] * x ** i for i in range(len(coeffs)))


# 计算勒让德多项式逼近值
def evaluate_legendre(coeffs, x):
    return sum(coeffs[i] * legendre_polynomial(x, i) for i in range(len(coeffs)))


# 计算平均误差
def calculate_error(y_true, y_approx):
    return sum(abs(y_true[i] - y_approx[i]) for i in range(len(y_true))) / len(y_true)


# 主函数
def main():
    # 输入参数
    a, b = -1, 1  # 函数区间
    c = 2  # 标准函数中的参数 c
    k = 3  # 逼近多项式的次数
    n = 100  # 采样点数量
    m = 100  # 实验点数量

    # 在区间 [a, b] 上生成 n+1 个采样点
    x_samples = [a + i * (b - a) / n for i in range(n + 1)]
    y_samples = [target_function(x, c) for x in x_samples]

    # 在区间 [a, b] 上生成 m 个实验点
    x_test = [a + i * (b - a) / m for i in range(m)]
    y_test = [target_function(x, c) for x in x_test]

    # 最小二乘拟合
    coeffs_ls = least_squares_fit(x_samples, y_samples, k)
    y_ls_approx = [evaluate_polynomial(coeffs_ls, x) for x in x_test]

    # 勒让德多项式逼近
    coeffs_legendre = legendre_polynomial_approximation(x_samples, y_samples, k)
    y_legendre_approx = [evaluate_legendre(coeffs_legendre, x) for x in x_test]

    # 计算两种方法的平均误差
    error_ls = calculate_error(y_test, y_ls_approx)
    error_legendre = calculate_error(y_test, y_legendre_approx)

    # 打印平均误差
    print(f"最小二乘拟合平均误差: {error_ls}")
    print(f"勒让德最佳平方逼近平均误差: {error_legendre}")

    # 绘制对比曲线
    plt.figure(figsize=(10, 6))
    plt.plot(x_test, y_test, label='Target Function', color='blue', linewidth=2)
    plt.plot(x_test, y_ls_approx, label='Least Squares Fit', color='red', linestyle='--', linewidth=2)
    plt.plot(x_test, y_legendre_approx, label='Legendre Approximation', color='green', linestyle='-.', linewidth=2)
    plt.legend()
    plt.show()


# 运行主函数
main()


