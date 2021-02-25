#include <iostream>

using namespace std;

int main()
{
  int current = 0;
  int input;
  int prev = -1;
  int answer;
  
  cout << "Enter to find Fibonacci number: " << endl;
  cin >> input;
  
  for(int i = 0; i <= N; i++)
  {
     if(i < 1)
     {
       cout << prev << " "; 
       prev++;
       current+;
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
