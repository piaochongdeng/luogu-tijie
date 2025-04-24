#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define ll long long
#define ull unsigned long long
#define ld long double
#define un unsigned
using namespace std;
int n;
int a[11000];
int j,b;
int find(int n1){
	for(int i=1;i<=n;i++)
	{
		if(a[i]==n1)
		{
			return i;
		}
		else if(a[i+1]==n1)
		{
			return i;
		}
	}
	return -1;
} 
int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	sort(a+1,a+1+n);
	
}

