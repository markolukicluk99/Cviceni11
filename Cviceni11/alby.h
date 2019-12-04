#pragma once

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

int vyroba(char arr[50]);
void add(const char * interpret, const char * nazov, int rok);
void show();