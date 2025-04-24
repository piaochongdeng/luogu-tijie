#include <bits/stdc++.h>

using namespace std;
bool a[11000000]={true};
void ai(){
    for(int i=0;i<=11000000;i++)a[i]=true;
    a[0]=a[1]=false;
    for(int i=2;i<=11000000;i++){
        if(a[i]){
            for(int j=2*i;j<=11000000;j+=i){
                a[j]=false;
            }
        }
    }
}
int main()
{
    int n;
    ai();
    cin >> n;
    for(int i=4;i<=n;i+=2)
    {
        int x=n;
        
    }
    //system("pause");
    return 0;
}
