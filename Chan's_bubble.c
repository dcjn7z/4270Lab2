#include <stdio.h>

int main()
{
    
    int array[] = {5,3,6,8,9,1,4,7,2};
    int n = 8;
    
    
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < 8 - i; j++)
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
[0x04000000]    lui   $zero, 0x0000
                addiu $a0, $zero, 0x5 //
[0x04000004]    addiu $a1, $zero, 0x3 
[0x04000008]    addiu $a2, $zero, 0x6
[0x0400000C]    addiu $a3, $zero, 0x8
[0x04000010]    addiu $a4, $zero, 0x9
[0x04000014]    addiu $a5, $zero, 0x1
[0x04000018]    addiu $a6, $zero, 0x4
[0x0400002C]    addiu $a7, $zero, 0x7
[0x04000030]    addiu $a8, $zero, 0x2
[0x04000034]    addiu $a9, $zero, 0x0 // set temp to 0
                addiu $a14, $zero, 0x8// set n to 8
                
                
                lui   $t1, 0x1001 //set base 0x10010000
                sw    $a0, 0x0000 ($t1)
[0x04000038]    sw    $a1, $t1,4
[0x0400003C]    sw    $a2, $t1,8
[0x04000040]    sw    $a3, $t1,12
[0x04000044]    sw    $a4, $t1,16
[0x04000048]    sw    $a5, $t1,20
[0x0400004C]    sw    $a6, $t1,24
[0x04000050]    sw    $a7, $t1,28
[0x04000054]    sw    $a8, $t1,32
                sw    $a9, $t1,36 //store temp 
                sw    $a14,$t1,40 //store n
                
                addiu $a10, $zero, 0x8 // upper bound for i < 8
                addiu $a11, $zero, 0x0 // i is initialize to 0
                
                addiu $a13, $zero, 0x0 // j is initialize to 0
                
                lw    $a0,  0x0000 ($t1)  //load first element of array
                lw    $a1,  $t1, 4  //load second element of array
                sub   $a16, $a0, $a1 // $a16 = first element - second element
                bgez  $a16, 0x // jump to increment j
                
                addiu $a13, $zero, 0x0 // j is initialize to 0
                
                sub   $a15, $a14, $a11 // 8 - i
                
                addiu $a13, $a13,0x1 // increment j
                
                blez  $a0,  $a1, 0x // jumps to 
                
                addiu $a11, $11, 0x1 // increment i
                
                blez  $a11, $a14, 0x //if i < 8 jumps to second for-loop
