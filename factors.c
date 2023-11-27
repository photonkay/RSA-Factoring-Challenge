#include "factors.h"

/**
 * factorize - factors number and prints result
 * @n: number to factorize
 * Return: void
 */
void factorize(long long int n)
{
	long long int i;

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			printf("%lld=%ld*%ld\n", n, n/i, i);
			break;
		}
	}
}

/**
 * main - main entry point of factoring code
 * @argc: command line arg count
 * @argv: command line arg array
 * Return: 0 on  success
 */
int main(int argc, char *argv[])
{
	char *filename;
	FILE *file;
	char line[512];
	long long int num;

	if (argc !=2)
	{
		fprintf(stderr, "Usage: ./factors <file>\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");

	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		num = atoi(line);
		factorize(num);
	}

	fclose(file);
	return (0);
}
