#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

#define debug


int main() { 
	int bpm = 128;			//beat per minute
	double d = 246.83102;		//duration in seconds
	int fpb = 1;			//frame per beat
	
	int fpm = fpb*bpm;
	double step_s = 60;
	step_s/=fpm;
	double step_ms = step_s*1e6;	//step in microseconds
	double cont = d;
	cont/=step_s;
	
#ifdef debug
	printf("bpm\t\t%d\nduration\t%f\nfpb\t\t%d\nfpm\t\t%d\nstep s\t\t%f\nstep ms\t\t%f\nframe tot\t%f", bpm, d, fpb, fpm, step_s, step_ms, cont);	//debug
	fflush(stdout);
#endif
	
	pid_t pid = fork();
	if ( pid == 0 ){
		int ret = system("./linux_play prova2.mp3");
		exit(WEXITSTATUS(ret));
	}
	else {
		usleep(step_ms/2);
		/*while (cont-- >=-5) { 
			putchar( '|' );
			fflush( stdout );
			usleep(step_ms);
		}*/
	int status;
	waitpid(pid, &status, 0);
#ifdef debug
	printf("Exit status of the child was %d\n", WEXITSTATUS(status));
#endif
	}
}

