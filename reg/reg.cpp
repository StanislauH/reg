#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
int main() {
    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "file is not found";
        exit(0);
    }
    string s;
    vector <string> vec;
    while (getline(in, s)) {
        vec.push_back(s + " ");
    }
    regex r(R"(^([0-3][0-9])/([0-1][0-9])/([1-2][0-9][0-9][0-9]) )");
    smatch sm;
    int cnt = 0;
    for (int i = 0; i < vec.size(); i++) {
        regex_search(vec[i], sm, r);
        if (sm.size() == 0) continue;
        int day = stoi(string(sm[1]));
        int month = stoi(string(sm[2]));
        int year = stoi(string(sm[3]));
        if (day == 0 || month == 0) continue;
        if (month == 2 && day == 29 && year % 4 != 0) continue;
        if (year < 1800 || year > 2100) continue;
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day >= 32)continue;
        if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day >= 31)continue;
        cnt++;
    }
    cout << cnt;
}