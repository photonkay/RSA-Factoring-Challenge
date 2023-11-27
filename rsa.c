#include <stdio.h>
#include <stdlib.h>

void factorize(long long int n) {
    printf("%lld=", n);

    while (n % 2 == 0) {
        printf("2*");
        n /= 2;
    }

    for (long long int i = 3; i <= n; i += 2) {
        while (n % i == 0) {
            printf("%lld", i);
            n /= i;

            if (n != 1) {
                printf("*");
            }
        }
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        long long int num = atoll(line);
        factorize(num);
    }

    fclose(file);
    return 0;
}
