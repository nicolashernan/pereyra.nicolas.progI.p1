#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id[10];
    char procesador[20];
    char marca[20];
    float precio[10];

}eNotebook;


int aplicarDescuento(int precios);
int ordenarPorMarcaYPrecio(eNotebook vec[],int tam);

int main()
{
    int a = 100;
    int descuento;

    descuento = aplicarDescuento(a);

    printf("%d\n",descuento);

    eNotebook notebook[4] =
    {
        {1010,"ryzen","hp",233},
        {1011,"intel","compac",300},
        {1012,"intel","gigabyte",400}
    };

    ordenarPorMarcaYPrecio(notebook,4);

        printf("    id     |  procesador   |   marca   |   precio\n\n");

        for(int i = 0;i<3;i++)
        {

            printf("%d      %s                %s             %.2f\n",
            notebook[i].id,
            notebook[i].procesador,
            notebook[i].marca,
            notebook[i].precio);
        }


    return 0;
}

int aplicarDescuento(int precio)
{
    int descuento;

    descuento = precio-((precio*5)/100);

    return descuento;

}

int ordenarPorMarcaYPrecio(eNotebook vec[],int tam)
{
    int todoOk = 0;
    eNotebook auxNotebook;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0;i<tam-1;i++)
        {
            for(int j = i+1;j<tam;j++)
            {
            	if((strcmp(vec[i].marca,vec[j].marca) > 0) || (strcmp(vec[i].marca,vec[j].marca) == 0 && vec[i].precio > vec[j].precio))

            	                {
            	                    auxNotebook = vec[i];
            	                    vec[i] = vec[j];
            	                    vec[j] = auxNotebook;
            	                }
            }
        }
        todoOk = 1;

    }

    return todoOk;
}
