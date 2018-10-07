#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;

int n, t, num[20];
bool sel_num[20], found = false;
set<string> out_set;
vector<string> out;

int calc_ans() {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += sel_num[i] * num[i];
    }
    return ans;
}

void produce_ans() {
    int ans = calc_ans();
    if(ans != t) return;

    int first = true;
    string s = "";

    for(int i = 0; i < n; i++) {
        if(sel_num[i] == 1) {
            if(first) {
                first = false;
            } else {
                s += "+";
            }
            s += to_string(num[i]);
        }
    }
    if(out_set.find(s) == out_set.end()) {
        out_set.insert(s);
        out.push_back(s);
    }
}

void find_ans(int d) {
    if(d == n) {
        produce_ans();
        return;
    }

    for(int i = d+1; i <= n; i++) {
        sel_num[i] = true;
        find_ans(i);
        sel_num[i] = false;
    }
}

int main() { 
    while(scanf("%d %d", &t, &n), n || t) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        out_set.clear();
        out.clear();
        memset(sel_num, 0, sizeof(sel_num));

        find_ans(-1);

        printf("Sums of %d:\n", t);
        if(out.size() > 0) {
            for(auto it : out) {
                puts(it.c_str());
            }
        } else {
            puts("NONE");
        }
    }
}
