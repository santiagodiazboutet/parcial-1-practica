#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define TAM 100
#define TAM2 1000
#define TAM3 10000


int main()
{
    eUsuario usuarios[TAM];
    eUsuario_init(usuarios,TAM);
    eProducto productos[TAM2];
    eProducto_init(productos,TAM2);
    eVentas ventas[TAM3];
    eVentas_init(ventas,TAM3);
    int id=0;
    int i=0;
    int opcion=0;
    while(opcion!=11)
    {   system("cls");
        printf("MENU\n1-ALTA DE USUARIO\n2-MODIFICACION DE USUARIO\n3-BAJADE USUARIO\n4-PUBLICAR PRODUCTO\n5-MODIFICAR PUBLICACION\n6-CANCELAR PUBLICACION\n7-COMPRAR PRODUCTO\n8-LISTAR PUBLICACIONES DE USUARIO\n9-LISTAR PUBLICAIONES\n10-LISTAR USUARIOS\n11-SALIR\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            eUsuario_alta(usuarios,TAM);
            break;
        case 2:
            eUsuario_modificacion(usuarios,TAM);
            break;
        case 3:
            eUsuario_baja(usuarios,TAM);
            break;
        case 4:
            eUsuario_mostrarListado(usuarios,TAM);
            printf("\nSeleccione el usuario que desea publicar un producto, ingrese cero para salir.\n");
            scanf("%d",&id);
            i=eUsuario_buscarPorId(usuarios,TAM,id);
            if (i>1)
            {
                eProducto_alta(productos,TAM2,id);
            }else{
            printf("Ingrese un usuario valido e intente nuevamente");
            }
            break;
        case 5:
            eUsuario_mostrarListado(usuarios,TAM);
            printf("\nSeleccione el usuario cuyo producto desea modificar.\n");
            scanf("%d",&id);
            eProducto_mostrarListadoProductosPorUsuario(productos,TAM2,id);
            printf("\n Ingrese el codigo del producto a modificar");
            scanf("%d",&id);
            eProducto_modificacion(productos,TAM2,id);
            break;
            break;
        case 6:
            eUsuario_mostrarListado(usuarios,TAM);
            printf("\nSeleccione el usuario cuyo producto desea modificar.\n");
            scanf("%d",&id);
            eProducto_mostrarListadoProductosPorUsuario(productos,TAM2,id);
            printf("\nSeleccione el producto que desea borrar.\n");
            scanf("%d",&id);
            eProducto_baja(productos,TAM2,id);
            break;
        case 7:
            Venta(ventas,productos,TAM2,TAM3);
            break;
        case 11:
            break;
        }
    }
}
