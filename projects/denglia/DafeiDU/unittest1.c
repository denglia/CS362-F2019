#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//baron test
int main(){
  int num_player = 2;
  int seed = 1000;
  int player = 0;
  int hand_pos = 0;
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int whoseTurn = 0;
  int coin_bonus = 0;
  int bonus = 0;
  struct gameState game, test;
  int k[10] = {minion, mine, silver, gold, cutpurse,sea_hag, tribute, baron, council_room, copper};
  initializeGame(num_player, k, seed, &game);
  memcpy(&test, &game, sizeof(struct gameState));
  game.handCount[game.whoseTurn] + 3;
  test.handCount[test.whoseTurn];
  cardEffect(baron, choice1, choice2, choice3, &game, hand_pos, &bonus);
  assert(test.handCount[player]-2 != game.handCount[player]);
  assert(game.discardCount[game.whoseTurn] != test.discardCount[game.whoseTurn]);
  discardCard(0, game.whoseTurn, &game, 0);
  assert(test.numBuys+1 != game.numBuys);
  return 0;
}
