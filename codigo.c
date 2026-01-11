#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func(char *estrutura, char *onde){
    char comand[600];
    sprintf(comand, "echo \"%s\" >> %s", estrutura, onde);
    return system(comand);
}

int main(){
    char topico[50];
    char arquivo[50];
    char conteudo[500];

    while (1){
        printf("digite o nome do topico> ");
        fgets(topico, sizeof(topico), stdin);
        topico[strcspn(topico, "\n")] = '\0';
        
        if (strcmp(topico, "exit") == 0){
            break;
        }

        printf("e em qual arquivo colocar? ");
        fgets(arquivo, sizeof(arquivo), stdin);
        arquivo[strcspn(arquivo, "\n")] = '\0';

        func(topico, arquivo);

        while (1){
            printf("> ");
            fgets(conteudo, sizeof(conteudo), stdin);
            conteudo[strcspn(conteudo, "\n")] = '\0';
            
            if (strcmp(conteudo, "EOF") == 0){
                break;
            }
            
            func(conteudo, arquivo);
        }    
    }
    return 0;
}
