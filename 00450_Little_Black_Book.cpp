#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct book {
    char title[100];
    char firstname[100];
    char lastname[1000];
    char home_address[100];
    char department[100];
    char home_phone[100];
    char work_phone[100];
    char campus[100];
};

book create_book(char *buff, char *department) {
    char *p;
    char out[10][100];
    p = strtok(buff, ",");
    int idx = 0;

    while(p) {
        strcpy(out[idx++], p);
        p = strtok(NULL, ",");
    }

    book b;
    strcpy(b.title, out[0]);
    strcpy(b.firstname, out[1]);
    strcpy(b.lastname, out[2]);
    strcpy(b.home_address, out[3]);
    strcpy(b.home_phone, out[4]);
    strcpy(b.work_phone, out[5]);
    strcpy(b.campus, out[6]);
    strcpy(b.department, department);

    return b;
}

bool cmp(book a, book b) {
    return strcmp(a.lastname, b.lastname) < 0;
}

int main() {
    int ts;
    char department[1000];
    char buff[1000];
    vector<book> books;
    scanf("%d\n", &ts);

    while(ts--) {
        fgets(department, 1000, stdin);
        department[strlen(department)-1] = '\0';

        while(fgets(buff, 1000, stdin) && strcmp(buff, "\n")) {
            buff[strlen(buff)-1] = '\0';
            books.push_back(create_book(buff, department));
        }
    }
    sort(books.begin(), books.end(), cmp);

    for(int i = 0; i < books.size(); i++) {
        puts("----------------------------------------");
        printf("%s %s %s\n", books[i].title, books[i].firstname, books[i].lastname);
        puts(books[i].home_address);
        printf("Department: %s\n", books[i].department);
        printf("Home Phone: %s\n", books[i].home_phone);
        printf("Work Phone: %s\n", books[i].work_phone);
        printf("Campus Box: %s\n", books[i].campus);
    }
}
