#include <bits/stdc++.h>

using namespace std;
bool hui(string s)
{
    int l=0,r=s.size()-1;
    while(l<=r)
    {
        if(s[l]!=s[r])
        {
            return 0;
        }
        l++,r--;
    }
    return 1;
}
string jin_2(int x)
{
    string s;
	while(x>0) {
		s+=to_string(x%2);
		x/=2;
	}
	string s1;
	//cout << endl;
	for(int i=s.size()-1; i>=0; i--) {
		s1+=s[i];
	}
    return s1;
}
int jin_x(int x)
{
    int ans=0;
    for(int k=2;k<=10;k++)
    {
        int n=x;
        string s;
	    while(n>0) {
		    s+=to_string(n%k);
	    	n/=k;
	    }
	    string s1;
	    //cout << endl;
    	for(int i=s.size()-1; i>=0; i--) {
	    	s1+=s[i];
	    }
        //cout << s1 << " ";
        if(hui(s1))
        {
            ans++;
        }
        //cout << k << " " ;
    }
    return ans;
    //return s1;
}
int main()
{
    int n;
    cin >> n;
    int s;
    cin >> s;
    //cout << hui("33") << endl;
    //cout << hui(jin_2(s));
    int cnt=0;
    for(int i=s;;i++)
    {
        //cout << jin_2(i) <<" " << hui(jin_2(i)) <<" " << i<< endl;
        if(cnt==n)
        {
            break;
        }
        string s=to_string(i);
        if(jin_x(i)>=2)
        {
            cout << i << endl;
            cnt++;
        }
    }
    //system("pause");
    return 0;
}
