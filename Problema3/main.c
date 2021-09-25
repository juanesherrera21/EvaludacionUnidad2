#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>

#define BUF_SIZE 100

int op = 4;
char comando[10];

void upper(char *buffer);
void words(char *buffer);
void vowels(char *buffer);

void *threadComandos(void *arg){
    char comando[20];
    while (1)
    {
        scanf("%s",comando);
        for (int i = 0; comando[i] !='\0'; ++i)
        {
            comando[i] = tolower(comando[i]);
        }
        int opUpper = strcmp(comando,"upper");
        int opWords = strcmp(comando,"words");
        int opVowels = strcmp(comando,"vowels");
        int opNone = strcmp(comando,"none");

        if (opUpper == 0)
        {
            op = 1;
        }else if (opWords == 0)
        {
            op = 2;
        }else if (opVowels == 0)
        {
            op = 3;
        }else if (opNone == 0)
        {
            op = 4;
        }
    }
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
    // Creacion Hilo
    pthread_t threadsID;
    pthread_create(&threadsID,NULL,&threadComandos, NULL);

    char buffer[64];
    char *status;
    do{
        status = fgets(buffer, sizeof(buffer),fin);
        if(status != NULL){
            switch (op)
            {
            case 1:
                printf("%s",buffer);
                upper(buffer);
                sleep(1);
                break;
            case 2:
                printf("%s",buffer);
                words(buffer);
                sleep(1);
                break;
            case 3:
                printf("%s",buffer);
                vowels(buffer);
                sleep(1);
                break;
            case 4:
                printf("%s",buffer);
                sleep(1);
                break;
            default:
                printf("%s",buffer);
                sleep(1);
                break;
            }
        }
    }while (status !=NULL);
    printf("\n");
    
    fclose(fin);
    return(EXIT_SUCCESS);
}

void upper(char *buffer){
    for (int i = 0; buffer[i] != '\0'; ++i){
        buffer[i] = toupper(buffer[i]);
    }
    printf("%s\n", buffer);
}

void words(char *buffer){
    int count = 0;
    char lastC;
    int len  = strlen(buffer);
    for (int i = 0; i <= len; i++) {
        if((buffer[i]==' ' || buffer[i]=='\0') && lastC != ' '){
            count++;
        }
        lastC = buffer[i];
    }
    printf("%d\n",count);
}

void vowels(char *buffer){
    int vowels = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        char lastL = tolower(buffer[i]);
        if(lastL == 'a' || lastL == 'e' || lastL == 'i' || lastL == 'o' || lastL == 'u'){
            vowels++;
        }
    }
    printf("%d\n",vowels);
}

