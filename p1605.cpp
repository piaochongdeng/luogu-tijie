#include <bits/stdc++.h>
using namespace std;

string trm(const string& s) {
    int i = 0;
    while (i < s.size() && s[i] == '0') i++;
    return i == s.size() ? "0" : s.substr(i);
}

int cmp(const string& a, const string& b) {
    string s1 = trm(a), s2 = trm(b);
    if (s1.size() != s2.size())
        return s1.size() > s2.size() ? 1 : -1;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i])
            return s1[i] > s2[i] ? 1 : -1;
    }
    return 0;
}

string addp(const string& a, const string& b) {
    string s1 = a, s2 = b;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int len = max(s1.size(), s2.size());
    string res;
    int c = 0;
    for (int i = 0; i < len; i++) {
        int n1 = i < s1.size() ? s1[i] - '0' : 0;
        int n2 = i < s2.size() ? s2[i] - '0' : 0;
        int sum = n1 + n2 + c;
        c = sum / 10;
        res += char(sum % 10 + '0');
    }
    if (c) res += char(c + '0');
    reverse(res.begin(), res.end());
    return trm(res);
}

string subp(const string& a, const string& b) {
    string s1 = a, s2 = b;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string res;
    int c = 0;
    for (int i = 0; i < s1.size(); i++) {
        int n1 = s1[i] - '0';
        int n2 = i < s2.size() ? s2[i] - '0' : 0;
        int sub = n1 - n2 - c;
        if (sub < 0) {
            sub += 10;
            c = 1;
        } else {
            c = 0;
        }
        res += char(sub + '0');
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return trm(res);
}

string mulp(const string& a, const string& b) {
    vector<int> res(a.size() + b.size(), 0);
    for (int i = a.size() - 1; i >= 0; i--) {
        int n1 = a[i] - '0';
        for (int j = b.size() - 1; j >= 0; j--) {
            int n2 = b[j] - '0';
            res[i + j + 1] += n1 * n2;
        }
    }
    for (int i = res.size() - 1; i > 0; i--) {
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }
    string ans;
    int i = 0;
    while (i < res.size() && res[i] == 0) i++;
    if (i == res.size()) return "0";
    for (; i < res.size(); i++)
        ans += char(res[i] + '0');
    return ans;
}

string divp(const string& a, const string& b) {
    string dv = a;
    string ds = b;
    if (cmp(dv, ds) < 0) return "0";
    int n = dv.size();
    int m = ds.size();
    string res;
    string rmd = dv.substr(0, m - 1);
    for (int i = m - 1; i < n; i++) {
        rmd += dv[i];
        rmd = trm(rmd);
        int q = 0, l = 0, r = 9;
        while (l <= r) {
            int mid = (l + r) / 2;
            string t = mulp(ds, to_string(mid));
            if (cmp(t, rmd) <= 0) {
                q = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        res += char(q + '0');
        string tmp = mulp(ds, to_string(q));
        rmd = subp(rmd, tmp);
    }
    return trm(res);
}

string modp(const string& a, const string& b) {
    string dv = a;
    string ds = b;
    if (cmp(dv, ds) < 0) return dv;
    int n = dv.size();
    int m = ds.size();
    string rmd = dv.substr(0, m - 1);
    for (int i = m - 1; i < n; i++) {
        rmd += dv[i];
        rmd = trm(rmd);
        int q = 0, l = 0, r = 9;
        while (l <= r) {
            int mid = (l + r) / 2;
            string t = mulp(ds, to_string(mid));
            if (cmp(t, rmd) <= 0) {
                q = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        string tmp = mulp(ds, to_string(q));
        rmd = subp(rmd, tmp);
    }
    return trm(rmd);
}

string add(const string& a, const string& b) {
    bool na = a[0] == '-';
    bool nb = b[0] == '-';
    string s1 = na ? a.substr(1) : a;
    string s2 = nb ? b.substr(1) : b;
    int cp = cmp(s1, s2);
    if (!na && !nb) {
        return addp(s1, s2);
    } else if (na && nb) {
        return '-' + addp(s1, s2);
    } else if (na && !nb) {
        if (cp == 0) return "0";
        return cp == 1 ? '-' + subp(s1, s2) : subp(s2, s1);
    } else {
        if (cp == 0) return "0";
        return cp == 1 ? subp(s1, s2) : '-' + subp(s2, s1);
    }
}

string sub(const string& a, const string& b) {
    string nb = b[0] == '-' ? b.substr(1) : '-' + b;
    return add(a, nb);
}

string mul(const string& a, const string& b) {
    bool na = a[0] == '-';
    bool nb = b[0] == '-';
    string s1 = na ? a.substr(1) : a;
    string s2 = nb ? b.substr(1) : b;
    string res = mulp(s1, s2);
    return (na != nb && res != "0") ? '-' + res : res;
}

string dv2(const string& b) {
    string res;
    int c = 0;
    for (int i = 0; i < b.size(); i++) {
        int num = c * 10 + (b[i] - '0');
        res += (num / 2) + '0';
        c = num % 2;
    }
    return trm(res);
}

bool iev(const string& b) {
    int ld = b[b.size() - 1] - '0';
    return ld % 2 == 0;
}

string pwe(const string& a, const string& b) {
    string z = "0", o = "1";
    if (b == z) return o;
    if (b == o) return a;
    if (iev(b)) {
        string hb = dv2(b);
        string hp = pwe(a, hb);
        return mul(hp, hp);
    } else {
        string bm = subp(b, o);
        return mul(a, pwe(a, bm));
    }
}

string dvd(const string& a, const string& b) {
    bool na = a[0] == '-';
    bool nb = b[0] == '-';
    string s1 = na ? a.substr(1) : a;
    string s2 = nb ? b.substr(1) : b;
    if (s2 == "0") {
        return "Error";
    }
    string res = divp(s1, s2);
    return (na != nb && res != "0") ? '-' + res : res;
}

string mod(const string& a, const string& b) {
    bool na = a[0] == '-';
    string s1 = na ? a.substr(1) : a;
    string s2 = b[0] == '-' ? b.substr(1) : b;
    if (s2 == "0") {
        return "Error";
    }
    string res = modp(s1, s2);
    return (na && res != "0") ? '-' + res : res;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2 ;
    cout << add(s1,s2) << endl;
    return 0;
}