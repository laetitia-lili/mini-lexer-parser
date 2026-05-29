#include <ctype.h>
#include "lexer.h"

/* ---- Lexer ---- */

Token next_token(const char **p){
    Token tok ;
    char c = **p;

    /* cas 01 : fin de  chaîne */
    if (c == '\0'){
        tok.type = TOKEN_EOF;
        tok.value[0] = '\0';
        return tok ;
    }

    /* cas 02 : espace */
    if (isspace(c)){
        (*p) ++;
        return next_token(p);
    }

    /* cas 03 : nombre */
    if (isdigit(c)){
        int i = 0;
        while (isdigit(**p)){
            tok.value[i++] = **p;
            (*p)++;
        }
        if (**p == '.') {
            tok.value[i++] = '.';
            (*p)++;
            while (isdigit(**p)) {
                tok.value[i++] = **p;
                (*p)++;
        }
    }
        tok.value[i] = '\0';
        tok.type = TOKEN_NUMBER;
        return tok ; 
    }

    /* cas 04 : identifiant */
    if (isalpha(c)){
        int i = 0;
        while (isalpha(**p)){
            tok.value[i++] = **p;
            (*p)++;
        }
        tok.value[i] = '\0';
        tok.type = TOKEN_IDENT;
        return tok ; 
    }

    /* cas 05 : opérateurs et parenthèses */
    switch (c){
        case '+':
            tok.type = TOKEN_PLUS;
            tok.value[0] = '+';
            tok.value[1] = '\0';
            (*p)++;
            return tok; 
        case '-':
            tok.type = TOKEN_MINUS;
            tok.value[0] = '-';
            tok.value[1] = '\0';
            (*p)++;
            return tok;
        case '*':
            tok.type = TOKEN_STAR;
            tok.value[0] = '*';
            tok.value[1] = '\0';
            (*p)++;
            return tok;
        case '/':
            tok.type = TOKEN_SLASH;
            tok.value[0] = '/';
            tok.value[1] = '\0';
            (*p)++;
            return tok;
        case '(':
            tok.type = TOKEN_LPAREN;
            tok.value[0] = '(';
            tok.value[1] = '\0';
            (*p)++;
            return tok;
        case ')':
            tok.type = TOKEN_RPAREN;
            tok.value[0] = ')';
            tok.value[1] = '\0';
            (*p)++;
            return tok;
        default :
            tok.type = TOKEN_UNKNOWN;
            tok.value[0] = c;
            tok.value[1] = '\0';
            (*p)++;
            return tok;
    }
}

/* ---- Affichage ---- */
const char *token_type_to_str(TokenType type) {
    switch (type) {
        case TOKEN_NUMBER:  return "Nombre";
        case TOKEN_IDENT:   return "Identifiant";
        case TOKEN_PLUS:    return "Opérateur +";
        case TOKEN_MINUS:   return "Opérateur -";
        case TOKEN_STAR:    return "Opérateur *";
        case TOKEN_SLASH:   return "Opérateur / ";
        case TOKEN_LPAREN:  return "Parenthèse ouvrante";
        case TOKEN_RPAREN:  return "Parenthèse fermante";
        case TOKEN_EOF:     return "Fin de chaîne";
        case TOKEN_UNKNOWN: return "caractère inconnu";
        default:            return "?";
    }
}