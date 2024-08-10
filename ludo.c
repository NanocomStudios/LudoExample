#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "datatypes.c"

struct piece Piece[16];	

void reset(){
	for(int i = 0; i < 16; i++){

		Piece[i].map = 0;
		Piece[i].loc = BASE;

	}
}

void printPlayer(int player){

	if(player == 0){printf("Green");}
	else if(player == 1){printf("Yellow");}
        else if(player == 2){printf("Blue");}
        else if(player == 3){printf("Red");}

}

int main(){
	srand(time(0));
	reset(Piece);
	int max1 = 0;
	int max2 = 0;
	int maxplayer;
	
	while(1){
		for(int i = 0; i < 4; i++){
			int num = (rand() % 6) + 1;
			if(max1 < num){
				max1 = num;
				maxplayer = i;
			}else if(max1 == num){
				max2 = num;
			}
			printPlayer(i);
			printf(" rolled %d\n",num);
	
		}
		if(max2 < max1){
			break;	
		}
		max1 = 0;
		max2 = 0;
	}
	printPlayer(maxplayer);
	printf(" player has the highest roll and will begin the game.\n");
	printf("The order of a single round is ");
	printPlayer(maxplayer);

	int maxplayertmp = maxplayer;
	for(int i = 0; i < 3; i++){
		
		maxplayer ++;
		if(maxplayer > 3){
			maxplayer =0;
		}
		if(i == 2){
        		printf(" and ");
		}else{
        		printf(", ");
		}
		printPlayer(maxplayer);

	}
	printf(".\n");
	int roundCount = 0;
	while(1){

		int currentPlayer;		
		//gamelogic();

		currentPlayer ++;
		if(currentPlayer > 3){
			currentPlayer = 0;
		}
		roundCount ++;

	}	

	return 0;
}
