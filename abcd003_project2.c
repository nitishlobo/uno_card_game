#include "proj2.h"

// Naive strategy - play the first valid card that is noticed in my hand of cards.
int abcd004_Play(GameState *gameInfo)
{
	int lastCardType, lastCardColour, lastCardValue, lastCardsPilePosition, i; 
	
	//lastCardPilePosition variable stores the index value of the last card's position 
	//on the discard pile.
	lastCardsPilePosition = (gameInfo->numberOfDiscards) -1; 
	lastCardType = gameInfo->discardPile[lastCardsPilePosition].type;
	lastCardColour = gameInfo->discardPile[lastCardsPilePosition].colour;
	lastCardValue = gameInfo->discardPile[lastCardsPilePosition].value;
	
	//If the card on top of discard pile is a wild, then finding the last colour called.
	if ((lastCardType == WILD) || (lastCardType == WILD_D4)) {
		lastCardColour = gameInfo->lastColourCalled;
	}

	for (i=0; i<(gameInfo->yourNumberOfCards); i++) {

		if ((gameInfo->yourCards[i].type) == WILD) {
		return i+ 10000;
		}

		if ((gameInfo->yourCards[i].type) == WILD_D4) {
		return i+10000;
		}
	
		if ((gameInfo->yourCards[i].colour)==lastCardColour) {
			return i;
		}
		if (((gameInfo->yourCards[i].type)==lastCardType) && (lastCardType != NUMBER)) {
			return i;
		}
		if ((gameInfo->yourCards[i].type)==NUMBER) {
			if ((gameInfo->yourCards[i].value)==lastCardValue) {
				return i;
			}
		}
	}
	
	//Else return -1
	return -1;
}
