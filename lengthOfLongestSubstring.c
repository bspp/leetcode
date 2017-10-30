#include <stdio.h>
#include<string.h>
int lengthOfLongestSubstring(char* s)
{
	int index[128] = {-1};  
	int i = 0;
	int len = strlen(s);
	int j = 0;
	int max = 0;
	for(;i<len;i++){
		//最新的重复数的的前一个的位置
		j = max_value(index[s[i]],j);
		max = max_value(max,i-j+1);
		index[s[i]] = i+1;
	}

	return max;
}
int max_value(int a,int b)
{
	return a > b ? a : b;
}
int main()
{
	char *x = "a";
	printf("%d\n",lengthOfLongestSubstring(x));
	return -1;
}
