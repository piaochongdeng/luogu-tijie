#include <bits/stdc++.h>

using namespace std;
bool is_less(const string &a, const string &b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}

string jian(const string &a, const string &b) {
    string A = a;
    string B = b;
    bool negative = false;
    if (is_less(A, B)) {
        swap(A, B);
        negative = true;
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    string result;
    int carry = 0;

    for (size_t i = 0; i < A.size(); ++i) {
        int digitA = A[i] - '0';
        int digitB = i < B.size() ? B[i] - '0' : 0;
        int temp = digitA - digitB - carry;
        if (temp < 0) {
            temp += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(temp + '0');
    }
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    if (negative) {
        result.push_back('-');
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    cout << jian(s1,s2);
    //system("pause");
    return 0;
}
