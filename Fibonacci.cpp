#include <iostream>

using namespace std;

int main()
{
  int current = 0;
  int prev = -1;
  int answer = 0;
  int input;
  
  
  cout << "Enter to find Fibonacci number: " << endl;
  cin >> input;
  
  for(int i = 0; i <= input; i++)
  {
     if(i < 1)
     {
       prev++;
       cout << prev << " "; 
       current++;
       cout << current << " ";
     }
     else
     {
        answer = prev + current;
        prev = current;
        current = answer;
        cout << answer << " ";
     }  
  }
  return 0;   
}

/* MIPS Assembly
[0x04000000]    addiu $a0, $zero, 0 //set current to 0
[0x04000004]    addiu $a1, $zero, 0 //set prev to -1
[0x04000008]    addiu $a2, $zero, 0 //set answer to 0
[0x0400000C]    addiu $a3, $zero, 0xA //upper bound for i is 10
[0x04000010]    addiu $a4, $zero, 0x0 //i is initially 0
[0x04000014]    ble?? what branch? for i < 1??
[0x04000018]    addiu $a1, $a1, 0x1 // prev++
[0x0400002C]    addiu $a0, $a0, 0x1 // current++
[0x04000030]    else statement
[0x04000034]    add $a2, $a1,$a0 // answer = prev + current
[0x04000038]    addiu $a1, $a0, 0 // prev = current
[0x0400003C]    addiu $a0, $a2, 0 // current = answer
[0x04000040]    bne $a3, $a4, - //if branch taken jump to
[0x04000044]    syscall
[0x04000048]
[0x0400004C]
[0x04000050]
[0x04000054]
