#include <stdio.h>
#include "lexer.h"
#include "parser.h"

/* ---- affichage de l'arbre ---- */
void print_tree(Node *n) {
    if (n == NULL) return;
    print_tree(n->left);
    printf("%s", n->token.value);
    print_tree(n->right);
}

/* ---- affichage indenté de l'arbre ---- */
void print_tree_indent(Node *n, int depth) {
    if (n == NULL) return;
    print_tree_indent(n->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("    ");
    printf("%s\n", n->token.value);
    print_tree_indent(n->left, depth + 1);
}

/* ---- main ---- */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Erreur : pas d'arguments\n");
        return 1;
    }
    /* afficher les tokens */
    const char *p = argv[1];
    Token tok;
    tok = next_token(&p);
    while (tok.type != TOKEN_EOF) {
        printf("valeur: %s\ttype : %s\n", tok.value, token_type_to_str(tok.type));
        tok = next_token(&p);
    }
    /* collecter les tokens dans un tableau */
    p = argv[1];
    Token tokens[256];
    int n = 0;
    do {
        tokens[n] = next_token(&p);
    } while (tokens[n++].type != TOKEN_EOF);
    /* construire et afficher l'arbre */
    int i = 0;
    Node *tree = expr(tokens, &i);
    printf("\nExpression : ");
    print_tree(tree);
    printf("\n");
    printf("\nArbre syntaxique :\n");
    print_tree_indent(tree, 0);
    return 0;
}