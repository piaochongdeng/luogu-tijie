#include <bits/stdc++.h>

using namespace std;

int main()
{
   string s;
   cin >> s;
   int k;
   cin >> k;
   k++;
   int cnt=0;
   while(cnt!=s.size())
   {
        k--;
        if(k==0)
        {
            break;
        }
        //cout << s[cnt] << " " << s[cnt+1] << " kill";
        if(s[cnt]-'0'>s[cnt+1]-'0')
        {
            //cout << s[cnt] << endl;
            s.erase(cnt,1);
            cnt--;
            
        }else
        {
            //cout << s[cnt+1]<<endl;
            s.erase(cnt+1,1);
            //cnt--;
        }
        cnt++;
   }
   cout << s;
   // system("pause");
    return 0;
}
