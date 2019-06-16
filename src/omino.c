#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if defined LINUX || defined OSX
	#include <wait.h>
	#include <sys/types.h>
	#include <unistd.h>
#elif WIN
	#include <windows.h>
#endif

#define music

void omino(){
#if defined LINUX || defined OSX
	char *cls = "clear";
#elif WIN
	char *cls = "cls";
#endif


	char *omi[] = {

		//1, 0

		"      _\n"
		" #  _(_)_\n"
		" \\_/| Y /|\n"
		"     \\!/ |\n"
		"     /V\\/\n"
		"     |/^\\\n"
		"    /    \\\n"
		"  _/      \\_\n" ,

		//1, 1

		"      _\n"
		"     (_)\n"
		"#__/T Y T\\\n"
		"     \\!/ |\n"
		"     /V\\/\n"
		"    |/^\\|\n"
		"   /     \\\n"
		" _/       \\_\n",

		//1, 2

		"      _\n"
		"     (_)\n"
		"   /T Y T\\\n"
		"  /  \\!/ |\n"
		" #   /V\\/\n"
		"    |/^\\|\n"
		"   /     \\\n"
		" _/       \\_\n",

		//1, 3

		"      _\n"
		"     (_)\n"
		"   /T Y T\\\n"
		"   | \\!/ |\n"
		"    \\/V\\/\n"
		"     |^|\n"
		"    /   \\\n"
		"  _/     \\_\n",

		//1, 4

		"      _\n"
		"    _(_)_\n"
		"   || Y ||\n"
		"    \\_X_/\n"
		"     /U\\\n"
		"     |^|\n"
		"    /   \\\n"
		"  _/     \\_\n",

		//1, 5

		"      _\n"
		"     (_)\n"
		"   /T Y T\\\n"
		"   | \\!/ |\n"
		"    \\/V\\/\n"
		"     |^|\n"
		"    /   \\\n"
		"  _/     \\_\n",

		//1, 6

		"      _\n"
		"     (_)\n"
		"   /T Y T\\\n"
		"  /  \\!/  \\\n"
		" #   /V\\   #\n"
		"     |^|\n"
		"    /   \\\n"
		"  _/     \\_\n",

		//1, 7

		"      _\n"
		"    _(_)\n"
		"   /| Y T\\__#\n"
		"   | \\!/\n"
		"   # /V\\\n"
		"     |^\\|\n"
		"    /    \\\n"
		"  _/      \\_\n",

		//2, 8

		"      _\n"
		"    _(_)_   #\n"
		"   |\\ Y |\\_/\n"
		"   | \\!/\n"
		"    \\/V\\\n"
		"    / ^\\|\n"
		"   /     \\\n"
		" _/       \\_\n",

		//2, 9

		"      _\n"
		"     (_)\n"
		"   /T Y T\\__#\n"
		"   | \\!/\n"
		"    \\/V\\\n"
		"    |/^\\|\n"
		"   /     \\\n"
		" _/       \\_\n",

		//2, 10

		"      _\n"
		"     (_)\n"
		"   /T Y T\\\n"
		"   | \\!/  \\\n"
		"    \\/V\\   #\n"
		"    |/^\\|\n"
		"   /     \\\n"
		" _/       \\_\n",

		//2, 11

		"      _\n"
		"     (_)\n"
		"   /T Y T\\\n"
		"   | \\!/ |\n"
		"    \\/V\\/\n"
		"     |^|\n"
		"    /   \\\n"
		"  _/     \\_\n",

		//2, 12

		"      _\n"
		"    _(_)_\n"
		"   || Y ||\n"
		"    \\_X_/\n"
		"     /U\\\n"
		"     |^|\n"
		"    /   \\\n"
		"  _/     \\_\n",

		//2, 13

		"      _\n"
		"     (_)\n"
		"   /T Y T\\\n"
		"   | \\!/ |\n"
		"    \\/V\\/\n"
		"     |^|\n"
		"    /   \\\n"
		"  _/     \\_\n",

		//2, 14

		"      _\n"
		"     (_)\n"
		"   /T Y T\\\n"
		"  /  \\!/  \\\n"
		" #   /V\\   #\n"
		"     |^|\n"
		"    /   \\\n"
		"  _/     \\_\n",

		//2, 15

		"      _\n"
		"    _(_)\n"
		"#__/| Y T\\\n"
		"     \\!/ |\n"
		"     /V\\ #\n"
		"     |/^|\n"
		"    /    \\\n"
		"  _/      \\_\n"

	};

	//u can't touch this, MC Hammer,		134 bpm
	//live in the moment, portugal + the man,	128 bpm

	int bpm = 134;			//beat per minute
	double d = 7.262041;		//duration in seconds
	int fpb = 2;			//frame per beat

	int fpm = fpb*bpm;
	double step_s = 60;
	step_s/=fpm;
	double step_ms = step_s*1e6;	//step in microseconds
	double cont = d;
	cont/=step_s;

	#ifdef debug
	printf("bpm\t\t%d\nduration\t%f\nfpb\t\t%d\nfpm\t\t%d\nstep s\t\t%f\nstep ms\t\t%f\nframe tot\t%f\n\n", bpm, d, fpb, fpm, step_s, step_ms, cont);	//debug
	#endif

	#if defined music && ( defined LINUX || defined OSX )
	pid_t pid = fork();
	if ( pid == 0 ){
		#if defined OSX
		int ret = system("afplay cant_touch_this.wav");
		#elif LINUX
		int ret = system("./linux_play cant_touch_this.wav");
		#endif
		exit(WEXITSTATUS(ret));
	}
	else {
	#endif

		#ifdef debug
		fflush(stdout);
		printf("%d", (int)cont);
		#endif
		#ifdef WIN
		PlaySound("cant_touch_this.wav", NULL, SND_ASYNC);
		#endif
		sleep(step_s/2);
		int i=0;
		while((int)cont--){
			system(cls);
			#ifdef debug
			printf("%d %d\n", i, (int)cont);
			#endif
			printf("%s", omi[i]);
			//fflush( stdout );

			#if defined LINUX || defined OSX
			usleep((int)step_ms);	//in microseconds
			#elif WIN
			Sleep((int)step_s);	//in seconds
			#endif

			i==15 ? i=0: i++ ;
		}


	#if defined music && defined LINUX || OSX
		int status;
		waitpid(pid, &status, 0);
		#ifdef debug
		printf("Exit status of the child was %d\n", WEXITSTATUS(status));
		#endif
	}
	#endif

}

/*TODO:
 molto inefficente con array tridimensionali, meglio prendere sigoli frame da un file dedicato
-aggiungere musica e adattare tempo
-aggiungere colori
 aggiungere compilazione sbs step by step per controllo fotogrammi uno ad uno
 */
