void quickSort(int arr[], int left, int right) 
{

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      /* partition */
      while (i <= j) 
      {

            while (arr[i] < pivot)
                  i++;

            while (arr[j] > pivot)
                  j--;

            if (i <= j) 
            {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      } 
      /* recursion */
      if (left < j)
           quickSort(arr, left, j);

      if (i < right)
            quickSort(arr, i, right);
}

int main()
{
   int arr[] = {1,9,78,55,70,45,2,4,0,9};
   quickSort(arr, 0, 9);
   
   return 0;

}
