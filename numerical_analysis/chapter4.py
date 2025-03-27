import math


# 定义被积函数 f(x) = √x * ln(x)
def f(x):
    return math.sqrt(x) * math.log(x)


# 复化梯形公式
def composite_trapezoidal(f, a, b, h):
    n = int((b - a) / h)  # 划分的区间数
    result = 0.5 * (f(a) + f(b))  # 端点的贡献
    for i in range(1, n):
        result += f(a + i * h)  # 内部点的贡献
    return result * h


# 龙贝格算法
def romberg(f, a, b, eps=1e-6):
    R = [[0]]
    n = 1
    h = b - a
    R[0][0] = h * (f(a) + f(b)) / 2  # 初始的梯形公式结果
    k = 1
    while True:
        # 计算 T(2^k) 项
        h /= 2
        sum_f = 0
        for i in range(1, 2 ** (k - 1) + 1):
            sum_f += f(a + (2 * i - 1) * h)

        R.append([0] * (k + 1))
        R[k][0] = 0.5 * R[k - 1][0] + h * sum_f

        # 龙贝格外推
        for j in range(1, k + 1):
            R[k][j] = R[k][j - 1] + (R[k][j - 1] - R[k - 1][j - 1]) / (4 ** j - 1)

        # 判断是否达到精度要求
        if abs(R[k][k] - R[k - 1][k - 1]) < eps:
            break
        k += 1
    return R[k][k], k, h


# 计算两种方法的精度对比
def compare_methods(a, b, eps, h_init):
    # 初始化步长
    h_trap = h_init
    h_rom = b - a

    # 复化梯形公式计算
    trap_steps = 0
    while True:
        trap_result = composite_trapezoidal(f, a, b, h_trap)
        trap_result_half = composite_trapezoidal(f, a, b, h_trap / 2)
        if abs(trap_result_half - trap_result) < eps:
            break
        h_trap /= 2
        trap_steps += 1

    # 龙贝格算法计算
    romberg_result, rom_steps, h_rom = romberg(f, a, b, eps)

    return {
        "Trapezoidal": {
            "Result": trap_result_half,
            "Steps": trap_steps,
            "Step Size": h_trap
        },
        "Romberg": {
            "Result": romberg_result,
            "Steps": rom_steps,
            "Step Size": h_rom
        }
    }


# 测试参数
a = 1  # 积分下限
b = 2  # 积分上限
eps = 1e-6  # 精度要求
h_init = 0.1  # 初始步长

# 调用函数进行计算
compare_results = compare_methods(a, b, eps, h_init)

# 输出结果
print("复化梯形公式结果：")
print(f"积分值：{compare_results['Trapezoidal']['Result']}")
print(f"划分次数：{compare_results['Trapezoidal']['Steps']}")
print(f"步长：{compare_results['Trapezoidal']['Step Size']}")

print("\n龙贝格算法结果：")
print(f"积分值：{compare_results['Romberg']['Result']}")
print(f"划分次数：{compare_results['Romberg']['Steps']}")
print(f"步长：{compare_results['Romberg']['Step Size']}")



