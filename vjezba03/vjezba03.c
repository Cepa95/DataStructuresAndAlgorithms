#include <stdio.h>
#include <stdlib.h>
#include "stl.h"

int main()
{

	FILE* fp1 = fopen("primjerbin.stl", "rb");
	if (!fp1)
	{
		return 1;
	}
	Objekt3D* objekt3d = ispuni_objekt3D(fp1);
	fclose(fp1);


	FILE* fp2 = fopen("updateprimjerbin.stl", "wb");
	if (!fp2)
	{
		return 2;
	}
	zapisi_binarno(objekt3d, fp2);
	fclose(fp2);

	FILE* fp3 = fopen("updateprimjertxt.stl", "w");
	if (!fp3)
	{
		return 3;
	}
	zapisi_tekstualno(objekt3d, fp3);
	fclose(fp3);

	brisi_objekt3d(objekt3d);

	FILE* fp4 = fopen("primjertxt.stl", "r");
	if (!fp4)
	{
		return 4;
	}
	citaj_tekstualno(fp4);
	fclose(fp4);

	return 0;

}

