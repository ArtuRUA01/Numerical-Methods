
#include <stdio.h>
#include "math.h"

double X[1000];
double Y[1000];

double f(double x)
{
	return sin(x);
}

int readdata()
{
	FILE *file;
	file = fopen("lab2.txt", "r");
	int i = 0;
	while(!feof(file))
	{
		fscanf(file, "%le\t%le", &X[i], &Y[i]);
		i++;
	}
	fclose(file);
	return i;
}

double wkx(int k, double x)
{
	int i;
	double p = 1;
	for (i = 0; i<=k; i++)
	{
		p = p * (x - X[i]);
	}
	return p;
}

double rr(int k)
{
	int i, j;
	double sum = 0;
	for (i = 0; i<=k; i++)
	{
		double p = 1;
		
		for (j = 0; j<=k; j++)
		{
			if(j!=i)
			{
				p = p * (X[i] - X[j]);
			}
		}
		sum += Y[i]/p;
	}
	return sum;
}

double nn(double x, int N)
{
	double S = Y[0];
	int k;
	for(k = 1; k<=N; k++)
	{
		S = S + wkx(k-1, x) * rr(k);
	}	
	return S;
}

int main()
{
	//printf("START\n");
	int j;
	int N = readdata() - 2;
	printf("%d\n", N);
	double R;
	double x=X[0];
	double h=(X[N]-X[0])/(20*N);
	FILE *fileNN, *fileWKX, *fileR;
	fileNN = fopen("outputNN.txt", "w");
	fileWKX = fopen("outputWKX.txt", "w");
	fileR = fopen("outputR.txt", "w");
	for(j = 0; j <= 20*N; j++)
	{
		fprintf(fileNN, "%le\t%le\n", x, nn(x, N));
		R = fabs(f(x) - nn(x, N));
		fprintf(fileWKX, "%le\t%le\n", x, wkx(N, x));
		fprintf(fileR, "%le\t%le\n", x, R);
		x = x + h;
	}
	fclose(fileNN);
	fclose(fileWKX);
	fclose(fileR);
	printf("FINISH");
	return 0;
}
