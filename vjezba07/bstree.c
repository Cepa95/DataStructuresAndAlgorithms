#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree* bst, char* word)
{
	// Rekurzivno se traži mjesto za novi èvor u stablu. Ako rijeè postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokazivaè.
	if (*bst == NULL)                      
	{
		*bst = (BSTree)malloc(sizeof(Node));
		//(*bst)->word = (char*)malloc(sizeof(char) * (strlen(word) + 1));
		//strcpy((*bst)->word, str);
		(*bst)->word = word;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
		return;
	}
	else if (strcmp((*bst)->word, word) > 0) //ako je rijec manja od trenutne,rekurzivno livo ili desno
	{
		return AddNode(&(*bst)->left, word);
	}
	else if (strcmp((*bst)->word, word) < 0)
	{
		return AddNode(&(*bst)->right, word);
	}
	return;


}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se pronašla najduža grana (visina stabla).
	if (bst == NULL)
	{
		return 0;
	}
	
	int left_branch = BSTHeight(bst->left);
	int right_branch = BSTHeight(bst->right);


	if (left_branch >= right_branch)
	{
		return (left_branch + 1);
	}

	else if (left_branch < right_branch)
	{
		return (right_branch + 1);
	}
	
	
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rijeèi u stablu na ekran po abecednom redu.
	// In-order šetnja po stablu (lijevo dijete, èvor, desno dijete)
	// inorder
	if (bst == NULL)
	{
		return;
	}
	if (bst->left != NULL)
	{
		PrintBSTree(bst->left); //  lijevo dijete
	}
	printf("%s ", bst->word); 
	
	if (bst->right != NULL)
	{
		PrintBSTree(bst->right); // desno dijete
	}

}

void SaveBSTree(BSTree bst, FILE* fd)
{
	// Snima rijeè po rijeè iz stabla u tekstualnu datoteku. Rijeèi su odvojene razmakom.
	// Pre-order šetnja po stablu (ttenutni èvor pa djeca)
	if (bst == NULL)
	{
		return;
	}
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);

}

/*void printPreorder(BSTree bst)
{
	if (bst == NULL)
	{
		return;
	}
	printf("%s ", bst->word); // cvor

	printPreorder(bst->left);
	printPreorder(bst->right);
}*/





void DeleteBSTree(BSTree bst)
{
	// Briše stablo (string word i sam èvor) iz memorije.
	// Post-order šetnja po stablu (prvo djeca pa trenutni èvor)
	
	if (bst == NULL)
	{
		return;
	}
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	
	free(bst->word);
	free(bst);
}

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
}


BSTree LoadBSTree(FILE* fd)
{
	// Uèitava rijeè po rijeè iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rijeè duplicirati sa strdup().

	BSTree bst = NULL;
	
	char buffer[1024];
	while (readWord(fd, buffer))
	{
		printf("%s\n", buffer);
		AddNode(&bst, strdup(buffer));
	}
	return bst;

}
