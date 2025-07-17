#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int x=100;
    pid_t pid=fork();
    if(pid<0){
        perror("Error:");
        exit(1);
    }
    else if(pid==0){
        printf("Child process x=%d\n",x);
        x=200;
        printf("Changed in child process x=%d\n",x);
    }
    else{
        sleep(1);
        printf("Parent process x=%d\n",x);
        x=300;
        printf("Changed in parent process x=%d\n",x);
    }
}