#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int seed = 1000;
  int players = rand() % MAX_PLAYERS + 1;
  int curPlayer = 0;
  int v;
  int deckSize = rand()% MAX_DECK + 1;
  int handSize = rand()% MAX_HAND + 1;
  int i, j;
  int beforeHand;
  int beforeDeck;
  int beforeDiscard;
  int numEstates = 0;
  int gainEstates = 0;
  int gainCoins = 0;
  int numCoins = 0;
  int r;
  int k[10] = { gardens, embargo, village, minion, mine, cutpurse, adventurer, sea_hag, tribute, baron};
  srand(time(NULL));

	struct gameState G;
	//loop runs
	for (i = 0; i < 50; i++) {
	   initializeGame(2, k, seed, &G);
		//loop players
	   for(j = 0; j < players; j++){
       G.handCount[j] = handSize;
		 G.deckCount[j] = deckSize - handSize;
       //int sumCoins = updateCoins(0,G);
		 beforeHand = numHandCards(&G);
       beforeDeck = deckCount(&G);
       beforeDiscard = playedCardCount(&G);
       gainCard(baron, &G, 2, 0);
       r = playCard(numHandCards(&G)-1,0,0,0,&G);
			 for (i = 0; i < G.handCount[j]; i++){
          if(handCard(i, &G) == estate);
            gainEstates++;
      }
       myassert(numEstates - gainEstates != 1);
       myassert(gainCoins != numCoins + 4);
       printf("Tests complete.");
       

			endTurn(&G);

		}
	}

	return 0;
}
