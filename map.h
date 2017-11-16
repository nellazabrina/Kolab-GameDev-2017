#include "matriks.h"
#include "unit.h"

#ifndef MAP_H
#define MAP_H

void CreateMap(int m, int n, MATRIKS* M);
/* Untuk membuat map Awal */

void PrintMap(int m, int n, MATRIKS M);
/* Untuk Mencetak Map */

void convertIndex (int m, int n);
/* Untuk mengkonvert indeks */

#endif