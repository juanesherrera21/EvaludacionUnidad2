#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>

#define BUF_SIZE 100

char comando[10];

void upper(char *buffer);
void words(char *buffer);
void vowels(char *buffer);

void *threadComandos(void *arg){
    return NULL;
}

int main(int argc, char *argv[]){
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
    int *op = malloc(sizeof(int));
    *op = 2;
    // Creacion Hilo
    pthread_t threadsID;
    pthread_create(&threadsID,NULL,&threadComandos, NULL);

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
    
    fclose(fin);
    return(EXIT_SUCCESS);
}

void upper(char *buffer){
    scanf("%s",comando);
    if((strcmp(comando,"upper"))==0){
        for (int i = 0; buffer[i] != '\0'; ++i){
		    buffer[i] = toupper(buffer[i]);
	    }
	    printf("upper: %s\n", buffer);
    }
}

void words(char *buffer){
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
}

void vowels(char *buffer){
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
}

