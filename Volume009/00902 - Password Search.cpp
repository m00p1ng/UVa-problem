#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, max;
    string s, temp, sub;
    map<string, int> freq;

    while(cin >> n >> s) {
        freq.clear();
        int len = s.length();
        max = -1;

        for(int i = 0; i <= len-n; i++) {
            temp = s.substr(i, n);
            freq[temp]++;
            if(freq[temp] > max) {
                max = freq[temp];
                sub = temp;
            }
        }
        cout << sub << endl;
    }
}
