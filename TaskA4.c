#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        sleep(2); 
        printf("Child process completed.\n");
        exit(0); 
    } else {
        // Parent process
        printf("Parent process: PID = %d, waiting for child...\n", getpid());
        wait(NULL); // Wait for the child process to complete
        printf("Child process has finished. Parent process exiting.\n");
    }

    return 0;
}
