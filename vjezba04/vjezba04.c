#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define BIGRAND (rand()*rand())

void shuffle(int* niz, int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = i + BIGRAND % (n - i);
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* generate(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = 1 + BIGRAND % 3;
	for (int i = 1; i < n; i++)
		niz[i] = niz[i - 1] + BIGRAND % 3 + 1;
	shuffle(niz, n);
	return niz;
}

int presjek(int* niz1, int* niz2, int duljina1, int duljina2) {
	int brojac = 0;
	for (int i = 0; i < duljina1; i += 1)
	{
		for (int j = 0; j < duljina2; j += 1)
		{
			if (niz1[i] == niz2[j])
			{
				brojac += 1;
			}
		}
	}
	return brojac;
}

int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);

}


int presjek_jedan_sortiran(int* niz1, int* niz2, int duljina1, int duljina2)
{
	int brojac = 0;
	qsort(niz2, duljina2, sizeof(int), cmpfunc);
	/*for (int i = 0; i < duljina2; i++)
	{
		printf("%d ", niz2[i]);
	}*/
	int* item;
	for (int i = 0; i < duljina1; i += 1)
	{
		item = (int*)bsearch(&niz1[i], niz2, duljina2, sizeof(int), cmpfunc);
		if (item != NULL)
		{
			brojac += 1;
		}
		/*else
		{
			printf("nema presjeka: %d:\n", *item);
		}*/
	}

	return brojac;
}

int presjek_oba_sortirana(int* niz1, int* niz2, int duljina1, int duljina2)
{

	int brojac = 0, i = 0, j = 0;
	qsort(niz2, duljina2, sizeof(int), cmpfunc);
	qsort(niz1, duljina1, sizeof(int), cmpfunc);
	/*for (int i = 0; i < duljina2; i++)
	{
		printf("%d ", niz2[i]);
	}
	for (int i = 0; i < duljina1; i++)
	{
		printf("%d ", niz1[i]);
	}*/

	while (i < duljina1 && i < duljina2)
	{
		if (j < duljina2)
		{
			if (niz1[i] == niz2[j])
			{
				brojac += 1;
				i += 1;
				j += 1;
			}
			if (niz1[i] > niz2[j])
			{
				j += 1;
			}
			if (niz1[i] < niz2[j])
			{
				i += 1;
			}
		}
		else
		{
			return brojac;
		}

	}
	return brojac;
}


int maxi(int* niz1, int duljina)
{
	int broj = niz1[0];
	for (int i = 1; i < duljina; i += 1)
	{
		if (broj < niz1[i])
		{
			broj = niz1[i];
		}

	}

	return broj;
}



int presjek_po_indexima(int* niz1, int* niz2, int duljina1, int duljina2)
{
	int brojac = 0;

	int najveci1 = maxi(niz1, duljina1);
	int najveci2 = maxi(niz2, duljina2);
	//printf(" %d, %d\n", najveci1, najveci2);
	int* niz3 = (int*)malloc((sizeof(int) * (najveci1 + 1)));//ipak treba plus 1 jer ce se najveci broj uvijek nalazit na zadnjem mistu/index+1
	if (!niz3)
	{
		return -1;
	}
	int* niz4 = (int*)malloc((sizeof(int) * (najveci2 + 1)));
	if (!niz4)
	{
		return -1;
	}
	for (int i = 0; i <= najveci1; i += 1)
	{
		niz3[i] = 0;
	}

	for (int i = 0; i < duljina1; i += 1)
	{

		niz3[niz1[i]] = 1;
	}
	/*for (int i = 0; i <= najveci1; i += 1)
	{
		printf(" %d\t", niz3[i]);
	}*/

	for (int i = 0; i <= najveci2; i += 1)
	{
		niz4[i] = 0;
	}
	for (int i = 0; i < duljina2; i += 1)
	{

		niz4[niz2[i]] = 1;
	}
	/*for (int i = 0; i <= najveci2; i += 1)
	{
		printf(" %d\t", niz4[i]);
	}*/
	if (najveci1 >= najveci2)
	{

		for (int i = 0; i <= najveci2; i += 1)
		{
			if (niz3[i] == 1 && niz4[i] == 1)
			{
				brojac += 1;
			}

		}

	}
	else
	{

		for (int i = 0; i <= najveci1; i += 1)
		{
			if (niz3[i] == 1 && niz4[i] == 1)
			{
				brojac += 1;
			}

		}

	}
	free(niz3);
	free(niz4);

	return brojac;
}



void main()
{
	srand(time(NULL));
	int duljina1 = 50000;
	int duljina2 = 100000;
	int* niz1 = generate(duljina1);
	int* niz2 = generate(duljina2);
	/*for (int i = 0; i < duljina1; i+=1)
	{
		printf("%d ", niz1[i]);
	}
	printf("\n");
	printf("Pocetak novog niza:\n");
	for (int i = 0; i < duljina2; i+=1)
	{
		printf("%d ", niz2[i]);
	}*/
	clock_t t_0;
	t_0 = clock();
	int presjek_niza_duzina = presjek(niz1, niz2, duljina1, duljina2);
	t_0 = clock() - t_0;
	double time_consumed = ((double)t_0) / CLOCKS_PER_SEC;
	printf("Funkciji je trebalo %f sekundi da se izvrsi. \n", time_consumed);
	//printf("Duzina presjeka niza iznosi: %d\n", presjek_niza_duzina);
	printf("\n");
	free(niz1);
	free(niz2);
	int* niz3 = generate(duljina1);
	int* niz4 = generate(duljina2);
	clock_t t_01;
	t_01 = clock();
	int presjek_sortirani = presjek_jedan_sortiran(niz3, niz4, duljina1, duljina2);
	t_01 = clock() - t_01;
	double time_consumed1 = ((double)t_01) / CLOCKS_PER_SEC;
	printf("Funkciji je trebalo %f sekundi da se izvrsi. \n", time_consumed1);
	//printf("Duzina presjeka niza iznosi: %d\n", presjek_sortirani);
	printf("\n");
	free(niz3);
	free(niz4);
	int* niz5 = generate(duljina1);
	int* niz6 = generate(duljina2);
	clock_t t_02;
	t_02 = clock();
	int presjek_sortirani_dva = presjek_oba_sortirana(niz5, niz6, duljina1, duljina2);
	t_02 = clock() - t_02;
	double time_consumed2 = ((double)t_02) / CLOCKS_PER_SEC;
	printf("Funkciji je trebalo %f sekundi da se izvrsi. \n", time_consumed2);
	//printf("Duzina presjeka niza iznosi: %d\n", presjek_sortirani_dva);
	printf("\n");
	free(niz5);
	free(niz6);
	int* niz7 = generate(duljina1);
	int* niz8 = generate(duljina2);
	/*for (int i = 0; i < duljina1; i += 1)
	{
		printf("%d ", niz7[i]);
	}
	printf("\n");
	for (int i = 0; i < duljina2; i += 1)
	{
		printf("%d ", niz8[i]);
	}
	printf("\n");*/
	clock_t t_03;
	t_03 = clock();
	int presjek_index = presjek_po_indexima(niz7, niz8, duljina1, duljina2);
	t_03 = clock() - t_03;
	double time_consumed3 = ((double)t_03) / CLOCKS_PER_SEC;
	printf("Funkciji je trebalo %f sekundi da se izvrsi. \n", time_consumed3);
	//printf("Duzina presjeka niza iznosi: %d\n", presjek_index);
	free(niz7);
	free(niz8);

	return 0;
}