#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <limits>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
#include <string>

#define ll long long
#define ld long double
#define un unsigned
#define ull unsigned long long
/*二分答案：
最小值最大：定小了更新
最大值最小：定大了更新
*/using namespace std;
int read()
{
	int f=1,ans=0;
	char x;
	x=getchar();
	while(x<'0'||x>'9')
	{
		if(x=='-')
		{
			f=-1;
		}
		x=getchar();
	}
	while (x>='0'&&x<='9')
	{
		ans=ans*10+x-'0';
		x=getchar();
	}
	return f*ans;
}
int n;
string s[110000];
string add(string tmp)
{
	string s2;
	bool x=0;
	for(int i=0;i<tmp.size();i++)
	{
		if(tmp[i]>='a'&&tmp[i]<='z')
		{
			tmp[i]-=('a'-'A');
		}else if(tmp[i]>='A'&&tmp[i]<='Z')
		{
			tmp[i]+=('a'-'A');
		}
		if(tmp[i]>='0'&&tmp[i]<='9')
		{
			x=1;
			s2+=tmp[i];
		}
	}
	if(x)
	{
		string s3;
		for(int i=s2.size()-1;i>=0;i--)
		{
			s3+=s2[i];
		}
		cout <<s3 << "\n";
		return s3;
	}
	return tmp;
}
int main()
{
	//freopen(".txt","w",stdout);	
	string s1;
	while(cin >> s[++n]);
	for(int i=n;i>=1;i--)
	{
		cout << add(s[i]) <<' ';
	}
    return 0;
}
/*激进的奶牛（二分答案模板，最小值最大）here is
int n,c;
int a[1100000];
bool check(int x)
{
	int tot=1,now=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[now]<x)
		{
			continue;
		}
		tot++;
		now=i;
	}
	if(tot>=c)
	{
		return false;
	}else{
		return true;
	}
}
int main()
{
	cin >> n >> c;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int l,r;
	int ans=0;
	l=1;
	r=a[n]-a[1];
	int mid=(l+r)/2;
	while(l<=r)
	{
		if(check(mid))
		{
			r=mid-1;
		}else{
			l=mid+1;
			ans=mid;
		}
		mid=(l+r)/2;
	}
	cout << ans;

    return 0;
}*/
/*
数列分段II(最大值最小) here is

#include <bits/stdc++.h>
using namespace std;
long long l,r;
long long  n,m,ans,a[1000005];
bool check(long long h){
	long long he=0;
	int tot=1;
	for(int i=1;i<=n;i++){
		if(a[i]+he>h){
			he=a[i];
			tot++;
		}else he+=a[i];
	}
	return tot<=m;
}
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		r+=a[i];
		l=max(l,a[i]);
	}while(l<=r){

		long long mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	cout << ans << '\n';
}

*/
