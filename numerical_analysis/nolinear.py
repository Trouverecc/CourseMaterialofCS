import math


class NonLinear:
    def __init__(self, funcs):
        self.funcs = funcs

    def fn(self, x):
        return self.funcs[0](x)

    def Fn(self, x):
        return [self.funcs[i](x) for i in range(len(self.funcs))]

    def Jacobian(self, x):
        num = len(self.funcs)
        df = [[0.0] * num for _ in range(num)]
        dx = 1e-8
        x1 = x[:]

        for i in range(num):
            for j in range(num):
                x1[j] = x[j] + dx
                f_x1 = self.Fn(x1)
                f_x = self.Fn(x)
                df[i][j] = (f_x1[i] - f_x[i]) / dx
                x1[j] = x[j]

        # 使用矩阵求逆函数（可以自己实现）
        df_rev = self.inverse_matrix(df)
        return df_rev

    def inverse_matrix(self, matrix):
        # 使用高斯-约当法计算逆矩阵
        n = len(matrix)
        identity = [[float(i == j) for i in range(n)] for j in range(n)]

        for i in range(n):
            # 选择主元并交换行
            pivot = matrix[i][i]
            for j in range(n):
                matrix[i][j] /= pivot
                identity[i][j] /= pivot
            for k in range(n):
                if k != i:
                    factor = matrix[k][i]
                    for j in range(n):
                        matrix[k][j] -= factor * matrix[i][j]
                        identity[k][j] -= factor * identity[i][j]
        return identity

    def fixed_iter(self, x0, delta):
        x = x0
        next_x = x0
        count = 0
        while True:
            next_x = self.fn(x)
            err = abs(x - next_x)
            if err < delta:
                break
            x = next_x
            count += 1
        return (next_x, count)

    def stefenson_iter(self, x0, delta):
        x = x0
        count = 0
        while True:
            y = self.fn(x)
            z = self.fn(y)
            next_x = x - ((y - x) * (y - x) / (z - 2 * y + x))
            err = abs(next_x - x)
            if err < delta:
                break
            x = next_x
            count += 1
        return (next_x, count)

    def derivative(self, func, x, dx=1e-8):
        # 手动实现数值求导
        return (func(x + dx) - func(x - dx)) / (2 * dx)

    def newton_iter(self, x0, delta):
        x = x0
        count = 0
        while True:
            deriv = self.derivative(self.fn, x)
            if deriv == 0:
                break
            next_x = x - self.fn(x) / deriv
            err = abs(next_x - x)
            if err < delta:
                break
            x = next_x
            count += 1
        return (next_x, count)

    def vec_fixed_iter(self, x0, delta):
        x = x0[:]
        count = 0
        while True:
            next_x = [self.funcs[i](x) for i in range(len(self.funcs))]
            err = max(abs(x[i] - next_x[i]) for i in range(len(x)))
            if err < delta:
                break
            x = next_x
            count += 1
        return (next_x, count)

    def vec_newton_iter(self, x0, delta):
        x = x0[:]
        count = 0
        while True:
            j_inv = self.Jacobian(x)
            f_val = self.Fn(x)
            next_x = [x[i] - sum(j_inv[i][j] * f_val[j] for j in range(len(f_val))) for i in range(len(x))]
            err = max(abs(next_x[i] - x[i]) for i in range(len(x)))
            if err < delta:
                break
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
    x0 = 0.0
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
        return math.sqrt((x[0] ** 2 + math.sin(x[2]) + 1.06) / 81) - 0.1

    def h(x):
        return (-math.exp(-x[0] * x[1]) - (10 / 3) * math.pi + 1) / 20

    non_linear = NonLinear([f, g, h])
    x0 = [0.0, 0, 0]
    delta = 1e-8
    x, count = non_linear.vec_fixed_iter(x0, delta)
    print("------------------不动点迭代法----------------------")
    print("求得的根为: {}, 迭代次数为: {}".format(x, count))

    def f2(x):
        return 3 * x[0] - math.cos(x[1] * x[2]) - 0.5

    def g2(x):
        return x[0] ** 2 - 81 * (x[1] + 1) ** 2 + math.sin(x[2]) + 1.06

    def h2(x):
        return math.exp(-x[0] * x[1]) + 20 * x[2] + (10 / 3) * math.pi - 1

    non_linear = NonLinear([f2, g2, h2])
    x, count = non_linear.vec_newton_iter(x0, delta)
    print("------------------牛顿迭代法----------------------")
    print("求得的根为: {}, 迭代次数为: {}".format(x, count))


if __name__ == "__main__":
    test_nonlinear()
    test_vec_nonlinear()
