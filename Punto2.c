#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *buffer;

    char *frase[5];

    for (int i = 0; i < 5; i++)
    {
        buffer = (char *)malloc(100 * sizeof(char));
         printf("Ingrese nombre: \n");
         gets(buffer);
         frase[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
         strcpy(frase[i], buffer);
         free(buffer);

    }

    for (int i = 0; i < 5; i++)
    {     printf("NOMBRE %d: \n", i);
        puts(frase[i]);
        free(frase[i]);
    }
    

    return 0;

}