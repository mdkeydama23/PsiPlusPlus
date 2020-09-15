# A lexical Analyzer For The PsiPlusPlus Language

## A Brief Introduction to the Program

The Program accepts a source file called *code.psi* and produces a text file named *code.lex* that contains all the tokens of the code.psi listed one after the other.

### Analysis Phase

A brief description of all the token types and rules implemented in the program are included in the section below:

### Identifiers

Maximum identifier size is 15 characters. If you use an identifier larger than that, the lexical analyzer issues an error message.
Psi++ language is not case sensitive, and all the identifier names are standardized as lowercase.
Identifiers start with an alphabetic character (a letter) and are composed of one or more letters, digits or _ (underscore)
Example Token: Identifier(my_var_5)

### Integer Constants

Maximum integer size is 50 digits. If you use an integer value longer than that, the lexical analyzer issues an error message.
Negative values are not supported.
Example Token: IntConst(2459)

### Operators

Valid operators of the language are +, -, *, /, ++, --, :=
Example Token: Operator (++)

### Brackets

LeftPar: (, RightPar: )
LeftSquareBracket: [, RightSquareBracket]
LeftCurlyBracket: {, RightCurlyBracket: }
Example Token: LeftCurlyBracket

### String Constants

String constants of Psi++ are delimited by double quotes (ASCII code 34) as in “this is a string”
String constants have unlimited size.
String constants cannot contain the double quote character. when you reach one, the string terminates.
If a string constant cannot terminate before the file end, there should be a lexical error issued.

### Keywords

Keywords are: break, case, char, const, continue, do, else, enum, float, for, goto, if, int, long, record, return, static, while
Psi++ language is not case sensitive, and all the keywords are standardized as lower case. You can write the same word as “while” OR “While” OR “WHILE” and they all generate them…
Example Token: Keyword(while)

### End of Line

Period “.” represents end of line in this language.
Example Token: EndOfLine

### Comments

Anything between { and } is a comment.
If a comment cannot terminate before the file end, there should be a lexical error issued.
Comments are just like blank space and they provide no tokens.

