#include <bits/stdc++.h>

using namespace std;

// 去除字符串前导零和尾部多余的零
string trim(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < s.size() && (s[l] == '0' || s[l] == '.')) l++;
    while (r >= 0 && (s[r] == '0' || s[r] == '.')) r--;
    if (l > r) return "0";
    return s.substr(l, r - l + 1);
}

// 比较两个数的大小，返回1表示a>b，0表示a=b，-1表示a<b
int cmp(const string& a, const string& b) {
    string s1 = trim(a), s2 = trim(b);
    if (s1 == s2) return 0;
    bool n1 = s1[0] == '-', n2 = s2[0] == '-';
    if (n1 && !n2) return -1;
    if (!n1 && n2) return 1;
    if (!n1 && !n2) {
        if (s1.size() != s2.size()) return s1.size() > s2.size() ? 1 : -1;
        return s1 > s2 ? 1 : -1;
    }
    // n1 && n2
    if (s1.size() != s2.size()) return s1.size() > s2.size() ? -1 : 1;
    return s1 > s2 ? -1 : 1;
}

// 解析字符串，分离符号、整数部分、小数部分
void parse(const string& s, bool& neg, string& intp, string& decp) {
    neg = false;
    int i = 0;
    if (s[i] == '-') {
        neg = true;
        i++;
    }
    while (i < s.size() && s[i] != '.') {
        intp += s[i++];
    }
    if (i < s.size() && s[i] == '.') i++;
    while (i < s.size()) {
        decp += s[i++];
    }
    if (intp.empty()) intp = "0";
}

// 去除整数部分的前导零和小数部分的尾部零
void trim_parts(string& intp, string& decp) {
    while (intp.size() > 1 && intp[0] == '0') intp.erase(0, 1);
    while (!decp.empty() && decp.back() == '0') decp.pop_back();
}

// 高精度加法，支持正负数，当输入不含小数时，结果不包含小数点
string add(const string& a, const string& b) {
    bool na = false, nb = false;
    string ia, ib, da, db;
    parse(a, na, ia, da);
    parse(b, nb, ib, db);

    // 对小数部分进行对齐
    int dl = max(da.size(), db.size());
    while (da.size() < dl) da += '0';
    while (db.size() < dl) db += '0';

    // 对整数部分进行对齐
    int il = max(ia.size(), ib.size());
    while (ia.size() < il) ia = '0' + ia;
    while (ib.size() < il) ib = '0' + ib;

    string res_int, res_dec;
    int c = 0;

    // 处理小数部分
    for (int i = dl - 1; i >= 0; i--) {
        int n1 = da[i] - '0', n2 = db[i] - '0';
        int sum = (na ? -n1 : n1) + (nb ? -n2 : n2) + c;
        c = sum >= 0 ? sum / 10 : (sum - 9) / 10;
        sum = (sum % 10 + 10) % 10;
        res_dec = char(sum + '0') + res_dec;
    }

    // 处理整数部分
    for (int i = il - 1; i >= 0; i--) {
        int n1 = ia[i] - '0', n2 = ib[i] - '0';
        int sum = (na ? -n1 : n1) + (nb ? -n2 : n2) + c;
        c = sum >= 0 ? sum / 10 : (sum - 9) / 10;
        sum = (sum % 10 + 10) % 10;
        res_int = char(sum + '0') + res_int;
    }

    if (c != 0) res_int = char(c + '0') + res_int;

    // 去除多余的零
    trim_parts(res_int, res_dec);

    // 判断结果是否为0
    bool is_zero = (res_int == "0" && res_dec.empty());

    // 结果符号判断
    bool neg_res = false;
    if (!is_zero) {
        if (res_int[0] == '-') {
            neg_res = true;
            res_int = res_int.substr(1);
        } else if (na && nb) {
            neg_res = true;
        } else if (na || nb) {
            int comp = cmp(a, b);
            if ((comp == -1 && na) || (comp == 1 && nb)) {
                neg_res = true;
            }
        }
    }

    // 组合结果
    string res = res_int;
    if (!res_dec.empty()) res += '.' + res_dec;

    if (neg_res) res = '-' + res;

    // 当输入的 a 和 b 都不含小数时，结果也不含小数点
    if (da.empty() && db.empty() && res_dec.empty()) {
        size_t pos = res.find('.');
        if (pos != string::npos) res.erase(pos);
    }

    return res;
}

// 高精度减法，支持正负数，当输入不含小数时，结果不包含小数点
string sub(const string& a, const string& b) {
    // 减法等价于加上一个相反数
    string nb = b;
    if (b[0] == '-') nb = b.substr(1);
    else nb = '-' + b;
    return add(a, nb);
}

// 高精度乘法，支持正负数，当输入不含小数时，结果不包含小数点
string mul(const string& a, const string& b) {
    bool na = false, nb = false;
    string sa = a, sb = b;
    if (sa[0] == '-') {
        na = true;
        sa = sa.substr(1);
    }
    if (sb[0] == '-') {
        nb = true;
        sb = sb.substr(1);
    }

    int p1 = sa.find('.'), p2 = sb.find('.');
    int d1 = p1 == string::npos ? 0 : sa.size() - p1 - 1;
    int d2 = p2 == string::npos ? 0 : sb.size() - p2 - 1;
    if (p1 != string::npos) sa.erase(p1, 1);
    if (p2 != string::npos) sb.erase(p2, 1);

    vector<int> v1, v2;
    for (int i = sa.size() - 1; i >= 0; i--) v1.push_back(sa[i] - '0');
    for (int i = sb.size() - 1; i >= 0; i--) v2.push_back(sb[i] - '0');

    vector<int> res(v1.size() + v2.size(), 0);
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            res[i + j] += v1[i] * v2[j];
        }
    }

    for (int i = 0; i < res.size() - 1; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }

    int dec = d1 + d2;
    string res_s;
    bool non_zero = false;
    for (int i = res.size() - 1; i >= 0; i--) {
        if (i == dec - 1 && dec != 0) res_s += '.';
        res_s += res[i] + '0';
        if (res[i] != 0) non_zero = true;
    }

    if (!non_zero) res_s = "0";
    else {
        // 去除多余的零
        size_t pos = res_s.find('.');
        if (pos != string::npos) {
            while (res_s.back() == '0') res_s.pop_back();
            if (res_s.back() == '.') res_s.pop_back();
        }
        if (res_s[0] == '0' && res_s.length() > 1 && res_s[1] != '.') res_s.erase(0, 1);
    }

    if (na != nb && res_s != "0") res_s = '-' + res_s;

    // 当输入的 a 和 b 都不含小数时，结果也不含小数点
    if (d1 == 0 && d2 == 0) {
        size_t pos = res_s.find('.');
        if (pos != string::npos) res_s.erase(pos);
    }

    return res_s;
}

// 高精度除法，支持正负数，pre为小数点后精度
string divd(const string& a, const string& b, int pre) {
    bool na = false, nb = false;
    string sa = a, sb = b;
    if (sa[0] == '-') {
        na = true;
        sa = sa.substr(1);
    }
    if (sb[0] == '-') {
        nb = true;
        sb = sb.substr(1);
    }

    int p1 = sa.find('.'), p2 = sb.find('.');
    int d1 = p1 == string::npos ? 0 : sa.size() - p1 - 1;
    int d2 = p2 == string::npos ? 0 : sb.size() - p2 - 1;
    if (p1 != string::npos) sa.erase(p1, 1);
    if (p2 != string::npos) sb.erase(p2, 1);

    int shift = d2 - d1 + pre;
    while (shift > 0) {
        sa += '0';
        shift--;
    }
    while (shift < 0) {
        sb += '0';
        shift++;
    }

    string res;
    string rem = "0";
    for (int i = 0; i < sa.size(); i++) {
        rem = rem + sa.substr(i, 1);
        int cnt = 0;
        while (cmp(rem, sb) >= 0) {
            rem = sub(rem, sb);
            cnt++;
        }
        res += cnt + '0';
    }

    res.insert(res.end() - pre, '.');
    res = trim(res);
    if (na != nb && res != "0") res = '-' + res;
    return res;
}

// 高精度取余运算，支持正负数
string mod(const string& a, const string& b) {
    bool na = false, nb = false;
    string sa = a, sb = b;
    if (sa[0] == '-') {
        na = true;
        sa = sa.substr(1);
    }
    if (sb[0] == '-') {
        nb = true;
        sb = sb.substr(1);
    }

    int p1 = sa.find('.'), p2 = sb.find('.');
    int d1 = p1 == string::npos ? 0 : sa.size() - p1 - 1;
    int d2 = p2 == string::npos ? 0 : sb.size() - p2 - 1;
    int maxd = max(d1, d2);

    if (p1 != string::npos) sa.erase(p1, 1);
    else sa += string(maxd, '0');
    if (p2 != string::npos) sb.erase(p2, 1);
    else sb += string(maxd, '0');

    // 补齐
    while (sa.size() < sb.size()) sa = '0' + sa;
    while (sb.size() < sa.size()) sb = '0' + sb;

    string rem = "0";
    for (int i = 0; i < sa.size(); i++) {
        rem = mul(rem, "10");
        rem = add(rem, sa.substr(i,1));
        while (cmp(rem, sb) >= 0) {
            rem = sub(rem, sb);
        }
    }

    // 处理小数点位置
    if (maxd > 0) {
        rem.insert(rem.end() - maxd, '.');
    }

    rem = trim(rem);

    if (na && rem != "0") rem = '-' + rem;

    return rem;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    cout << add(s1,s2) << endl;
    cout << sub(s1,s2) << endl;
    cout << mul(s1,s2) << endl;
    cout << divd(s1,s2, 0) << endl;
    cout << mod(s1,s2) << endl;
    //system("pause");
    return 0;
}
