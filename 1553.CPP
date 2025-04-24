#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    // int x=int(s.find('%'));
    // cout << s.substr(0,x) << " " << s.substr(x+1,s.size());
    int x=int(s.find('.'));
    int y=int(s.find('/'));
    int z=int(s.find('%'));
    if(x==-1&&y==-1&&z==-1)
    {
        string s1;
        for(int i=s.size()-1;i>=0;i--)
        {
            s1+=s[i];
        }
        int x1=0;
        while(x1 < s1.size()-1 && s1[x1]=='0')
        {
            x1++;
        }
        for(int i=x1;i<s1.size();i++)
        {
            cout << s1[i];
        }
        return 0;
    }
    if(x!=-1)
    {
        string s1;
        string s2;
        s1=s.substr(0,x);
        s2=s.substr(x+1,s.size());
        string y1,y2;
        for(int i=s1.size()-1;i>=0;i--)
        {
            y1+=s1[i];
        }
        int x1=0;
        while(x1 < y1.size()-1 && y1[x1]=='0')
        {
            x1++;
        }
        for(int i=x1;i<y1.size();i++)
        {
            cout << y1[i];
        }
        cout << '.';
        for(int i=s2.size()-1;i>=0;i--)
        {
            y2+=s2[i];
        }
        int x2=y2.size()-1;
        //cout << s2 << '\n';
        while(x2 >=1 && y2[x2]=='0')
        {
            x2--;
        }
        for(int i=0;i<=x2;i++)
        {
            cout << y2[i];
        }
        return 0;
    }
    else if(y!=-1)
    {
        string s1;
        string s2;
        s1=s.substr(0,y);
        s2=s.substr(y+1,s.size());
        string y1,y2;
        for(int i=s1.size()-1;i>=0;i--)
        {
            y1+=s1[i];
        }
        int x1=0;
        while(x1 < y1.size()-1 && y1[x1]=='0')
        {
            x1++;
        }
        for(int i=x1;i<y1.size();i++)
        {
            cout << y1[i];
        }
        cout << '/';
        for(int i=s2.size()-1;i>=0;i--)
        {
            y2+=s2[i];
        }
        int x2=0;
        while(x2 < y2.size()-1 && y2[x2]=='0')
        {
            x2++;
        }
        for(int i=x2;i<y2.size();i++)
        {
            cout << y2[i];
        }
        return 0;
    }else if(z!=-1)
    {
        string s1=s.substr(0,z);
        string s2;
        for(int i=s1.size()-1;i>=0;i--)
        {
            s2+=s1[i];
        }
        int x1=0;
        while(x1 < s2.size()-1 && s2[x1]=='0')
        {
            x1++;
        }
        for(int i=x1;i<s2.size();i++)
        {
            cout << s2[i];
        }
        cout << "%";
        return 0;
    }
}