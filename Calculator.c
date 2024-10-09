#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//variables:
float A,B,S;
int m, n, num, entry;

//functions:
void sum();
void sub();
void multi();
void divis();
void sqt();
void matrix();
void fact();

int main (){

    printf("Welcome to the calculator! Our operations are:\n\n");
    printf(" 1: Adition\n 2: Subtraction\n 3: Multiplication\n 4: Division\n");
    printf(" 5: Square Root\n 6: Matrix Generator\n 7: Factorial\n 8: Exit \n");
    do{
        printf("\nInsert your operation: ");
        scanf("%d", &entry);
        switch(entry){
            case 1: sum(); break;
            case 2: sub(); break;
            case 3: multi(); break;
            case 4: divis(); break;
            case 5: sqt(); break;
            case 6: matrix(); break;
            case 7: fact(); break;
            case 8: printf("Goodbye!"); break;
            default: printf("INVALID OPTION! PLEASE, TRY AGAIN: \n");
        }
    } while (entry != 8);

    return 0;
}

void sum(void){

    printf("\nADITION! \n");
    printf("Insert A:\n");
    scanf("%f", &A);
    printf("Insert B:\n");
    scanf("%f", &B);
    printf("The result is: %.2f \n", A+B);
}

void sub(void){

    printf("\nSUBTRACTION! \n");
    printf("Insert A:\n");
    scanf("%f", &A);
    printf("Insert B:\n");
    scanf("%f", &B);
    printf("The result is: %.2f \n", A-B);
}

void multi(void){

    printf("\nMULTIPLICATION! \n");
    printf("Insert A:\n");
    scanf("%f", &A);
    printf("Insert B:\n");
    scanf("%f", &B);
    printf("The result is: %.2f \n", A*B);
}

void divis(void){

    printf("\nDIVISION! \n");
    printf("Insert A:\n");
    scanf("%f", &A);
    printf("Insert B:\n");
    scanf("%f", &B);
    if(B!=0){
        printf("The result is: %.2f \n", A/B);
    }
    else{
        printf("ERROR \n");
    }
}

void sqt(void){

    printf("\nSQUARE ROOT! \n");
    printf("Insert the number:\n");
    scanf("%f", &S);
    if(S>=0){
        printf("The result is: %.2f \n", sqrt(S));
    }
    else{
        printf("ERROR! \n");
    }
}

void matrix(void){

    printf("\nMATRIX GENERATOR! \n");
    printf("Insert the amount of lines:\n");
    scanf("%d", &m);
    printf("Insert the amount of columns:\n");
    scanf("%d", &n);

    int **mtx = (int **)malloc(m * sizeof (int *));
        for(int i=0; i<m; i++){
            mtx[i] = (int *)malloc(n * sizeof (int));
        }

    printf("Now insert the %d elements of your matrix:\n", m*n);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("Element a[%d][%d]: ", i+1, j+1);
            scanf("%d", &mtx[i][j]);
        }
    }

    printf("Your matrix:\n\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<m; i++){
        free (mtx[i]);
    }
    free(mtx);
}

void fact(void){

    printf("\nFACTORIAL! \n");
    printf("Insert the number: \n");
    scanf("%d", &num);

    if(num > 0){
        printf("%d factorial is: ", num);
        for(int i=num-1; i>0; i--){
            num *= i;
        }
        printf("%d \n", num);
    }

    if(num == 0){
        printf("0 factorial is: 1 \n");
    }

    if (num < 0){
        printf("ERROR! \n");
    }
}
