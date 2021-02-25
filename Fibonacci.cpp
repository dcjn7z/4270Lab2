#include <iostream>

using namespace std;

int main()
{
  int current = 1;
  int N;
  int prev = -1;
  for(int i = 0; i < N; i++)
  {
     if(i < 1)
     {
       cout << prev << " "; 
       prev++; 
     }
     else
     {
        answer = prev + current;
        prev = current;
        current = answer;
        cout << answer << " ";
     }
    return 0;
  }
  
  
  return 0;   
}
