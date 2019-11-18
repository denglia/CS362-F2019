#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myAssert(int r, char* msg, int i)
{
	static int failed = 0;

	if(r == 0){
		printf("FAILED", i, msg);
		failed = 1;
	}
	return 0;
}

int main(){
  int seed = 1000;
  int players = rand() % MAX_PLAYERS + 1;
  int curPlayer = 0;
  int deckSize = rand()% MAX_DECK + 1;
  int handSize = rand()% MAX_HAND + 1;
  int i, j;
  int beforeHand;
  int afterDiscard;
  int beforeDeck;
  int beforeDiscard;
  int beforeAction;
  int beforeCoins = 0;
  int numEstates = 0;
  int gainEstates = 0;
  int gainCoins = 0;
  int afterActions = 0;
  int numCoins = 0;
  int r;
  int choice1 = rand() % 2;
  int choice2 = rand() % 2;
  int k[10] = { gardens, embargo, village, minion, mine, cutpurse, adventurer, sea_hag, tribute, baron};
  srand(time(NULL));
  printf("\nTesting tribute card\n");
  struct gameState G;
  for (i = 0; i < 50; i++) {
    initializeGame(2, k, seed, &G);
    for(j = 0; j < players; j++){
    G.handCount[j] = handSize;
    G.deckCount[j] = deckSize - handSize;
      //int sumCoins = updateCoins(0,G);
    beforeHand = numHandCards(&G);
    beforeDeck = deckCount(&G);
    beforeDiscard = playedCardCount(&G);
    beforeCoins = G.handCount[curPlayer];
    afterDiscard = G.handCount[0];
    afterAction = G.numActions[0];

    gainCard(tribute, &G, 2, 0);
    r = playCard(numHandCards(&G)-1,0,0,0,&G);
    myAssert(beforeCoins < G.coins + 2，“Did not add coins”, i);
    printf("Tests complete.");
    endTurn(&G);
    }
  }
  	return 0;
}
