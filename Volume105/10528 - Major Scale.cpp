#include <cstdio>
#include <cstring>

char key_map[][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
char c_map[128];
int scale[12];

void c_map_init() {
    c_map['C'] = 11;
    c_map['D'] = 9;
    c_map['E'] = 7;
    c_map['F'] = 6;
    c_map['G'] = 4;
    c_map['A'] = 2;
    c_map['B'] = 0;
}

void gen_scale() {
    scale[0] = 0b101011010101;
    for(int i = 1; i <= 12; i++) {
        int temp = scale[i-1]&1;
        scale[i] = (scale[i-1]>>1) | (temp << 11);
    }
}

int main() {
    c_map_init();
    gen_scale();
    char buff[10000];
    while(fgets(buff, 10000, stdin), strcmp(buff, "END\n")) {
        buff[strlen(buff)-1] = '\0';
        int num = 0;
        char* p = strtok(buff, " ");

        while(p != NULL) {
            int sh = c_map[p[0]] - (p[1] == '#');
            num |= 1<<sh;
            p = strtok(NULL, " ");
        }

        int first = true;
        for(int i = 0; i < 12; i++) {
            int flag = true;
            int a = scale[i];
            int b = num;
            for(int j = 0; j < 12; j++) {
                if((b&1) == 1 && (a&1) != 1) {
                    flag = false;
                    break;
                }
                a >>= 1, b >>= 1;
            }
            if(flag) {
                if(!first) printf(" "); first = false;
                printf("%s", key_map[i]);
            }
        }
        puts("");
    }
}
