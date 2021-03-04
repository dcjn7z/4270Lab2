#include <stdio.h>

int main()
{
    
    int array[] = {5,3,6,8,9,1,4,7,2,10};
    int n = 9;
    
    
    for (int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9 - i; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    for (i = 0; i < n ;i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

/*MIPS Assembly
lui   $zero, 0x0000
addiu $t0, $zero, 0x5 //
addiu $t1, $zero, 0x3 
addiu $t2, $zero, 0x6
addiu $t3, $zero, 0x8
addiu $t4, $zero, 0x9
addiu $t5, $zero, 0x1
addiu $t6, $zero, 0x4
addiu $t7, $zero, 0x7
addiu $t8, $zero, 0x2
addiu $f6, $zero, 0xA
addiu $a0, $zero, 0x0 // set temp to 0
addiu $a2, $zero, 0x8// set n to 8
                        
lui   $a1, 0x1001 //set base 0x10010000
sw    $a0, 0x0000 ($a1)
sw    $t1, $a1,4
sw    $t2, $a1,8
sw    $t3, $a1,12
sw    $t4, $a1,16
sw    $t5, $a1,20
sw    $t6, $a1,24
sw    $t7, $a1,28
sw    $t8, $a1,32
sw    $f6, $a1,36
sw    $a0, $a1,40 //store temp 
sw    $a2,$a1,44 //store n

addiu $t8, $zero, 0x8 // upper bound for i < 8
addiu $t9, $zero, 0x0 // i is initialize to 0
addiu $a3, $zero, 0x0 // j is initialize to 0
                
lw    $t0,  0x0000 ($a1)  //load first element of array
lw    $t1,  $a1, 4  //load second element of array
sub   $f4, $t0, $t1 // $f4 = first element - second element
bgez  $f4, 0x14 // jump to increment j
addiu $a0, $t0, 0x0 // temp = array[j]
addiu $t0, $t1, 0x0 // array[j] = array[j+1]
addiu $t1, $a0, 0x0 // array[j+1] = temp
addiu $a3, $a3,0x1 // increment j
sub   $f4, $a2, $t9 // 8 - i
sub   $f5, $f4, $a3 // (8 -i) - j
bltz  $f5, 0x28
addiu $t9, $t9, 0x1 // increment i
bltz  $f4, 
addiu $v0, $zero, 0x8
syscall
              
