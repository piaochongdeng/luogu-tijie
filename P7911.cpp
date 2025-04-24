#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

int a, b, c, d,e;

bool check_zero(string s)
{
    if (s.size() > 1 && s[0] == '0')
    {
        return false;
    }
    return true;
}

bool check(string s)
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '.')
        {
            cnt1++;
        }
        else if (s[i] == ':')
        {
            cnt2++;
        }
    }
    if (cnt1 != 3 || cnt2 != 1)
    {
        return false;
    }

    string s1, s2, s3, s4,s5;
    int add = 1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == ':')
        {
            s5 = s.substr(i + 1);
            break;
        }
        else if (s[i] == '.')
        {
            add++;
        }
        else
        {
            if (add == 1)
            {
                s1 += s[i];
            }
            else if (add == 2)
            {
                s2 += s[i];
            }
            else if (add == 3)
            {
                s3 += s[i];
            }
            else if(add == 4)
            {
                s4 += s[i];
            }
        }
    }

    if (s1.empty() || s2.empty() || s3.empty() || s4.empty() || s5.empty()) 
    {
        return false;
    }
    if (!check_zero(s1))
    {
        return false;
    }
    if (!check_zero(s2))
    {
        return false;
    }
    if (!check_zero(s3))
    {
        return false;
    }
    if (!check_zero(s4))
    {
        return false;
    }
    if(!check_zero(s5))
    {
        return false;
    }

    return true;
}

void split(string s)
{
    string s1, s2, s3, s4,s5;
    int add = 1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == ':')
        {
            s4 = s.substr(i + 1);
            d = stoi(s4);
            return;
        }
        else if (s[i] == '.')
        {
            if (add == 1)
            {
                a = stoi(s1);
                s1.clear();
            }
            else if (add == 2)
            {
                b = stoi(s2);
                s2.clear();
            }
            else if (add == 3)
            {
                c = stoi(s3);
                s3.clear();
            }
            add++;
        }
        else
        {
            if (add == 1)
            {
                s1 += s[i];
            }
            else if (add == 2)
            {
                s2 += s[i];
            }
            else if (add == 3)
            {
                s3 += s[i];
            }
        }
    }
}

map<string, int> m;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (!check(s2))
        {
            cout << "ERR" << endl;
            continue;
        }

        split(s2);
        if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 65535)
        {
            cout << "ERR" << endl;
            continue;
        }

        if (s1 == "Server")
        {
            if (m.count(s2))
            {
                cout << "FAIL" << endl;
            }
            else
            {
                m[s2] = i;
                cout << "OK" << endl;
            }
        }
        else
        {
            if (m.count(s2))
            {
                cout << m[s2] << endl;
            }
            else
            {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}