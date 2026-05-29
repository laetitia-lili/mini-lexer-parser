#ifndef LEXER_H
#define LEXER_H

#define MAX_SIZE 256

/* ---- Types de tokens ----*/
typedef enum {
    TOKEN_NUMBER , // entiers
    TOKEN_IDENT , // identifiant 
    TOKEN_PLUS, // +
    TOKEN_MINUS , // -
    TOKEN_STAR , // *
    TOKEN_SLASH, // /
    TOKEN_LPAREN,// (
    TOKEN_RPAREN, // )
    TOKEN_EOF, // fin de  chaîne 
    TOKEN_UNKNOWN, // caractère non reconnu 
}TokenType;


/* ---- Structure token ---- */
typedef struct {
    TokenType type ; // le type du token
    char value[MAX_SIZE]; // la valeur du token
}Token;


/* ---- Lexer ---- */
Token next_token(const char **p);
/* ---- Affichage ---- */
const char *token_type_to_str(TokenType type);

#endif