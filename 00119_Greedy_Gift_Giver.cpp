#include <cstdio>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main() {
    map<string, int> name;
    queue<string> q;

    int person;
    char inputName[1000], key[1000];
    bool f = true;
    while(scanf("%d", &person) == 1) {
        if(!f) puts("");
        f = false;

        name.clear();
        for(int i = 0; i < person; i++) {
            scanf("%s", inputName);
            q.push(inputName);
            name[inputName] = 0;
        }

        for(int i = 0; i < person; i++) {
            int money, di, total;

            scanf("%s %d %d", key, &money, &di);

            if(di > 0) {
                name[key] += -money + (money % di);
                total = money / di;

                for(int p = 1; p <= di; p++) {
                    scanf("%s", key);
                    name[key] += total;
                }
            }
        }

        while(!q.empty()) {
            string key = q.front();
            q.pop();
            printf("%s %d\n", key.c_str(), name[key]);
        }
    }
}

