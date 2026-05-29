<div align="center">

# 🌸 Mini Lexer & Parser en C

*Un analyseur lexical et syntaxique écrit from scratch en C*

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-427819?style=for-the-badge&logo=gnu&logoColor=white)
![License](https://img.shields.io/badge/licence-MIT-pink?style=for-the-badge)
</div>

---

## 💫 À propos

Ce projet implémente les deux premières étapes d'un compilateur :

- 🔍 **Le lexer** — lit une expression caractère par caractère et la découpe en *tokens*
- 🌳 **Le parser** — analyse les tokens et construit un *arbre syntaxique* (AST) en respectant les priorités opératoires

---

## ✨ Fonctionnalités

- ✅ Tokenisation d'expressions arithmétiques
- ✅ Gestion des entiers et flottants (`42`, `3.14`, `0.5`)
- ✅ Gestion des identifiants (`x`, `foo`, `abc`)
- ✅ Opérateurs `+` `-` `*` `/` et parenthèses `(` `)`
- ✅ Respect des priorités opératoires (`*` avant `+`)
- ✅ Affichage visuel de l'arbre syntaxique

---

## 📁 Structure du projet

```
mini-lexer-parser/
├── 📄 lexer.h        # Définitions des tokens et prototypes
├── 📄 lexer.c        # Implémentation du lexer
├── 📄 parser.h       # Définition de l'AST et prototypes
├── 📄 parser.c       # Implémentation du parser
├── 📄 main.c         # Programme principal
├── 📄 Makefile       # Compilation et nettoyage
└── 📄 .gitignore
```

---

## 🚀 Compilation et exécution

**Compiler le projet :**
```bash
make
```

**Lancer le lexer et parser :**
```bash
./parser "3 + 42 * x"
```

**Nettoyer les fichiers compilés :**
```bash
make clean
```

---

## 📌 Exemple de sortie

```bash
./parser "3 + 42 * x"
```

```
valeur: 3       type : Nombre
valeur: +       type : Opérateur +
valeur: 42      type : Nombre
valeur: *       type : Opérateur *
valeur: x       type : Identifiant

Expression : 3+42*x

Arbre syntaxique :
        x
    *
        42
+
    3
```

> 💡 L'arbre est affiché couché sur le côté — les nœuds les plus profonds ont la priorité la plus haute.

---

## 🔧 Architecture

### 🔍 Lexer — les tokens reconnus

| Token | Exemples |
|:---|:---|
| `Nombre` | `42`, `3.14`, `0.5` |
| `Identifiant` | `x`, `foo`, `abc` |
| `Opérateur +` | `+` |
| `Opérateur -` | `-` |
| `Opérateur *` | `*` |
| `Opérateur /` | `/` |
| `Parenthèse ouvrante` | `(` |
| `Parenthèse fermante` | `)` |

### 🌳 Parser — descente récursive

Le parser utilise trois niveaux de priorité imbriqués :

```
expr()        →  gère + et -        (priorité faible)
  └─ term()       →  gère * et /    (priorité moyenne)
       └─ factor()    →  gère () et valeurs  (priorité haute)
```

---

## 🙈 Fichiers ignorés

```gitignore
parser
out
*.o
```

---


