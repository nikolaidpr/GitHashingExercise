#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int sigint_count = 0;


void custom_sigint_handler(int signo)
{
    printf("\nSIGINT signal caught with a signal number of %d\n", signo);
    sigint_count++;

    if (sigint_count == 2)
    {
        printf("Restoring default behavior for SIGINT\n");
        // Restore the default behavior for SIGINT
        signal(SIGINT, SIG_DFL);
    }
}

int main()
{
    // Register the custom signal handler for SIGINT
    if (signal(SIGINT, custom_sigint_handler) == SIG_ERR)
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
