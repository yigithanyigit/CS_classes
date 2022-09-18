#include<stdio.h>

#define N 10

int main()
{
	int a[N] = {0,923,2870,934,-502,340294,32423,5,-235,-1};
	FILE *fp;
	int i;
	
	fp = fopen("output_binary.txt", "wb");
	if(fp==NULL) {
		fprintf(stderr, "fopen failed\n");
		return 1;
	}
	fwrite(a, sizeof(int), N, fp);
	fclose(fp);
	
	fp = fopen("output_char.txt", "w");
	if(fp==NULL) {
		fprintf(stderr, "fopen failed\n");
		return 2;
	}
	for(i=0; i<N; i++) {
		fprintf(fp, "%d\n", a[i]);
	}
	fclose(fp);
	
	return 0;
}
