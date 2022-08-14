#include <stdio.h>
#include "utils.h"

int main(){
    
    struct matrix Kernel = {  9, 1 , KERNEL };
    
    struct matrix Image =  { 1, 9 ,IMAGE };
    struct matrix m;

    for (int r =0 ; r< Kernel.r; r++){
        printf("\n");
        for (int c =0 ; c< Kernel.c; c++)
            printf("%f\t",*(Kernel.matrix + r*Kernel.c + c));
    }
     printf("\n");
    for (int r =0 ; r< Image.r; r++){
        printf("\n");
        for (int c =0 ; c< Image.c; c++)
            printf("%f\t",*(Image.matrix + r*Image.c + c));
    }

    m = matmul(Kernel, Image);

    printf("\n");
    
    for (int r =0 ; r< m.r; r++){
        printf("\n");
        for (int c =0 ; c< m.c; c++)
            printf("%f\t",*(m.matrix + r*m.c + c));
    }

 printf("\n");
    return 0;
}