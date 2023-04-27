#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum type_e - Enumeration of card suits.
 * @SPADE: Spades suit.
 * @HEART: Hearts suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */
typedef enum type_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} type_t;

/**
 * struct card_s - Playing card
 *
 * @worth: worth of the card
 * From "Ace" to "King"
 * @type: Type of the card
 */
typedef struct card_s
{
	const char *worth;
	const type_t type;
} card_t;

/**
 * struct deck_node_s - Deck of card
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
