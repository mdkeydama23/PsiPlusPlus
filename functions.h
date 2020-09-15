#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


// Function prototypes
char checkIfOperator(char c, FILE *fptr1, FILE *fptr2);
char checkIfInt(char c, FILE *fptr1, FILE *fptr2);
char checkIfIdentifier(char c, FILE *fptr1, FILE *fptr2);
char checkIfComment(char c, FILE *fptr1, FILE *fptr2);
char checkIfStringLiteral(char c, FILE *fptr1, FILE *fptr2);


#endif // FUNCTIONS_H_INCLUDED
