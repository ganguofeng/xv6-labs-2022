#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
   int p[2];
   pipe(p); //new pipe
   char readtext[10]; //text to read from pipe

   
  int pid = fork();
  if (pid == 0)
  {
    
    read(p[0], readtext, 10); //read from pipe
    printf("received read text: %s\n", readtext);
   
    write(p[1], "pong", 4); //write to pipe
    
  }
  else if (pid < 0) {
    fprintf(2, "fork failed\n");
    exit(0);
  }
  else
  {
    
    write(p[1], "ping", 4); //write to pipe
    wait(0);
   
    read(p[0], readtext, 4); //read from pipe
    printf("received write text: %s\n", readtext);
    
    exit(0);
  }
  exit(0);
}
