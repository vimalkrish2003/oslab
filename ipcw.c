#include <stdio.h>
#include <sys/ipc.h>
#include<sys/shm.h>
#include <stdlib.h>

int main()
{
    int key = ftok("/Documents/Vimal/os_lab",2);
    int shmid= shmget(key,1024,0666|IPC_CREAT);
    char* shmaddr=(char*) shmat(shmid,NULL,0);
    printf("data to store:");
    fgets(shmaddr,50,stdin);
    //scanf("%s",shmaddr);
    shmdt(shmaddr);
    return 0;
}