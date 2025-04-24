#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans[110000];
int check[11000];
void dfs(int pos) {
	if(pos==m+1){
		for(int i=1;i<=m;i++){
			cout << ans[i]<< " ";
		}
		cout << "\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(check[i]==0){
			check[i]=1;
			ans[pos]=i; 
			dfs(pos+1);
			check[i]=0;
		}
		
	}
}
int main()
{
	n=10,m=5;
	dfs(1);
}