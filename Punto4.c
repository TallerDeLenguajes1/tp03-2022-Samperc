#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantfilas;

    char *buffer;
    buffer = (char *)malloc(100 * sizeof(char));
    char **frase;
printf("Ingrese la cantidad de nombres q desea usar \n");
scanf("%d",&cantfilas);
fflush(stdin);
frase=(char **)malloc(sizeof(char *)*cantfilas);
    for (int i = 0; i <cantfilas; i++)
    {
         printf("Ingrese el nombre %d \n",i);
         gets(buffer);
         fflush(stdin);
         frase[i]=(char *)malloc((strlen(buffer) + 1) * sizeof(char));
         strcpy(frase[i],buffer);
         
    }

    for (int i = 0; i < cantfilas; i++)
    {     printf("NOMBRE %d: \n", i);
        puts(frase[i]);
        free(frase[i]);
        
    }
    free(buffer);

    return 0;

}