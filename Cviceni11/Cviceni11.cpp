// ul12.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "pch.h"
#include <iostream>
#include "tchar.h"
#include "alby.h"

int _tmain(int argc, _TCHAR* argv[])
{

	add("Scooter", "Wicked!", 2015);
	add("POD", "Satellite", 2001);
	add("Nickelback", "Hesher", 1996);
	add("Disturbed", "Immortalized", 2015);
	add("Saliva", "Saliva", 1997);


	printf("Rozvrh podle interpreta:\n\n");
	printf("Interpret-------Album-------Rok\n");
	show();
	//getchar();


	return 0;
}

