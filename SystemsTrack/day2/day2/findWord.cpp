#include<stdio.h>
#include<stdlib.h>
int len_string(char*str){
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}


int find(char*word, char**matrix, int row_max, int col_max){
	int len = len_string(word);
	int count = 0, row = 0, col = 0, index=0,found=0;
	for (row; row < row_max; row++)
	{
		for (col=0; col < col_max; col++)
		{
			found = 1;
			index = 0;
			if (matrix[row][col] == word[index])
			{
				//checking in <-- direction
				if (col-len >= 0)
				{
					for (int i = 1; i < len; i++)
					{
						if (matrix[row][col - i] != word[index+i])
						{
							found = 0;
						}
					}
					if (found)
					{
						count++;
						printf("\nindex is %d %d, %d %d\n", row, col, row, col - len+1);
					}
				}


				//checking in --> direction
				index = 0;
				found = 1;
				if (col_max - len >= 0)
				{
					for (int i = 1; i < index; i++)
					{
						if (matrix[row][col +i] != word[index + i])
						{
							found = 0;
						}
					}
					if (found)
					{
						count++;
						printf("\nindex is %d %d, %d %d\n", row, col, row, col + len );
					}
				}


			}
		}
	}
	return count;
}

int main()
{
	char** matrix = (char**)malloc(sizeof(char*) * 2);
	matrix[0] = (char*)malloc(sizeof(char) * 15);
	matrix[1] = (char*)malloc(sizeof(char) * 15);
	matrix[0] = "lnerirsrirf";
	matrix[1] = "lnerirsrirf";
	char*word = "sr";
	int count=find(word, matrix, 2, 10);
	printf("count is %d", count);
	return 0;
}