#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum Month {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
enum Bool {FALSE = 0, TRUE = 1};
enum DayOfWeek {MON=1, TUE, WED, THU, FRI, SAT, SUN};

/* I know: 21st Sep 2015 --> Monday */

enum Bool isLeapYear (int year) {
	if ( (year %4 != 0))
		return FALSE;
	if ( (year % 100 == 0) && (year %400 == 0))
		return TRUE;
	if (year % 100 == 0)
		return FALSE;
	return TRUE;

}
int getNumDaysinYear(int year){
	if (isLeapYear(year))
		return 366;
	return 365;
}
int getNumDaysinMonth(int month, enum Bool isly){
	if ( (month == FEB) && isly)
		return 29;
	switch(month){
		case JAN:
			return 31;
		case FEB:
			return 28;
		case MAR:
			return 31;
		case APR:
			return 30;
		case MAY:
			return 31;
		case JUN:
			return 30;
		case JUL:
			return 31;
		case AUG:
			return 31;
		case SEP:
			return 30;
		case OCT:
			return 31;
		case NOV:
			return 30;
		case DEC:
			return 31;
				
	}
	printf ("Should never reach this point \n");
	exit(1);
}

int numDaysFromJan1(int day, int month, int year){
	enum Bool isly = isLeapYear (year);
	int curMonth;
	int totDays = 0;
	/* get number of days in preceding months */
	for(curMonth = 1; curMonth <= (month-1); curMonth++){
		totDays += getNumDaysinMonth(curMonth,isly); 
	}

	/* get total days */
	totDays += day;

	/* return */
	return (totDays - 1);
}

enum DayOfWeek getDayOfTheWeek(int numDays){
	int rem = numDays % 7;
	switch (rem) {
		case 0:
			return MON;
		case 1:
			return SUN;
		case 2:
			return SAT;
		case 3:
			return FRI;
		case 4:
			return THU;
		case 5:
			return WED;
		case 6:
			return TUE;
	}
}

void printDayofWeek(enum DayOfWeek dd){
	switch(dd){
		case MON:
			printf ("Monday \n");
			break;
		case TUE:
			printf ("Tuesday \n");
			break;
		case WED:
			printf ("Wednesday \n");
			break;
		case THU:
			printf ("Thursday \n");
			break;
		case FRI:
			printf ("Friday \n");
			break;
		case SAT:
			printf ("Saturday \n");
			break;
		case SUN:
			printf ("Sunday \n");
			break;

	}
}

int getNumDays(int day, int month, int year){
	int totDays = 0;
	int ytemp;
	int remainingDays, offset;
	int numDaysInYear;

	/* add the days for the years */
	for(ytemp = year+1; ytemp < 2015; ytemp++)
		totDays += getNumDaysinYear(ytemp);

	/* get remaining number of days in the birthday year */
	if(year == 2015)
		numDaysInYear = 0;
	else
		numDaysInYear =  getNumDaysinYear(year);
	remainingDays =  numDaysInYear - numDaysFromJan1(day,month,year);

	/* compute offset of 21 sep 2015 */
	offset = numDaysFromJan1 (21, 9, 2015);

	return (totDays + remainingDays + offset);
}

int main (int argc, char* argv[]){
	int i;
	int day, month, year;
	int numdays;
	enum DayOfWeek dd;

	/* test if we have 3 arguments after a.exe */
	if (argc != 4) {
		printf ("Illegal input \n");
		return;
	}
	/* parse the arguments */
	day = atoi(argv[1]);
	month = atoi(argv[2]);
	year = atoi (argv[3]);

	/* between two (d,m,y) pairs, find the number of days */
	numdays = getNumDays(day,month,year); /* computed from 21 sep 2015 */
	dd = getDayOfTheWeek(numdays);
	printDayofWeek(dd);
}

