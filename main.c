#include <stdio.h>
#include "tokens.h"

// Prototipo de la función del lexer
TokenType reconocerToken(FILE *fuente, char *lexema);

int main() {
    FILE *fuente = fopen("fuente.txt", "r");
    FILE *salida = fopen("output.txt", "w");
    char lexema[256];
    TokenType token;

    if (!fuente || !salida) {
        printf("Error al abrir archivos.\n");
        return 1;
    }

    while ((token = reconocerToken(fuente, lexema)) != EOF_TOKEN) {
        switch (token) {
            case L_LLAVE: fprintf(salida, "L_LLAVE "); break;
            case R_LLAVE: fprintf(salida, "R_LLAVE "); break;
            case L_CORCHETE: fprintf(salida, "L_CORCHETE "); break;
            case R_CORCHETE: fprintf(salida, "R_CORCHETE "); break;
            case COMA: fprintf(salida, "COMA "); break;
            case DOS_PUNTOS: fprintf(salida, "DOS_PUNTOS "); break;
            case LITERAL_NUM: fprintf(salida, "LITERAL_NUM "); break;
            case LITERAL_CADENA: fprintf(salida, "LITERAL_CADENA "); break;
            case PR_TRUE: fprintf(salida, "PR_TRUE "); break;
            case PR_FALSE: fprintf(salida, "PR_FALSE "); break;
            case PR_NULL: fprintf(salida, "PR_NULL "); break;
            case ERROR_TOKEN: fprintf(salida, "ERROR "); break;
            default: break;
        }
    }

    fclose(fuente);
    fclose(salida);
    return 0;
}

