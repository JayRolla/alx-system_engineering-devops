#include <stdio.h>
#include <unistd.h>

/**
 * infinite_while - Infinite loop to keep the parent process alive
 * Return: 0
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - Creates 5 zombie processes
 * Return: 0
 */
int main(void)
{
    pid_t pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
            return (0);
        else if (pid > 0)
            printf("Zombie process created, PID: %d\n", pid);
        else
            return (1);
    }

    infinite_while();
    return (0);
}
