#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;          // El tamaño de este arreglo depende de la variable // “CantidadProductosAPedir”
} typedef Cliente;

// FUNCION CARGAR CLIENTE
void cargar(Cliente *clientes, int tam)
{
    char *buffer;
    char *buffer2;
    int aux, aux2;
    Producto *pro;
    for (int i = 0; i < tam; i++)
    {
        clientes->ClienteID = i;
        buffer = (char *)malloc(100 * sizeof(char));
        printf("Ingrese el nombre del cliente[%d]: \n",i+1);
        gets(buffer);
        
        clientes->NombreCliente = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(clientes->NombreCliente, buffer);
        free(buffer);
        clientes->CantidadProductosAPedir = rand() % 5 + 1;
        aux = clientes->CantidadProductosAPedir;
        printf("aux %d \n",aux);
        // CARGAR PRODUCTOS
        clientes->Productos = (Producto *)malloc(aux * sizeof(Producto));
        pro = clientes->Productos;
        for (int i = 0; i < aux; i++)
        {
            printf("Cargar el producto %d \n", i+1);
            clientes->Productos->ProductoID = i;
            clientes->Productos->Cantidad = rand() % 10 + 1;
         
            aux2 = rand() % 5;
           
            clientes->Productos->TipoProducto = TiposProductos[aux];
           
            clientes->Productos->PrecioUnitario = rand() % 91 + 10;
            clientes->Productos++;
        }
        clientes->Productos = pro;
           printf("sali de productos \n");
        clientes++;
    }
}

// Funcion Calcular costo producto
float Calcular(Producto *productos)
{
    return productos->Cantidad * productos->PrecioUnitario;
}

// MOSTRAR TODOS LOS DATOS
void MOSTRAR(Cliente *clientes, int tam)
{    Producto *pro;
    float totalP;
    float totalC = 0;
    for (int i = 0; i < tam; i++)
    {
        printf("--------------------\n");
        printf("cliente numero: %d\n", i+1);
        printf("Nombre:");
        puts(clientes->NombreCliente);
        printf("cantidad de productos: %d \n", clientes->CantidadProductosAPedir);
        pro=clientes->Productos;
        for (int i = 0; i < clientes->CantidadProductosAPedir; i++)
        {
            printf("-----PRODUCTO ID [%d]------\n", i);
            printf("cantidad: %d \n", clientes->Productos->Cantidad);
            printf("tipo producto: ");
            puts(clientes->Productos->TipoProducto);
            //free(clientes->Productos->TipoProducto);
            printf("Precio unitario: %f \n", clientes->Productos->PrecioUnitario);
            totalP = Calcular(clientes->Productos);
            printf("Total a pagar producto: %f \n", totalP);

            totalC = totalC + totalP;
            clientes->Productos++;
        }
        clientes->Productos=pro;
        free(clientes->Productos);
        printf("Total a pagar cliente: $ %f \n", totalC);
        clientes++;
    }

   
}

int main()
{
    srand((int)time(NULL));
    Cliente *clientes, *p;
   
    int tam;
    printf("Ingrese la cantidad de clientes del 1 al 5: \n");
    scanf("%d", &tam);
    fflush(stdin);
    clientes = (Cliente *)malloc(tam * sizeof(Cliente));
     p = clientes;
    cargar(clientes, tam);
    clientes = p;
    MOSTRAR(clientes, tam);
     clientes = p;
      free(clientes);
    return 0;
}