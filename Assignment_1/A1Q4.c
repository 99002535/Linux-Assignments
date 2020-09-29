#include <unistd.h>
#include <stdio.h>

int main(void) {
  char *programName ;
  printf("Enter your command:");
	scanf("%s",programName);
  char *arg1 = "-lh";
  char *arg2 = "/home";
 
  execlp(programName, programName, arg1, arg2, NULL);
 
  return 0;
}