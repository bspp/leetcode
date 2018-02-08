/*======================================================================
 * Copyright (C) 2018 Sangfor Ltd. All rights reserved.
 * Programmer :Linyuanpeng
 * Date       :2018/02/08
 *
 * 0                8                  16
 * 1            7   9              15
 * 2        6       10        14
 * 3    5           11   13 
 * 4                12
 * 首行和行尾之间的数据间隔为:interval =2*(numRows-2)+2;
 * 除首行和行尾数据第i行数据间隔为 interval-2i,2i,interval-2i
 *========================================================================*/

#include<string.h>
#include<malloc.h>
#include<string.h>


char* convert(char* s,int numRows)
{
	if ((NULL == s) | (numRows < 1))
		return NULL;

	int s_len = strlen(s);
	int interval = 2*numRows-2;
	int result_index = 0;

	char *result = (char *)malloc(sizeof(char)*(s_len+1));
	if(result == NULL)
		return NULL;
	result[s_len] = '\0';

	if(numRows == 1)
	{
		strcpy(result,s);
		return result;
	}

	for(int i = 0;i < numRows;i++)
	{
		if(i == 0 || i == numRows-1)
		{
			for(int j = i; j < s_len; j+=interval)
				result[result_index++] = s[j];
		}else
		{
			int interval2 = 2 * i;
			for(int j = i;j < s_len; j+=interval2)
			{
				result[result_index++] = s[j];
				interval2 = interval-interval2;
			}
		}
	}
	return result;
}
int main()
{
	printf("%s\n",convert("AB",1));
	return 0;
}

