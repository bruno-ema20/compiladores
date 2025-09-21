#ifndef TOKENS_H
#define TOKENS_H

// Definición de todos los tipos de tokens válidos
typedef enum {
    L_CORCHETE,     // [
    R_CORCHETE,     // ]
    L_LLAVE,        // {
    R_LLAVE,        // }
    COMA,           // ,
    DOS_PUNTOS,     // :
    LITERAL_CADENA, // "texto"
    LITERAL_NUM,    // 123, 3.14, 2e10
    PR_TRUE,        // true / TRUE
    PR_FALSE,       // false / FALSE
    PR_NULL,        // null / NULL
    EOF_TOKEN,      // Fin de archivo
    NEWLINE,        // salto de linea
    ERROR_TOKEN     // Token no válido
} TokenType;

#endif

