/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NKMax 50
#define BLANK ' '
#define NEWLINE '\n'

typedef struct {
	char TabKata[NKMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

const Kata recruit = {"RECRUIT", 7};
const Kata change_unit = {"CHANGE_UNIT", 12};
const Kata info = {"INF0", 4};
const Kata attack = {"ATTACK", 6};
const Kata map = {"MAP", 3};
const Kata next_unit = {"NEXT_UNIT", 9};

void IgnoreBlank(boolean bacafile);
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(boolean bacafile);
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(boolean bacafile);
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(boolean bacafile);
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          
boolean IsSama(Kata K1, Kata K2);
/* I.S. : K1 dan K2 terdefinisi
   Proses : mengembalikan true jika K1 dan K2 sama, mengembalikan false jika K1 tidak sama dengan K2 */

boolean IsBilangan(Kata K);
/* I.S. : K1 terdefinisi
   Proses : mengembalikan true jika isi kata K merupakan hanya angka */

int KatatoBilangan(Kata K);
/* I.S. : K1 terdefinisi bilangan
   Proses : mengembalikan bilangan hasil konversi dari kata K */

void PrintKata(Kata K);
/* I.S. : K1 terdefinisi
   Proses : menulis ke layar kata K tanpa karakter tambahan lainnya */

#endif