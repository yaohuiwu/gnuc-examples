#include "calculator.h"
#include <stdio.h>
double plus(double d1,double d2)
{
	return d1 + d2 ;
}

double minus(double d1,double d2)
{
	return d1 - d2;
}

double multiply(double d1,double d2)
{
	return d1 * d2;
}
double divide(double d1,double d2)
{
	if(d2 == 0.0){
	    printf("%lf%s",d2,"不能为0");	
	    return 0;
	}
	return d1 / d2;
}
