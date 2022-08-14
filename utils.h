/*

utility functions required for model inference
*/
#include<stdlib.h>


float  KERNEL[9] = {    
                        2,2,1,
                        1,1,1,
                        3,3,1
                   };


float  IMAGE[16] = {    1,2,3,
                        4,5,6,
                        4,5,6
                    };

struct matrix{
    int r;
    int c;
    float* matrix;
    
};

struct matrix conv2d(struct matrix ker,struct matrix img)
{
    struct matrix result;
    
    result.r = img.r - ker.r + 1;       // stride = 0, padding = 0
    result.c = img.c - ker.c + 1;       // stride = 0, padding = 0
    int img_startr = (ker.r - 1)/2;
    int img_startc = (ker.c - 1)/2;
    float* temp = (float*)malloc(result.r*result.c*sizeof(float));

    for(int r = 0 ; r < result.r ; r++)
        for(int c = 0 ; c < result.c ; c++)
            for(int kr = 0 , i = -1; kr < ker.r ; kr++, i++)
                for(int kc = 0 , j = -1; kc < ker.c ; kc++, j++)
                    *(temp + r*result.c + c) += *(ker.matrix + kr*ker.c + kc) * (*(img.matrix + ((img_startr+r+i)*img.c + (img_startc+c+j))));  


    result.matrix = temp;
    return result;

}


struct matrix matmul(struct matrix wt,struct matrix img)
{
    struct matrix result;
    if (wt.c != img.r)
    {
        printf("matrix dimensions dont match");
        exit (0);
    }

    result.r = wt.r;       // stride = 0, padding = 0
    result.c = img.c;       // stride = 0, padding = 0
  
    float* temp = (float*)malloc(result.r*result.c*sizeof(float));
    
    for(int r = 0 ; r < result.r ; r++)
        for(int c = 0 ; c < result.c ; c++)
            for(int i = 0 , j=0; i < wt.c ; i++,j++)
                *(temp + r*result.c + c) += *(wt.matrix + r*wt.c+ i) * *(img.matrix + j*img.c + c) ;     
        
   
    
    result.matrix = temp;
    return result;
}