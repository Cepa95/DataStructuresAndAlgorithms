#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable* NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	HashTable* dict = (HashTable*)malloc(sizeof(HashTable));
	dict->table = (Bin**)malloc(sizeof(Bin*) * size);
	if (dict->table == NULL)
	{
		return;
	}
	dict->size = size;
	dict->load = 0;
	for (int i = 0; i < size; i+=1)
	{
		dict->table[i] = NULL;
	}
	return dict;

}

unsigned int hash(char* word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while (*word != '\0')
	{
		key = key * HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable* ht, char* word)
{
	unsigned int key = hash(word) % ht->size;
	ht->load = ht->load + 1;
	Bin* tmp = (Bin*)malloc(sizeof(Bin));
	if (tmp == NULL)
	{
		return;
	}
	tmp->word = word;
	tmp->next = ht->table[key];
	ht->table[key] = tmp;
}


int Get(HashTable* ht, char* word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	unsigned int key = hash(word) % ht->size;
	Bin* item = ht->table[key];
	while (item != NULL) 
	{
		if (strcmp(item->word, word) == 0)
		{
			return 1;
		}
		item = item->next;	
	}
	return 0;
}

void DeleteTable(HashTable* ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	for (int i = 0; i < ht->size; i++) 
	{
		while (ht->table[i] != NULL) 
		{
			Bin* tmp = ht->table[i];
			ht->table[i] = ht->table[i]->next;
			free(tmp->word);
			free(tmp);
		}
	}
	free(ht->table);
	free(ht);
}