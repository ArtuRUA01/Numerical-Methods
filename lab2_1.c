
#include <stdio.h>
#include <math.h>

double f(double x)
{
	return sin(x);
}

int main(int argc, char **argv)
{
	double a = 0.0, b = 1.0;
	int N = 20;
	double step = (a + b) / N;
	double x[N+1];
	FILE *file;
	file = fopen("lab2.txt", "w");
	for(int i = 0; i <= N; i++)
	{
		x[i] = a + (i * step);
		fprintf(file, "%le\t%le\n", x[i], f(x[i]));
	} 
	printf("DONE!");
	fclose(file);
	return 0;
}

