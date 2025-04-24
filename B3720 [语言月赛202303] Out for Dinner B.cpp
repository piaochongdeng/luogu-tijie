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
ll n;
int main(){
	
	cin >> n;
	char a,b;
	cin >>a>> b;
	ld x,y;
	x=0;
	if(a=='B')
	{
		if(b=='C')
		{
			x=0.6;
		}
		else x=0.8;
	}
	else if(a=='C'){
		if(b=='B')
		{
			x=0.6;
		}else
		{
			x=0.7;
		}
	}
	if(b=='B'){
		x=0.8;
	}else if(b=='C'){
		x=0.7;
	}
	cout <<x*n;
} 
