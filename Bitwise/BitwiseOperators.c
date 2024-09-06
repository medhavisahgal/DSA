#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void recursive_calculate(int n, int k, int i, int j, int* maxand, int* maxor, int* maxxor) {
    if (i > n) {
        return;
    }

    if (j > n) {
        recursive_calculate(n, k, i + 1, i + 2, maxand, maxor, maxxor);
        return;
    }

    int cand = i & j;
    int cor = i | j;
    int cxor = i ^ j;

    if (*maxand < cand && cand < k) {
        *maxand = cand;
    }
    if (*maxor < cor && cor < k) {
        *maxor = cor;
    }
    if (*maxxor < cxor && cxor < k) {
        *maxxor = cxor;
    }

    recursive_calculate(n, k, i, j + 1, maxand, maxor, maxxor);
}

void calculate_the_maximum(int n, int k) {
    int maxand = 0;
    int maxor = 0;
    int maxxor = 0;
    recursive_calculate(n, k, 1, 2, &maxand, &maxor, &maxxor);
    printf("%d\n%d\n%d\n", maxand, maxor, maxxor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
