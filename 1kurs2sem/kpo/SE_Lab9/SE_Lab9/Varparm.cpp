#include "Varparm.h"
#include <cfloat>
namespace Varparm {
	int ivarparm(int k, ...)
	{
		int* d = &k;
		int proisv=1;
		for (int i = 1; i <= k; i++)
		{
			proisv *= *(d + i);
		}
		return proisv;
	}
	int svarparm(short k, ...)
	{
	    int* d =(int*) & k;
		int max = *(d+1);
		for (int i = 2; i <= k; i++)
		{
			if (*(d + i) > max)
			{
				max = *(d + i);
			}
		}
		return max;
	}
	double fvarparm(float k, ...)
	{
		double* d = (double*)(&k+1);
		double sum = (double)k;
		int i = 0;
		while (d[i] != (double)FLT_MAX)
		{
			sum += d[i++];
		}
		return sum;
	}
	double dvarparm(double k, ...) {
		double* d = &k;
		double sum = 0;
		int i = 0;
		while (d[i] != DBL_MAX) 
		{sum += d[i++];}
		return sum;
	}
 }