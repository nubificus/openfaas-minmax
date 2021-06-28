#include <stdio.h>
#include <math.h>

int minmax(int rowcount, double **input_data, double **output_data, double *outmin, double *outmax)
{
	int low_th = 3;
	int high_th = 6;
	double *indata;
	double *outdata;
	outdata = (double *)malloc(rowcount * sizeof(double));
	//int rowcount = 262144;
	//indata = (double *)malloc(rowcount * sizeof(double));
	//FILE *f_input;
	//f_input = fopen("input_262144.csv", "r");
	//for (int i = 0; i < rowcount; i++) {
	//	fscanf(f_input, "%lf\n", &indata[i]);
	//}
	indata = *input_data;

	double *h_max, *h_min, *h_sum;
	double *d_max, *d_min, *d_sum;
	int *d_mutex;
	h_max = (double *)malloc(sizeof(double));
	h_min = (double *)malloc(sizeof(double));
	h_sum = (double *)malloc(sizeof(double));

	*h_max = 0;
	*h_min = 10000;
	*h_sum = 0;
	// find minimum + maximum
	int min = 10000;
	int max = 0;
	double sum = 0;
	for (int i = 0; i < rowcount; i++) {
		if (indata[i] > max)
			max = indata[i];
		if (indata[i] < min)
			min = indata[i];
		sum = sum + indata[i];
	}
	float mean;
	mean = sum / rowcount;
	//printf("%d %d\n", max, min);
	*outmin = min;
	*outmax = max;
	for (int i = 0; i < rowcount; i++) {
		outdata[i] =
		    ((indata[i] - min) / (max - min)) * (high_th - low_th) +
		    low_th;
	}
	*output_data = outdata;

}
