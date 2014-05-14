#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int number = 64;
    int closestNumber = 0;
    int dummy = 1;
       
    while(number > 0)
    {
        if(dummy >= number)
        {
            // Check if closentNumber is closer to the number than dummy
            if((dummy-number)<(number-closestNumber))
                printf("closest number is: %u", dummy); 
            else
                printf("closest number is: %u", closestNumber);
            
            break;        
        }
        else
        {            
            closestNumber = dummy;
            dummy = dummy << 1;        
        }
        
    }
    
    return 0;
}
