#include <stdio.h>
// Writing C Programs using Fork(), Getpid(), Getppid() and Exec() System Calls

#include <unistd.h>
int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());
        printf("Child PPID: %d\n", getppid());
        exit(0);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }
    return 0;
}
