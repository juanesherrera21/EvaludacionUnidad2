#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
int main(int argc, char *argv[]){

printf("Soy el proceso: %d\n",getpid());

FILE * flujo=fopen("datos.txt","r");
if(flujo==NULL){
perror("Error apertura archivo");

}
char caracter;
while(feof(flujo)==0){
caracter=fgetc(flujo);
printf("%c", caracter);
}
fclose(flujo);
printf("se leyo correctamente el archivo.....\n");

}

