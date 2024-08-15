#include<stdio.h>

void swap(char ** p, char**q){
	   char*t;
	     t=*p;
		   *p=*q;
		     *q=t;

}

int main(){
	 
	  char s1[]="Harsh";
	    char s2[]="Ayush";
		  printf("%s %s\n", s1,s2);
		    swap(&s1,&s2);
			  printf("%s %s\n", s1,s2);


}

