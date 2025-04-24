#include <bits/stdc++.h>

using namespace std;
string s;
int cnt=0;
string a[11000];
string b[11000];
string x;
int c[11000]; // 数字栈
string d[11000]; // 字符串栈
int p=0, q=0; // 栈顶指针
int i=0;
int n=0;

int main()
{
    cin >> s;
    while(i<s.size())
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            // 如果 n>0，表示需要重复字母序列
            if(n > 0)
            {
                string temp = "";
                while(s[i]>='A' && s[i]<='Z')
                {
                    temp += s[i];
                    i++;
                }
                for(int k=0; k<n; k++)
                {
                    x += temp;
                }
                n = 0; // 重置 n
            }
            else
            {
                x += s[i];
                i++;
            }
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            n = n*10 + (s[i]-'0');
            i++;
        }
        else if(s[i]=='[')
        {
            if(n==0) n=1;
            c[p++] = n;
            d[q++] = x;
            n = 0;
            x = "";
            i++;
        }
        else if(s[i]==']')
        {
            string tmp = d[--q];
            int t = c[--p];
            for(int k=0; k<t; k++)
            {
                tmp += x;
            }
            x = tmp;
            i++;
        }
        else
        {
            // 处理其他字符
            i++;
        }
    }
    cout << x << endl;
    return 0;
}