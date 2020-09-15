/**
 * Contains for identifying the different
 * types of tokens in Psi++
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "functions.h"

// Function prototype
bool checkIfKeyWord(char *str);

// Max identifier length
#define maxIdtLen 15

// Max int length
#define maxInt 50


// Name of tokens
char *operator = "Operator";
char *strConst = "StrConst";
char *intConst = "IntCont";
char *identifier = "Identifier";
char *keyWord = "Keyword";


/**
 *  Check if character c is beginning of an operator or not.
 *  If operator write to fptr2(code.lex)
 **/
char checkIfOperator(char c, FILE* fptr1, FILE* fptr2)
{
    if (c == '/')
    {
        fputs(operator, fptr2);
        fputs("(/)\n", fptr2);
        return fgetc(fptr1);
    }
    else if (c == '*')
     {
        fputs(operator, fptr2);
        fputs("(*)\n", fptr2);
        return fgetc(fptr1);
     }
    else if (c == '+')
    {
        fputs(operator, fptr2);
        fputs("(+", fptr2);
        c = fgetc(fptr1);
        if (c == '+')
        {
            fputs("+)\n", fptr2);
            return fgetc(fptr1);
        }
        else
        {
            fputs(")\n", fptr2);
            return c;
        }
    }
    else if (c == '-')
    {
        fputs(operator, fptr2);
        fputs("(-", fptr2);
        c = fgetc(fptr1);
        if (c == '-')
        {
            fputs("-)\n", fptr2);
            return fgetc(fptr1);
        }
        else
        {
            fputs(")\n", fptr2);
            return c;
        }
    }
    else if (c == ':')
    {
        c = fgetc(fptr1);
        if (c == '=')
        {
            fputs(operator, fptr2);
            fputs("(:=)\n", fptr2);
            return fgetc(fptr1);
        }
        else
        {
            printf("Error. Unidentified char in code.psi file.\nExiting...\n");
            exit(1);
        }
    }
}


/**
 *  Check if character c is beginning of a valid identifier or not.
 *  If a valid identifier is found write to fptr2(code.lex)
 **/
char checkIfIdentifier(char c, FILE *fptr1, FILE *fptr2)
{
    // Max identifier length holder array
    char holder[maxIdtLen + 1] = "";

    // Look for whole identifier string
    int i = 0;
    while (isalnum(c) || c == '_')
    {
        if (i > 14)
        {
            printf("Error. Identifier length cannot be greater than 15 characters long.\nExiting...\n");
            exit(1);
        }
        holder[i++] = tolower(c);
        c = fgetc(fptr1);
    }

    // check if identifier is keyword
    if (checkIfKeyWord(holder))
    {
        fputs(keyWord, fptr2);
        fputc('(', fptr2);
        fputs(holder, fptr2);
        fputs(")\n", fptr2);
        return c;
    }
    else
    {
        fputs(identifier, fptr2);
        fputc('(', fptr2);
        fputs(holder, fptr2);
        fputs(")\n", fptr2);
        return c;
    }
}


/**
 *  Check if character c is beginning of a valid integer or not.
 *  If a valid integer write to fptr2(code.lex)
 **/
char checkIfInt(char c, FILE *fptr1, FILE *fptr2)
{
    // Max integer length checker
    int holder = 1;

    // Look for whole integer string
    fputs(intConst, fptr2);
    fputc('(', fptr2);
    fputc(c, fptr2);
    c = fgetc(fptr1);
    while (isdigit(c))
    {
        holder++;
        if (holder > maxInt)
        {
            printf("Error. Integer constant cannot be greater than 50 digits long.\nExiting...\n");
            exit(1);
        }
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    fputs(")\n", fptr2);
    return c;
}


/**
 *  Check if character c is beginning of a valid character string or not.
 *  If valid character string write to fptr2(code.lex)
 **/
char checkIfStringLiteral(char c, FILE *fptr1, FILE *fptr2)
{
    fputs(strConst, fptr2);
    fputs("(", fptr2);
    c = fgetc(fptr1);
    while(c != '"')
    {
        if (c == EOF)
        {
            printf("Error. EOF reached before string literal close.\nExiting...\n");
            exit(1);
        }
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    fputs(")\n", fptr2);
    return fgetc(fptr1);
}


/**
 *  Check if character c is beginning of a valid comment or not.
 *  If valid character string write to fptr2(code.lex)
 **/
char checkIfComment(char c, FILE *fptr1, FILE *fptr2)
{
    c = fgetc(fptr1);
    while(c != '}')
    {
        if (c == EOF)
        {
            printf("Error. EOF reached before comment close.\nExiting...\n");
            exit(1);
        }
        c = fgetc(fptr1);
    }
    return fgetc(fptr1);
}

// Check if character string is a key word as defined by Psi++ definition
bool checkIfKeyWord(char *str)
{
    if(!strcasecmp(str, "break") || !strcasecmp(str, "case") || !strcasecmp(str, "char") ||
    !strcasecmp(str, "const") || !strcasecmp(str, "continue") || !strcasecmp(str, "do") ||
    !strcasecmp(str, "else") || !strcasecmp(str, "enum") || !strcasecmp(str, "float") ||
    !strcasecmp(str, "for") || !strcasecmp(str, "goto") || !strcasecmp(str, "if")  || !strcasecmp(str, "int") ||
    !strcasecmp(str, "long") || !strcasecmp(str, "record") || !strcasecmp(str, "return") || !strcasecmp(str, "static") ||
    !strcasecmp(str, "while"))
    {
        return true;
    }
    return false;
}
