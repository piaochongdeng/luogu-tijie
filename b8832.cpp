#include <bits/stdc++.h>
using namespace std;
struct abc{
	int id;
	int t;
	int k;
	int all;
};


bool cmp(const abc &a, const abc &b) {
    if (a.all != b.all) {
        return a.all > b.all;
    }
    if (a.id != b.id) {
        return a.id < b.id;
    }
    return false;
}
int main(){
	int n;
    vector<abc> a(n);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i].t >> a[i].k;
		a[i].all=a[i].t*a[i].k;
		a[i].id=i; 
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n;i++){
		cout << a[i].id << " ";
	} 
}