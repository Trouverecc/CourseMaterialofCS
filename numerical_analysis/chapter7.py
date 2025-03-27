from scipy.misc import derivative
import numpy as np
import math


class NonLinear:
    def __init__(self, funcs):
        self.funcs = funcs

    def fn(self, x):
        return self.funcs[0](x)

    def Fn(self, x):
        return np.array([self.funcs[i](x) for i in range(len(self.funcs))])

    def Jacobian(self, x):
        num = len(self.funcs)
        df = np.zeros((num, num), dtype=float)
        dx = 1e-8
        x1 = np.copy(x)
        for i in range(0, num):
            for j in range(0, num):
                x1 = np.copy(x)
                x1[j] = x1[j] + dx
                df[i, j] = (self.Fn(x1)[i] - self.Fn(x)[i]) / dx
        df_rev = np.linalg.inv(df)
        return df_rev

    # 不动点迭代, x0 为初始点, delta 为要求的误差值
    def fixed_iter(self, x0, delta):
        x = x0
        next_x = x0
        count = 0
        while True:
            next_x = self.fn(x)
            err = abs(x - next_x)
            if err < delta:
                break
            else:
                x = next_x
            count += 1
        return (next_x, count)

    # 斯蒂芬森迭代法
    def stefenson_iter(self, x0, delta):
        x = x0
        y = x0
        z = x0
        next_x = x0
        count = 0
        while True:
            y = self.fn(x)
            z = self.fn(y)
            next_x = x - ((y - x) * (y - x) / (z - 2 * y + x))
            err = abs(next_x - x)
            if err < delta:
                break
            else:
                x = next_x
            count += 1
        return (next_x, count)

    # 牛顿迭代法
    def newton_iter(self, x0, delta):
        x = x0
        next_x = x0
        count = 0
        while True:
            next_x = x - (self.fn(x) / derivative(self.fn, x))
            err = abs(next_x - x)
            if err < delta:
                break
            else:
                x = next_x
            count += 1
        return (next_x, count)

    # 多变量的不动点迭代
    def vec_fixed_iter(self, x0, delta):
        x = x0
        next_x = x0
        count = 0
        while True:
            next_x = np.array([self.funcs[i](x) for i in range(len(self.funcs))])
            err = max(abs(x - next_x))
            if err < delta:
                break
            else:
                x = next_x
            count += 1
        return (next_x, count)

    # 非线性方程组的牛顿迭代法
    def vec_newton_iter(self, x0, delta):
        x = x0
        next_x = x0
        count = 0
        while True:
            next_x = x - np.dot(self.Jacobian(x), self.Fn(x))
            err = max(abs(next_x - x))
            if err < delta:
                break
            else:
                x = next_x
            count += 1
        return (x, count)


def test_nonlinear():
    def f(x):
        return (x * x + 2 - math.exp(x)) / 3

    def f1(x):
        return x * x - 3 * x + 2 - math.exp(x)

    def g(x):
        return 20 / (x * x + 2 * x + 10)

    def g1(x):
        return pow(x, 3) + 2 * pow(x, 2) + 10 * x - 20

    non_linear = NonLinear([f])
    x0 = 0.00
    delta = 1e-8
    x, count = non_linear.fixed_iter(x0, delta)
    print("------------------不动点迭代法-------------------")
    print("求得的根为: {} 迭代次数为: {}".format(x, count))
    x, count = non_linear.stefenson_iter(x0, delta)
    print("------------------斯蒂芬森迭代法------------------")
    print("求得的根为: {}, 迭代次数为: {}".format(x, count))
    non_linear = NonLinear([f1])
    x, count = non_linear.newton_iter(x0, delta)
    print("------------------牛顿迭代法----------------------")
    print("求得的根为: {}, 迭代次数为: {}".format(x, count))

    non_linear = NonLinear([g])
    x0 = 1.36
    delta = 1e-8
    x, count = non_linear.fixed_iter(x0, delta)
    print("------------------不动点迭代法-------------------")
    print("求得的根为: {} 迭代次数为: {}".format(x, count))
    x, count = non_linear.stefenson_iter(x0, delta)
    print("------------------斯蒂芬森迭代法------------------")
    print("求得的根为: {}, 迭代次数为: {}".format(x, count))
    non_linear = NonLinear([g1])
    x, count = non_linear.newton_iter(x0, delta)
    print("------------------牛顿迭代法----------------------")
    print("求得的根为: {}, 迭代次数为: {}".format(x, count))


def test_vec_nonlinear():
    print("---------------------非线性方程组-------------------")

    def f(x):
        return (math.cos(x[1] * x[2]) + 0.5) / 3

    def g(x):
        return pow((pow(x[0], 2) + math.sin(x[2]) + 1.06) / 81, 1 / 2) - 0.1

    def h(x):
        return (-math.exp(-x[0] * x[1]) - (10 / 3) * math.pi + 1) / 20

    non_linear = NonLinear([f, g, h])
    x0 = np.array([0.0, 0, 0])
    delta = 1e-8
    (x, count) = non_linear.vec_fixed_iter(x0, delta)
    print("------------------不动点迭代法----------------------")
    print("求得的根为: {}, 迭代次数为: {}".format(x, count))

    def f2(x):
        return 3 * x[0] - math.cos(x[1] * x[2]) - 0.5

    def g2(x):
        return pow(x[0], 2) - 81 * pow((x[1] + 1), 2) + math.sin(x[2]) + 1.06

    def h2(x):
        return math.exp(-x[0] * x[1]) + 20 * x[2] + (10 / 3) * math.pi - 1

    non_linear = NonLinear(np.array([f2, g2, h2]))
    (x, count) = non_linear.vec_newton_iter(x0, delta)
    print("------------------牛顿迭代法----------------------")
    print("求得的根为: {}, 迭代次数为: {}".format(x, count))


if __name__ == "__main__":
    test_nonlinear()
    test_vec_nonlinear()