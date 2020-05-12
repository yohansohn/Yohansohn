#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "record.h"

int count=0;
// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// prints all the data in structure Record
void print_all_records(Record records[]){
	// print all data in structure Records
	for (int i=1;i<=count;i++){
    printf("=====================\n");
    printf("NAME: %s\t| ID: %d\n",records[i].name,records[i].id);
    printf("TEAM: %s\n",records[i].team);
  }
  printf("=====================\n");
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// add a record about baseball player
void add_a_record(Record records[]){
	// add record of player's id, name, team, and wRC
  char temp[1024];
	printf("Player ID : ");
  scanf("%d",&records[count+1].id);
  fgets(temp,1024,stdin);
  printf("Player Name : ");
  fgets(temp,1024,stdin);
  temp[strlen(temp)-1]='\0';
  strcpy(records[count+1].name,temp);
  printf("Player's Team : ");
  fgets(temp,1024,stdin);
  temp[strlen(temp)-1]='\0';
  strcpy(records[count+1].team,temp);
  printf("Player's wRC : ");
  scanf("%d",&records[count+1].wRC);
  fgets(temp,1024,stdin);
  count++;
}

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// prints wRC average of all players in data
void defragment(Record records[]){
	// TODO: Modify this function as you need
	int sum=0;
  for (int i=1;i<=count;i++){
    sum+=records[i].wRC;
  }
  float avg=(float)sum/count;
  printf("Current All Player's wRC average : %.2f\n",avg);
}

// Function: delete_r()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// prints wRC+= average of all players in data
void delete_r(Record records[]){
  int id;
  printf("Enter Player ID to Delete : ");
  scanf("%d",&id);
  int control=0;
  for (control=1;control<=count;control++){
    if (records[control].id==id) break;
  }
  if (control>count){
    printf("No Such ID\n");
  }
  else{
    for (int i=control;i<=count;i++){
      records[i].id=records[i+1].id;
      strcpy(records[i].name,records[i+1].name);
      strcpy(records[i].team,records[i+1].team);
      records[i].wRC=records[i+1].wRC;
    }
    count--;
  }
}

// Function: sort_data()
// Input: record - array of Records, count - length of array
// Output: none
// sort data by player id
void sort_data(Record records[]){
  for (int i=1;i<=count;i++){
    for (int j=1;j<=count-1-i;j++){
      if (records[j].id>records[j+1].id){
        int tempid=records[j].id;
        records[j].id=records[j+1].id;
        records[j+1].id=tempid;
        char tempname[1024];
        strcpy(tempname,records[j].name);
        strcpy(records[j].name,records[j+1].name);
        strcpy(records[j+1].name,tempname);
        char tempteam[1024];
        strcpy(tempteam,records[j].team);
        strcpy(records[j].team,records[j+1].team);
        strcpy(records[j+1].team,tempteam);
        int tempwRC=records[j].wRC;
        records[j].wRC=records[j+1].wRC;
        records[j+1].wRC=tempwRC;
      }
    }
  }
  printf("Data Sorted\n");
}


// Function: adv_search()
// Input: record
// Output: none
/*
1. Advanced search: 
	After receiving the team name and wRC value from the user, 
	search for players who have a wRC value greater than the wRC value entered
*/
void adv_search(Record records[]) {
	char team[1024];
	int wRC, c = 0;
	char temp[1024];

	printf("Enter the team name: ");
	fgets(team, 1024, stdin);
	team[strlen(team) - 1] = '\0';

	printf("Enter minimum wRC value: ");
	scanf("%d", &wRC);
	fgets(temp, 1024, stdin);
	
	for (int i = 1; i <= count; i++) {
		if (!strcmp(team, records[i].team) && wRC <= records[i].wRC) {
			printf("=====================\n");
			printf("NAME: %s\t| ID: %d\n", records[i].name, records[i].id);
			printf("TEAM: %s\t| wRC: %d\n", records[i].team, records[i].wRC);
			c++;
		}
	}
	printf("=====================\n");

	if (c == 0) {
		printf("No data matches the conditions\n");
	}
}
