#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void gravar_linha(char *text, FILE *file) {
    if (file != NULL) {
        fprintf(file, "%s\n", text);
        fflush(file); 
    }
}

int main() {
    char topico[200];
    char onde[50];
    char texto[800];
    FILE *file;

    printf("Digite o nome do topico: ");
    fgets(topico, sizeof(topico), stdin);
    topico[strcspn(topico, "\n")] = '\0';

    if (strcmp(topico, "exit") == 0) return 0;

    printf("E em qual arquivo? ");
    fgets(onde, sizeof(onde), stdin);
    onde[strcspn(onde, "\n")] = '\0';

    file = fopen(onde, "a");
    if (file == NULL) {
        perror("Erro");
        return 1;
    }

    gravar_linha(topico, file);

    while (1) {
        printf("> ");
        if (fgets(texto, sizeof(texto), stdin) == NULL) break;
        
        texto[strcspn(texto, "\n")] = '\0';

        if (strcmp(texto, "EOF") == 0) break;

        gravar_linha(texto, file);
    }

    fclose(file);
    return 0;
}
