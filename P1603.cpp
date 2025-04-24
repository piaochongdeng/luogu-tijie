   #include <bits/stdc++.h>
   using namespace std;

   map<string, int> m;

   int main() {
       // 初始化数字词与对应的数字映射
       m["one"] = 1;
       m["two"] = 2;
       m["three"] = 3;
       m["four"] = 4;
       m["five"] = 5;
       m["six"] = 6;
       m["seven"] = 7;
       m["eight"] = 8;
       m["nine"] = 9;
       m["ten"] = 10;
       m["eleven"] = 11;
       m["twelve"] = 12;
       m["thirteen"] = 13;
       m["fourteen"] = 14;
       m["fifteen"] = 15;
       m["sixteen"] = 16;
       m["seventeen"] = 17;
       m["eighteen"] = 18;
       m["nineteen"] = 19;
       m["twenty"] = 20;
       m["a"] = 1;
       m["both"] = 2;
       m["another"] = 1;
       m["first"] = 1;
       m["second"] = 2;
       m["third"] = 3;
       
       vector<string> words(6); // 存储输入的6个单词
       for(int i = 0; i < 6; i++) {
           cin >> words[i];
           // 将单词转换为小写
           transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
           // 去除末尾的句号
           if(words[i].back() == '.') {
               words[i].pop_back();
               break;
           }
       }

       vector<string> nums; 

       for(const auto& w : words) {
           if(m.count(w)) {
               int num = m[w];
               int val = (num * num) % 100;
               stringstream ss;
               ss << setw(2) << setfill('0') << val;
               nums.push_back(ss.str());
           }
       }

       if(nums.empty()) {
           cout << "0" << endl;
           return 0;
       }
       sort(nums.begin(), nums.end());
    //    string min_num = "";
    //    do {
    //        string tmp = "";
    //        for(const auto& s : nums) {
    //            tmp += s;
    //        }
    //        tmp.erase(0, tmp.find_first_not_of('0'));
    //        if(min_num.empty() || tmp < min_num) {
    //            min_num = tmp;
    //        }
    //    } while(next_permutation(nums.begin(), nums.end()));
        for(const auto& s : nums)
        {
            cout << s;
        }
       //cout << min_num << endl;

       return 0;
   }