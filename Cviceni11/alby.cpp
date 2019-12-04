#include <stdlib.h>
#include <string.h>
#include "pch.h"
#include <iostream>
#include "tchar.h"


struct t_alba
{
	char interpret[30];
	char nazov[30];
	int rok;
	struct t_alba* dalsi;
};
struct t_alba* prvni = NULL; // globalni ukazatel na prvni Album

int vyroba(char arr[50]) {
	char abc[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	//printf("%s\n",arr);
	for (int i = 0; i < 53; i++)
	{
		if (arr[0] == abc[i]) {
			//printf("a%c\n",arr[0]);
			for (int j = 0; j < 53; j++) {
				if (arr[1] == abc[j]) {
					i = i * 10;
					return i + j;
				}
			}
		}
	}
	//printf("chyba");
	return 0;
}

void show() // tisk alb
{
	struct t_alba * aktAlbum = prvni; // ukazatel na aktualni Album
	while (aktAlbum) // prochazeni seznamu
	{
		printf("%s - %s   r%d\n", aktAlbum->interpret, aktAlbum->nazov, aktAlbum->rok); // tisk radku
		aktAlbum = aktAlbum->dalsi; // posun na dalsi Album
	}
}

void add(const char * interpret, const char * nazov, int rok) // pridani auta
{
	struct t_alba * noveAlbum; // ukazatel pro nove vkladane Album
	struct t_alba* aktAlbum; // ukazatel na aktualni Album
	noveAlbum = (struct t_alba *)malloc(sizeof(struct t_alba)); // alokace dynamicke promenne
	strcpy_s(noveAlbum->interpret, 30, interpret); // naplneni struktury
	strcpy_s(noveAlbum->nazov, 30, nazov);
	noveAlbum->rok = rok;
	noveAlbum->dalsi = NULL;

	if (prvni == NULL) // linearni seznam je prazdny
	{
		prvni = noveAlbum;
		return;
	}
	else if (vyroba(noveAlbum->interpret) < vyroba(prvni->interpret)) // vlozime na zacatek          poradie(prvni->rok)
	{
		noveAlbum->dalsi = prvni;
		prvni = noveAlbum;
		return;
	}

	aktAlbum = prvni; // ukazatel na aktualni Album
	while (aktAlbum) // prochazeni seznamu
	{
		if (aktAlbum->dalsi == NULL) // jsme na poslednim aute  
		{
			aktAlbum->dalsi = noveAlbum; // pridavame na konec
			return;
		}
		else if (vyroba(noveAlbum->interpret) < vyroba(aktAlbum->dalsi->interpret))
		{
			noveAlbum->dalsi = aktAlbum->dalsi; // vlozime za aktAlbum
			aktAlbum->dalsi = noveAlbum;
			return;
		}
		aktAlbum = aktAlbum->dalsi; // posun na dalsi Album
	}
}