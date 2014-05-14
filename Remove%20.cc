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


void quickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = arr[(left+right)/2];
	int tmp;
	
	while(i <= j)
	{
		while(arr[i] < pivot)
			i++;
			
		while(arr[j] > pivot)
			j--;
			
		if(i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	
	if(left < j)
		quickSort(arr, left, j);
	if(i < right)
		quickSort(arr, i, right);
}

bool findTwoNumbers(int arr[], int length, int number)
{
	// Sort the array
	quickSort(arr, 0, length-1);
	
	int right = length -1;
	int left = 0;
	
	while(left < right)
	{
		if(arr[left] + arr[right] == number)
		{
			printf("\n number 1: %d number 2: %d",arr[left], arr[right]);
			return true;
		}
		
		if(arr[left] + arr[right] < number)
			left++;
		else
		if(arr[left] + arr[right] < number)
			right--;
	}
	
	return false;
}

int main()
{
	/*int length = strlen("I am g ood");
	char * str = (char*) malloc(sizeof(char) * (length +1));
	str[length] = NULL;
	strcpy(str, "I am g ood");
	add(str);
	*/
	int arr[] = {1,8,0,-9,3,4,6,2};
	findTwoNumbers(arr, sizeof(arr)/sizeof(int), 9);	
		
}
