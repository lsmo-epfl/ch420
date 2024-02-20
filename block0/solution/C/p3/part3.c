#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float potential(float eps, float sig, float r) {
	float V;
	V = 4*eps*(pow(sig/r,12)-pow(sig/r,6));
	return V;
}

int main() {
        int size = 200;	
	float eps, sig, r[size], V[size];
        printf("Enter epsilon (K) followed by sigma (Angstrom): ");
        scanf("%f \n", &eps);
	scanf("%f", &sig);
	FILE * fp; 
	fp = fopen("data.dat", "w");
	for (int i = 0; i < size; i += 1){
		r[i] = sig*(0.95+i/(size/4.0));
		V[i] = potential(eps, sig, r[i]);
		fprintf(fp, "%f %f\n", r[i]/sig, V[i]/eps);
	}
	fclose(fp);
}
