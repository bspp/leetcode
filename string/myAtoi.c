#include<stdio.h>
#include<limits.h>

int isNum(char c){
	return (c>='0'&&c<='9');
} 

int MyAtoi(char* str)
{ 
	long result = 0;
	if(str == NULL)
		return 0;
	while(*str == '\x20')
		str = str + 1;

	if(*str == '-')
	{
		str = str+1;
		while(*str != '\0' && isNum(*str))
		{
			result = 10 * result - (*str-'0');
			if(result < INT_MIN){
				result = INT_MIN;
				break;
			}
			str = str+1;
		}
	}else{
		if(*str == '+'){
			str = str + 1;
		}

		while(*str != '\0' && isNum(*str))
		{
			result = 10 * result + (*str-'0');
			if(result > INT_MAX){
				result = INT_MIN;
				break;
			}
			str = str + 1;
		}
	}



	return (int)result;
}
int main(){
	char* str= "+9";
	printf("%d\n",MyAtoi(str));
}
