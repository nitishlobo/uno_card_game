#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER   0
#define SKIP     1
#define REVERSE  2
#define DRAW_TWO 3
#define WILD     4
#define WILD_D4  5
#define PENALTY  6

#define LEFT     7
#define RIGHT    8

#define RED    10000
#define GREEN  20000
#define BLUE   30000
#define YELLOW 40000
#define NONE   50000

#define MAX_CARDS 108
#define MAX_PLAYERS 4

typedef struct {
	int type;
	int colour;
	int value;
} Card;

typedef struct {
	Card cards[MAX_CARDS];
	int numCards;
} Deck;

typedef struct {
	int numberOfPlayers;
	int directionOfPlay;
	int lastColourCalled;
	int yourPosition;
	int yourNumberOfCards;
	Card yourCards[MAX_CARDS];
	int numberOfDiscards;
	Card discardPile[MAX_CARDS];
	int allPlayersCardsLeft[MAX_PLAYERS];
	int allPlayersColoursCalled[MAX_PLAYERS];
	int allPlayersScores[MAX_PLAYERS];
} GameState;
