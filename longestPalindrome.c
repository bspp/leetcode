#include<stdio.h>
#include<string.h>
#include<malloc.h>
int mid_to_left_right(char* s,int left,int right,int len);
char *longestPalindrome(char* s)
{
	
	int start = 0;
	int end = 0;
	int len = strlen(s);
	int max = 0;
	int i = 0;

	for(i = 0 ;i<len;i++)
	{
		int len1 = mid_to_left_right(s,i,i,len);
		int len2 = mid_to_left_right(s,i,i+1,len);
		int len12_max = len1 > len2 ? len1 : len2;

		if(len12_max > max)
		{
			max = len12_max;
			start = i-(len12_max-1)/2;
		}
	}

	char *ans = (char *)malloc(sizeof(char)*(max + 1));
	strncpy(ans,s+start,max);
	ans[max] = '\0';
	return ans;
}
int mid_to_left_right(char* s,int left,int right,int len)
{
	while(left >= 0 && right < len && s[left] == s[right])
	{
		left--;
		right++;
	}
	return right-left-1;

}

int main(){
	char *kk = "ad7788999997777999998877jk";
	printf("%s\n",longestPalindrome(kk));

	return -1;
}


