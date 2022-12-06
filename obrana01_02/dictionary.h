#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct Word {
	char* word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word* next;
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char* str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// briše cijeli rjeènik
void destroy(Dictionary dict);

int filter(Word* w);

Dictionary filterDictionary(Dictionary indict, int(*filter)(Word* w));

//obrana

char* najduza(Dictionary dict);
int ukupan_broj_rijeci(Dictionary dict);
void dodaj_na_pocetak_liste(Dictionary dict, char* str);
void dodaj_na_kraj_liste(Dictionary dict, char* str);
void dodaj_prije_elementa(Dictionary dict, char* str);
void umetni_na_indexu(Dictionary dict, char* str, int index);
Dictionary okreni(Dictionary dict);
void izbrisi_prvu(Dictionary dict);
void izbrisi_zadnju(Dictionary dict);
void izbrisi_rijec(Dictionary dict, char* str);
void najduza_na_prvo_mjesto(Dictionary dict);
int filter_new_po_kriteriju(Word* w);
Dictionary filterDictionary_new_po_kriteriju(Dictionary indict, int(*filter)(Word* w));
void izbrisi_zadnjih_deset(Dictionary dict);
void dodavanje_ispred_duzine_deset(Dictionary dict, char* str);
void prvi_na_zadnje_mjesto(Dictionary dict);
void zadnji_na_prvo_mjesto(Dictionary dict);
void zamjena_prvi_zadnji(Dictionary dict);
void prebacivanje_liste_u_novu_listu(Dictionary dict);
void dodaj_na_kraj_liste_niz(Dictionary dict, char* arr);
int* dodavanje_elemenata_iz_liste_u_niz(Dictionary dict,int*i);
void kopirani_elementi_nova_lista(Dictionary kopirani_list, Dictionary dict, int koliko_kopirati);




#endif