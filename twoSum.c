#include<stdio.h>
#include<malloc.h>
int* twoSum(int* nums, int numsSize, int target) {
	int m[1000001] = {0},*n = m + 500000;
	int i = 0;
	for (;i < numsSize; i++) {
		int poor = target-nums[i];
		if (n[poor] > 0) {
			int *value_index = malloc(sizeof(int) * 2);
			value_index[0] = i;
			value_index[1] = n[poor] - 1;
			return value_index;
		}
		else
			n[nums[i]] = i + 1;
	}
	return NULL;
}
int main()
{
	int k[8] ={-10,-9,-8,-7,-6,8,9,10};
	int *m = twoSum(k,8,19);

	printf("%d\n",m[0]);
	printf("%d\n",m[1]);
	
	return 0;
}
