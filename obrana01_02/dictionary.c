#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>


Dictionary create()
{
	Dictionary rjecnik = (Dictionary)malloc(sizeof(Word));
	rjecnik->count = 0;
	rjecnik->next = NULL;
	rjecnik->word = NULL;

	return rjecnik;
}

void add(Dictionary dict, char* str)
{

	Dictionary p = dict;
	Dictionary n = dict->next;

	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(novi->word, str);
	novi->count = 1;
	//printf("%s ", novi->word);

	while (n != NULL)
	{
		if (strcmp(n->word, str) == 0)
		{
			n->count++;
			free(novi->word);
			free(novi);
			//printf("if\n");
			return;

		}
		else if (strcmp(n->word, str) > 0)
		{
			novi->next = n;
			p->next = novi;
			//printf("else if\n");
			return;
		}
		//printf("iza if i elsa\n"); 
		n = n->next;
		p = p->next;

	}
	//printf("while end\n");
	p->next = novi;
	novi->next = NULL;

}


void print(Dictionary dict)
{
	dict = dict->next;
	while (dict != NULL)
	{
		printf("%s - count:%d\n", dict->word, dict->count);
		dict = dict->next;
	}
}

void destroy(Dictionary dict)
{

	while (dict != NULL)
	{
		Dictionary temp;
		temp = dict;
		dict = dict->next;
		free(temp->word);
		free(temp);
	}
}


int filter(Word* w)

{
	if ((w->count > 5 && w->count < 10) && strlen(w->word) > 3)
	{
		return 1;
	}
	else
		return 0;
}

Dictionary filterDictionary(Dictionary indict, int(*filter)(Word* w))
{
	Dictionary p = indict;
	Dictionary n = indict->next;

	while (n != NULL)
	{
		if (filter(n) == 1)
		{
			p = p->next;
			n = n->next;
		}
		else
		{
			p->next = n->next;
			free(n->word);
			free(n);
			n = p->next;
		}
	}
	return indict;
}


char* najduza(Dictionary dict) //najduza ric
{
	Dictionary n = dict->next;
	char* p = NULL;
	if (n == NULL)
		return p;
	p = n->word;
	n = n->next;
	while (n != NULL)
	{
		if (strlen(n->word) > strlen(p))
		{
			p = n->word;
		}
		n = n->next;
	}
	return p;
}

int ukupan_broj_rijeci(Dictionary dict)
{
	int brojac = 0;
	while (dict != NULL)
	{
		brojac += dict->count;
		dict = dict->next;
	}
	return brojac;
}


void dodaj_na_pocetak_liste(Dictionary dict, char* str)
{
	Dictionary nova = (Dictionary)malloc(sizeof(Word));
	nova->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
	nova->count = 1;

	Dictionary n = dict->next;
	strcpy(nova->word, str);
	//printf("%s", nova->word);
	nova->next = dict->next; //zbog dic==nul prije u vjezbi sta sam radia
	dict = nova;
	//dict = dict->next;
	while (dict != NULL)
	{
		printf("%s - count:%d\n", dict->word, dict->count);
		dict = dict->next;
	}
	printf("\n \n \n");

}


void dodaj_na_kraj_liste(Dictionary dict, char* str)
{

	Dictionary nova = (Dictionary)malloc(sizeof(Word));
	nova->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
	nova->count = 1;
	nova->next = NULL;
	strcpy(nova->word, str);
	//dict = dict->next;
	Dictionary tmp = dict;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;

	}
	tmp->next = nova;
	while (dict != NULL)
	{
		printf("%s\n", dict->word);
		dict = dict->next;
	}
}

void dodaj_prije_elementa(Dictionary dict, char* str)
{
	Dictionary nova = (Dictionary)malloc(sizeof(Word));
	nova->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
	strcpy(nova->word, str);
	nova->count = 1;
	nova->next = NULL;
	dict = dict->next;
	printf("jaja");

	if (strcmp(dict->word, str) == 0)
	{
		nova->next = dict;
		dict = nova;
		return;
	}

	Dictionary tmp = dict;
	while (strcmp(tmp->next->word, "dovoljno") != 0)
	{
		tmp = tmp->next;
	}
	nova->next = tmp->next;
	tmp->next = nova;

	while (dict != NULL)
	{
		printf("%s\n", dict->word);
		dict = dict->next;
	}
}

void umetni_na_indexu(Dictionary dict, char* str, int index)
{
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
	novi->count = 1;
	strcpy(novi->word, str);
	dict = dict->next;

	Dictionary tmp = dict;

	if (index == 0)
	{
		novi->next = dict;
		dict = novi;
	}
	for (int i = 0; i < index - 1; i += 1)
	{
		if (tmp->next == NULL)
		{
			return;
		}
		tmp = tmp->next;

	}
	novi->next = tmp->next;
	tmp->next = novi;

	while (dict != NULL)
	{
		printf("%s\n", dict->word);
		dict = dict->next;
	}
}

Dictionary okreni(Dictionary dict)
{
	Dictionary okr = NULL;
	dict = dict->next;
	while (dict->next != NULL)
	{
		Dictionary tmp = dict;
		dict = dict->next;
		tmp->next = okr;
		okr = tmp;
	}
	return okr;
}

void izbrisi_prvu(Dictionary dict)
{
	dict = dict->next;
	Dictionary temp = dict;
	Dictionary n = dict->next;
	dict = n;
	free(temp->word);
	free(temp);
	while (dict != NULL)
	{
		printf("%s\n", dict->word);
		dict = dict->next;
	}
}

void izbrisi_zadnju(Dictionary dict)
{
	dict = dict->next;
	Dictionary tmp = dict;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}

	free(tmp->next->word);
	free(tmp->next);
	tmp->next = NULL;
	while (dict != NULL)
	{
		printf("%s\n", dict->word);
		dict = dict->next;
	}
}

void izbrisi_rijec(Dictionary dict, char* str) {

	dict = dict->next;
	Dictionary novi, tmp = dict;
	while (tmp->next != NULL)
	{
		if (strcmp(tmp->next->word, str) == 0)
		{
			novi = tmp->next->next;
			free(tmp->next->word);
			free(tmp->next);
			tmp->next = novi;

			while (dict != NULL)
			{
				printf("%s\n", dict->word);
				dict = dict->next;
			}
			return;
		}
		tmp = tmp->next;
	}
}

void najduza_na_prvo_mjesto(Dictionary dict)
{
	dict = dict->next;
	Dictionary p = dict;
	Dictionary n = dict->next;
	Dictionary najduza = NULL, pn = NULL;
	Dictionary dummy = dict;
	Dictionary prvi = dict;
	int brojac = 0;

	while (n != NULL) {
		if (strlen(n->word) > brojac) {
			najduza = n;
			pn = p;
			brojac = strlen(n->word);
		}
		p = p->next;
		n = n->next;
	}
	pn->next = pn->next->next;
	dummy = najduza;
	najduza->next = prvi;
	dict = dummy;

	while (dict != NULL)
	{
		printf("%s\n", dict->word);
		dict = dict->next;
	}
}

int filter_new_po_kriteriju(Word* w)

{
	if (strlen(w->word) > 6)
	{
		return 1;
	}
	else
		return 0;
}

Dictionary filterDictionary_new_po_kriteriju(Dictionary indict, int(*filter)(Word* w))
{

	Dictionary p = indict;
	Dictionary n = indict->next;

	while (n != NULL)
	{
		if (filter_new_po_kriteriju(n) == 1)
		{
			p = p->next;
			n = n->next;
		}
		else
		{
			p->next = n->next;
			free(n->word);
			free(n);
			n = p->next;
		}
	}

	return indict;
}

void izbrisi_zadnjih_deset(Dictionary dict)
{
	//dict = dict->next;
	Dictionary n = dict->next;
	Dictionary p = dict;
	int brojac = 0;
	while (dict != NULL)
	{
		dict = dict->next;
		brojac++;
	}
	int br2 = 0;
	while (n != NULL) {
		if (br2 == (brojac - 11)) {
			n->next = NULL;
			free(n->word);
			free(n->next);
			p->next = p->next->next;
			return;
		}
		br2++;
		n = n->next;
		p = p->next;
	}
}


void dodavanje_ispred_duzine_deset(Dictionary dict, char* str)
{
	Dictionary p = dict;
	Dictionary n = dict->next;
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
	strcpy(novi->word, str);
	novi->count = 0;
	while (n != NULL)
	{
		if (strlen(n->word) > 10)
		{
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			novi->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
			strcpy(novi->word, str);
			novi->count = 0;
			p->next = novi;
			novi->next = n;
			p = p->next->next;
			n = n->next;
			continue;
		}
		n = n->next;
		p = p->next;
	}
}

void prvi_na_zadnje_mjesto(Dictionary dict)
{
	//dict = dict->next;
	Dictionary dummy = dict;
	Dictionary prvi = dict->next;
	while (dict->next != NULL)
	{
		dict = dict->next;
	}
	dict->next = prvi;
	dummy->next = dummy->next->next;
	prvi->next = NULL;
}

void zadnji_na_prvo_mjesto(Dictionary dict)
{
	dict = dict->next;
	Dictionary secLast = NULL;
	Dictionary last = dict;

	while (last->next != NULL)
	{
		secLast = last;
		last = last->next;

	}
	secLast->next = NULL;
	last->next = dict;
	dict = last;
}

void zamjena_prvi_zadnji(Dictionary dict)
{
	dict = dict->next;
	Dictionary dummy = dict;
	Dictionary prvi = dict;
	Dictionary p = dict;
	Dictionary n = dict->next;

	while (n->next != NULL)
	{
		n = n->next;
		p = p->next;
	}
	dummy = n;
	n->next = prvi->next;
	p->next = prvi;
	prvi->next = NULL;
	dict = dummy;

	while (dict != NULL)
	{
		printf("%s\n", dict->word);
		dict = dict->next;
	}
}


void prebacivanje_liste_u_novu_listu(Dictionary dict)
{
	Dictionary p = dict;
	Dictionary n = dict->next;
	Dictionary dict2 = (Dictionary)malloc(sizeof(Word));
	Dictionary temp = dict2;
	while (n != NULL)
	{
		if (strlen(n->word) > 5)
		{
			p->next = n->next;
			temp->next = n;
			temp = n;
			n = p->next;
			continue;
		}
		n = n->next;
		p = p->next;
	}
	temp->next = NULL;
}


void dodaj_na_kraj_liste_niz(Dictionary dict, char* arr)
{

	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	Dictionary p = dict;
	while (p->next != NULL) 
	{
		p = p->next;
	}
	novi->word = (char*)malloc(sizeof(char) * (strlen(arr) + 1));
	strcpy(novi->word, arr);
	novi->count = 1;
	novi->next = NULL;
	p->next = novi;
}

int* dodavanje_elemenata_iz_liste_u_niz(Dictionary dict, int*i)
{

	Dictionary p = dict->next;
	int niz[1024];
	
	while (p->next != NULL)
	{
		niz[*i] = p->count;
		p = p->next;
		*i+=1;
	}
	return niz;
}


void kopirani_elementi_nova_lista(Dictionary kopirani_list, Dictionary dict, int koliko_kopirati)
{
	Dictionary temp = dict->next, nova_lista = kopirani_list, novi;
	int i = 0;
	while (i < koliko_kopirati) 
	{
		novi = (Word*)malloc(sizeof(Word));
		novi->word = strdup(temp->word);
		novi->count = temp->count;
		novi->next = NULL;
		while (nova_lista->next != NULL) {
			nova_lista = nova_lista->next;
		}
		nova_lista->next = novi;
		temp = temp->next;
		i++;
	}
}