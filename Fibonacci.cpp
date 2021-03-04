#include <iostream>

using namespace std;

int main()
{
  int current = 0;
  int prev = -1;
  int answer = 0;
  int zero = 0;

  int input;
  
  
  cout << "Enter to find Fibonacci number: " << endl;
  cin >> input;
  
  for(int i = 0; i <= input; i++)
  {
     if(i == 0)
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
[0x04000004]    addiu $a1, $zero, 0x //set prev to -1
[0x04000008]    addiu $a2, $zero, 0 //set answer to 0
[0x0400000C]    addiu $a3, $zero, 0 //set zero to 0
[0x04000010]    addiu $a4, $zero, 0 //set one to 1
[0x04000014]    lui   $t1, 0x1001 //set base 0x10010000
[0x04000018]    sw    $a1, $t1, 0 // store previous varible to memory
[0x0400001C]    sw    $a0, $t1, 4 // store current varible to memory
[0x04000020]    addiu $a5, $zero, 0xA //upper bound for i is 10
[0x04000024]    addiu $a6, $zero, 0x0 //i is initially 0
[0x04000028]    bnq   $a6, $a3, +0xC// if i == 0 if not jumps to 0x04000034
[0x0400002C]    addiu $a1, $a1, 0x1 // prev++           
[0x04000030]    addiu $a0, $a0, 0x1 // current++
[0x04000034]    bnq   $a6, $a3, +0x14 // jump to increment i 0x04000048
[0x04000038]    add $a2, $a1,$a0 // answer = prev + current
[0x0400003C]    sw  $a2, $t1,8 //store answer to memory
[0x04000040]    addiu $a1, $a0, 0 // prev = current
[0x04000044]    addiu $a0, $a2, 0 // current = answer
[0x04000048]    addiu $a5, $a5, 0x1 //i++
[0x0400004C]    bne $a6, $a5, -0x28//if branch is taken jumps back to 0x04000028
[0x04000050]    addiu $v0, $zero, 0xA //set $v0 to 10 to exit
[0x04000054]    syscall

