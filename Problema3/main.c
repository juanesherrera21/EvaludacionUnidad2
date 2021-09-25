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
    struct termios tp, save;
    char buf[BUF_SIZE];

    /* Retrieve current terminal settings, turn echoing off */

    if (tcgetattr(STDIN_FILENO, &tp) == -1)
        exit("tcgetattr");
    save = tp;                          /* So we can restore settings later */
    tp.c_lflag &= ~ECHO;                /* ECHO off, other bits unchanged */
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tp) == -1)
        exit("tcsetattr");

    /* Read some input and then display it back to the user */

    printf("Enter text: ");
    fflush(stdout);
    if (fgets(buf, BUF_SIZE, stdin) == NULL)
        printf("Got end-of-file/error on fgets()\n");
    else
        printf("\nRead: %s", buf);

    /* Restore original terminal settings */

    if (tcsetattr(STDIN_FILENO, TCSANOW, &save) == -1)
        exit("tcsetattr");

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