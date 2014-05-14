#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int fibonacci(unsigned int n)
{
    int first = 1, second = 0, sum = 0;
    
    if(n == 0)
      return 0;
      
    if(n == 1)
      return 1;  
    
    for(int i=2; i<=n; i++)
    {
        sum = first + second;
        second = first;
        first = sum;
    }
    
    cout<<"Fibonacci : "<<sum;
    
    return sum;
    
}

int fib(int n)
{
  int a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}

int main()
{
    
    int n = fibonacci(10);
    int m = fib(10);
    
    cout<<endl<<m<<endl;
    
    getchar();
}
