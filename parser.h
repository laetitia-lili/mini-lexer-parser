#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

/* ---- arbre syntaxique ---- */
typedef struct Node {
    Token token ; // valeur du noeud
    struct Node *left ;// enfant gauche 
    struct Node *right ; // enfant droit 
}Node ;

/* ---- Prototypes ----*/
Node *expr(Token *tokens , int *i);
Node *term(Token *tokens , int *i);
Node *factor(Token *tokens , int *i);

#endif 