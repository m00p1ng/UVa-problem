#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int parent[26];
int height[26];

int find_set(int i) {
    if(i == parent[i]) return i;
    return find_set(parent[i]);
}

bool union_set(string s) {
    int pa = find_set(s[0] - 'A');
    int pb = find_set(s[1] - 'A');

    if(pa == pb) return false;
    if(height[pa] > height[pb])
        parent[pb] = pa;
    else {
        parent[pa] = pb;
        if(height[pa] == height[pb]) height[pb]++;
    }
    return true;
}

int main() {
    int testcase;
    scanf("%d\n\n", &testcase);

    while(testcase--) {
        string s;
        int range;

        getline(cin, s);
        range = s[0]-'A';

        memset(height, 0, sizeof(height));
        for(int i = 0; i <= range; i++) parent[i] = i;

        while(getline(cin, s) && !s.empty()) {
            if(union_set(s)) range--;
        }

        printf("%d\n", range+1);
        if(testcase) puts("");
    }
}

