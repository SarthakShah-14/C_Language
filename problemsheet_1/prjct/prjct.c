#include <stdio.h>
#include <string.h>

struct census {
    char name[20];
    int pop;
    float litl;
};

void pointer(int n, struct census *p) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((p + i)->pop > (p + j)->pop) {
                struct census temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", (p + i)->name, (p + i)->pop);
    }
}

int main() {
    struct census c[2];
    int n = 2;

    for (int i = 0; i < n; i++) {
        printf("Enter the name of city %d: \n", i + 1);
        scanf("%s", c[i].name);
        printf("Enter the population of city %s: \n", c[i].name);
        scanf("%d", &c[i].pop);
    }

    pointer(n, c);

    return 0;
}