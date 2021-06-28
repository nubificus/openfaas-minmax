#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int ret = 0;

	int rowcount = 262144;
	double *indata = (double *)malloc(rowcount * sizeof(double));
	FILE *f_input;
	f_input = fopen("input_262144.csv", "r");
	for (int i = 0; i < rowcount; i++) {
		fscanf(f_input, "%lf\n", &indata[i]);
	}
	printf ("{ \"array\" : [ \n");
	for (int i = 0; i < rowcount; i++) {
		printf("%lf", indata[i]);
		if (i == (rowcount - 1)) printf(" "); else printf(", ");
	}
	printf ("], \n");
	printf("\"rowcount\" : %d\n", rowcount); 
	printf ("} \n");

	return ret;
}
