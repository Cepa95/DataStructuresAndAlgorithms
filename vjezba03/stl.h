#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float x;
	float y;
	float z;
} Vrh;

typedef struct
{
	float nj;
	float ni;
	float nk;
	Vrh vrhovi[3];
	unsigned short broj;
} Trokut;

typedef struct
{
	Trokut* niz_trokuta;
	unsigned int broj_trokuta;
} Objekt3D;


Objekt3D* ispuni_objekt3D(FILE* fp);
void zapisi_binarno(Objekt3D* objekt3d, FILE* fp);
void zapisi_tekstualno(Objekt3D* objekt3d, FILE* fp);
void brisi_objekt3d(Objekt3D* objekt3d);
void citaj_tekstualno(FILE* fp4);
