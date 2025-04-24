        #include <bits/stdc++.h>

        using namespace std;

        int main()
        {
            string s;
            cin >> s;
            int a,b,c;
            a=b=c=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]>='0'&&s[i]<='9')
                {
                    a++;
                }else if(s[i]>='a'&&s[i]<='z')
                {
                    b++;
                }else 
                {
                    c++;
                }
            }
            cout <<a<< " " << b << " " << c <<endl;
        //    system("paus e");
            return 0;
        }
