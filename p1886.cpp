#include <iostream>
#include <deque>
using namespace std;
struct node
{
    int val, id;
};
deque<node> q1, q2;
int a[2100000];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < k; i++)
    {
        while (q1.size() && q1.back().val >= a[i])
        {
            q1.pop_back();
        }
        q1.push_back({a[i], i});
    }
    for (int i = k, j = 1; i <= n; i++, j++)
    {
        while (q1.size() && q1.front().id < j)
        {
            q1.pop_front();
        } // cout << q1.size() << endl;
        while (q1.size() && q1.back().val >= a[i])
        {
            q1.pop_back();
        }
        q1.push_back({a[i], i});

        cout << q1.front().val << " ";
    }
    cout << "\n";

    for (int i = 1; i < k; i++)
    {
        while (q2.size() && q2.back().val <= a[i])
        {
            q2.pop_back();
        }
        q2.push_back(node{a[i], i});
    }
    for (int i = k, j = 1; i <= n; i++, j++)
    {
        while (q2.size() && q2.back().val < a[i])
        {
            q2.pop_back();
        }
        q2.push_back(node{a[i], i});
        while (q2.size() && q2.back().id < j)
        {
            q2.pop_front();
        }

        cout << q2.front().val << " ";
    }
}