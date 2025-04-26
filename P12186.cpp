#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>   // for system()
#include <windows.h> // for Sleep()

using namespace std;

// 从文件读取题号列表（每行一个题号）
vector<string> read_problems(const string &filename)
{
    vector<string> problems;
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            problems.push_back(line);
        }
    }
    return problems;
}

int main()
{
    vector<string> problems = {
        "P1202", "P1204", "P1206", "P1207",
        "P1208", "P1211", "P1217", "P1218", "P1223", "P1226", "P1234",
        "P1241", "P1252", "P1255", "P1293", "P1294", "P1296", "P1303",
        "P1308", "P1328", "P1348", "P1358", "P1372", "P1376", "P1403",
        };

    // 遍历所有题号
    for (const string &problem : problems)
    {
        string url = "https://www.luogu.com.cn/problem/" + problem;
        cout << "Opening: " << url << endl;

        // Windows 系统使用 start 命令
        system(("start " + url).c_str());

        // Linux/macOS 使用以下命令
        // system(("xdg-open " + url).c_str());  // Linux
        // system(("open " + url).c_str());      // macOS

        // 适当延迟防止同时打开过多页面
        Sleep(2000); // 100ms 间隔，Windows
        // usleep(100000); // Linux/macOS 100ms
    }

    return 0;
}