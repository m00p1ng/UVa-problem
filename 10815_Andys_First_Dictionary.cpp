#include <iostream>
#include <set>
using namespace std;

int main() {
    string temp;
    set<string> s;
    while(cin >> temp, !cin.eof()) {
        string clean_str = "";
        for(int i = 0; i < temp.length(); i++) {
            if(isalpha(temp[i])) {
                clean_str += tolower(temp[i]);             
            } else if(clean_str != "") {
                s.insert(clean_str);
                clean_str = "";
            }
        }
        if(clean_str != "") {
            s.insert(clean_str);
            clean_str = "";
        }
    }
    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
}
