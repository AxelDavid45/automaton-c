#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

char userInput[100];
char firstLetter;

int main () {
    printf("Escribe algo:");
    fgets(userInput, 100, stdin);

    // Check whether the expression has white-spaces
    for (int i = 0; i < strlen(userInput) - 1; i++) {
        if (isspace(userInput[i]) != 0) {
            fprintf(stderr, "Espacios no permitidos\n");
            exit(-1);
        }
    }

    firstLetter = userInput[0];

    char expression[100];
//    regex_t isNumber;
//    int result = regcomp(&isNumber, "[0-9]",0);
//    int result1 = regexec(&isNumber, "5452", 0, NULL, 0);

//    printf("%i\n", result);
//    printf("%i\n", result1);
    if (isdigit(firstLetter)) {
        bool isValid = true;
        bool expressionReset = false;
        bool foundPoint = false;
        int startingPoint = 0;
        while(isValid){
            for (int i = startingPoint; i < strlen(userInput) - 1; i++) {
                if (isdigit(userInput[i])) {
                    expression[i] = userInput[i];
                } else if (userInput[i] == '.') {
                    if (foundPoint) {
                        printf("Unexpected token: %c\n", userInput[i]);
                        exit(-1);
                    }
                    foundPoint = true;
                    startingPoint = i + 1;
                    expressionReset = true;
                    memset(expression,0, sizeof(expression));
                } else {
                    isValid = false;
                    printf("Unexpected token: %c\n", userInput[i]);
                    exit(-1);
                }
            }
            isValid = false;

            // Determine if the expression is an even number
            if (!expressionReset) {
                int expressionInt = atoi(expression);
                if ((expressionInt % 2) != 0) {
                    printf("Invalid number: %i\n", expressionInt);
                    exit(-1);
                }
            }
            printf("Valid expression :)");
        }
    }

    if (isalpha(firstLetter)) {
        printf("es letra");
    }

    if (firstLetter == '#') {
        printf("es #");
    }


    return 0;
}
