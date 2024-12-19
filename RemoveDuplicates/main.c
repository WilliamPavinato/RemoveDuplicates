
#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    
    

    if ( numsSize == 0 ){
        
        return 0;

    }

    int k = 1;

    int *aux = ( int *) malloc ( sizeof(int) );

    if( aux == NULL ){
        printf("Falha na locação de memória");
        return -1;
    }

   
    aux[0] = nums[0];

    for( int i = 1 ;i < numsSize ; i++ ){

        int isDuplicate = 0;

        for( int j = 0 ;  j < k ; j++ ){

            if( nums[i] == aux[j] ){
            
                isDuplicate = 1;
                break;

            }
            
        }


        if( isDuplicate == 0 ){
            
            int* temp = ( int *) realloc ( aux, sizeof(int) * ( k + 1 ) );

            if (temp == NULL) {
                free(aux); 
                printf("Erro de alocação de memória.\n");
                return -1; 
            }

            aux = temp;  
            aux[k] = nums[i];
            k++;

        }

    }

     for (int i = 0; i < k; i++) {

        nums[i] = aux[i];

    }

    free(aux);

    return k;  

}

int main(){

    int nums[] = {0,1,2,2,3,4,5,5,6};

    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates( nums, numsSize);

    printf("k = %d\n", k);


    for( int i = 0 ; i < k ; i++ ){
        
        printf("%d ", nums[i]);

    }


    return 0;
}