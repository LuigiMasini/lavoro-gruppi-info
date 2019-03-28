#include <stdio.h>
#include <stdlib.h>
/*#include <unistd.h> 
#include <wait.h>


int main() { 
	pid_t pid = fork();
	if ( pid == 0 ){
		//inside child
		int ret = system("./linux_play prova2.mp3");
		
		
		exit(WEXITSTATUS(ret));
	}
	
	int status;
	waitpid(pid, &status, 0);
	
	printf("Exit status of the child was %d\n", WEXITSTATUS(status));
} 
*/

void main(){
	system("echo -e \"\\e[44m\"");
}