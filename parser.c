#include <stdlib.h>
#include "parser.h"

/* ---- Création d'un noeud ----*/
Node *new_node (Token token , Node *left , Node *right){
    Node *n = malloc(sizeof(Node));
    n -> token = token ; 
    n -> left = left ;
    n -> right = right ;
    return n ; 
}

/* ---- factor : valeurs et parenthèses ---- */
Node *factor(Token *tokens ,int *i){
    Token tok = tokens [*i];

    /* cas 01 : nombre ou identifiant */
    if (tok.type == TOKEN_NUMBER || tok.type == TOKEN_IDENT) {
        (*i)++;
        return new_node(tok, NULL, NULL);
    }

    /* cas 02 : parenthèse ouvrante */
    if (tok.type == TOKEN_LPAREN) {
        (*i)++;              /* on passe ( */
        Node *n = expr(tokens, i);  /* on lit l'expression dedans */
        (*i)++;              /* on passe ) */
        return n;
    }

    return NULL;
}

/* ---- term : multiplication et division ---- */
Node *term(Token *tokens, int *i) {
    Node *left = factor(tokens, i);
    while (tokens[*i].type == TOKEN_STAR || tokens[*i].type == TOKEN_SLASH) {
        Token op = tokens[*i];
        (*i)++;
        Node *right = factor(tokens, i);
        left = new_node(op, left, right);
    }
    return left;
}

/* ---- expr : addition et soustraction ---- */
Node *expr(Token *tokens, int *i) {
    Node *left = term(tokens, i);
    while (tokens[*i].type == TOKEN_PLUS || tokens[*i].type == TOKEN_MINUS) {
        Token op = tokens[*i];
        (*i)++;
        Node *right = term(tokens, i);
        left = new_node(op, left, right);
    }
    return left;
}