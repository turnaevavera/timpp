#include <stdio.h>

#include <stdlib.h>

#include <string.h>

struct Wrapper

{

	int arr[100];

};

int show(int ** a, int * n) {

	for (int i = 1; i <= *n; i++) {

		for (int j = 1; j <= *n; j++) {

			printf("%d ", a[i][j]);

			}

		printf("\n");

		}

	return 1;

}

int** find_len(int ** a, int ** b, int vershina, int length, int * n, int flow, struct Wrapper marked) {

	marked.arr[flow]++;

	for (int i = 1; i <= *n; i++) {

		if (flow == i) {

			b[flow][i] = 0;

			}

		else if (a[flow][i] != 0 && marked.arr[i] == 0) {

			b = find_len(a, b, vershina, (length + a[flow][i]), n, i, marked);

			}

		}

	int found = 1;

	for (int i = 1; i <= *n; i++) {

		if (marked.arr[i] != 1) {

			found = 0;

			break;

			}

		}

		if (found > 0) {

			b[vershina][flow] = length;

			}

		return b;

}

int input(int ** a, int ** b, int * n, int * find_vershina, int nc, int maximum) {

	FILE* file = fopen("input.txt", "r"); // read file

	fscanf(file, "%d", n); // get n

	// initialize two dimensional array

	for (int i = 0; i<nc; i++) {

		b[i] = malloc(sizeof(int)*nc);

		a[i] = malloc(sizeof(int)*nc);

		}

		// get array

	for (int i = 1; i <= *n; i++) {

		for (int j = 1; j <= *n; j++) {

			fscanf(file, "%d", &a[i][j]);

			b[i][j] = maximum;

			}

		}

	fscanf(file, "%d", find_vershina); // get find vershina

	fclose(file);

	return 0;

}

int output(char * s) {

	FILE* file = fopen("output.txt", "w"); // open file to write

	fprintf(file,"%s", s);
	
	fclose(file);

	return 0;

}

int ex2(int ** a, int ** b, int vershina, int length, int * n, int flow, struct Wrapper marked, int * find_vershina, int maximum) {

		// calculate routes from each vershina

	for (int i = 1; i <= *n; i++) {

			*find_vershina = i;

			find_len(a, b, *find_vershina, 0, n, *find_vershina, marked);

			}

			// get minimal route from b array data

	int min = maximum;

	for (int i = 1; i <= *n; i++) {

		for (int j = 1; j <= *n; j++) {

			if (b[i][j] != 0 && b[i][j] < min)

			min = b[i][j];

			}

		}

	return min;

}

int main()

{

		// custom variables

	int nc = 101; // maximum array elements

	int maximum = 1001; // "infinite" number

	// init arrays and their lengths

	int ** a = malloc(sizeof(int)*nc),

	** b = malloc(sizeof(int)*nc);

	int * n = malloc(sizeof(int));

	int * find_vershina = malloc(sizeof(int)); // search ways from what vershina

	input(a, b, n, find_vershina, nc, maximum);

	struct Wrapper marked;

	for (int i = 1; i < *n + 1; i++) {

		marked.arr[i] = 0;

	}

	printf("vershina connections:\n");

	show(a, n);

	int min = ex2(a, b, *find_vershina, 0, n, *find_vershina, marked, find_vershina, maximum);

	char str[100];

	sprintf(str, "%d", min);

	output(str);

	printf("minimal possible route to visit each vershina exactly one time is %d long\n", min);

	return 0;

}
