#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#define BUF_SIZE 100

int main(int argc, char *argv[]){
    // Apagar el ECHO
    
    // Lectura de argumentos argv    
    for (int i = 0; i < argc; i++)
    {
        printf("Argv[%d]: %s\n",i,argv[i]);
    }
    // Lectura del Archivo de Entrada 'fin'
    FILE *fin = fopen(argv[1],"r+");
    if (fin == NULL){
        perror("open fin file fails: ");
        return(EXIT_FAILURE);
    }
    char buffer[64];
    char *status;
    do{
        status = fgets(buffer, sizeof(buffer),fin);
        if(status != NULL){
            printf("%s",buffer);
            sleep(1);
        }
    }while (status !=NULL);
    printf("\n");
    
    // Comando 'upper'
    char comando[10];
    scanf("%s",comando);
    if((strcmp(comando,"upper"))==0){
        for (int i = 0; buffer[i] != '\0'; ++i){
		    buffer[i] = toupper(buffer[i]);
	    }
	    printf("upper: %s\n", buffer);
    }
    
    // Comando 'words'
    int count = 0;
    char lastC;
    int len  = strlen(buffer);
    if((strcmp(comando,"words"))==0){
        for (int i = 0; i <= len; i++) {
            if((buffer[i]==' ' || buffer[i]=='\0') && lastC != ' '){
                count++;
            }
            lastC = buffer[i];
        }
        printf("words: %d\n",count);
    }
    
    // comando 'vowels'
    if((strcmp(comando,"vowels"))==0){
        int vowels = 0;
        for (int i = 0; buffer[i] != '\0'; i++) {
            char lastL = tolower(buffer[i]);
            if(lastL == 'a' || lastL == 'e' || lastL == 'i' || lastL == 'o' || lastL == 'u'){
                vowels++;
            }
        }
        printf("vowels: %d\n",vowels);
    }
    
    fclose(fin);
    return(EXIT_SUCCESS);
}