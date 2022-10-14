/*#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int* podniz(int* niz, int pocetak, int kraj)
{
	int duljina = kraj - pocetak;
	int* pod_niz = (int*)malloc((duljina) * sizeof(int));
	if (!niz)
	{
		return NULL;
	}
	int j = 0;
	for (int i = pocetak; i < kraj; i += 1)
	{
		pod_niz[j] = niz[i];
		j += 1;
	}
	return pod_niz;
}


int main(void)
{
	int pocetak, kraj;
	int niz[] = { 10, 2, 1, 15, 19, 6, 4, 8, 7, 9, 11, 16, 13, 15 };

	printf("Unesite pocetak novog niza:");
	scanf("%d", &pocetak);
	printf("Unesite kraj novog niza:");
	scanf("%d", &kraj);



	int* novi_podniz = podniz(niz, pocetak, kraj);

	for (int i = 0; i < kraj - pocetak; i += 1)
	{
		printf("%d\t", novi_podniz[i]);
	}

	free(novi_podniz);
	return 0;

}


int* filtriraj(int* niz, int n, int th, int* nth)
{
    *nth = 0;
    int* novi_niz = (int*)malloc(n * sizeof(int));
    if (!novi_niz)
    {
        return NULL;
    }

    for (int i = 0; i < n; i += 1)
    {
        if (niz[i] < th)
        {
            novi_niz[*nth] = niz[i];
            *nth += 1;
        }
    }
    if (*nth <= n)
    {
        novi_niz = (int*)realloc(novi_niz, *nth * sizeof(int));
        if (!novi_niz)
        {
            return NULL;
        }
    }
    else
    {
        printf("lose uneseni podaci");
    }

    return novi_niz;
}

int main(void)
{

    int niz[] = { 10, 3, 15, 20, 1, 11, 1, 2, 3, 5, 7, 55 };
    int n = sizeof(niz) / sizeof(niz[0]);
    int th, nth;
    printf("Unesite neki broj i svi brojevi manje od njega ce biti u novoj listi:");
    scanf("%d", &th);
    int* Novi_niz = filtriraj(niz, n, th, &nth);
    for (int i = 0; i < nth; i += 1)
    {
        printf("%d\t", Novi_niz[i]);
    }

    free(Novi_niz);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int** podijeli(int* niz, int n)
{
	int pola_duljine1 = n / 2;
	int pola_duljine2 = n - pola_duljine1;
	int* prva_polovica = (int*)malloc(pola_duljine1 * sizeof(int));
	if (!prva_polovica)
	{
		return NULL;
	}
	int* druga_polovica = (int*)malloc(pola_duljine2 * sizeof(int));
	if (!druga_polovica)
	{
		return NULL;
	}
	int j = 0;
	for (int i = 0; i < pola_duljine1; i += 1)
	{

		prva_polovica[i] = niz[i];


	}
	for (int i = 0; i < pola_duljine2; i += 1)
	{

		druga_polovica[i] = niz[i + pola_duljine1];

	}




	int** dupli_pointer = (int**)malloc(2 * sizeof(int*));
	if (!dupli_pointer)
	{
		return NULL;
	}
	dupli_pointer[0] = prva_polovica;
	dupli_pointer[1] = druga_polovica;
	return dupli_pointer;

}
int main(void)
{
	int niz[] = { 15, 20, 1, 3, 15, 18, 16, 17, 1, 5, 7 };
	int duljina = sizeof(niz) / sizeof(niz[0]);
	int pola_duljine1 = duljina / 2;
	int pola_duljine2 = duljina - pola_duljine1;

	int** novi_nizevi = podijeli(niz, duljina);


	for (int i = 0; i < duljina / 2; i += 1)
	{
		printf("%d\t", novi_nizevi[0][i]);
	}
	printf("\n");

	for (int i = 0; i < pola_duljine2; i += 1)
	{
		printf("%d\t", novi_nizevi[1][i]);
	}

	return 0;
}



#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


typedef struct
{
    float x;
    float y;

}Tocka;

typedef struct
{
    Tocka* broj_vrhova;
    int n;

}Poligon;


Poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{

    Poligon* novi_struct_pol = (Poligon*)malloc(sizeof(Poligon));
    if (!novi_struct_pol)
    {
        return 0;
    }
    Tocka* novi_vrh = (Tocka*)malloc(sizeof(Tocka) * n);
    if (!novi_vrh)
    {
        return 0;
    }

    novi_struct_pol->broj_vrhova = novi_vrh;

    for (int i = 0; i < n; i += 1)
    {

        novi_vrh[i].x = niz_x[i];
        novi_vrh[i].y = niz_y[i];


    }
    novi_struct_pol->n = n;
    return novi_struct_pol;
}

Tocka** pozitivni(Poligon* p, int* np)
{
    *np = 0;
    int vrijednost = p->n;


    for (int i = 0; i < vrijednost; i += 1)
    {
        if (p->broj_vrhova[i].x > 0 && p->broj_vrhova[i].y > 0)
        {

            *np += 1;
        }
    }
    Tocka** poz = (Tocka**)malloc(vrijednost * sizeof(Tocka*) * *np);
    if (!poz)
    {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < vrijednost; i += 1)
    {
        if (p->broj_vrhova[i].x > 0 && p->broj_vrhova[i].y > 0)
        {
            poz[j] = &p->broj_vrhova[i];
            j += 1;


        }
    }
    Poligon* poligon_novi = p;
    poligon_novi->n = *np;

    return poz;

}



int main(void)
{
    float x[] = { 2.9, -8.2, 3.3, 1.1 };
    float y[] = { 7.3, 2.9, 6.5, 3.6, 4.6, 4.9 };
    int duljina_prvog_niza = sizeof(x) / sizeof(x[0]);
    int duljina_drugog_niza = sizeof(y) / sizeof(y[0]);
    int np;


    if (duljina_prvog_niza >= duljina_drugog_niza && duljina_drugog_niza >= 3)
    {
        Poligon* novi_pol = novi_poligon(x, y, duljina_drugog_niza);
        for (int i = 0; i < duljina_drugog_niza; i += 1)
        {

            printf("x koordinata novog poligona iznosi: %fl\n", novi_pol->broj_vrhova[i].x);
            printf("y koordinata novog poligona iznosi: %fl\n", novi_pol->broj_vrhova[i].y);
        }

        printf("duljina parova niza iznosi: %.d\n", novi_pol->n);


        Tocka** t = pozitivni(novi_pol, &np);
        for (int i = 0; i < np; i += 1)
        {

            printf("adresa pointera broj_vrhova.x:%p\n", &novi_pol->broj_vrhova[i].x);
            printf(" adresa double pointera na x: %p\n", &t[i]->x);
            printf("adresa pointera broj_vrhova.y:%p\n", &novi_pol->broj_vrhova[i].y);
            printf(" adresa double pointera na y: %p\n", &t[i]->y);
            printf("vrijednost pozitivne x koordinate: %fl\n", t[i]->x);
            printf("vrijednost pozitivne y koordinate: %fl\n", t[i]->y);



        }
        printf("broj parnih elemenata niza kojem su koordinate pozitivne: %d", np);
        free(t);
        free(novi_pol);
        return 0;
    }

    else if (duljina_prvog_niza <= duljina_drugog_niza && duljina_prvog_niza >= 3)
    {
        Poligon* novi_pol = novi_poligon(x, y, duljina_prvog_niza);
        for (int i = 0; i < duljina_prvog_niza; i += 1)
        {

            printf("x koordinata novog poligona iznosi: %fl\n", novi_pol->broj_vrhova[i].x);
            printf("y koordinata novog poligona iznosi: %fl\n", novi_pol->broj_vrhova[i].y);

        }
        printf("duljina parova niza iznosi: %.d\n", novi_pol->n);

        Tocka** t = pozitivni(novi_pol, &np);
        for (int i = 0; i < np; i += 1)
        {

            printf("adresa pointera broj_vrhova.x:%p\n", &novi_pol->broj_vrhova[i].x);
            printf(" adresa double pointera na x: %p\n", &t[i]->x);
            printf("adresa pointera broj_vrhova.y:%p\n", &novi_pol->broj_vrhova[i].y);
            printf(" adresa double pointera na y: %p\n", &t[i]->y);
            printf("vrijednost pozitivne x koordinate: %fl\n", t[i]->x);
            printf("vrijednost pozitivne y koordinate: %fl\n", t[i]->y);


        }
        printf("broj parnih elemenata niza kojem su koordinate pozitivne: %d", np);
        free(t);
        free(novi_pol);
        return 0;
    }
    else
    {
        printf("krivo postavljen zadatak");
        return 0;
    }
}*/
