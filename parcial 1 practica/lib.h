typedef struct
{
    char usuario[50];
    char password[10];
    float calificacion;
    int id;
    int estado;
}eUsuario;

typedef struct{
    char nombre[50];
    float precio;
    int stock;
    int idUsuario;
    int estado;
    int idProducto;
}eProducto;

typedef struct{
int idVenta;
int idProducto;
int calificacion;
int cantidad;
int estado;
}eVentas;


int eUsuario_init(eUsuario[],int limite);
int eUsuario_buscarPorId(eUsuario[] ,int limite, int id);
int eUsuario_siguienteId(eUsuario[] ,int limite);
int eUsuario_buscarLugarLibre(eUsuario listado[],int limite);
int eUsuario_alta(eUsuario[] ,int limite);
void eUsuario_baja(eUsuario[] ,int limite);
int eUsuario_modificacion(eUsuario[] ,int limite);
void eUsuario_mostrarUno(eUsuario parametro);
int eUsuario_mostrarListado(eUsuario[] ,int limite);
int eUsuario_buscarPorId(eUsuario[] ,int limite, int id);



int eProducto_init(eProducto[],int limite);
int eProducto_buscarPorId(eProducto[] ,int limite, int id);
int eProducto_siguienteId(eProducto[] ,int limite);
int eProducto_buscarLugarLibre(eProducto listado[],int limite);
void eProducto_mostrarUno(eProducto parametro);
int eProducto_mostrarListado(eProducto[] ,int limite);
int eProducto_alta(eProducto[] ,int limite, int idUsuario);
void eProducto_baja(eProducto[] ,int limite, int id);
int eProducto_modificacion(eProducto[] ,int limite, int id);
int eProducto_ordenar(eProducto[] ,int limite, int orden);
int eProducto_mostrarListadoProductosPorUsuario(eProducto listado[],int limite,int idUsuario);


int eVentas_init( eVentas listado[],int limite);
int Venta(eVentas ventas[],eProducto productos[],int limiteProductos, int limiteVentas);
