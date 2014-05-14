#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

bool reverse1(char* s, int start, int end)
{
    while(start<end)
    {
      char temp = s[start];
      s[start] = s[end];
      s[end] = temp;
      start++;
      end--;   
    }
    
    return true;
}

void ReverseSentence(char* s, int length)
{
    // Reverse the sentence
    reverse1(s, 0, length-1);
    
    int wordStart =0, wordEnd = 0;
    
    for(int i=0;i<length;i++)
    {
        if(s[i] == ' ')
        {
            reverse1(s, wordStart, --wordEnd);
            
            wordStart = i+1;
            wordEnd = i+1;
        } 
        else
        {
            wordEnd++;   
        }        
          
    }
    reverse1(s, wordStart, --length);
    
    cout<<"#"<<s<<"#";
    
}

int main()
{
    char s[] = "Hi my name is.";
    ReverseSentence(s, 14);
    
    getchar();
} 
