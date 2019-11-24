#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//minion test
int main(){
  int num_player = 2;
  int seed = 1000;
  int player = 0;
  int hand_pos = 0;
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int bonus = 0;
  struct gameState game, test;
  int k[10] = {minion, mine, silver, gold, cutpurse,sea_hag, tribute, baron, council_room, copper};
  initializeGame(num_player, k, seed, &game);
  memcpy(&test, &game, sizeof(struct gameState));
  assert(test.playedCardCount+5 != test.playedCardCount);
  assert(game.discardCount[game.whoseTurn] != test.discardCount[game.whoseTurn]);
  if(test.numActions+1 == game.numActions){
  printf("Action was added\n");
  }
  return 0;
}
