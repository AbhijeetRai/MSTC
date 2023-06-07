#include<stdio.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
    /* code */
    int*** ppp_master_array = 0;
    int N = 5;

    int i;
    int j;
    ppp_master_array = (int***)malloc(N * sizeof(int**));
    if(ppp_master_array==0)
    {
        puts("failed to allocate master array");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < N; i++)
    {
        /* code */
        ppp_master_array[i] = (int**) malloc(N * sizeof(int*));
        if(ppp_master_array[i]==0)
        {
            puts("failed to allocated chield array");
            exit(EXIT_FAILURE);
        }
       
        for (j=0;j< N;j++)
        {
            /* code */
            //allocate
            ppp_master_array[i][j]=(int*)malloc(sizeof(int));
            if(ppp_master_array[i][j]==0)
            {
                puts("failed to allocated each element of chield array");
                exit(EXIT_FAILURE);
            }
            //init
            *ppp_master_array[i][j] = (i+j+1)*100;
        }
        
    }

    for (i = 0; i < N; i++)
    {
        printf("**a[%d]=*a[%d]->{",i,i);
        /* code */
        for (j = 0; j < N; j++)
        {
            /* code */
            printf("%d ",*ppp_master_array[i][j]);
        }
        printf("}\n");
    }
    
    //free resources
    for (i = 0; i < N; i++)
    {
        /* code */
        for (j = 0; j < N; j++)
        {
            /* code */
            free(ppp_master_array[i][j]);
            ppp_master_array[i][j]=0;
        }
        free(ppp_master_array[i]);
        ppp_master_array[i]=0;        
    }
    free(ppp_master_array);
    ppp_master_array=0;
    
    
    return 0;
}
