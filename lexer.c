#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tokens.h"

// Función que reconoce el siguiente token en el archivo
TokenType reconocerToken(FILE *fuente, char *lexema) {
    int c;

    // Ignorar espacios en blanco excepto saltos de línea
    do {
        c = fgetc(fuente);
        if (c == '\n') return NEWLINE;  
    } while (isspace(c));

    // Fin de archivo
    if (c == EOF) return EOF_TOKEN;

    // Signos de puntuación
    if (c == '{') return L_LLAVE;
    if (c == '}') return R_LLAVE;
    if (c == '[') return L_CORCHETE;
    if (c == ']') return R_CORCHETE;
    if (c == ',') return COMA;
    if (c == ':') return DOS_PUNTOS;

    // Números
    if (isdigit(c)) {
        int i = 0;
        lexema[i++] = c;
        while (isdigit(c = fgetc(fuente))) {
            lexema[i++] = c;
        }
        if (c == '.') { // decimal
            lexema[i++] = c;
            while (isdigit(c = fgetc(fuente))) {
                lexema[i++] = c;
            }
        }
        if (c == 'e' || c == 'E') { // notación científica
            lexema[i++] = c;
            c = fgetc(fuente);
            if (c == '+' || c == '-') {
                lexema[i++] = c;
                c = fgetc(fuente);
            }
            while (isdigit(c)) {
                lexema[i++] = c;
                c = fgetc(fuente);
            }
        }
        lexema[i] = '\0';
        ungetc(c, fuente); // devolver último caracter no numérico
        return LITERAL_NUM;
    }

    // Literales en cadena
    if (c == '"') {
        int i = 0;
        while ((c = fgetc(fuente)) != '"' && c != EOF) {
            lexema[i++] = c;
        }
        lexema[i] = '\0';
        return LITERAL_CADENA;
    }

    // Palabras reservadas: true, false, null
    if (isalpha(c)) {
        char buffer[20];
        int i = 0;
        buffer[i++] = c;
        while (isalpha(c = fgetc(fuente))) {
            buffer[i++] = c;
        }
        buffer[i] = '\0';
        ungetc(c, fuente); // devolvemos el último no-alfabético

        if (strcasecmp(buffer, "true") == 0) return PR_TRUE;
        if (strcasecmp(buffer, "false") == 0) return PR_FALSE;
        if (strcasecmp(buffer, "null") == 0) return PR_NULL;

        return ERROR_TOKEN;
    }

    return ERROR_TOKEN;
}

