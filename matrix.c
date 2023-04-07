#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_martix(int** matrix, int row, int column){
    printf("matrix \n");
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < column; j++){
            printf("%d ", matrix[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}
void free_matrix(int ** matrix, int row){

        for(int i=0; i<row; i++)
            free(matrix[i]);
        free(matrix);
}

void addition_matrix(int **A, int **B, int A_n, int A_m, int B_n, int B_m){
    if(A_n != B_n || A_m != B_m){
        printf("A and B cannot be added \n");
        
    }
    else{
        int ** added_matrix = (int **)malloc(sizeof(int *) * A_n);
        
        for (int i =0; i < A_n; i++){
            added_matrix[i] = (int *)malloc(sizeof(int) * A_m);
            for(int j =0; j< A_m; j++){
                added_matrix[i][j] = A[i][j] + B[i][j];
            }
        }
        print_martix(added_matrix, A_n, A_m);
        free_matrix(added_matrix, A_n);
    }
}

void subtraction_matrix(int **A, int **B, int A_n, int A_m, int B_n, int B_m){
    if(A_n != B_n || A_m != B_m){
        printf("A and B cannot be subtracted \n");
        
    }
    else{
        int ** subtracted_matrix = (int **)malloc(sizeof(int *) * A_n);
        
        for (int i =0; i < A_n; i++){
            subtracted_matrix[i] = (int *)malloc(sizeof(int) * A_m);
            for(int j =0; j< A_m; j++){
                subtracted_matrix[i][j] = A[i][j] - B[i][j];
            }
        }
        print_martix(subtracted_matrix, A_n, A_m);
        free_matrix(subtracted_matrix, A_n);
    }
}

void transpose_matrix(int **matrix,int row,int column){
    int ** transpose_matrix = (int**)malloc(sizeof(int*) * column);
    for(int i =0; i < column; i++){
        transpose_matrix[i] = (int*)malloc(sizeof(int) * row);
    }
    for(int i = 0;i < row; i++){
        for(int j=0; j < column; j++){
            transpose_matrix[j][i] = matrix[i][j];
        }
    }
    print_martix(transpose_matrix, column, row);
    free_matrix(transpose_matrix, column);
}

void multiply_matrix(int **A, int **B, int A_n, int A_m, int B_n, int B_m){
    if(A_m != B_n){
        printf("A cannot be multiplied by B \n");
        
    }
    int **multiply_matrix = (int **)malloc(sizeof(int*) * A_n);
    for(int i =0; i < A_n; i++){
        multiply_matrix[i] = (int *)malloc(sizeof(int) * B_m);
        for(int j=0; j< B_m; j++){
            multiply_matrix[i][j] = 0;
            for(int k=0; k < B_n; k++){
                multiply_matrix[i][j] += A[i][k] * B[k][j];
            }
            
        }
    }
    print_martix(multiply_matrix,A_n, B_m);
    free_matrix(multiply_matrix, A_n);
}

int main(){
    int A_n , A_m, B_n, B_m;
    printf("----- ohjaesik 2022040014 ----- \n");
    printf("input A matrix size : ");
    scanf("%d %d", &A_n, &A_m);
    printf("input B matrix size : ");
    scanf("%d %d", &B_n, &B_m);

    int ** A_martix = (int **)malloc(sizeof(int *) * A_n);
    int ** B_martix = (int **)malloc(sizeof(int *) * B_n);
    
    for(int i =0; i <A_n; i++){
        A_martix[i] = (int *)malloc(sizeof(int)* A_m);
    }
    for(int i=0; i< B_n; i++){

        B_martix[i] = (int *)malloc(sizeof(int)* B_m);
    }
    for(int i=0; i<A_n; i++){
        for(int j=0; j<A_m; j++){
            A_martix[i][j] = rand() % 10;
        }
    }
    for(int i=0; i<B_n; i++){
        for(int j=0; j<B_m; j++){
            B_martix[i][j] = rand() % 10;
        }
    }
    printf("--- A_matrix --- \n");
    print_martix(A_martix, A_n, A_m);
    
    printf("--- B_matrix --- \n");
    print_martix(B_martix,B_n, B_m);
    
    printf("--- A+B matrix --- \n");
    addition_matrix(A_martix,B_martix,A_n,A_m,B_n,B_m);
    
    printf("--- A-B matrix --- \n");
    subtraction_matrix(A_martix, B_martix, A_n, A_m, B_n, B_m);

    printf("--- Transpose matrix --- \n");
    transpose_matrix(A_martix,A_n,A_m);

    printf("--- A*B matrix --- \n");
    multiply_matrix(A_martix,B_martix,A_n,A_m,B_n,B_m);
    return 0;
}