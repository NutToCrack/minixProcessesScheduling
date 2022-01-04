#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <lib.h>
#include <time.h>


int main(int argc, char * arg[])
{
  double running_time = 0.0;
  int i,j;
  int my_pid, p_user_group;
  int procgroup_change_result;
  clock_t end;
  clock_t begin = clock();

  if(argc != 2){
    printf("Nie podano numery grupy");
    return 1;
  }

  p_user_group = atoi(arg[1]);
  my_pid = getpid();

	procgroup_change_result = setuserprocgroup(my_pid, p_user_group);
  for(i = 0; i <1; i++) {
    for(j = 0; j < 999999999; j++) {
      
    }
  }
  end = clock();
  
  running_time =(double) (end - begin)/CLOCKS_PER_SEC;
  printf("PID: %d GROUP: %d Exec time:%f\n", my_pid, p_user_group, running_time);
	return 0;
}


int setuserprocgroup(pid_t pid, int userpgr)
{
	message m;
	m.m1_i1 = pid;
	m.m1_i2 = userpgr;
	return _syscall(0, SETPROCGROUP, &m);
}
