/*======================================================================
 * Copyright (C) 2018 Sangfor Ltd. All rights reserved.
 * Programmer :Linyuanpeng
 * Date       :2018/02/08
 *========================================================================*/


#include<stdio.h>
#include<limits.h>

int reverse(int x) {

	long result = 0;

	if(x == 0)
		return x;

	while(x % 10 == 0)
		x = x / 10;

	if(x <= 9 && x >= -9)
		return x;

	while(1)
	{
		result = result * 10 + x % 10;
		x = x / 10;
		if(x == 0)
			break;
	}

	if(result > INT_MAX|| result < INT_MIN)
		return 0;
	else
		return result;
}

int main()
{
	int m = reverse(-534236469);
	printf("m value is %d \n",m);
}

