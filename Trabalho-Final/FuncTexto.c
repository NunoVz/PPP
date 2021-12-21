#include "header.h"
static int comp_mchar(const char *um, const char *outro);
static char acentuadas[][8] ={"á", "Á", "à", "À", "ã", "Ã", "â", "Â", "ä", "Ä", "ç", "Ç",
         "é", "É", "è", "È", "ê", "Ê", "í", "Í", "ì", "Ì", "î", "Î",
         "ó", "Ó", "ò", "Ò", "õ", "Õ", "ô", "Ô", "ö", "Ö", "ú", "Ú",
         "ù", "Ù", "û", "Û", "\0"};
static char base[] ={'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'c', 'c',
         'e', 'e', 'e', 'e', 'e', 'e', 'i', 'i', 'i', 'i', 'i', 'i',
         'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'u', 'u',
         'u', 'u', 'u', 'u', '\0'};


void strtobase_u8(char *dest, const char *orig) {
    int i = 0, j = 0, c;
    // percorrer a string origem
    c = (unsigned char) orig[0];
    while (c != 0) {
        if ((c & 0x80) == 0) {
            // é um carater ASCII, basta converter as letras para minusculas
            if (c <= 'Z' && c >= 'A')
                c = c + 'a' - 'A';
            i++;
            dest[j] = (char) c;
            j++;
        } else {
            // é um carater UTF-8 com mais de um byte
            int k = 0, tc = 0;
            while (acentuadas[k][0] != 0) {
                // se for uma das letras acentuadas, retira-se o acento
                if ((tc = comp_mchar(&acentuadas[k][0], &orig[i])) != 0) {
                    // encontramos uma minúscula acentuada
                    dest[j] = base[k];
                    j++;
                    i = i + tc;
                    break;
                }
                k++;
            }
            if (tc == 0) {
                // não é uma letra acentuada, logo é de copiar para
                //   o destino, sem alterações, todos os carateres UTF-8
                do {
                    dest[j] = orig[i];
                    i++;
                    j++;
                } while ((orig[i] & 0xC0) == 0x80);
            }
        }
        c = (unsigned char) orig[i];
    }
    dest[j] = 0;
}

static int comp_mchar(const char *um, const char *outro) {
    int i = 0;
    while (um[i] != 0) {
        if (um[i] != outro[i])
            return 0;
        i++;
    }
    return i;
}

int compara(char*chave, char* plvrArvore){
    if (strlen(chave)>strlen(plvrArvore)){
        return 0;
    }else{
        if (!strcmp(chave, plvrArvore))
            return 1;
        else{
            for (int i = 0; i < strlen(chave); ++i) {
                if (chave[i] != plvrArvore[i])
                    return 0;
            }
            return 1;
        }
    }
}


void mostra_contexto(int posicao,FILE* fich) {
    int lim_esq = 0, lim_dir = 0, c;
    fseek(fich, posicao, SEEK_SET);
    int i = 0;
    bool teste = true;
    while (i <= 5 && teste) {
        while ((c = fgetc(fich)) && c != ' ' && c != '\n') {
            lim_esq = (int) ftell(fich);
            if (lim_esq == 1) {
                teste = false;
                break;
            }
            fseek(fich, -2, SEEK_CUR);
        }
        if (i != 5) {
            fseek(fich, -2, SEEK_CUR);
        }
        i++;
    }
    fseek(fich,posicao,SEEK_SET);
    for(int n=0;n<=10;n++){
        while((c = fgetc(fich)) && c != ' ' && c !='\n' && c != EOF){
            lim_dir=(int)ftell(fich);
        }
    }
    lim_dir+=1;
    fseek(fich,lim_esq-1,SEEK_SET);
    int limite;
    while((c = fgetc(fich)) && limite != lim_dir && c != EOF ){
        fputc(c,stdout);
        limite=(int)ftell(fich);
    }
    printf("\n");
    free(fich);
    fich=NULL;
}



