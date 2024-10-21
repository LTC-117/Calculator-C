#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//functions:
void add_numbers();
void subtract_numbers();
void multiply_numbers();
void divide_numbers();
void square_root();
void matrix_generator();
void factorial_calculator();

int main (){
    int entry;

    printf("Welcome to the calculator! Our operations are:\n\n");
    printf(" 1: Adition\n 2: Subtraction\n 3: Multiplication\n 4: Division\n");
    printf(" 5: Square Root\n 6: Matrix Generator\n 7: Factorial\n 8: Exit \n");

    do{
        printf("\nInsert your operation: ");
        scanf("%d", &entry);
        switch(entry){
            case 1:
                add_numbers();
                break;
            case 2:
                subtract_numbers();
                break;
            case 3:
                multiply_numbers();
                break;
            case 4:
                divide_numbers();
                break;
            case 5:
                square_root();
                break;
            case 6:
                matrix_generator();
                break;
            case 7:
                factorial_calculator();
                break;
            case 8:
                printf("\nPress ENTER to exit!");
                exit(1);
                break;
            default:
                printf("INVALID OPTION! PLEASE, TRY AGAIN: \n");
        }
    } while (entry != 8);

    return 0;
}

void add_numbers(void){
    int amount_sum;

    printf("\nADITION!\n");
    printf("How many numbers would you like to add? ");
    scanf("%d", &amount_sum);
    printf("Insert the %d numbers:\n", amount_sum);

    float *num_sum = malloc(amount_sum * sizeof(float));
    float result_sum = 0;

    for(int i=0; i<amount_sum; i++){
        printf("Number %d: ", i+1);
        scanf("%f", &num_sum[i]);
        result_sum += num_sum[i];
    }

    printf("Result is: %.2f", result_sum);

    free(num_sum);
}

void subtract_numbers(void){
    int amount_sub;

    printf("\nSUBTRACTION!\n");
    printf("How many numbers would you like to subtract? ");
    scanf("%d", &amount_sub);
    printf("Insert the %d numbers:\n", amount_sub);

    float *num_sub = malloc(amount_sub * sizeof(float));
    float result_sub = 0;

    for(int i=0; i<amount_sub; i++){
        printf("Number %d: ", i+1);
        scanf("%f", &num_sub[i]);
        result_sub -= num_sub[i];
    }

    printf("Result is: %.2f", result_sub);

    free(num_sub);
}

void multiply_numbers(void){
    int amount_multi;

    printf("\nMULTIPLICATION!\n");
    printf("How many numbers would you like to multiply? ");
    scanf("%d", &amount_multi);
    printf("Insert the %d numbers:\n", amount_multi);

    float *num_multi = malloc(amount_multi * sizeof(float));
    float result_multi = 1;

    for(int i=0; i<amount_multi; i++){
        printf("Number %d: ", i+1);
        scanf("%f", &num_multi[i]);
        result_multi *= num_multi[i];
    }

    printf("Result is: %.2f", result_multi);

    free(num_multi);
}

void divide_numbers(void){
    float num, denom;

    printf("\nDIVISION! \n");
    printf("Insert numerator:\n");
    scanf("%f", &num);
    printf("Insert denominator:\n");
    scanf("%f", &denom);
    if(denom!=0){
        printf("The result is: %.2f \n", num/denom);
    }
    else{
        printf("ERROR! Division by zero is not allowed! \n");
    }
}

void square_root(void){
    float radicand;

    printf("\nSQUARE ROOT! \n");
    printf("Insert the number:\n");
    scanf("%f", &radicand);
    if(radicand>=0){
        printf("The result is: %.2f \n", sqrt(radicand));
    }
    else{
        printf("ERROR! \n");
    }
}

void matrix_generator(void){
    int m, n;

    printf("\nMATRIX GENERATOR! \n");
    printf("Insert the amount of lines:\n");
    scanf("%d", &m);
    printf("Insert the amount of columns:\n");
    scanf("%d", &n);

    int **matrix = malloc(m * sizeof (int *));
    for(int i=0; i<m; i++){
        matrix[i] = malloc(n * sizeof (int));
    }

    printf("Now insert the %d elements of your matrix:\n", m*n);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("Element a[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Your matrix:\n\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<m; i++){
        free (matrix[i]);
    }
    free(matrix);
}

void factorial_calculator(void){
    int factorial_num;
    unsigned long long result = 1;

    printf("\nFACTORIAL! \n");
    printf("Insert the number: ");
    scanf("%d", &factorial_num);

    if(factorial_num > 0){
        printf("%d factorial is: ", factorial_num);
        for(int i=1; i<=factorial_num; i++){
            result *= i;
        }
        printf("%llu \n", result);
    }
    else if(factorial_num == 0){
        printf("0 factorial is: 1 \n");
    }
    else{
        printf("ERROR! \n");
    }
}
