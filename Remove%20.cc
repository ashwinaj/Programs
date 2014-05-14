#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

void add(char* str)
{
	int length = strlen(str);
	int count = 0;
	
	// Count the number of spaces
	for(int i = 0;i<length;i++)
	{
		if(str[i] == ' ')
			count++;	
	}

	count *=2;
	
    str = (char*) realloc(str, sizeof(char)*((length+count+1)));	
	str[length+count] = NULL;
	
	int next = 0;
	next = length + count-1;
	//current = length-1;
	
	for(int i = (length -1);i>=0;i--)
	{
		if(str[i] != ' ')
		{
			str[next] = str[i];
			next--;
		}
		else
		{
			// We found a space
			str[next--] = '0';
			str[next--] = '2';
			str[next--] = '%';
		}
	}
	
	printf("$%s$", str);
}

int main()
{
	int length = strlen("I am g ood");
	char * str = (char*) malloc(sizeof(char) * (length +1));
	str[length] = NULL;
	strcpy(str, "I am g ood");
	add(str);
	
		
}
