#include <stdio.h>

int main() {
	int i = 0; 
	float number, average, sum = 0;
	FILE * fp;
	fp = fopen("numbers.dat", "r");
	while(fscanf(fp, "%f$", &number) != EOF)
	{
	sum += number;
	i += 1;
	}
	fclose(fp);
	average = sum/i;
	printf("%f\n%f\n", sum, average);
	return 0;
}
