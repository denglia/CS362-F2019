#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Bug: first if both nextplayer become currentplayer

int main (int argc, char** argv){
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };// declarethe game state
	struct gameState game1;// declarethe arrays 
	int seed = 38;
	
	printf("Unit Test 4\n");

	memset(&game1, 23, sizeof(struct gameState));   // set the game state 
	int r1 = initializeGame(2, k, seed, &game1); // initialize a new game
	game1.numPlayers = 2;
	game1.whoseTurn = 0;
	game1.numActions = 1;
	game1.numBuys = 1;
	game1.coins = 10;
	game1.hand[0][0] = tribute;
	game1.deckCount[0] = 0;
	game1.deckCount[1] = 1;
	game1.deck[1][0] = gold;
	game1.discardCount[0] = 0;
	game1.discardCount[1] = 1;
	game1.handCount[0] = 1; // set any other variables
	for(int i = 0;i<30;i++){
	if(i == 2 || i == 12 || i == 26){
		game1.supplyCount[i] = 0;
	}
	else
		game1.supplyCount[i] = 1;
	}
	
	if(isGameOver(&game1) == 1){
		printf("Testing Game Over [PASS] \n");
	}
	else{
		printf("Testing Game Over [FAIL] \n");
	}
}