#include <stdio.h>

float srednia_harm(float * tablica, unsigned int n);
float nowy_exp(float x);
void dodaj_sse(char* t1, char* t2, char* wynik);
void int2float(int * calkowite, float * zmienno_przec);
void pm_jeden(float * tabl);
void dodawanie_SSE(float * a);


int main() {
	// 5.1

	float t[] = { 1.3f, 2.5f, 5.1f };
	printf("%f\n", srednia_harm(t, 3));

	// 5.2

	printf("%f\n", nowy_exp(2));

	// 5.3

	char liczby_A[16] = { -128, -127, -126, -125, -124, -123, -122,
		-121, 120, 121, 122, 123, 124, 125, 126, 127 };
	char liczby_B[16] = { -3, -3, -3, -3, -3, -3, -3, -3,
		3, 3, 3, 3, 3, 3, 3, 3 };
	char suma[16];

	dodaj_sse(liczby_A, liczby_B, suma);

	for (int i = 0; i < 16; i++)
		printf("%d ", suma[i]);
	printf("\n");

	// 5.4

	int a[2] = { -17, 24 };
	float r[4];
	// podany rozkaz zapisuje w pamiêci od razu 128 bitów,
	// wiêc musz¹ byæ 4 elementy w tablicy
	int2float(a, r);
	printf("\nKonwersja = %f %f\n", r[0], r[1]);

	// 5.5

	float tablica[4] = { 27.5,143.57,2100.0, -3.51 };

	printf("\n%f %f %f %f\n", tablica[0],
		tablica[1], tablica[2], tablica[3]);

	pm_jeden(tablica);

	printf("\n%f %f %f %f\n", tablica[0],
		tablica[1], tablica[2], tablica[3]);

	// 5.6
	float wyniki[4];
	dodawanie_SSE(wyniki);
	printf("\nWyniki = %f %f %f %f\n",
		wyniki[0], wyniki[1], wyniki[2], wyniki[3]);

	return 0;
}