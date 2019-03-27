#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


// wait()

int main() {

  //fork() returns twice
  int pid = fork();

  if (pid == 0) {
    printf("Child here!\n");
    printf("kiwiiis\n");
    printf("Child's pid: %d\n", pid);

    exit(999999);
  } else {

      int status;
    // waitpid(pid, NULL, );
    wait(&status);
    // wait(NULL);

    if WIFEXITED(status){
        printf("Parent Wexited: child exited with status %d\n", WEXITSTATUS(status));
    } else
    {
        printf("Parent Wexited: child kiled, crashed, or stopped\n");
    }
    
    
    printf("Parent here!\n");
    printf("alg0r4v3rs\n");
    printf("Parent's pid: %d\n", pid);
    
  }

  return 0;
}