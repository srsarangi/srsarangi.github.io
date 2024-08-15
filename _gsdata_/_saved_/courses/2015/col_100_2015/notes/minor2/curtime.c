#include <stdio.h>

typedef struct {
	int hours;
	int mins;
	int seconds;
} TIME;

TIME addTime (TIME curTime, TIME jobTime){
	TIME ftime = {0,0,0};
	ftime.seconds = curTime.seconds + jobTime.seconds;
	if (ftime.seconds >= 60) {
		ftime.seconds -= 60;
		ftime.mins = 1;
	}

	ftime.mins += curTime.mins + jobTime.mins;
	if (ftime.mins >= 60) {
		ftime.mins -= 60;
		ftime.hours = 1;
	}

	ftime.hours += curTime.hours + jobTime.hours;
	if (ftime.hours >= 24) {
		printf ("Exceeded range \n");
	}
	return ftime;
}

int main(){
	TIME curTime = {3, 24, 42};
	TIME jobTime = {2, 20, 20};

	TIME ftime = addTime (curTime, jobTime);
	printf ("hours = %d, mins = %d, seconds = %d \n", ftime.hours, ftime.mins, ftime.seconds);
}
