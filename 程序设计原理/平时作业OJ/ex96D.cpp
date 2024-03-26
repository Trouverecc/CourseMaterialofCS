#include<iostream>
#include<string>
using namespace std;
char ph[101][101];
bool ifx(int x1,int x2,int y1,int y2) {      //判断该图形是否关于x轴对称
if ((x1 - x2) % 2 != 0) {
    for (int i = x2; i <= (x1 + x2) / 2; i++) {
        for (int j = y2; j <= y1; j++) {
            if (ph[i][j] != ph[x1][j]) {
                if (ph[i][j] == '\0' && ph[x1][j] == ' ')
                    continue;
                else if (ph[x1][j] == '\0' && ph[i][j] == ' ')
                    continue;
                else
                    return false;
            }
        }
        x1--;
    }
    return true;
}
else {
    for (int i = x2; i < (x1 + x2) / 2; i++) {
        for (int j = y2; j <= y1; j++) {
            if (ph[i][j] != ph[x1][j]) {
                if (ph[i][j] == '\0' && ph[x1][j] == ' ')
                    continue;
                else if (ph[x1][j] == '\0' && ph[i][j] == ' ')
                    continue;
                else
                    return false;
            }
        }
        x1--;
    }
    return true;
}
}
bool ify(int x1, int x2, int y1, int y2) {    //判断该图形是否关于x轴对称
int b=y1;
if ((y1 - y2) % 2 != 0) {
    for (int i =x2; i <= x1; i++) {
        b = y1;
for (int j = y2; j <= (y1 + y2) / 2; j++) {
if (ph[i][j] != ph[i][b]) {
if (ph[i][j] == '\0' && ph[i][b] == ' ') {
b--;
continue;
}
else if (ph[i][b] == '\0' && ph[i][j] == ' ') {
b--;
continue;
}
else
return false;
}
b--;
}
}
return true;
}
else {
for (int i = x2; i <= x1; i++) {
b = y1;
for (int j = y2; j < (y1 + y2) / 2; j++) {
if (ph[i][j] != ph[i][b]) {
if (ph[i][j] == '\0' && (ph[i][b] == ' '||ph[i][b]=='0') ){
b--;
continue;
}
else if (ph[i][b] == '\0' && (ph[i][j] == ' '||ph[i][j]=='0')) {
b--;
continue;
}
else
return false;
}
b--;
}
}
return true;
}
}
bool Cen(int x1, int x2, int y1, int y2) {     //判断该图形是否中心对称
int b = y2;
if ((x1 - x2) % 2 != 0) {
for (int i = x2; i <= (x1+x2)/2; i++) {
b = y2;
for (int j = y1; j >= y2; j--) {
if (ph[i][j] != ph[x1][b]) {
if ((ph[i][j] == '\0') && (ph[x1][b] == ' ')) {
b++;
continue;
}
else if ((ph[x1][b] == '\0') && (ph[i][j] == ' ')) {
b++;
continue;
}
else 
return false;
}
b++;
}
x1--;
}
return true;
}
else {
for (int i = x2; i < (x1 + x2) / 2; i++) {
b = y2;
for (int j = y1; j >= y2; j--) {
if (ph[i][j] != ph[x1][y2]) {
if ((ph[i][j] == '\0') && (ph[x1][b] == ' ')) {
b++;
continue;
}
else if ((ph[x1][b] == '\0') && (ph[i][j] == ' ')) {
b++;
continue;
}
else 
return false;
}
b++;
}
x1--;
}
return true;
}
}
int main() {
int x1, x2, y1=0, y2=101,n,  mfc = 0;
cin >> n;                                         //输入
for (int i = 0; i <= n; i++)
cin.getline(ph[i], 100, '\n');
for (int i = 1; i <= n; i++) {                  //确定有效图形范围
for (int j = 0; j < 101; j++) {
if (ph[i][j] == '\0')
break;
else if (ph[i][j] != ' '&&ph[i][j] != '0') {
if (j < y2)
y2 = j;
if (j > y1)
y1 = j;
}
}
}
for (int i = n; i >=1; i--) {
for (int j = 0; j < 101; j++) {
if (ph[i][j]=='\0') 
continue;
else if (ph[i][j] != ' ' && ph[i][j] != '\0' && ph[i][j] != '0') {
x1 = i;
i = 1;
break;
}
}
}
for (int i = 1; i <=n; i++) {
for (int j = 0; j < 101; j++) {
if (ph[i][j] == '\0')
continue;
else if (ph[i][j] != ' ' && ph[i][j] != '\0' && ph[i][j] != '0') {
x2 = i;
i = n;
break;
}
}
}
if (ifx(x1,x2,y1,y2))
mfc += 2;
if (ify(x1, x2, y1, y2))
mfc++;
if (Cen(x1, x2, y1, y2))
mfc+=3;
cout << mfc;               //输出图形得分
return 0;
}
