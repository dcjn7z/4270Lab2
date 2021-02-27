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
[0x04000000]    addiu $t0, $zero, 5 //
[0x04000004]    addiu $t1, $zero, 3 
[0x04000008]    addiu $t2, $zero, 6
[0x0400000C]    addiu $t3, $zero, 8
[0x04000010]    addiu $t4, $zero, 9
[0x04000014]    addiu $t5, $zero, 1
[0x04000018]    addiu $t6, $zero, 4
[0x0400002C]    addiu $t7, $zero, 7
[0x04000030]    addiu $t8, $zero, 2
[0x04000034]    
[0x04000038]    
[0x0400003C]    
[0x04000040]    
[0x04000044]    
[0x04000048]
[0x0400004C]
[0x04000050]
[0x04000054]
© 2021 GitHub, Inc.
