#include "map.h"
#include <stdio.h>

void CreateMap(int m, int n, MATRIKS* M) {
  convertIndex (m, n);
  MakeMATRIKS(n,m,M);
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (i%4==0) {
          Elmt(*M,i,j).CC='*';
	  Elmt(*M,i,j).kepemilikan=3;
      }
      else {
        if (j%4==0) {
          Elmt(*M,i,j).CC='*';
	  Elmt(*M,i,j).kepemilikan=3;
        }
        else {
          Elmt(*M,i,j).CC=' ';
	  Elmt(*M,i,j).kepemilikan=3;
        }
      }
    }
  }
  PrintMap(m, n, *M);
}

void PrintMap(int m, int n, MATRIKS M) {
  for (int k=0; k<(n-1)/4; k++) {
    if (k==0) {
        printf("   ");
    }
    printf("  ");
    printf("%d", k);
    if (k==((n-1)/4)-1) {
      printf("\n");
    }
    else {
      if (k<10) {
        printf(" ");
      }
    }
  }

  int l = 0;

  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (j==0) {
        if ((i-2)%4==0) {
          if (l<10) {
            printf(" %d ", l);
          }
          else {
            printf("%d ", l);
          }
          l++;
        }
        else {
          printf("   ");
        }
      }

      print_char(Elmt(M, i, j)); //printf("%c", Elmt(M, i, j));
      if (j==(n-1)) {
        printf("\n");
      }
    }
  }
}

void convertIndex (int m, int n) {
    m = (m*4)+1;
    n = (n*4)+1;
}