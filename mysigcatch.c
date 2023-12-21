#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void sigint_handler(int signo)
{
    printf("\nSIGINT signal caught!\n");
    exit(0);
}


int main()
{
    // Register the signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        fprintf(stderr, "Error registering signal handler for SIGINT\n");
        return 1;
    }

    while (1)
    {
        printf("Program running...\n");
        sleep(1);
    }
    return 0;
}
