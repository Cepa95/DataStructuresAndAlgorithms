#include <stdio.h>
#include<string.h>
#include "dictionary.h"
#define _CRT_SECURE_NO_WARNINGS

int readWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	FILE* fd;
	char buffer[1024];
	Dictionary dict;

	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	dict = create();
	int i = 0;
	while (readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		add(dict, buffer);

	}
	fclose(fd);


	//print(dict);
	printf("\n \n \n");
	//dict = filterDictionary(dict, filter);
	//printf("\n");
	//print(dict);

	//destroy(dict);

	//printf("najduza rijec je %s\n", najduza(dict));
	//printf("ukupan broj rijeci je %d\n", ukupan_broj_rijeci(dict));
	//dodaj_na_pocetak_liste(dict, "provjera1");
	//dodaj_na_kraj_liste(dict, "provjera2");
	//dodaj_prije_elementa(dict, "prije dovoljno");
	//umetni_na_indexu(dict, "peto misto", 5);
	//Dictionary okr = okreni(dict);
	//print(okr);
	//izbrisi_prvu(dict);
	//izbrisi_zadnju(dict);
	//izbrisi_rijec( dict, "josip");
	//najduza_na_prvo_mjesto(dict);
	//Dictionary dict_copy;
	//dict_copy = filterDictionary_new_po_kriteriju(dict, filter);
	//print(dict_copy);
	//izbrisi_zadnjih_deset(dict);
	//dodavanje_ispred_duzine_deset(dict, "provjera5");
	//prvi_na_zadnje_mjesto(dict);
	//zadnji_na_prvo_mjesto(dict);
	//zamjena_prvi_zadnji(dict);
	//prebacivanje_liste_u_novu_listu(dict);

	/*char* arr[] = {"neka", "provjera"};
	int duljina = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < duljina; i += 1)
	{
		//printf("%s\n", arr[i]);
		dodaj_na_kraj_liste_niz(dict, arr[i]);
	}
	print(dict);*/
	/*int jj = 0;
	int* niz = dodavanje_elemenata_iz_liste_u_niz(dict, &jj);
	for (int j = 0; j < jj; j += 1)
	{
		printf("%d ", niz[j]);
	}*/

}