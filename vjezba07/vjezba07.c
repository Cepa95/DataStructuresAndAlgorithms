#include <stdio.h>
#include <ctype.h>
#include "bstree.h"

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
	int wc;
	FILE* fd;
	char buffer[1024];
	BSTree bst;
	bst =  NULL;  //NewBSTree();

	// Kreiraj stablo
	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	wc = 0;
	while (readWord(fd, buffer))
	{
		//printf("%s\n", buffer);
		AddNode(&bst, strdup(buffer)); // valjda ne triba malloc, to radi strdup
		wc++;
	}

	fclose(fd);

	// Ispiši stablo, visinu i broj èvorova
	PrintBSTree(bst);
	printf("\nH = %d, N = %d\n", BSTHeight(bst), wc);

	// Snimi i izbriši
	if ((fd = fopen("stablo.txt", "wt")) == NULL)
	{
		printf("Error opening file for writing.\n");
		return;
	}
	SaveBSTree(bst, fd);
	//printPreorder(bst);
	fclose(fd);

	DeleteBSTree(bst);
	printf("\nprovjera:\n");
	/*if (bst == NULL)
	{
		printf("kraj");
	}
	else 
	{ 
		printf("\ngreska\n");
	}*/
	// Uèitaj stablo
	if ((fd = fopen("stablo.txt", "rt")) == NULL)
	{
		printf("Error opening file for reading.\n");
		return;
	}
	bst = LoadBSTree(fd);
	fclose(fd);

	// Ispiši visinu i izbriši
	printf("\nH = %d\n", BSTHeight(bst));
	DeleteBSTree(bst);

	return 0;
}