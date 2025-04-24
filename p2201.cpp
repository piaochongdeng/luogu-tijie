#include <iostream>
#include <deque>
using namespace std;

deque<int> a,b;
int s[1000005],mx[1000005];

void f(int x){
    a.push_back(x);
    int p = a.size();
    s[p] = x + (p>1 ? s[p-1] : 0);
    mx[p] = max(s[p], mx[p-1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--){
        char c;
        cin >> c;
        
        switch(c){
            case 'I':{
                int x;
                cin >> x;
                f(x);
                break;
            }
            case 'D':{
                if(!a.empty()){
                    a.pop_back();
                    s[a.size()+1] = 0;
                    mx[a.size()+1] = 0;
                }
                break;
            }
            case 'L':{
                if(!a.empty()){
                    b.push_front(a.back());
                    a.pop_back();
                }
                break;          
            }
            case 'R':{
                if(!b.empty()){
                    f(b.front());
                    b.pop_front();
                }
                break;
            }
            case 'Q':{
                int k;
                cin >> k;
                cout << mx[k] << endl;
                break;
            }
        }
    }
    return 0;
}