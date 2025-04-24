#include <bits/stdc++.h>
using namespace std;
map<string, int> m = {
    {"JAN", 1}, {"FEB", 2}, {"MAR", 3}, {"APR", 4}, {"MAY", 5}, {"JUN", 6}, {"JUL", 7}, {"AUG", 8}, {"SEP", 9}, {"OCT", 10}, {"NOV", 11}, {"DEC", 12}};
int main()
{
    string s;
    int day = 0, year = 0;
    string month = "";
    bool x = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= '9' && s[i] >= '0' && x != 1)
        {
            day = day * 10 + (s[i] - '0');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            x = 1;
            month = month + s[i];
        }
        else if (s[i] <= '9' && s[i] >= '0' && x == 1)
        {
            year = year * 10 + (s[i] - '0');
        }
    }
    int month1 = m[month];
    // cout << year << "-" << month1 << "-" << day << endl;
    bool more_1 = 0;
    bool more_2 = 0;
    if (year < 1582) {          // 旧规则（儒略历）
        more_1 = (year%4 == 0); 
    } else {                    // 新规则（格里高利历）
        more_1 = (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    }
    if (year >= 1582 || (year == 1582 && month1 >= 10 && day >= 15))
    {
        more_2 = 1;
    }
    int all_day = 0;
    for (int i = 1; i < year; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            all_day += 366;
        }
        else
        {
            all_day += 365;
        }
    }
    for (int i = 1; i < month1; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            all_day += 31;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            all_day += 30;
        }
        else if (i == 2)
        {
            if (more_1)
            {
                all_day += 29;
            }
            else
            {
                all_day += 28;
            }
        }
    }
    all_day += day;
    if (more_2)
    {
        cout << all_day - 10 << endl;
    }
    else
    {
        cout << all_day << endl;
    }
}