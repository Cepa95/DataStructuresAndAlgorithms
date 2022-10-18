#include <stdio.h>
#include <stdlib.h>
#include "stl.h"


Objekt3D* ispuni_objekt3D(FILE* fp)
{
	Objekt3D* objekt3d = (Objekt3D*)malloc(sizeof(Objekt3D));
	if (!objekt3d)
	{
		return NULL;
	}
	fseek(fp, 80, SEEK_SET);
	fread((&objekt3d->broj_trokuta), sizeof(unsigned int), 1, fp);
	//printf("%u", objekt3d->broj_trokuta);
	objekt3d->niz_trokuta = (Trokut*)malloc(sizeof(Trokut) * objekt3d->broj_trokuta);

	if (!objekt3d->niz_trokuta)
	{
		return NULL;
	}
	int i = 0;
	while (!feof(fp))
	{
		fread((&objekt3d->niz_trokuta[i]), 50, 1, fp);
		i += 1;



	}
	//printf("%f\n", objekt3d->niz_trokuta[0].vrhovi[0].x);
	//printf("%f\n", objekt3d->niz_trokuta[0].vrhovi[0].y);
	//printf("%f\n", objekt3d->niz_trokuta[0].vrhovi[0].z);
	//printf("%u\n", objekt3d->niz_trokuta->broj);


	return objekt3d;
}

void zapisi_binarno(Objekt3D* objekt3d, FILE* fp)
{
	int niz[20];
	for (int i = 0; i < 20; i += 1)
	{
		niz[i] = 0;
	}
	fwrite(niz, sizeof(int), 20, fp);
	fwrite(&objekt3d->broj_trokuta, sizeof(unsigned int), 1, fp);
	for (int i = 0; i < objekt3d->broj_trokuta; i += 1)
	{
		fwrite(&objekt3d->niz_trokuta[i], 1, 50, fp);
		
	}
}

void zapisi_tekstualno(Objekt3D* objekt3d, FILE* fp)
{

	fprintf(fp, "solid OpenSCAD_Model \n");
	for (int i = 0; i < objekt3d->broj_trokuta; i += 1)
	{
		fprintf(fp, "facet normal %f, %f, %f\n", objekt3d->niz_trokuta[i].nj, objekt3d->niz_trokuta[i].ni, objekt3d->niz_trokuta[i].nk);
		fprintf(fp, "outer loop\n");

		for (int j = 0; j < 3; j += 1)
		{
			fprintf(fp, "vertex %f, %f, %f\n", objekt3d->niz_trokuta[i].vrhovi[j].x, objekt3d->niz_trokuta[i].vrhovi[j].y, objekt3d->niz_trokuta[i].vrhovi[j].z);

		}

		fprintf(fp, "endloop\n");
		fprintf(fp, "endfacet\n");
	}
	fprintf(fp, "endsolid OpenSCAD_Model\n");

}

void brisi_objekt3d(Objekt3D* objekt3d)
{

	free(objekt3d->niz_trokuta);
	free(objekt3d);
}



void citaj_tekstualno(FILE* fp)
{
	char string[50];
	while (fgets(string, 50, fp) != NULL)
	{
		printf("%s", string);
	}

}
