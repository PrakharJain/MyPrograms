#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int rv;
	switch (pid = fork())
	{
		case -1:
			perror("fork");
			exit(1);
		case 0:
			printf ("CHILD : This is the child process\n ");
			printf ("CHILD : PID is : %d \n" , getpid());
			printf ("CHILD : My parent PID is %d \n" , getppid());
			printf ("CHILD : Please enter my exit status " );
			scanf ("%d" , &rv);
			printf ("CHILD : exiting \n");
			exit(rv);
		default:
			printf ("PARENT : This is the parent process \n");
			printf ("PARENT : My pid is %d " , getpid());
			printf ("PARENT : The child PID is %d \n" , pid);
			printf ("PARENT : Waiting for the child to exit \n");
			wait(&rv);
			printf ("PARENT : My child's exit status is %d \n" , WEXITSTATUS(rv));
			printf ("PARENT : Exiting \n");
	}
	return 0;
}
