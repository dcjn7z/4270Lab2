#include <stdio.h>

int main()
{
    
    int array[] = {5,3,6,8,9,1,4,7,2};
    int n = sizeof(array)/sizeof(array[0]);
    
    
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
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
[0x04000000]   
                addiu $a0, $zero, 5 //
[0x04000004]    addiu $a1, $zero, 3 
[0x04000008]    addiu $a2, $zero, 6
[0x0400000C]    addiu $a3, $zero, 8
[0x04000010]    addiu $a4, $zero, 9
[0x04000014]    addiu $a5, $zero, 1
[0x04000018]    addiu $a6, $zero, 4
[0x0400002C]    addiu $a7, $zero, 7
[0x04000030]    addiu $a8, $zero, 2
[0x04000034]    addiu $a9, $zero, 0 // set temp to 0
                
                lui   $t1, 0x1001 //set base 0x10010000
                sw    $a0, $t1,0
[0x04000038]    sw    $a1, $t1,4
[0x0400003C]    sw    $a2, $t1,8
[0x04000040]    sw    $a3, $t1,12
[0x04000044]    sw    $a4, $t1,16
[0x04000048]    sw    $a5, $t1,20
[0x0400004C]    sw    $a6, $t1,24
[0x04000050]    sw    $a7, $t1,28
[0x04000054]    sw    $a8, $t1,32
                sw    $a9, $t1,36 //store temp 
                
                addiu $a10, $zero, 0x n-1?? // upper bound for i < n-1
                addiu $a11, $zero, 0x0 // i is initialize to 0
                
                addiu $a12, $zero, 0x n-i-1 // upper bound for j < n - i -1
                addiu $a13, $zero, 0x0 // j is initialize to 0
                
                
                addiu $a13, $a13,0x1 // increment j
                
                addiu $a11, $zero, 0x1 // increment i
