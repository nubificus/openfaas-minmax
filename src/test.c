#include <stdio.h>
#include <stdlib.h>

#include <jansson.h>

int fileread(char **ptr, ssize_t * len);
int minmax(int rowcount, double **input_data, double **output_data, double *outmin, double *outmax);

json_t *load_json(const char *text) {
    json_t *root;
    json_error_t error;

    root = json_loads(text, 0, &error);

    if (root) {
        return root;
    } else {
        fprintf(stderr, "json error on line %d: %s\n", error.line, error.text);
        return (json_t *)0;
    }
}


int load_input(char *ptr, int *rowcount, double **array)
{

        json_t *root = load_json(ptr);

	*rowcount = json_integer_value(json_object_get(root, "rowcount"));
	double *arr = malloc(*rowcount * sizeof(double));
	json_t *arrayA = json_object_get(root, "array");
	json_t *element = arrayA;
        for (int i = 0; i < *rowcount; ++i)
		arr[i] = json_real_value(json_array_get(element, i));

        if (root) {
            json_decref(root);
        }
	*array = arr;

    return 0;

}

void print_output(double min, double max, int rowcount, double *B)
{
	printf("{ \"min\" : %lf, \n", min);
	printf("\"max\" : %lf, \n", max);
	printf("\"B\" : [ ");
	for (int i = 0; i < rowcount; i++) {
		printf (" %lf", B[i]);
		if ((i == rowcount - 1)) printf(" "); else printf (", ");
	}
	printf(" ] }\n");


}
int main(int argc, char **argv)
{
	char *ptr;
	ssize_t len;
	int ret = 0;
	double min, max;

	double *A;
	double *B;
	int rowcount;

	/* Read Input */
	fileread(&ptr, &len);
	load_input(ptr, &rowcount, &A);

	ret = minmax(rowcount, &A, &B, &min, &max);

	print_output(min, max, rowcount, B);

	free(A);
	free(B);

	return ret;
}
