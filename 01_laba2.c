#include <stdio.h>

#include <stdlib.h>

int show(int ** a, int * n) {

	for (int i = 1; i <= *n; i++) {

		for (int j = 1; j <= *n; j++) {

			printf("%d ", a[i][j]);

			}

		printf("\n");

		}

	return 1;

}

int** find_ways(int ** a, int ** b, int vershina, int length, int * n, int flow) {

	for (int i = 1; i <= *n; i++) {

		if (flow == i) {

			b[flow][i] = 0;

			}

		else if (a[flow][i] != 0) {

			if (b[flow][i] > length + a[flow][i]) {

				b[flow][i] = length + a[flow][i];
		
				if (b[vershina][i] > length + a[flow][i]) {

					b[vershina][i] = length + a[flow][i];

					}

				b = find_ways(a, b, vershina, (length + a[flow][i]), n, i);

				}

			}

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

int * ex1(int ** a, int ** b, int vershina, int length, int * n, int flow, int * find_vershina, int maximum) {

	int * lengths = malloc(sizeof(int));

	int j = 0;

	find_ways(a, b, *find_vershina, 0, n, *find_vershina);

	for (int i = 1; i <= *n; i++) {

		if (*find_vershina != i) {

			lengths[j] = b[*find_vershina][i];

			j++;
	
			}

		}

	return lengths;

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

	int * lengths = malloc(sizeof(int));

	input(a, b, n, find_vershina, nc, maximum);

	printf("vershina connections\n");

	show(a, n);

	// get lengths to each vershina

	lengths = ex1(a, b, *find_vershina, 0, n, *find_vershina, find_vershina, maximum);

	// variable for creating an asnwer

	char str[100] = "";

	// incremental variable for extracting lengths

	int k = 0;

	// write answer

	printf("the fastest ways from vershina #%d\n", *find_vershina);

	for (int i = 1; i <= *n; i++) {

		if (*find_vershina != i) {

			printf("to vershina #%d = %d\n", i, lengths[k]);

			sprintf(str, "%s%d ", str, lengths[k]);

			k++;

			}

		}

	output(str);

	return 0;

}
