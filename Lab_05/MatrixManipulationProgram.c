/*
Author: Mason West
Class: EECS 348
Lab: 05
Program: Matrix Manipulation
Input: None, Matrices are hard coded.
Outcome: Prints out the addition of two matrices, multiple of two matrices, and the transpose of matrice M1.
*/



#include <stdio.h>
#define SIZE 5 //Defines size 5 for easier use of matrice sizes.


//Funciton Prototypes:
int add_two_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
int print_matrix(int m1[SIZE][SIZE]);
int multiply_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
int transpose_matrix(int m1[SIZE][SIZE]);



//Main function to start program.
int main(){

    //Creates two, two dimensional arrays with [SIZE][SIZE] already filled with sample inputs.
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };


    //Creates print statements to make the outputs look organized and calls each corresponding function.
    printf("===Addition Of Matrices===\n");
    add_two_matrices(m1, m2);
    printf("\n===Multication Of Matrices===\n");
    multiply_matrices(m1, m2);
    printf("\n===Transpose of Matrix 1===\n");
    transpose_matrix(m1);
    printf("\n===Printed Matrix 1===\n");
    print_matrix(m1);
return 0;
}

//Print function to print the inputed two dimensional array.
//Loops through twice printing each integer with 4 spaces in between.
int print_matrix(int m1[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%4d ",m1[i][j]);
        }
    printf("\n");
    }
return 0;
}

//Function that takes in two, two dimensional arrays and adds the two then prints the resulting matrix.
int add_two_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    int result_m[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result_m[i][j] = m1[i][j] + m2[i][j];
        }
    }
    print_matrix(result_m);
return 0;
}

//Function that takes in two, two dimensional arrays and multiplies them together, printing the result.
int multiply_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    int result_m[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result_m[i][j] = m1[i][j] * m2[i][j];
        }
    }
    print_matrix(result_m);
return 0;
}

//Function that takes in a two dimensional array as a matrix and prints the transpose of the matrix.
int transpose_matrix(int m1[SIZE][SIZE]){
    int result_m[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result_m[j][i] = m1[i][j];
        }
    }
    print_matrix(result_m);
}