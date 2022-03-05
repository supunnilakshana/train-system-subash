#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include<windows.h>
#include "appstyle.h"
#include <windows.h>

void print_progressbar(int percent)
{
  const int mul = 2; // width factor
  percent = min(100, percent);

  // spinning animation
  static int spin_index = 0;
  char spinning[] = "_-\\|/-";

  // bar filler
  int len = (percent * mul / 10) + 1;
  char *bar = malloc(len);
  memset(bar, '|', len - 1);
  bar[len - 1] = 0;

  // write display
  printf("\t\t\t\t\t%c Loading: [%*s] %*d%%\r",
         percent == 100 ? ' ' : spinning[spin_index],
         mul * 10, bar,
         3, percent
        );
  spin_index = (spin_index + 1) % strlen(spinning);

  free(bar);
}








int main()
{
  printf("\n");
  for (int i = 0; i <= 100; i += 1)
  {
    if (i%5==0)
    {
      yellow();
    }else if (i%4==0)
    {
      green();
    }else  if (i%3==0)
    {
       red();
    }else  if (i%2==0)
    {
       cyan();
    }else{
        blue();
    }
   
      
    print_progressbar(i);
    Sleep(150);
  }


  
  printf("\n\t\t\t\t\t\t\tDone...\n");
   resetcolor();
}