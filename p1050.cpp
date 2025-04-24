#include <bits/stdc++.h>

using namespace std;
string add(string a, string b) {
    string result;
    int carry = 0, sum = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while(i >=0 || j >=0 || carry){
        sum = carry;
        if(i >=0) sum += a[i--] - '0';
        if(j >=0) sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}
bool hui(string s)
{
    int r=s.size()-1,l=0;
    while(l<=r)
    {
        if(s[l]!=s[r])
        {
            return 0;
        }
        l++;
        r--;
    }
    return 1;

}

int main()
{
    //cout << add("100","9999");
    //system("pause");
    string s;
    string s1;
    cout << hui("4884");
    int ans=0;
    cin >> s;
    int n;
    cin >> n;
    while(ans<=n)
    {
        s1=add(s1,s);
        if(hui(s1)==1)
        {
            break;
        }
        s=s1;
        reverse(s1.begin(),s1.end());
        
        //cout << s <<" " << s1 <<endl;
        ans++;
    }
    if(ans==n)

    cout <<"STEP="<< ans;
    return 0;
}
