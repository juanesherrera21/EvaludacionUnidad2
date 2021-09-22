#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int main(int argc, char *argv[]){
    for (int i = 0; i < argc; i++)
    {
        printf("Argv[%d]: %s\n",i,argv[i]);
    }
    
    FILE *fin = fopen(argv[1],"r+");
    if (fin == NULL){
        perror("open fin file fails: ");
        return(EXIT_FAILURE);
    }

    char buffer[64];
    char *status =  NULL;
    status = fgets(buffer,sizeof(buffer),fin);
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