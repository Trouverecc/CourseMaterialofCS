import numpy as np
import matplotlib.pyplot as plt
import math


# 目标函数 f(x) = 1 / (1 + cx^2)
def f(x, c):
    return 1 / (1 + c * x ** 2)


# 勒让德多项式递归生成
def legendre_polynomial(k, x):
    if k == 0:
        return 1
    elif k == 1:
        return x
    else:
        P_k_1 = legendre_polynomial(k - 1, x)
        P_k_2 = legendre_polynomial(k - 2, x)
        return ((2 * k - 1) * x * P_k_1 - (k - 1) * P_k_2) / k


# 计算勒让德多项式最佳平方逼近的系数
def legendre_approx_coefficients(a, b, k, c, n):
    coefficients = []
    for i in range(k + 1):
        numerator = 0
        denominator = 0
        # 用n个采样点进行数值积分
        for j in range(n + 1):
            x = a + (b - a) * j / n
            fx = f(x, c)
            P_i = legendre_polynomial(i, x)
            numerator += fx * P_i
            denominator += P_i ** 2
        coefficients.append(numerator / denominator)
    return coefficients


# 根据勒让德多项式系数计算逼近函数值
def legendre_approximation(x, coeffs, k):
    approx = 0
    for i in range(k + 1):
        approx += coeffs[i] * legendre_polynomial(i, x)
    return approx


# 最小二乘拟合，通过构造多项式拟合 n+1 个采样点
def least_squares_fit(a, b, k, n, c):
    # 采样点
    X = [(a + (b - a) * i / n) for i in range(n + 1)]
    Y = [f(x, c) for x in X]

    # 拟合多项式的系数
    coeffs = [0] * (k + 1)
    for i in range(k + 1):
        for j in range(n + 1):
            coeffs[i] += Y[j] * (X[j] ** i)

    return coeffs


# 根据最小二乘法系数计算逼近函数值
def least_squares_approximation(x, coeffs):
    approx = 0
    for i, coeff in enumerate(coeffs):
        approx += coeff * (x ** i)
    return approx


# 误差计算，返回平均误差
def calculate_error(a, b, m, c, approx_func, coeffs, k=None):
    error = 0
    for i in range(m):
        x = a + (b - a) * i / m
        fx = f(x, c)
        if k is not None:  # 如果是勒让德逼近
            approx = approx_func(x, coeffs, k)
        else:  # 如果是最小二乘拟合
            approx = approx_func(x, coeffs)
        error += (fx - approx) ** 2
    return math.sqrt(error / m)


# 绘制对比曲线
def plot_comparison(a, b, c, k, m, legendre_coeffs, ls_coeffs):
    # 生成m个实验点
    X = np.linspace(a, b, m)

    # 计算原函数值
    F = [f(x, c) for x in X]

    # 计算勒让德逼近值
    legendre_approx = [legendre_approximation(x, legendre_coeffs, k) for x in X]

    # 计算最小二乘拟合值
    ls_approx = [least_squares_approximation(x, ls_coeffs) for x in X]

    # 绘制曲线
    plt.figure(figsize=(10, 6))
    plt.plot(X, F, label="Target Function f(x)", color='blue', linewidth=2)
    plt.plot(X, legendre_approx, label="Legendre Approximation", color='red', linestyle='--', linewidth=2)
    plt.plot(X, ls_approx, label="Least Squares Approximation", color='green', linestyle='-.', linewidth=2)

    plt.title(f"Comparison of Approximation Methods (k={k})")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend()
    plt.grid(True)
    plt.show()


# 主程序
def main(a, b, c, k, n, m):
    # 勒让德多项式最佳平方逼近
    legendre_coeffs = legendre_approx_coefficients(a, b, k, c, n)
    legendre_error = calculate_error(a, b, m, c, legendre_approximation, legendre_coeffs, k)

    # 最小二乘拟合
    ls_coeffs = least_squares_fit(a, b, k, n, c)
    ls_error = calculate_error(a, b, m, c, least_squares_approximation, ls_coeffs)

    # 输出对比结果
    print(f"勒让德多项式最佳平方逼近的平均误差: {legendre_error}")
    print(f"最小二乘拟合的平均误差: {ls_error}")

    # 绘制对比曲线
    plot_comparison(a, b, c, k, m, legendre_coeffs, ls_coeffs)


# 示例运行
main(a=-1, b=1, c=2, k=3, n=10, m=100)



