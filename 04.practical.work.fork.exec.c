#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    printf("Main before fork()\n");
    int pid1 = fork();
    if(pid1 == 0){
        printf("I am the first child, launching ps -ef\n");
        char* args[] = {"/bin/ps", "-ef", NULL};
        execvp("/bin/ps", args);
    }
    else {
        printf("I am parent after the first fork(), the first child is %d\nContinue to create another child\n", pid1);
        waitpid(pid1, NULL, 0);
        int pid2 = fork();
        if(pid2 == 0){
            printf("I am  the second child, launching free -h\n");
            char* args[] = {"/usr/bin/free", "-h", NULL};
            execvp("/usr/bin/free", args);
        }
        else {
            printf("\nI am parent after 2 forks, the second child is %d\n", pid2);
            waitpid(pid2, NULL, 0);
        }
    }
    return 0;
}