#include "matriks.h"
#include "pcolor.h"

#ifndef MAP_H
#define MAP_H

void CreateMap(int m, int n, MATRIKS* M);
/* Untuk membuat map Awal */

void PrintMap(int m, int n, MATRIKS M);
/* Untuk Mencetak Map */

void convertIndex (int *m, int *n);
/* Untuk mengkonvert indeks pertama di petak */

void IndexUnit (int *m, int *n);
/* Untuk mengakses indeks unit */

void IndexBuilding (int *m, int *n);
/* Untik mengakses indeks building */

#endif
