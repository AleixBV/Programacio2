#include <Windows.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>


void Log(const char* cadena, char* imatge, float valor)
{
	char output[500];
	assert(cadena);
	assert(imatge);
	assert(valor);
	sprintf_s(output, 500, cadena, imatge, valor);
	OutputDebugString(output);
}

int main(int argc, char** argv)
{
	char textura[100] = "my textura.png";


	Log("Cargando Textura: %s en %f segundos\n", textura, 3.1416f);

	getchar();
}