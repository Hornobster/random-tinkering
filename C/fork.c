#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    printf("Process %d, child of process %d started...\n", getpid(), getppid());

    pid_t pid = fork();

    if (pid < 0) {
	printf("Failed fork()\n");
	return 1;
    } else if (pid == 0) {
	printf("Process %d, child of process %d started...\n", getpid(), getppid());

	execl("/usr/bin/top", "top", NULL);
	
	printf("Process %d, child of process %d stopped...\n", getpid(), getppid()); // not reachable, because execlp loads another ls into memory
    } else {
	wait(NULL); // wait for ls to finish
    }

    printf("Process %d, child of process %d stopped...\n", getpid(), getppid());
    return 0;
}
