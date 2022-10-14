/*#include <stdio.h>
#include <string.h>


int mystrlen(char* string)
{
	int i;
	for (i = 0; string[i] != '\0'; i += 1)
		;

	return i;
}

int main(void)
{

	char string[] = "josip";

	printf("Duljina stringa iznosi: %d\n", strlen(string));
	printf("Duljina stringa iznosi: %d\n", mystrlen(string));


	return 0;
}

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void mystrcpy(char* string3, char* string4)
{
	int i;
	for (i = 0; string3[i] != '\0'; i += 1)
	{

		string4[i] = string3[i];

	}
	string4[i] = '\0';

}

int main(void)
{
	char string1[] = "Ovo je premjesteno u drugi string.";
	char string2[50] = "Dio drugog stringa.";
	char string3[] = "Ovo je premjesteno u cetvrti string.";
	char string4[50] = "Dio cetvrtog stringa.";

	strncpy(string2, string1, sizeof(string2));

	puts(string2);

	mystrcpy(string3, string4);
	printf("%s\n", string4);

	return 0;

}


#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

int mystrcmp(char* string1, char* string2)
{
    int i = 0;
    while (string1[i] != '\0' || string2[i] != '\0')
    {
        if (string1[i] != string2[i])
        {
            if (string1[i] > string2[i])
            {

                return 1;
            }
            else
            {

                return -1;
            }

        }
        i += 1;
    }

    return 0;

}



int main(void)
{
    int a, b;
    char string1[] = "aa";
    char string2[] = "aaaa";

    a = strcmp(string1, string2);

    if (a == 0)
        printf("String1 i string2 su leksikografski jednaki\n");
    if (a < 0)
        printf("String1 je leksikografski veci od string2\n");
    if (a > 0)
        printf("String1 je leksikografski manji od string2\n");


    b = mystrcmp(string1, string2);
    if (b == 0)
        printf("String1 i string2 su leksikografski jednaki\n");
    if (b < 0)
        printf("String1 je leksikografski veci od string2\n");
    if (b > 0)
        printf("String1 je leksikografski manji od string2\n");


    return 0;
}




#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void mystrcat(char* string2, char* string3)
{
	int i, j = 0;
	for (i = strlen(string2); i < strlen(string3) + strlen(string2); i += 1)
	{

		string2[i] = string3[j];

		j += 1;
	}
	string2[i] = '\0';

}


int main(void)
{
	char string1[50] = "Ovo je prvi string.";
	char string2[100] = "Ovo je drugi string.";
	char string3[] = "Ovo je dodano drugom stringu.";
	strcat(string1, "Ovo je dodano prvom stringu. ");

	puts(string1);

	mystrcat(string2, string3);
	puts(string2);


	return 0;
}



#include <string.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS


int* mystrstr(char* string3, char* string4)
{
    int velicina2 = strlen(string3);
    int velicina1 = strlen(string4);
    int i, j, brojac = 0;
    for (i = 0; i < velicina2; i += 1)
    {
        for (j = 0; j < velicina1; j += 1)
        {

            if (string3[i + j] == string4[j])
            {
                brojac += 1;

                if (brojac == velicina1)
                {

                    return string3 + i;
                }
            }

        }
        brojac = 0;

    }

    return NULL;
}




int main(void)
{

    char string1[] = "Trazimo prvo pojavljivanje drugog stringa u prvome";
    char string2[] = "drugog";
    char string3[] = "novi neki provjereni string je ovo";
    char string4[] = "string";
    char* pojavljivanje;
    pojavljivanje = strstr(string1, string2);

    if (pojavljivanje != NULL)
    {
        printf("%s\n", pojavljivanje);
    }

    else
    {
        printf("Nema pojavljivanja drugog stringa u prvome.\n");
    }


    char* pojavljivanje2 = mystrstr(string3, string4);
    if (pojavljivanje2 != NULL)
    {
        printf("%s\n", pojavljivanje2);
    }
    else
    {
        printf("Nema pojavljivanja drugog stringa u prvome.\n");

    }

    return 0;
}


#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS



void reverse(char* string1, char* string2) {
    int i, j = 0;
    int a = strlen(string1);
    for (i = a - 1; i >= 0; i -= 1)
    {

        string2[j] = string1[i];

        j += 1;
    }

    string2[j] = '\0';
}

int main(void)
{

    char string1[] = "prvi string";
    char string2[20] = "drugi string";

    reverse(string1, string2);

    printf("%s\n", string2);

    return 0;
}*/