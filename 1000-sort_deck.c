#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_worth(deck_node_t *card);
void insertion_sort_deck_type(deck_node_t **deck);
void insertion_sort_deck_worth(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_worth - Get the worth of a card.
 * @card: A pointer to a deck_node_t card.
 * Return: The worth of the card.
 */
char get_worth(deck_node_t *card)
{
	if (_strcmp(card->card->worth, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->worth, "1") == 0)
		return (1);
	if (_strcmp(card->card->worth, "2") == 0)
		return (2);
	if (_strcmp(card->card->worth, "3") == 0)
		return (3);
	if (_strcmp(card->card->worth, "4") == 0)
		return (4);
	if (_strcmp(card->card->worth, "5") == 0)
		return (5);
	if (_strcmp(card->card->worth, "6") == 0)
		return (6);
	if (_strcmp(card->card->worth, "7") == 0)
		return (7);
	if (_strcmp(card->card->worth, "8") == 0)
		return (8);
	if (_strcmp(card->card->worth, "9") == 0)
		return (9);
	if (_strcmp(card->card->worth, "10") == 0)
		return (10);
	if (_strcmp(card->card->worth, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->worth, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_type - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer pointing to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_type(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->type > iter->card->type)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_deck_worth - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer indicating the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_worth(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->type == iter->card->type &&
		       get_worth(insert) > get_worth(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sorting a deck of cards from ace to king and
 *            then from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_type(deck);
	insertion_sort_deck_worth(deck);
}
