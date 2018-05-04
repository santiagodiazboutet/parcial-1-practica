#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1




int eUsuario_init( eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].id= 0;
        }
    }
    return retorno;
}

int eUsuario_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsuario_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }

            }
        }
    }

    return retorno+1;
}




int eUsuario_alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    char usuario[50];
    char password[10];
    int id;
    int indice;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUsuario_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            id = eUsuario_siguienteId(listado,limite);
            retorno = 0;
                    printf("\nIngrese el nombre del usuario a ingresar.\n");
                    fflush(stdin);
                    gets(usuario);
                    printf("\nIngrese la password a utilizar.\n");
                    fflush(stdin);
                    gets(password);
                    strcpy(listado[indice].usuario, usuario);
                    strcpy(listado[indice].password, password);
                    listado[indice].id = id;
                    listado[indice].estado = OCUPADO;

        }
    }
    return retorno;
}
void eUsuario_baja(eUsuario listado[] ,int limite)
{
    int i;
    int id;
    eUsuario_mostrarListado(listado,limite);
        printf("\nIngrese id del componente a modificar");
        scanf("%d",&id);
   i=eUsuario_buscarPorId(listado,limite,id);
   listado[i].estado=LIBRE;
}
int eUsuario_modificacion(eUsuario listado[] ,int limite)
{   int id;
    int i;
    int opcion=0;
    while(opcion!=1&&opcion!=2)
    {
        eUsuario_mostrarListado(listado,limite);
        printf("\nIngrese id del componente a modificar");
        scanf("%d",&id);
        i=eUsuario_buscarPorId(listado,limite,id);
        if(i==-2||i==-3)
        {
            printf("\nEl numero ingresado no pertenece a un Id en funcionamiento");
        }
        else
        {
            while(opcion!=1&&opcion!=2)
            {
            system("cls");
            printf("\nEl usuario a modificar es: %s.\n 1- Modificar nombre de usuario\n 2- Modificar password\n",listado[i].usuario);
            scanf("%d",&opcion);
            if(opcion==1)
            {
                printf("\nIngrese el nuevo nombre de usuario.\n");
                fflush(stdin);
                gets(listado[i].usuario);
            }
            else if(opcion==2)
            {
                printf("\nIngrese su nueva contraseña.\n");
                fflush(stdin);
                gets(listado[i].password);
            }
            }
        }
    }

   i=eUsuario_buscarPorId(listado,limite,id);

}
int eUsuario_buscarPorId(eUsuario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;

                break;
            }
        }
    }
    printf("%d",retorno);
    return retorno;
}



void eUsuario_mostrarUno(eUsuario parametro)
{
     printf("\n %s -codigo: %d",parametro.usuario,parametro.id);

}

int eUsuario_mostrarListado(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                eUsuario_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}

int eProducto_alta(eProducto  listado[],int limite, int idUsuario)
{
    int retorno = -1;
    char nombre[50];
    int vendidos=0;
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eProducto_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eProducto_siguienteId(listado,limite);
            printf("\nIngrese el nombre del producto\n");
            fflush(stdin);
            gets(nombre);
            strcpy(listado[indice].nombre, nombre);
            printf("\nIngrese el stock del producto\n");
            scanf("%d",&listado[indice].stock);
            printf("\nIngrese el precio del producto\n");
            scanf("%f",&listado[indice].precio);
            listado[indice].idUsuario=idUsuario;
            listado[indice].estado=OCUPADO;
        }
    }
    return retorno;
}
void eProducto_baja(eProducto listado[] ,int limite, int id)
{
    int i;
   i=eProducto_buscarPorId(listado,limite,id);
   listado[i].estado=LIBRE;
}
int eProducto_modificacion(eProducto listado[] ,int limite, int id)
{
    int i;
    float precio;
    int stock;
    i=eProducto_buscarPorId(listado,limite,id);
    printf("Ingrese el nuevo precio del producto");
    scanf("%f",&precio);
    printf("Ingrese el stock del producto");
    scanf("%d",&stock);
    listado[i].precio=precio;
    listado[i].stock=stock;
    return i;
}
int eProducto_init( eProducto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idProducto= 0;
        }
    }
    return retorno;
}

int eProducto_buscarLugarLibre(eProducto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProducto_siguienteId(eProducto listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idProducto>retorno)
                    {
                         retorno=listado[i].idProducto;
                    }

            }
        }
    }

    return retorno+1;
}


int eProducto_buscarPorId(eProducto listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int eProducto_buscarPorIdUsuario(eProducto listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


void eProducto_mostrarUno(eProducto parametro)
{
     printf("\n %s -codigo: %d -stock:%d -precio$%f",parametro.nombre,parametro.idProducto,parametro.stock,parametro.precio);

}

int eProducto_mostrarListadoProductosPorUsuario(eProducto listado[],int limite,int idUsuario)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                if(listado[i].idUsuario==idUsuario)
                {
                     eProducto_mostrarUno(listado[i]);
                }
            }
        }
    }
    return retorno;
}

int eProducto_mostrarListado(eProducto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                     eProducto_mostrarUno(listado[i]);

            }
        }
    }
    return retorno;
}

int eVentas_init( eVentas listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idVenta= 0;
        }
    }
    return retorno;
}

int Venta(eVentas ventas[],eProducto productos[],int limiteProductos, int limiteVentas)
{
    int id;
    int i;
    int j;
    int z;
    eProducto_mostrarListado(productos,limiteProductos);
    printf("Ingrese el codigo del producto a comprar");
    scanf("%d",id);
    i=eProducto_buscarPorId(productos,limiteProductos,id);

    j=eVentasbuscarLugarLibre(ventas,limiteVentas);
    eVentassiguienteId(ventas,limiteVentas);
    eVentas[j].idProducto=id;


}

int eVentasbuscarLugarLibre(eVentas listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eVentassiguienteId(eVentas listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idVentas>retorno)
                    {
                         retorno=listado[i].idVentas;
                    }

            }
        }
    }

    return retorno+1;
}
