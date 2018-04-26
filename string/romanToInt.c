#include<stdio.h>
#include<math.h>

int roman_char_to_int(char r)
{
	switch(r){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
}
int romanToInt2(char* str){
	int result = roman_char_to_int(*str);
	int i = 1;
	
	str = str + 1;
	while(*str != '\0'){
		if(roman_char_to_int(*(str-1)) < roman_char_to_int(*str)){
				result = result-roman_char_to_int(*(str-1))+
					(roman_char_to_int(*str)-roman_char_to_int(*(str-1)));
		}else{
			result = result + roman_char_to_int(*str);
		}
		str = str + 1;
	}
}
int romanToInt(char* str){
	long result = 0;
	int now = 0;
	int next = 0;
	int next_next = 0;
	while(*str != '\0'){
		if(*(str+1) == '\0'){
			result = result + roman_char_to_int(*str);
			break;

		}else if(*(str+2) == '\0' ){
			now = roman_char_to_int(*str);
			next = roman_char_to_int(*(str+1));
			printf("result %d,now %d next %d\n",result,now,next);
			result = result + ((now >= next) ? (now+next):(next-now));

			break;

		}else{

			now = roman_char_to_int(*str);
			next = roman_char_to_int(*(str+1));
			next_next = roman_char_to_int(*(str+2));

			if(now < next){
				result = result+(abs(now-next));
				str = str + 2;

			}else if(next >= next_next){
				result = result + now;
				str = str + 1;

			}else{
				result = result + now + next_next-next;
				str = str +3;

			}

		}

	}
	return (int)result;
}


int main(){
	printf("%d\n",romanToInt("III"));
	return 0;
}
