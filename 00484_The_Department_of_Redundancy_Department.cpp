#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main() {
    int temp;

    map<int ,int> m;
    vector<int> v;

    while(scanf("%d", &temp) == 1) {
        if(m[temp] == 0) {
            v.push_back(temp);
        }
        m[temp]++;
    }

    for(int i = 0; i < v.size(); i++) {
        printf("%d %d\n", v[i], m[v[i]]);
    }
}
