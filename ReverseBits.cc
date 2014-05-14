#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

void reverseBits(int number)
{
   unsigned int result = 0;
   
   unsigned int i = (sizeof(number) *8)-1;
   cout<<i<<endl;
   
   while(i > 0)
   {
        if(number&1) // rightmost bit is 1
        {
            result += 1<<i;
        }
        else
            result += 0<<i;
        
        number = number>>1;
        i--;            
   }   
   
   cout<<"Result: "<<result;
    
}

int main()
{
   reverseBits(4);
   
   getchar();   
}
