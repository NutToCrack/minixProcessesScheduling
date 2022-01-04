
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <lib.h>

int main(int argc, char * arg[])
{

  int p_user_group;
  int new_tick_rate;
  int old_tick_rate;
  int change_result;


  if(argc != 3){
    printf("Numer grupy i tick_rate są wymagane");
    return 1;
  }

  p_user_group = atoi(arg[1]);
  new_tick_rate = atoi(arg[2]);

	change_result = setuserpgrptr(p_user_group, new_tick_rate);
	return 0;
}

int setuserpgrptr(int userpgr, int new_tick_rate)
{
	message m;
	m.m1_i1 = userpgr;
	m.m1_i2 = new_tick_rate;
	return _syscall(MM, SETPROCRATE, &m);
}


