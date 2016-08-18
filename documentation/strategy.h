/* DOCUMENTATION

	STRATEGY DESCRIPTION:
	The code takes into account the last card that was played (i.e.: the card
	on top of the discard pile). This card's data (i.e.: type, colour and value) is
	recorded in a variable preffixed as 'last' and followed by the word 'Card' and
	suffixed by the data field (eg: Colour). This gives the variable named 'lastCardColour'.
	If the last card played	was a wild card, the variable 'lastCardColour' then stores
	the colour called by the player who played the wild card.

	The code then looks at all of the cards in my hand. This is done through a 'for loop'.
	If any card can be validly played, then the card's position is stored under
	a variable name that describes the card type (eg: 'reverseCardPos' decribes the position
	of the reverse card). Furthermore, if this variable is not equal to -1, then this indicates that it
	can be validly played.

	While looking at all the cards, the number of cards under each colour (red, green, blue, yellow)
	is recorded in a variable which has the prefix as count and the suffix as the
	colour (eg: countRed). For example, if I have 4 red cards in my hand, then countRed will equal 4.

	Once the code has looked at all the cards, it then puts the counter of each colour (i.e.:
	countRed, countGreen, countBlue, countYellow) into an array. Putting these into an
	array, allows for effecient comparison and the code then learns which suit of colour has the
	most number of cards in the hand of cards. The position of that colour in the array is
	recorded and then is used later when calling a colour when I play a wild card. In other
	words, after the playing a wild card, the colour that the code will call is the colour
	that appears the most in my hand. If I play a wild or wild draw 4 card, but I have no colour
	cards, then the formula will call red by default.

	Just before the lines of code to play the wild card and to call the correct colour, the code also
	calculates the positions of the players to the left and right of my position and then it
	observes how many cards they have.

	If either player on left or	right has less than 3 cards, then my cards, if they match,
	are played in the respective order:
	wild draw 4, wild, draw 2, skip, reverse, highest number card and same
	value card (i.e.: the number type card that has the same number but different colour).

	But if both players on left and right of my position have more than 2 cards, then my
	cards, if they match, are played in the respective order:
	number card, draw 2, skip, reverse, wild draw 4 and wild.
	In this instance, there is also a special catch to playing a number type card from my hand:
	The code figures out whether the number card (which has a matching colour to
	the top of the discard pile card) has a number value that is less than the
	number value of the card that matches the top of the discard pile card but
	has a different colour. If that is the case, then the card that will be played is
	the card that has a different colour but a value that matches the card on top of
	the discard pile. Otherwise the number card that has the same colour but the
	highest value is played.

	If both types of number cards (i.e.: number card which has a matching colour to
	the top of the discard pile card and the number card with a value that matches
	the top of the discard pile card but has a different colour) are not present,
	then the one that is present is played.

	For all other instances the play() function returns -1 which means that I can't play a valid card.
*/