#include <stdio.h>
#include <stdlib.h>

// Function to swap two values
void swap(long long int *a, long long int *b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

void factorize(long long int n) {
    printf("%lld=", n);

    // Array to store the factors
    long long int factors[256];
    int factorIndex = 0;

    while (n % 2 == 0) {
        n /= 2;
        factors[factorIndex++] = 2;
    }

    for (long long int i = 3; i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            factors[factorIndex++] = i;
        }
    }

    // Print factors in reverse order
    for (int i = factorIndex - 1; i >= 0; --i) {
        printf("%lld", factors[i]);

        if (i != 0) {
            printf("*");
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
