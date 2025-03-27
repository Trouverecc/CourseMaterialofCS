import matplotlib.pyplot as plt
import numpy as np
import math
from numpy.linalg import *

#拉格朗日插值法
def lagrange(x,y,NumPoint,x_value):
    l = np.zeros(shape = (NumPoint),)
    #计算每一个lk的数值
    for i in range(NumPoint):
        temp = 1
        #计算每一个插值点所带来的值
        for j in range(NumPoint):
            if i!=j:
               temp = temp * (x_value - x[j]) / (x[i] - x[j])
            else:
               pass
        l[i] = temp * y[i]
    res = 0
    for i in range(NumPoint):
        res += l[i]
    return res


#牛顿插值法
def newton(x,y,n,x_value):
    row = len(x)
    col = len(x) +2
    temp = [[0 for i in range(col)] for j in range(row)]
    #计算差商表
    for i in range(row):
        temp[i][0] = x[i]
        temp[i][1] = y[i]
    for i in range(1,row):
        for j in range(2,i+2):
            temp[i][j] = (temp[i][j-1] - temp[i-1][j-1]) / (temp[i][0] - temp[i-j+1][0])
    f = 1
    res = temp[0][1]
    #构造fx
    for i in range(n):
        s = 1
        k = 0
        while k<i+1:
            s = s*(x_value - x[k])
            k +=1
        res = res + temp[i+1][i+2]*s
    return res



#分段插值法
def limit(x,y):
    def line(x_value):
        index = -1
        for i in range(1,len(x)):
            if x_value<=x[i]:
                index = i-1
                break
            else:
                i = i+1
        if index == -1:
            return 0
        result = ((x_value-x[index+1]) / (x[index]-x[index+1]) * y[index]) + ((x_value-x[index]) / (x[index+1] - x[index] ) * y[index+1])
        return result
    return line

#分段三次Hermite插值
def hermite(x,y,y2list):
    def get(x_value):
        index = -1
        result = 0.0;
        for i in range(1,len(x)):
            if x_value<x[i]:
                index = i-1
                break
            else:
                i = i+1
        if index == -1:
           return
        result = ((x_value - x[index+1]) / (x[index] - x[index+1]))**2 * (1+2*((x_value-x[index]) / (x[index+1] - x[index]))) * y[index] +\
             ((x_value - x[index]) / (x[index+1] - x[index]))**2 * (1+2*((x_value-x[index+1]) / (x[index] - x[index+1]))) * y[index+1] +\
            ((x_value-x[index+1]) / (x[index] - x[index+1]))**2 * (x_value-x[index]) * y2list[index]  +\
            ((x_value-x[index]) / (x[index+1] - x[index]))**2 * (x_value-x[index+1]) * y2list[index+1]
        return result
    return get

print("本次实验令a=-3, b=3, c=2, d=3, e=3, f=4")
#采样区间
m = 0.1
a = -3
b = 3
scalex = np.arange(a,b,m)
#采样函数
ylist = []
for i in scalex:
    ylist.append(2*math.sin(3*i)+3*math.cos(4*i))
print("")

#采样函数的导数，用于实现分段三次hermite插值
y2list = []
for i in scalex:
    y2list.append(6*math.cos(3*i)-12*math.sin(4*i))


#x_i仅作为参考点，这里最多选择一个(limit函数不兼容list)
x_i = -2

#在原函数的基础上均匀采样作为采样点, n可自设，但是要更改x_test
x_test = np.arange(-3,4,0.5)
print("x_test值为%d" %len(x_test))
y_test = []
for i in x_test:
    y_test.append(2*math.sin(3*i)+3*math.cos(4*i))
y2_test = []
for i in x_test:
    y2_test.append(6*math.cos(3*i)-12*math.sin(4*i))

#分段插值法
lin = limit(x_test,y_test)
y6 = [lin(i) for i in x_test]


#分段三次hermite插值
get = hermite(x_test,y_test,y2_test)
y2 = [get(i) for i in x_test]



#范德蒙德插值法
x = scalex
y = ylist
n = len(x)
A = np.zeros((n,n))
for i in range(n):
    for j in range(n):
        A[i][j] = x[i]**(n-1-j)
B = np.zeros((n,1))
for b in range(len(y)):
    B[b][0] = y[b]
a = np.linalg.solve(A,B)
def f(a,x):
    f = 0
    for m in range(len(a)):
        f += a[m][0]*x**(n-m-1)
    return f
y5 = f(a,scalex)

#lagrange插值
y3 = [lagrange(x_test,y_test,14,x_i) for x_i in scalex]

#newton插值
y4 = [newton(x_test,y_test,13,x_i) for x_i in scalex]


#误差分析

print("标准值为")
print(ylist[10])
#lagrant插值法
res1 = lagrange(x_test,y_test,14,x_i)
print("拉格朗日插值")
print(res1 - ylist[10])
max = 0
for t in range(len(ylist)):
    e = abs(y[t] - lagrange(x_test,y_test,14,x_i))
    if e>max:
        max = e
    else:
        pass
print(max)
#newton插值
res2 = newton(x_test,y_test,13,x_i)
print("牛顿插值")
print(res2-y[10])
max = 0
for t in range(len(ylist)):
    e = abs(y[t] - newton(x_test,y_test,13,x_i))
    if e>max:
        max = e
    else:
        pass
print(max)

#分段插值法
res3 = limit(x_test,y_test)
print("分段线性插值法")
print(y6[2]-ylist[10])

#分段三次hermite插值法
res4 = hermite(scalex,ylist,y2list)
print("分段三次Hermite插值")
print(y2[2]-ylist[10])

#范德蒙德插值法
max = 0
for t in range(len(ylist)):
    e = abs(y[t] - f(a,x[t]))
    if e>max:
        max = e
    else:
        pass
print("范德蒙德插值法")
print(f(a,-2) - ylist[10])
print(max)


plt.figure(figsize=(6,6))
plt.plot(scalex,ylist)
plt.plot(x_test,y6,label = "limit") #分段线性插值法
plt.plot(x_test,y2,color = 'black',label = "hermit")#hermit插值
plt.plot(scalex,y3,color = 'blue',label = "lagrant")#拉格朗日插值法
plt.plot(scalex,y4,color = 'gold',label = "newton")#牛顿插值法
plt.plot(scalex,y5,label = "vandermonde")#范德蒙德插值法
plt.title("compare")
plt.legend()
plt.show()
