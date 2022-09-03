#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int matriz[4][4];
int fila3 = 3, columna3 = 3; //posicion de la matriz en la que se encuentra el 3
int valor = 19; //valor que se va a intercambiar con el 3
void imprimirMatriz(); //funcion para imprimir la matriz
void llenarMatriz(); //funcion para llenar la matriz
void buscarValor(int); //funcion para buscar el valor en la matriz


int main () {
  
    char caracter; //variable para leer un caracter
    char enter; //variable para leer un enter
    llenarMatriz(); 
    buscarValor(valor);
    matriz[3][3] = 0;//el 3 se pone en 0 para que no se imprima
    imprimirMatriz();
  
    do{
         caracter = getchar(); //se lee un caracter de entrada por teclado
         enter = getchar(); //se lee un enter de entrada por teclado
        printf("caracter: %c\n", caracter);
        switch (caracter) //para moverse entre la matriz
        {
        case 'w' : //mover arriba
            if(fila3 > 0){
                matriz[fila3][columna3] = matriz[fila3-1][columna3]; //intercambio de valor  [2][3] sabiendo que [3][3] es 0 y ahora la [3] [3] es la [2] [3]
                matriz[fila3-1][columna3] = 0; //se pone en 0 la posicion de la fila [2][3] 
                imprimirMatriz();
                fila3--; //se decrementa la fila 
            }else{printf("No se puede mover hacia arriba\n");}
            break;
        case 's' ://mover abajo
            if(fila3 < 3){ //si la fila no es la ultima
                matriz[fila3][columna3] = matriz[fila3+1][columna3]; //intercambio de valor  [2][3] al [3][3] 
                matriz[fila3+1][columna3] = 0;
                imprimirMatriz();
                fila3++;
            }else{printf("No se puede mover mas abajo\n");}
            break;
         case 'a' ://mover a la izquierda
            if(columna3 > 0){
                matriz[fila3][columna3] = matriz[fila3][columna3-1];
                matriz[fila3][columna3-1] = 0;
                imprimirMatriz();
                columna3--;
            }else{ printf("No se puede mover a la izquierda\n");}
            break;
        case 'd' ://mover a la derecha
            if(columna3 < 3){
                matriz[fila3][columna3] = matriz[fila3][columna3+1];
                matriz[fila3][columna3+1] = 0;
                imprimirMatriz();
                columna3++;
            }else{ printf("No se puede mover a la derecha\n");}
            break;
        case 'e':
            break;

        default:
        printf("Opcion no valida, por favor utilice (w), (d), (s) y (a) para moverse.\n");
            break;
        }




       
    }while(caracter != 'e');

    return 0;
}
void imprimirMatriz(){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            if(matriz[i][j] != 0){ //si el valor de la matriz es diferente de 0
                printf("[%2i] ", matriz[i][j]);
            }else{
                printf("[  ] ");
            };
        }
        printf("\n");
    }
}
void llenarMatriz(){
    int contador = 1;
    srand(time(0));
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
           // matriz[i][j] = 1 + rand() % 16 ;
         matriz[i][j] = contador;
         contador++;
        }
        printf("\n");
    }
}
void buscarValor(int valor){
    int aux;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(matriz[i][j] == valor){
                aux = matriz[i][j];
                matriz[i][j] = matriz[fila3][columna3];
                matriz[fila3][columna3] = aux;
              
            }
        }
    }
}


