#include <bits/stdc++.h>
#include <thread>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("www.txt","w",stdout);
    int n = 10000000;
    vector<int> a(n);
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        a[i] = i + 1;
    }

    // 使用多线程预先转换字符串
    int num_threads = thread::hardware_concurrency();
    if(num_threads == 0) num_threads = 4; // 默认4个线程
    vector<thread> threads;
    auto worker = [&](int start, int end){
        for(int i = start; i < end; ++i){
            s[i] = to_string(a[i]);
        }
    };
    int chunk = n / num_threads;
    for(int i = 0; i < num_threads; ++i){
        int start = i * chunk;
        int end = (i == num_threads - 1) ? n : start + chunk;
        threads.emplace_back(worker, start, end);
    }
    for(auto &t : threads){
        t.join();
    }

    // 创建索引数组
    vector<int> indices(n);
    for(int i = 0; i < n; ++i){
        indices[i] = i;
    }

    // 多线程排序可以使用并行排序库，如 TBB，但这里使用单线程 std::sort
    sort(indices.begin(), indices.end(), [&](const int &x, const int &y) -> bool{
        return s[x] < s[y];
    });

    for(auto idx : indices){
        cout << a[idx] << "\n";
    }

    return 0;
}