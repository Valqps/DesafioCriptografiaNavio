#include <stdio.h>

int main(){
    
    char codigo[] = "10010110111101110101011000000001000101110010011001010111000000010001011101110110010101110011011011110111110101110101011100000011";
    int bytes_codigo = 16;
    int i;
    int j;
    char temporario;
    int alvo;
    int vetor_numeros[8];
    int numero_decimal;
    int casa_decimal;
    int k;

    for (i = 0; i < bytes_codigo; i++){
        for(j = 0; j < 4; j++){
            alvo = 8 * i + j;
            
            //troca dos 4 primeiros com os 4 ultimos
            temporario = codigo[alvo];
            codigo[alvo] = codigo [alvo + 4];
            codigo[alvo + 4] = temporario;
        }

        if (j>1){
                if (codigo[alvo]=='0') {
                    codigo[alvo] = '1';
                } else {
                    codigo[alvo]= '0';
                }
            }
        
        numero_decimal = 0;

        for(j = 0; j < 8 ; j++){
            casa_decimal = 1;
            vetor_numeros[j] = codigo[j + 8 * i] - '0';
            for (k=0; k < 7 - j; k++){
                casa_decimal = casa_decimal * 2;
            }
            numero_decimal = numero_decimal + vetor_numeros[j]*casa_decimal;
        }

        printf("%c ", numero_decimal);
        

        //printf("A primeira letra é: %c", codigo[i:i+8]);
    }

    return 0;
}
