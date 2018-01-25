#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> slogan;
    string a, b;

    int n;
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++) {
        getline(cin, a);
        getline(cin, b);

        slogan[a] = b;
        slogan[b] = a;
    }

    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        getline(cin, a);
        cout << slogan[a] << endl;
    }
}
