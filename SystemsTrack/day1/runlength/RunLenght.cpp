#include<stdlib.h>
#include<stdio.h>
char* numTOString(int count)//function to convert 123 to '123'
{
	char* ch = (char*)malloc(sizeof(char) * 10);
	int index = 9;
	ch[index--] = '\0';
	while (count > 0){
		ch[index--] = (count % 10)+'0';
		count /= 10;
	}
	return (ch + index+1);
}

void runLength(char * str){
	int count = 1, temp = 1, index = 0;
	char* ch, counter = 0;
	while (str[index] != '\0'){
		if (str[index] == str[index + 1])
			count++;
		else{
			if (count <= 9 && count != 1)//length lies bw 2 and 9
			{
				str[temp++] = count + '0';
				if (str[index + 1] != '\0')
					str[temp++] = str[index + 1];
			}

			else if (count > 9)//length greater or equal to 2 digits
			{
				ch = numTOString(count);
				counter = 0;
				while (ch[counter] != '\0'){
					str[temp++] = ch[counter++];
				}
				if (str[index + 1] != '\0')
					str[temp++] = str[index + 1];
			}
			count = 1;
		}
		index++;
	}

	str[temp] = '\0';
}
/*
int main(){
char ch[1000];
printf("enter string\n");
scanf("%s", &ch);
runLength(ch);
for (int i = 0; ch[i] != '\0'; i++)
printf("%c",ch[i]);
return 0;
}
*/