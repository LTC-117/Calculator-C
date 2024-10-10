#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//functions:
void sum();
void sub();
void multi();
void divis();
void sqt();
void matrix();
void fact();

int main (){
    int entry;

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
            case 8: printf("\nGOODBYE!"); break;
            default: printf("INVALID OPTION! PLEASE, TRY AGAIN: \n");
        }
    } while (entry != 8);

    return 0;
}

void sum(void){
    int amount_sum;

    printf("\nADITION!\n");
    printf("How many numbers would you like to add? ");
    scanf("%d", &amount_sum);
    printf("Insert the %d numbers:\n", amount_sum);

    float *num_sum = malloc(amount_sum * sizeof(float));
    float result_sum = 0;

    for(int i=0; i<amount_sum; i++){
        printf("Number %d: ", i+1);
        scanf("%f", num_sum);
        result_sum += *num_sum;
    }

    printf("Result is: %.2f", result_sum);

    free(num_sum);
}

void sub(void){
    int amount_sub;

    printf("\nSUBTRACTION!\n");
    printf("How many numbers would you like to add? ");
    scanf("%d", &amount_sub);
    printf("Insert the %d numbers:\n", amount_sub);

    float *num_sub = malloc(amount_sub * sizeof(float));
    float result_sub = 0;

    for(int i=0; i<amount_sub; i++){
        printf("Number %d: ", i+1);
        scanf("%f", num_sub);
        result_sub -= *num_sub;
    }

    printf("Result is: %.2f", result_sub);

    free(num_sub);
}

void multi(void){
    int amount_multi;

    printf("\nMULTIPLICATION!\n");
    printf("How many numbers would you like to add? ");
    scanf("%d", &amount_multi);
    printf("Insert the %d numbers:\n", amount_multi);

    float *num_multi = malloc(amount_multi * sizeof(float));
    float result_multi = 1;

    for(int i=0; i<amount_multi; i++){
        printf("Number %d: ", i+1);
        scanf("%f", num_multi);
        result_multi *= *num_multi;
    }

    printf("Result is: %.2f", result_multi);

    free(num_multi);
}

void divis(void){
    float A, B;

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
    float S;

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
    int m, n;

    printf("\nMATRIX GENERATOR! \n");
    printf("Insert the amount of lines:\n");
    scanf("%d", &m);
    printf("Insert the amount of columns:\n");
    scanf("%d", &n);

    int **mtx = malloc(m * sizeof (int *));
        for(int i=0; i<m; i++){
            mtx[i] = malloc(n * sizeof (int));
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
    int num;

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
