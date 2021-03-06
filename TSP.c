#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

#define MAX 100


typedef struct NODE
{
	int x;
	int y;
} node;

node dot[MAX];

int n;
int i = 0;

int go[MAX];
int Tours[MAX];

double sum = 0;
double min = 10000;

void tour(int k, double sum);
void swap(node [], int a, int b);
double distance(node dot[], int a, int b);

void tour(int k, double sum) 
{

	if (k == n) 
	{
		sum = sum + distance(dot, n - 1, 0);
		if (min > sum)
		{
			min = sum;
			for (int i = 0; i < n; i++)
				Tours[i] = go[i];
		}
		return;
	}
	for (int i = k; i < n; i++) 
	{
		if (k > 0) 
		{
			if (sum > min)
				i++;
		}
		swap(dot, k, i);
		tour(k + 1, sum + distance(dot, k - 1, k));
		swap(dot, k, i);
	}
}

void swap(node dot[], int a, int b)
{

	node temp = dot[a];
	dot[a] = dot[b];
	dot[b] = temp;
}

double distance(node dot[], int a, int b)
{
	return sqrt((dot[a].x - dot[b].x)*(dot[a].x - dot[b].x) + (dot[a].y - dot[b].y)*(dot[a].y - dot[b].y));
}

int main() 
{

	FILE *fp;
	fopen_s(&fp, "input6.txt", "r");
	fscanf(fp, "%d\n", &n);
	node dot[MAX];

	for (int i = 0; i < n; i++) 
	{
		fscanf(fp, "%d %d", &dot[i].x, &dot[i].y);
	}
	fclose(fp);


	for (int i = 0; i < n; i++)
	{
		go[i] = i;
	}

	tour(1, 0);
	printf("ans:\n%lf", sum);
		
	for (int i = 0; i < n; i++)
		printf("%d ", Tours[i]);
	



	return 0;
}
