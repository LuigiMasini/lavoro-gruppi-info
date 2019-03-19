#include <stdio.h>
#include <windows.h>   // WinApi header

int main()
{
	freopen("out.txt", "w", stdout);
  HANDLE  hConsole;
    int k;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  // you can loop k higher to see more color choices
  for(k = 1; k < 65536; k++)
  {
    SetConsoleTextAttribute(hConsole, k);
    printf("%3d  %s\n", k, "I want to be nice today!");
  }

  getchar();  // wait
  return 0;
}
