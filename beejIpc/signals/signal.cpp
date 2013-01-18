#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>


void sigint_handler(int sig)
{
write(0,"In sigint Hello!\n" , 17);
}


int main(void)
{
char s[200];
struct sigaction sa;
sa.sa_handler = sigint_handler;
sa.sa_flags = SA_RESTART;
sigemptyset(&sa.sa_mask);
if(sigaction(SIGINT , &sa , NULL) == -1)
{
perror("sigaction");
exit(1);
}

printf(" Enter a string " );
scanf("%s" , s);
printf(" You entered %s \n" , s);
return 0;
}
