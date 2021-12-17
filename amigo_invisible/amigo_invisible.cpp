#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

#define PART 13
#define EXCEPT 4
#define RAND 100

void introduir_array(string a[], int M) {
	for (int i = 0; i < M; i++)
	{
		cin >> a[i];
	}
}

void imprimir(string a[], int M) {
	for (int i = 0; i < M; i++)
	{
		cout << a[i] << endl;
	}
}

void copiar_array(string a[], string b[], int M) {
	for (int i = 0; i < M; i++)
	{
		b[i] = a[i];
	}
}

void llenar_matriz(string r[][2], string a[], string b[], int f) {
	for (int i = 0; i < f; i++)
	{
		r[i][0] = a[i];
		r[i][1] = b[i];
	}
}

void imprimir_matriz(string r[][2], int f) {
	for (int i = 0; i < f; i++)
	{
		cout << r[i][0] << ": " << r[i][1] << endl;
	}
}

void randomizar(string b[], int m, int r) {
	srand((unsigned)time(NULL));
	string aux;
	int rnd;
	for (int i = 0; i < r; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (rand() % 2) {
				rnd = rand() % (m);
				aux = b[j];
				b[j] = b[rnd];
				b[rnd] = aux;
			}
		}
	}
}

bool comprovar(string r[][2], int f) {
	int i = 0;
	while ((i<f)&&(r[i][0]!=r[i][1]))
	{
		i++;
	}
	if (i == f) {
		return false;
	}
	return true;
}
//if (!strcmp(a, "guapa"))

void excepciones(string e[][2]) {
	int i = 0;
	while ((i<EXCEPT)&&(e[i][0] == e[i][1]))
	{
		cout << "Excepcion " << i + 1 << ", no pueden ir juntos : ";
		cin >> e[i][0] >> e[i][1];
		i++;
	}
}

bool comprobar_excepciones(string r[][2], string e[][2], int f) {
	int i = 0;
	while ((i < f) && ((r[i][0] != e[i][0]) || (r[i][1] != e[i][0]) || (r[i][0] != e[i][1]) || (r[i][1] != e[i][1])))
	{

		i++;
	}
	if (i == f) {
		return false;
	}
	return true;
}

int main()
{
	string a[PART], b[PART], r[PART][2], e[EXCEPT][2];
	char s;
	cout << "Introduce participantes: ";
	introduir_array(a, PART);
	imprimir(a, PART);
	copiar_array(a, b, PART);
	cout << "Quieres introducir excepciones? (S/N) ";
	cin >> s;
	if (s == 's') {
		excepciones(e);
		randomizar(b, PART, RAND);
		llenar_matriz(r, a, b, PART);
		while (comprovar(r, PART) || comprobar_excepciones(r, e, PART))
		{
			randomizar(b, PART, RAND);
			llenar_matriz(r, a, b, PART);
		}
	}
	else {
		randomizar(b, PART, RAND);
		llenar_matriz(r, a, b, PART);
		while (comprovar(r, PART) || comprobar_excepciones(r, e, PART))
		{
			randomizar(b, PART, RAND);
			llenar_matriz(r, a, b, PART);
		}
	}
	imprimir_matriz(r, PART);
}