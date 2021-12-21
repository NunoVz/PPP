#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "header.h"

static char acentuadas[][8] ={"á", "Á", "à", "À", "ã", "Ã", "â", "Â", "ä", "Ä", "ç", "Ç","é", "É", "è", "È", "ê", "Ê", "í", "Í", "ì", "Ì", "î", "Î","ó", "Ó", "ò", "Ò", "õ", "Õ", "ô", "Ô", "ö", "Ö", "ú", "Ú","ù", "Ù", "û", "Û", "\0"};
static char base[] ={'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'c', 'c','e', 'e', 'e', 'e', 'e', 'e', 'i', 'i', 'i', 'i', 'i', 'i','o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'u', 'u','u', 'u', 'u', 'u', '\0'};
static int comp_mchar(const char *um, const char *outro);
void strtobase_u8(char *dest, const char *orig) {
    int i = 0, j = 0, c;
    c = (unsigned char) orig[0];
    while (c != 0) {
        if ((c & 0x80) == 0) {
            if (c <= 'Z' && c >= 'A')
                c = c + 'a' - 'A';
            i++;
            dest[j] = (char) c;
            j++;
        } else {
            int k = 0, tc = 0;
            while (acentuadas[k][0] != 0) {
                if ((tc = comp_mchar(&acentuadas[k][0], &orig[i])) != 0) {
                    dest[j] = base[k];
                    j++;
                    i = i + tc;
                    break;
                }
                k++;
            }
            if (tc == 0) {
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
bool ler_texto(char *ptexto) {
    FILE *fich1;
    int i, c;
    fich1 = fopen("palavras.txt", "r");
    if (fich1 == NULL) {
        return false;
    }
    i = 0;
    while (i < (MAX_TEXTO) && (c = fgetc(fich1)) != EOF) {
        ptexto[i] = tolower(c);
        if (i == 2 && ptexto[0] == (char)0xEF && ptexto[1] == (char) 0xBB && ptexto[2] == (char) 0xBF)
            i = 0;
        else
            i++;
    }
    ptexto[i] = 0;
    i++;
    fclose(fich1);
    if (i <= MAX_TEXTO)
        return true;
    else
        return false;
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
