#include<stdio.h>

#define N 10

void print_array(int *a, int l)
{
	int i;
	for(i=0; i<l; i++) {
		fprintf(stdout, "%d\n", a[i]);
	}
}

int main()
{
	int a[N];
	FILE *fp;
	int i;
	
	fp = fopen("output_binary.txt", "rb");
	if(fp==NULL) {
		fprintf(stderr, "fopen failed\n");
		return 1;
	}
	fread(a, sizeof(int), N, fp);
	fclose(fp);
	print_array(a, N);
	
	fprintf(stdout, "\n\n\n");
	
	fp = fopen("output_char.txt", "r");
	if(fp==NULL) {
		fprintf(stderr, "fopen failed\n");
		return 2;
	}
/*	// reading N integers
	for(i=0; i<N; i++) { 
		fscanf(fp, "%d\n", &a[i]);
	}
*/
/*	//reading integers using feof (in case the exact number of elements is unknown)
	i = 0;
	while(!feof(fp)) {
		fscanf(fp, "%d\n", &a[i]);
		i++;
	}
*/	
	//reading integers using only fscanf until a failure
	i = 0;
	while(fscanf(fp, "%d\n", &a[i]) == 1) { //fscanf returns the number of arguments successfully read
		i++;
	}
	fclose(fp);
	print_array(a, N);
	
	return 0;
}
