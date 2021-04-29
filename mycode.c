#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sigint_handler(int sig){
 printf("You are NOT Allowed to do so!!\n");
}

int main(void) {

  void sigint_handler(int sig);

  if(signal(SIGINT, sigint_handler) == SIG_ERR){
   perror("signal");
   exit(1);
  }

  int pipenum[2];
  pipe(pipenum);
  pid_t pid = fork();
  int num, n , i, flag=0;

 if (pid==0){

  printf("Enter any number: ");
  scanf("%d", &num);

  write(pipenum[1], &num , sizeof(num));
 }
 else if (pid>0){
  read(pipenum[0], &n , sizeof(n));

  for (i = 2; i <= n / 2; ++i) {
    // condition for non-prime
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

   if (n == 1) {
     printf("1 is neither prime nor composite.");
   }
   else {
     if (flag == 0)
       printf("%d is a prime number.\n", n);
     else
       printf("%d is not a prime number.\n", n);
  }
 }

return 0;
}
