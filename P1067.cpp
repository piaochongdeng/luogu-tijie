#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
string s;
cin >> s;
double a = 0, b = 0;
int f = 1, n = s.size();
char x;
for (int i = 0; i < n; i++) {
if (s[i] == '=') {
f = -1;
continue;
}
if (s[i] >= 'a' && s[i] <= 'z') {
x = s[i];
if (i == 0 || s[i - 1] == '+' || s[i - 1] == '-') {
a += f;
} else {
int num = 0;
while (i < n && s[i] >= '0' && s[i] <= '9') {
num = num * 10 + s[i] - '0';
i++;
}
i--;
a += f * num;
}
}
if (s[i] >= '0' && s[i] <= '9') {
int num = 0;
while (i < n && s[i] >= '0' && s[i] <= '9') {
num = num * 10 + s[i] - '0';
i++;
}
i--;
b += f * num;
}
if (s[i] == '+' || s[i] == '-') {
f = (s[i] == '+') ? 1 : -1;
}
}
double result = -b / a;
cout << x << "=" << fixed << setprecision(3) << result << endl;
return 0;
}