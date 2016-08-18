#include "proj2.h"
void peer001_CreateDeck(Deck *deck)
{
	/* Declaring loop variable, i.*/
	int i;
	//Initialising the number of cards in the deck as zero.
	deck->numCards = 0;

	//For loop runs until all the cards on the deck have been laid.
	for (i = 0; i <108; i++) {

		/* If statements to change the numeric value for type of card. */
		if ( ((i <19) && (i> -1)) || ((i<44) && (i>24)) || ((i<69) && (i>49)) || ((i<94) && (i>74))){
			//Type will be a number type card
			deck->cards[i].type = 0;
		} else if ((i==19)|| (i==20)|| (i==44)|| (i==45)|| (i==69)|| (i==70)|| (i==94)|| (i==95)) {
			//Card will be of skip type.
			deck->cards[i].type = 1;
		} else if ((i==21)|| (i==22)|| (i==46)|| (i==47)|| (i==71)|| (i==72)|| (i==96)|| (i==97)) {
			//Card will be of reverse type.
			deck->cards[i].type = 2;
		} else if ((i==23)|| (i==24)|| (i==48)|| (i==49)|| (i==73)|| (i==74)|| (i==98)|| (i==99)) {
			//Card will be of draw two type.
			deck->cards[i].type = 3;
		} else if ((i<104) && (i>99)) {
			//Card will be of wild type.
			deck->cards[i].type = 4;
		} else {
			//Card will be of wild draw four type. This will be the last 4 cards.
			deck->cards[i].type = 5;
		}


		/* If statements to change the suit colour.
		The given values are the ranges within the array where the respective colour will occur. */
		if ((i <25) && (i> -1)) {
			//Red suit
			deck->cards[i].colour = 10000;
		} else if ((i <50) && (i> 24)) {
			//Green suit
			deck->cards[i].colour = 20000;
		} else if ((i <75) && (i> 49)) {
			//Blue suit
			deck->cards[i].colour = 30000;
		} else if ((i <100) && (i> 74)) {
			//Yellow suit
			deck->cards[i].colour = 40000;
		} else {
			//For wild cards or wild draw four cards
			deck->cards[i].colour = 50000;
		}


		/* If statements to change the numeric value for value field of card struct.
		These numeric values also indicate the number of points. */
		if ((i<76) && ((i%25) == 0)) {
			//Setting points to 0. Positions that have value of 0 are 0, 25, 50 and 75.
			deck->cards[i].value = 0;
		} else if ((i==1)|| (i==2)|| (i==26)|| (i==27)|| (i==51)|| (i==52)|| (i==76)|| (i==77)){
			//Setting points to 1 for the above i positions.
			deck->cards[i].value = 1;
		} else if ((i==3)|| (i==4)|| (i==28)|| (i==29)|| (i==53)|| (i==54)|| (i==78)|| (i==79)){
			//Setting points to 2 for the above i positions.
			deck->cards[i].value = 2;
		} else if ((i==5)|| (i==6)|| (i==30)|| (i==31)|| (i==55)|| (i==56)|| (i==80)|| (i==81)){
			//Setting points to 3 for the above i positions.
			deck->cards[i].value = 3;
		} else if ((i==7)|| (i==8)|| (i==32)|| (i==33)|| (i==57)|| (i==58)|| (i==82)|| (i==83)){
			//Setting points to 4 for the above i positions.
			deck->cards[i].value = 4;
		} else if ((i==9)|| (i==10)|| (i==34)|| (i==35)|| (i==59)|| (i==60)|| (i==84)|| (i==85)){
			//Setting points to 5 for the above i positions.
			deck->cards[i].value = 5;
		} else if ((i==11)|| (i==12)|| (i==36)|| (i==37)|| (i==61)|| (i==62)|| (i==86)|| (i==87)){
			//Setting points to 6 for the above i positions.
			deck->cards[i].value = 6;
		} else if ((i==13)|| (i==14)|| (i==38)|| (i==39)|| (i==63)|| (i==64)|| (i==88)|| (i==89)){
			//Setting points to 7 for the above i positions.
			deck->cards[i].value = 7;
		} else if ((i==15)|| (i==16)|| (i==40)|| (i==41)|| (i==65)|| (i==66)|| (i==90)|| (i==91)){
			//Setting points to 8 for the above i positions.
			deck->cards[i].value = 8;
		} else if ((i==17)|| (i==18)|| (i==42)|| (i==43)|| (i==67)|| (i==68)|| (i==92)|| (i==93)){
			//Setting points to 9 for the above i positions.
			deck->cards[i].value = 9;
		} else if ((i<108) && (i>99)) {
			//Wild card and wild draw four cards are 50 points.
			deck->cards[i].value = 50;
		} else {
			//Special cards are worth 20 points.
			deck->cards[i].value = 20;
		}

		//Incrementing the no. of cards by 1. Moving on to next card.
		(deck->numCards)++;
	}
}

void peer001_ShuffleDeck(Deck *deck, int numberOfCards)
{
	/* Declaring Variables */
	int pickCard, i, numOfCardsInLocalDeck;
	Deck localDeck; //variable localDeck is a local deck that is a replica of the
	//main deck which was passed as an input.

	//Replicating the deck.
	localDeck = *deck;
	numOfCardsInLocalDeck = numberOfCards; //need to replicate no. of
	//cards because it is different to the one used in the 'for-loop' statement.

	for (i=0; i<numberOfCards; i++) {

		//pickCard picks an element that contains a card's data from the local deck.
		pickCard = (rand() % numOfCardsInLocalDeck);

		//The card picked is moved onto the original deck from the local deck.
		deck->cards[i].type = localDeck.cards[pickCard].type;
		deck->cards[i].colour = localDeck.cards[pickCard].colour;
		deck->cards[i].value = localDeck.cards[pickCard].value;

		//Moving the card in the last position in the lcoal deck onto the pickCard position.
		localDeck.cards[pickCard].type = localDeck.cards[numOfCardsInLocalDeck-1].type;
		localDeck.cards[pickCard].colour = localDeck.cards[numOfCardsInLocalDeck-1].colour;
		localDeck.cards[pickCard].value = localDeck.cards[numOfCardsInLocalDeck-1].value;

		//Decreasing the number of the cards in the duplicate deck by 1.
		numOfCardsInLocalDeck--;
	}
}

int peer001_ValidSelection(GameState *gameInfo, int selection)
{
	//The 'last' preffixed variables store data about the last card played.
	int lastCardType, lastCardColour, lastCardValue, lastCardsPilePosition;
	int i, wildCardPosition;

	//lastCardPilePosition variable stores the index value of the last card's position
	//on the discard pile.
	lastCardsPilePosition = (gameInfo->numberOfDiscards) -1;
	lastCardType = gameInfo->discardPile[lastCardsPilePosition].type;
	lastCardColour = gameInfo->discardPile[lastCardsPilePosition].colour;
	lastCardValue = gameInfo->discardPile[lastCardsPilePosition].value;

	//Considering case where selection is -1 and also considering case where
	//the selection is in between 0 and yourNumberOfCards-1.
	for (i=0; i<(gameInfo->yourNumberOfCards); i++) {
		if ((gameInfo->yourCards[i].colour)==lastCardColour) {
			//If the colours of the cards (played card and top of discard pile card) match, then
			//play can be valid.
			if (selection==-1) {
				//But if player chose not play the card, then it was an invalid selection.
				return 0;
			} else if (i==selection) {
				//If the i value matches the selection and the above criteria was met,
				//then play is valid.
				return 1;
			} //Do nothing if the 2nd if statements were not met.
		}
		if (((gameInfo->yourCards[i].type)==lastCardType) && (lastCardType != NUMBER)) {
			//Comparing card types.
			if (selection==-1) {
				//But if player chose not play the card, then it was an invalid selection.
				return 0;
			} else if (i==selection) {
				//If the i value matches the selection and the above criteria was met,
				//then play is valid.
				return 1;
			}
		}
		if ((gameInfo->yourCards[i].type)==NUMBER) {
			//If the card is a number type and the card values match, then play can be valid.
			if ((gameInfo->yourCards[i].value)==lastCardValue) {
				if (selection==-1) {
				//But if player chose not play the card, then it was an invalid selection.
				return 0;
				} else if (i==selection) {
				//If the i value matches the selection and the above criteria was met,
				//then play is valid.
				return 1;
				}
			}
		}

		//Considering the case where the selection was -1 but there was a wild card.
		if (selection == -1){
			if (((gameInfo->yourCards[i].type)== WILD) || ((gameInfo->yourCards[i].type)== WILD_D4)) {
				return 0;
			}
		}
	}

	if (selection == -1) {
		return 1; //if the no valid card was found in the
		//above for loop. Then the selection was correct.
	}

	//Considering case where selection is greater than yourNumberOfCards.
	if ((selection>9999) && (selection<20000)) {
		//If wild card was played and the colour called was red.
		wildCardPosition = selection - 10000; //This gives the position of the wild card
		//Checking if valid position is selected.
		if ((wildCardPosition < 0) || (wildCardPosition > ((gameInfo->yourNumberOfCards)-1))) {
			return 0;
		}
		if (((gameInfo->yourCards[wildCardPosition].type) == 4) || ((gameInfo->yourCards[wildCardPosition].type) == 5)) {
			//if the card was a wild card or a wild draw four card then confirm the call.
			return 1;
		}
	} else if ((selection>19999) && (selection<30000)) {
		//If wild card was played and the colour called was green.
		wildCardPosition = selection - 20000;
		//Checking if valid position is selected.
		if ((wildCardPosition < 0) || (wildCardPosition > ((gameInfo->yourNumberOfCards)-1))) {
			return 0;
		}
		if (((gameInfo->yourCards[wildCardPosition].type) == 4) || ((gameInfo->yourCards[wildCardPosition].type) == 5)) {
			return 1;
		}
	} else if ((selection>29999) && (selection<40000)) {
		//If wild card was played and the colour called was blue.
		wildCardPosition = selection - 30000;
		//Checking if valid position is selected.
		if ((wildCardPosition < 0) || (wildCardPosition > ((gameInfo->yourNumberOfCards)-1))) {
			return 0;
		}
		if (((gameInfo->yourCards[wildCardPosition].type) == 4) || ((gameInfo->yourCards[wildCardPosition].type) == 5)) {
			return 1;
		}
	} else if ((selection>39999) && (selection<50000)) {
		//If wild card was played and the colour called was yellow.
		wildCardPosition = selection - 40000;
		//Checking if valid position is selected.
		if ((wildCardPosition < 0) || (wildCardPosition > ((gameInfo->yourNumberOfCards)-1))) {
			return 0;
		}
		if (((gameInfo->yourCards[wildCardPosition].type) == 4) || ((gameInfo->yourCards[wildCardPosition].type) == 5)) {
			return 1;
		}
	}

	//For all other instances the selection in invalid.
	return 0;
}

int peer001_Play(GameState *gameInfo)
{
	//The 'last' preffixed variables store data about the last card played.
	int lastCardType, lastCardColour, lastCardValue, lastCardsPilePosition, playerLeftPos, playerRightPos;
	int i, wild_D4CardPos, wildCardPos, skipCardPos, reverseCardPos, draw2CardPos, highestNumCardPos, sameValueCardPos;
	int countRed, countGreen, countBlue, countYellow, numCardsOfColour, posNumCardsOfColour, wildCallValue;
	int countArray[4];

	//Count preffixed variables count the number of each colour of card.
	countRed = 0;
	countGreen = 0;
	countBlue = 0;
	countYellow = 0;

	//These variables return the number of cards of a colour with highest number of cards and
	//it's position in the countArray.
	numCardsOfColour = 0;
	posNumCardsOfColour = 0;

	//By default setting that none of the below type cards are present in the hand.
	wild_D4CardPos = -1;
	wildCardPos = -1;
	skipCardPos = -1;
	reverseCardPos = -1;
	draw2CardPos = -1;
	highestNumCardPos = -1;
	sameValueCardPos = -1;

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

		//Counting the number of cards of each colour.
		if ((gameInfo->yourCards[i].colour)==RED) {
			countRed++;
		} else if ((gameInfo->yourCards[i].colour)==GREEN) {
			countGreen++;
		} else if ((gameInfo->yourCards[i].colour)==BLUE) {
			countBlue++;
		} else if ((gameInfo->yourCards[i].colour)==YELLOW) {
			countYellow++;
		}

		//Checking what type of cards I have, whether they match the card on top of discard pile and
		//then storing the index position where the last type of that card occurs in my hand of cards.
		if ((gameInfo->yourCards[i].type)==WILD_D4) {
			wild_D4CardPos = i; //Index position of the wild_D4 card
		} else if ((gameInfo->yourCards[i].type)==WILD) {
			wildCardPos = i; //Index position of the wild card
		} else if (((gameInfo->yourCards[i].type)==SKIP) && ((gameInfo->yourCards[i].colour)==lastCardColour)) {
			skipCardPos = i; //Index position of the skip card
		} else if (((gameInfo->yourCards[i].type)==SKIP) && ((gameInfo->yourCards[i].type)==lastCardType)) {
			skipCardPos = i;
		} else if (((gameInfo->yourCards[i].type)==DRAW_TWO) && ((gameInfo->yourCards[i].colour)==lastCardColour)) {
			draw2CardPos = i; //Index position of the draw two card
		} else if (((gameInfo->yourCards[i].type)==DRAW_TWO) && ((gameInfo->yourCards[i].type)==lastCardType)) {
			draw2CardPos = i;
		} else if (((gameInfo->yourCards[i].type)==REVERSE) && ((gameInfo->yourCards[i].colour)==lastCardColour)) {
			reverseCardPos = i; //Index position of the reverse card
		} else if (((gameInfo->yourCards[i].type)==REVERSE) && ((gameInfo->yourCards[i].type)==lastCardType)) {
			reverseCardPos = i;
		} else if ((gameInfo->yourCards[i].type)==NUMBER) {

			if ((gameInfo->yourCards[i].colour)==lastCardColour) {
				//Storing the highest number card position as the higher ones are worth more points.
				if (highestNumCardPos < (gameInfo->yourCards[i].value)) {
					highestNumCardPos = i;
				}
			} else if ((gameInfo->yourCards[i].value)==lastCardValue) {
				//Storing index position if the colour of Number card doesn't match but the values match.
				sameValueCardPos = i;
			}

		}
	}

	//Storing count values into array for comparison of highest number of cards of any colour.
	countArray[0] = countRed;
	countArray[1] = countGreen;
	countArray[2] = countBlue;
	countArray[3] = countYellow;

	//The below 'for-loop' finds out the number of cards of a colour with highest number of
	//cards and it's position in the countArray.
	for (i=0; i<4; i++) {
		if (countArray[i] > numCardsOfColour) {
			numCardsOfColour = countArray[i];
			posNumCardsOfColour = i;
		}
	}

	//Calculating player right and left positions
	playerLeftPos = (gameInfo->yourPosition)-1;
	playerRightPos = (gameInfo->yourPosition)+1;

	//If you are player 0, then player on the left will be in position 3.
	if (playerLeftPos==-1) {
		playerLeftPos = 3;
	}
	//But if you are player 3, then player on the right will be in position 0.
	if (playerRightPos == 4) {
		playerRightPos = 0;
	}

	//Playing a card. Please see description of strategy.
	if (((gameInfo->allPlayersCardsLeft[playerLeftPos]) < 3) || ((gameInfo->allPlayersCardsLeft[playerRightPos]) < 3)) {
		if (wild_D4CardPos > -1) {
			//If the wild-draw-4 card is going to be played, the colour called will be the
			//highest number of cards with that colour in my hand of cards.
			//If there is no such 'highest no. of cards' then value called will be RED (i.e.: 10000).
			wildCallValue = wild_D4CardPos + (posNumCardsOfColour*10000 + 10000);
			return wildCallValue;
		} else if (wildCardPos > -1) {
			//Wild card play has same idea (above) as wild-draw-card.
			wildCallValue = wildCardPos + (posNumCardsOfColour*10000 + 10000);
			return wildCallValue;
		} else if (draw2CardPos > -1) {
			//Note that the returned variable stores the position of the draw2Card.
			return draw2CardPos;
		} else if (skipCardPos > -1) {
			//Returning variable that has the position of the skip card.
			return skipCardPos;
		} else if (reverseCardPos > -1) {
			//Returning variable that has the position of the reverse card.
			return reverseCardPos;
		} else if (highestNumCardPos > -1) {
			//Returning variable that has the position of the number card if the last
			//played card was a number type.
			return highestNumCardPos;
		} else if (sameValueCardPos > -1) {
			//Returning variable that has the position of the reverse card.
			return sameValueCardPos;
		}
	} else {
		if ((highestNumCardPos > -1) && (sameValueCardPos > -1)) {
			if ((gameInfo->yourCards[highestNumCardPos].value) < (gameInfo->yourCards[sameValueCardPos].value)) {
				//If the card has that has the same colour but has a value that is
				//less than the card that has a different colour but a higher value, then
				//return the later card. Otherwise return the former card.
				return sameValueCardPos;
			} else {
				return highestNumCardPos;
			}
		} else if (highestNumCardPos > -1) {
			//Returning variable that has the position of the number card if the last
			//played card was a number type.
			return highestNumCardPos;
		} else if (sameValueCardPos > -1) {
			//Returning variable that has the position of the same value card.
			return sameValueCardPos;
		}  else if (draw2CardPos > -1) {
			//Note that the returned variable stores the position of the draw2Card.
			return draw2CardPos;
		} else if (skipCardPos > -1) {
			//Returning variable that has the position of the skip card.
			return skipCardPos;
		} else if (reverseCardPos > -1) {
			//Returning variable that has the position of the reverse card.
			return reverseCardPos;
		} else if (wild_D4CardPos > -1) {
			//If the wild-draw-4 card is going to be played, the colour called will be the
			//highest number of cards with that colour in my hand of cards.
			//If there is no such 'highest no. of cards' then value called will be RED (i.e.: 10000).
			wildCallValue = wild_D4CardPos + (posNumCardsOfColour*10000 + 10000);
			return wildCallValue;
		} else if (wildCardPos > -1) {
			//Wild card play has same idea (above) as wild-draw-card.
			wildCallValue = wildCardPos + (posNumCardsOfColour*10000 + 10000);
			return wildCallValue;
		}
	}

	//All other instances returning -1. IE: can't play a valid card.
	return -1;
}
