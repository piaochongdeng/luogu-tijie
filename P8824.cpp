#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;
map<string , int > m;
struct ab{
    string id;
    int num;
};
bool cmp(ab a , ab b)
{
    return a.num > b.num;
}
int main()
{
    cin >> n;
    string s;
    for(int j=1;j<=n;j++)
    {
        cin >> s;
        if(s=="touch")
        {
            string y;
            cin >> y;
            if(m[y]!=0)
            {
                continue;
            }
            m[y]=j;
        }
        else if(s=="rm")
        {
            string y;
            cin >> y;
            if(m[y]==0)
            {
                continue;
            }
            m[y]=0;
        }
        else if(s=="rename")
        {
            string y,z;
            cin >> y >> z;
            if(m[y]==0||m[z]!=0)
            {
                continue;
            }
            m[z]=m[y];
            m[y]=0;
        }else if(s=="ls")
        {
            ab a[1100];
            int tail=1;
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(it->second==0)
                {
                    continue;
                }
                else
                {
                    a[tail].id=it->first;
                    a[tail].num=it->second;
                    tail++;
                }
            }
            sort(a+1,a+tail,cmp);
            for(int i=tail-1;i>=1;i--)
            {
                cout << a[i].id << "\n";
            }
        }
    }
}