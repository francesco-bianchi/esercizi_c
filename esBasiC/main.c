#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    const int myNumConst = 15;
    bool isProgrammingFun = true;  //(1/0 -> %d trattato come int)
    int myNum;
    float myFloatNum = myNum; //cast implicito
    //input tastiera
    printf("Type a number: \n");
    // Get and save the number the user types (%d -> int, %f -> float, %lf -> double, %c -> char, %s -> string)
    scanf("%d", &myNum); //con & per tutti i valori tranne stringhe
    // Output the number the user typed
    printf("Your number is: %d", myNum);

    // Create a string
    char firstName[30];
    printf("Enter your first name: \n");
    scanf("%s", firstName); // senza &
    printf("Hello %s", firstName);

    //stringhe usando char
    char greetings[] = "Hello World!";
    printf("%s", greetings);
    greetings[0] = 'J'; //modifica la stringa in posizione 0

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%zu\n", strlen(alphabet));   // 26 caratteri perché parte da 1
    printf("%zu\n", sizeof(alphabet));   // 27 caratteri perché parte da 0

    //concatenazione
    char str1[20] = "Hello ";
    char str2[] = "World!";
    // Concatenate str2 to str1 (result is stored in str1)
    strcat(str1, str2);

    //copia
    char str1C[20] = "Hello World!";
    char str2C[20];
    // Copy str1 to str2
    strcpy(str2C, str1C);

    //comparazione
    char str1Comp[] = "Hello";
    char str2Comp[] = "Hello";
    char str3Comp[] = "Hi";
    // Compare str1 and str2, and print the result
    printf("%d\n", strcmp(str1Comp, str2Comp));  // Returns 0 (the strings are equal)
    // Compare str1 and str3, and print the result
    printf("%d\n", strcmp(str1Comp, str3Comp));  // Returns -4 (the strings are not equal)

    //array
    int myNumbers[] = {10, 25, 50, 75, 100}; // array int
    printf("%zu", sizeof(myNumbers)); // lunghezza array

    //matrici
    int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\n", matrix[i][j]);
        }
    }

    /* caratteri speciali
        \'	'	Single quote
        \"	"	Double quote
        \\	\	Backslash
    */
    char txt[] = "It\'s alright."; // esempio apostrofo


    return 0;
}
