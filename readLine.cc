#include<cstdio>
#include<iostream>
#include<sstream>


using namespace std;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int i = 0;
    string line;
    int token;
    int lTasks = 0;
  
  	while(getline(std::cin, line, '.') )
    {       
        istringstream is(line);
        
        if(i == 0)
        {          
          while(is >> token)
          {
             //Server lServer(token);
             //lDataCenter.addServer(lServer);  
             cout<<" "<<token;
          }
          
          i++;
        }
        else
        {
          cout<<"Tasks";
          while(is >> token)
          {
        	  //Task lTask(token, lTasks);
            //cout<<lDataCenter.assignServerWithTask(lTask);  
            cout<<" "<<token;
          }
        }
      
    }
  
    return 0;
}
