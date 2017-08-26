#include <stdio.h>

void ksa(unsigned char *state, unsigned char *key, int len){
   int i,j=0,t;
   for (i=0; i < 256; ++i)
      state[i] = i;
   for (i=0; i < 256; ++i) {
      j = (j + state[i] + key[i % len]) % 256;
      t = state[i];
      state[i] = state[j];
      state[j] = t;
   }
}

void prga(unsigned char *s, unsigned char *texto, int len){
    int i = 0;
    int j = 0;
    int t = 0;
    int k = 0;
    char tmp;
    for(k=0;k<len;k++)
    {
        i=(i+1)%256;
        j=(j+s[i])%256;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        t=(s[i]+s[j])%256;
        texto[k] ^= s[t];
    }
}

int main(){
    unsigned char state[256], key[25], texto[50];
    printf("\nTEXTO(max. 50 caracteres): ");
    fgets(texto, 50, stdin);
    fflush(stdin);
    printf("\nCHAVE(max. 25 caracteres): ");
    fgets(key, 25, stdin);
    fflush(stdin);

    int textoLength=strlen(texto), chaveLength=strlen(key) ,idx;


    ksa(state,key,chaveLength);
    printf("\n----------TEXTO ORIGINAL-----------\n");
    for (idx=0; idx < textoLength; idx++){
        printf("%c ",texto[idx]);
    }

    prga(state,texto,textoLength);

    printf("\n--------TEXTO CRIPTOGRAFADO--------\n");
    for (idx=0; idx < textoLength; idx++){
        printf("%c ",texto[idx]);
    }

    ksa(state,key,chaveLength);
    prga(state,texto,textoLength);

    printf("\n-------TEXTO DESCRIPTOGRAFADO------\n");
    for (idx=0; idx < textoLength; idx++){
        printf("%c ",texto[idx]);
    }
   return 0;
}
