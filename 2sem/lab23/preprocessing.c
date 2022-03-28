#include <stdio.h> // <> поиск файла в стандартной директории
#include <stdlib.h>

// #include "camera.h" - поиск файла в файлах проекта

#define width 100
#define my_print printf("%s", "hello!\n")

int main(void)
{
	#ifdef width // Директива условной компиляции
		my_print;
	#else
		printf("%s\n", "width is not defined");
	#endif

	// #ifndef           (if not defined)
	// #elif 			 (else if)
	// #ifdef width > 50 (Добавление условий)

	return 0;
}