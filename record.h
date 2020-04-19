#ifndef _RECORD_H_
#define _RECORD_H_

// type defition
typedef struct{
	int id;
  char name[1024];
  char team[1024];
  int wRC;
} Record;
// control variable of how many inputs were there
//int count=0;

#endif
