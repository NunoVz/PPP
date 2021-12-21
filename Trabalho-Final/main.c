#include "header.h"


int main(int argc,char *argv[]) {

    FILE *ficheiro = NULL; char ficheiro_nome[1000];
    while (ficheiro == NULL) {
        if (argc == 2) {
            strcpy(ficheiro_nome,argv[1]);
            ficheiro = fopen(ficheiro_nome, "r");
        } else {
            printf("Indique o nome do ficheiro: ");
            scanf("%s", ficheiro_nome);
            ficheiro = fopen(ficheiro_nome, "r");
        }
        if (ficheiro == NULL) {
            printf("Erro!! volte a indicar o nome do ficheiro: ");
            scanf("%s", ficheiro_nome);
            ficheiro = fopen(ficheiro_nome, "r");
        }
    }
    char ficheiroBIN[1024]="pal_";
    int len = strlen(ficheiro_nome);
    ficheiro_nome[len-4] = '\0';
    strcat(ficheiroBIN,ficheiro_nome);strcat(ficheiroBIN,".bin");
    printf("...");
    printf("\n..");
    printf("\n.");
    printf("\nSucesso!");

    FILE *f2 = fopen(ficheiroBIN, "wb");
    int wordPos = 0, c = 0;char w[30] = "";
    Data d;
    if (ficheiro == NULL) {
        printf("Problemas na criação do arquivo\n");
        return 0;
    } else {
        do {
            c = fgetc(ficheiro);


            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c =='-') || (c >= 128)) {
                w[wordPos] = (char) c;
                wordPos++;
            } else {
                w[wordPos] = '\0';
                wordPos = 0;

                if (strlen(w) > 1) {
                    strcpy(d.word, w);
                    d.posi = ftell(ficheiro) - strlen(w);
                    fwrite(&d, sizeof(Data), 1, f2);
                }
            }
        } while (c != EOF);
    }

    fclose(ficheiro);
    fclose(f2);

    return 0;
}