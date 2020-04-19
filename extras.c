#include <stdio.h>
#include "extras.h"

// Function: explanation()
// Input: none
// Output: none
// gives information about what kind of data is in data structure
void explanation(){
  printf("Which information do you want to know?\n");
  printf(" 1. Player ID\n");
  printf(" 2. Player Name\n");
  printf(" 3. Player Team\n");
  printf(" 4. Player wRC\n");
  int input;
  scanf("%d",&input);
  if (input==1){
    printf("It is a ficional number to sort player.\n");
  }
  else if (input==2){
    printf("It is player's name recorded in official site.\n");
  }
  else if (input==3){
    printf("It is player's team recorded in official site.\n");
  }
  else if (input==4){
    printf("It is a statistical data of how much runs a player made.\n");
  }
  else{
    printf("Wrong input");
  }
}


// TODO: Add more functions to fulfill the optional requirements
