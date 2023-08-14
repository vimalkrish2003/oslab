#include <stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include <sys/shm.h>

int main()
{
    int key=ftok("/Documents/Vimal/os_lab",2);
    int shmid=shmget(key,1024,0666 | IPC_CREAT);
    char* shmaddr=(char*) shmat(shmid,NULL,0);
    printf("the stored information is \n");
    puts(shmaddr);
    return 0;
}