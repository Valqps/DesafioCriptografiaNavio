#include <stdio.h>

int calcula_tamanho_string(char codigo[]){
    int tamanho = 0;
    while(codigo[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
}

void troca_numeros(char *a, char *b){
    char temporario;
    temporario = *a;
    *a = *b;
    *b = temporario;
}

void inverte_valores_dos_ultimos(char *n){
    if (*n =='0') {
        *n = '1';
    } else {
        *n = '0';
    }
}

int calcula_multiplicador_binario(int n){
    int k;
    int multiplicador = 1;
    for (k=0; k < 7 - n; k++){
        multiplicador = multiplicador * 2;
    }
    return multiplicador;
}

int main(){
    
    char codigo[] = "10010110111101110101011000000001000101110010011001010111000000010001011101110110010101110011011011110111110101110101011100000011";
    int bytes_codigo = calcula_tamanho_string(codigo)/8;
    int i;
    int j;
    int alvo;
    int vetor_numeros[8];
    int numero_decimal;
    int multiplicador_bin;

    printf("O dado decodificado eh: \n");
    //laço para analisar cada 8 bits de código
    for (i = 0; i < bytes_codigo; i++){

        //dentro dos 8 bits, trocar os 4 primeiros com os 4 últimos
        for(j = 0; j < 4; j++){
            alvo = 8 * i + j;
            troca_numeros(&codigo[alvo], &codigo[alvo + 4]);  
        }

        //muda de 0 para 1, e de 1 para 0 os últimos 2 valores dentro dos 8 bits
        if (j>1){
            inverte_valores_dos_ultimos(&codigo[alvo]);
            }
        
        //transforma os 8 bits de binário para decimal
        numero_decimal = 0;
        for(j = 0; j < 8 ; j++){
            vetor_numeros[j] = codigo[j + 8 * i] - '0';
            multiplicador_bin = calcula_multiplicador_binario(j);
            numero_decimal = numero_decimal + vetor_numeros[j] * multiplicador_bin;
        }

        //imprime o resultado do decimal em caracter, segundo tabela ascii
        printf("%c ", numero_decimal);
        
    }
    printf("\n");
    return 0;
}
