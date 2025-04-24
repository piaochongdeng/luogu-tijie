#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[1100];
	string s,s1;
	int n;
	cin >> n;
	cin>>s;
	s1=s;
	sort(s.begin(),s.end());
	int ans=1;
	while(s1!=s){
        next_permutation(s.begin(),s.end());
		ans++;
	}
	cout << ans;
}