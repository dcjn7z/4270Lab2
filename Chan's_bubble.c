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
                addiu $t0, $zero, 0x5 //
[0x04000004]    addiu $t1, $zero, 0x3 
[0x04000008]    addiu $t2, $zero, 0x6
[0x0400000C]    addiu $t3, $zero, 0x8
[0x04000010]    addiu $t4, $zero, 0x9
[0x04000014]    addiu $t5, $zero, 0x1
[0x04000018]    addiu $t6, $zero, 0x4
[0x0400002C]    addiu $t7, $zero, 0x7
[0x04000030]    addiu $t8, $zero, 0x2
[0x04000034]    addiu $a0, $zero, 0x0 // set temp to 0
                addiu $a2, $zero, 0x8// set n to 8
                
                
                lui   $a1, 0x1001 //set base 0x10010000
                sw    $a0, 0x0000 ($a1)
[0x04000038]    sw    $t1, $a1,4
[0x0400003C]    sw    $t2, $a1,8
[0x04000040]    sw    $t3, $a1,12
[0x04000044]    sw    $t4, $a1,16
[0x04000048]    sw    $t5, $a1,20
[0x0400004C]    sw    $t6, $a1,24
[0x04000050]    sw    $t7, $a1,28
[0x04000054]    sw    $t8, $a1,32
                sw    $a0, $a1,36 //store temp 
                sw    $a2,$a1,40 //store n
                
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
              
