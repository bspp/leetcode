#include<stdio.h>
#define INT_MAX 21474847

double findMedian(int *nums1,int start1,int len1,int *nums2,int start2,int len2,int mid);
double findMedianSortedArrays(int *nums1,int nums1Size,int *nums2,int nums2Size);


double findMedianSortedArrays(int *nums1,int nums1Size,int *nums2,int nums2Size)
{
	int len = nums1Size + nums2Size;
	if(len % 2 == 1)
	{
		return findMedian(nums1,0,nums1Size,nums2,0,nums2Size,len/2+1);
	}else{
		return findMedian(nums1,0,nums1Size,nums2,0,nums2Size,len/2+1)/2+findMedian(nums1,0,nums1Size,nums2,0,nums2Size,len/2)/2;
	}
}
int k = 0;
double findMedian(int *nums1,int start1,int len1,int *nums2,int start2,int len2,int mid)
{

	if(start1 >= len1)
		return nums2[start2+mid-1]/1.0;
	
	if(start2 >= len2)
	{
		return nums1[start1+mid-1]/1.0;
	}
	if(mid == 1)
	{
		printf("kkkkkk\n");
		return nums1[start1] < nums2[start2] ? nums1[start1]:nums1[start2];
	}

	int nums1_key = start1+mid/2-1 >= len1 ? INT_MAX : nums1[start1+mid/2-1];
	int nums2_key = start2+mid/2-1 >= len2 ? INT_MAX : nums2[start2+mid/2-1];
	printf("key1:%d key2:%d\n",nums1_key,nums2_key);


	if(nums1_key < nums2_key)
	{ 
		//mid/2为被舍弃的数
		printf("&&&&&&&&&&&&&&&&&&&&&&&\n");
		k++;
		return findMedian(nums1,start1+mid/2,len1,nums2,start2,len2,mid-mid/2);
	}else if(nums1_key <= nums2_key){
		return findMedian(nums1,start1,len1,nums2,start2+mid/2,len2,mid-mid/2);
	}
}
int main(){
	int a[8] = {1,3};
	int b[6] = {2};
	printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("%f\n",findMedianSortedArrays(a,2,b,1));
	return -1;
}
