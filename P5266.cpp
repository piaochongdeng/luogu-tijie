#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n1;
map<string , int > m;

int main()
{
    cin >> n1;
    for(int i=1;i<=n1;i++)
    {
        int n;
        string s;
        cin >> n;
        if(n==1)
        {
            cin >> s;
            int sc;
            cin >> sc;
            m[s]=sc;
            cout << "OK\n";
        }
        else if(n==2)
        {
            cin >> s;
            if(m[s]==0)
            {
                cout << "Not found\n";
                continue;
            }
            else
            {
                cout << m[s] << endl;    
            }
        }else if(n==3)
        {
            cin >> s;
            if(m[s]==0)
            {
                cout << "Not found\n";
                continue;
            }
            m[s]=0;
            cout << "Deleted successfully\n";
        }
        else if(n==4)
        {
            int cnt=0;
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(it->second==0)
                {
                    continue;
                }
                cnt++;
            }
            cout << cnt << "\n";
        }
    }
}