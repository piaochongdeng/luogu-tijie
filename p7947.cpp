    #include<bits/stdc++.h>
    using namespace std;
    queue<int> q;
    int n,m;
    int fen(int x)
    {
        int ans=0;
        int cnt=1;
        while(1)
        {
            cnt++;
            if(x==1)
            {
                return ans;
            }
            else if(x%cnt==0)
            {
                x/=cnt;
                ans+=cnt;
                q.push(cnt);
                cnt=1;
            }
            
        }
    }
    int main()
    {
        cin >> n >> m;
        int ans=fen(n);
        if(ans>m)
        {
            cout<<-1;
            return 0;
        }else
        {
            cout << q.size()+(m-ans) << endl;
            while(!q.empty())
            {
                cout << q.front() << " ";
                q.pop();
            }
            for(int i=1;i<=m-ans;i++)
            {
                cout << 1 << " ";
            }
        }
    }