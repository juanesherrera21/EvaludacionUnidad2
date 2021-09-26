#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM_CHILD 1

int main(int argc, char *argv[]){
char *const argv2[]={"1","2","3", NULL};
pid_t pidC;
int status;

printf("HOla acabo de iniciar Soy el proceso original creeme: %d\n",getpid());


for(int i=0;i< NUM_CHILD;i++){

pidC=fork();
if(pidC>0){
pidC=wait(&status);
execv("./program",argv2);

}else if(pidC==0)
{
int num1=0;
int num2=0;

num1=atoi(argv[1]);
num2=atoi(argv[2]);



int suma=0;
suma=num1+num2;
printf("HIJO: PID=%d, Resulatado de la suma realizada %d \n",getpid(),suma);

FILE *f;
f=fopen("datos.txt","w");
if(f==NULL){
printf("no se logro crear el archivo");
}
fprintf(f,"%d\n",suma);
fclose(f);

exit(suma);
}else{
/*error*/
}
if(pidC!=0){
wait();
}
}


}
