#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "eCliente.h"
#include "alquiler.h"
#include "Vista.h"
#include "DataManager.h"



static ArrayList* nominaClientes;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);
//static int getNewIdAlquiler();
//static int setNewIdCliente(int id);
//static int setNewIdRelacion(int idRelacion);
//static int getNewIdRelacion();


static ArrayList* nominaAlquileres;
static int proximoIdAlquiler=0;
static int getNewIdAlquiler();
static int setNewIdAlquiler(int idAlquiler);

/*static ArrayList* nominaClientes;
static int proximoIdRelacion=0;
static int getNewIdRelacion();
static int setNewIdRelacion(int idRelacion);
*/
void cont_init()
{
    nominaClientes = al_newArrayList();
    nominaAlquileres = al_newArrayList();
  //  nominaInscriptos = al_newArrayList();

    setNewIdCliente(dm_readAllClientes(nominaClientes)+1);
    setNewIdAlquiler(dm_readAllAlquileres(nominaAlquileres)+1);
    //setNewId(/*dm_readAll(nominaSocios) + 1*/);

    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaCliente (char* nombre,char* apellido,char* dni, int estado)
{
    eCliente* auxCliente;
    auxCliente = eCliente_new(getNewIdCliente(), nombre,apellido, estado, dni);
    al_add(nominaClientes,auxCliente);
    dm_saveAll(nominaClientes);
    return 0;
}

int cont_altaAlquiler (int* idCliente, int* idEquipo, int* idOperador, int* tiempoEstimado, int* tiempoReal, int* estado)
{
    Alquiler* auxAlquiler;
    auxAlquiler = alquiler_new(getNewIdAlquiler(),idCliente,idEquipo,idOperador,tiempoEstimado,tiempoReal,estado);
    al_add(nominaAlquileres,auxAlquiler);
    dm_saveAllAlquileres(nominaAlquileres);
    return 0;
}

/*int cont_altaRelacion (int* idRelacion, int* idSocio, int* idServicio)
{
   /* int retorno=-1;

    RelacionSS* auxRelacion;
    if ( relSS_findByIdSocioServicio(auxRelacion,idSocio,idServicio) == NULL)
    {
    auxRelacion = relSS_new(idRelacion,idSocio,idServicio,RELACION_ESTADO_ACTIVO);
    al_add(nominaInscriptos,auxRelacion);
    dm_saveAllRelacion(nominaInscriptos);
    retorno=0;
    }
    else
    {
       retorno=-2;
    }
    return retorno;
}*/




int cont_bajaCliente (int id)
{
    eCliente* auxCliente;
    auxCliente=eCliente_findById(nominaClientes,id);
    if(auxCliente!=NULL)
    {
        eCliente_setEstado(auxCliente,CLIENTE_ESTADO_INACTIVO);
        dm_saveAllClientes(nominaClientes);
    }

    return 0;
}



int cont_bajaAlquileres(int id)
{
    Alquiler* auxAlquiler;
    auxAlquiler= alquiler_findById(nominaAlquileres,id);
    if(auxAlquiler!=NULL)
    {
        alquiler_setEstado(auxAlquiler,ALQUILER_ESTADO_INACTIVO);
        dm_saveAllAlquileres(nominaAlquileres);
    }

    return 0;
}




int cont_modificarCliente(char* nombre,char* apellido,char* dni, int id, int estado)
{
    eCliente* auxCliente;

    auxCliente=soc_findById(nominaClientes,id);

    if(auxCliente!=NULL)
    {
        eCliente_setNombre(auxCliente,nombre);
        eCliente_setApellido(auxCliente,apellido);
        eCliente_setDni(auxCliente,dni);
        eCliente_setEstado(auxCliente,estado);
        dm_saveAllClientes(nominaClientes);
    }

    return 0;
}


int cont_listarClientes ()
{
    vista_mostrarClientes(nominaClientes);
    return 0;
}


int cont_listarAlquileres ()
{
    vista_mostrarAlquileres(nominaAlquileres);
    return 0;
}

//SETTER-GETTER ID SOCIO
static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}

//SETTTER-GETTER ID SERVICIO
static int getNewIdAlquiler()
{
    return proximoIdAlquiler++;
}

static int setNewIdAlquiler(int id)
{
    proximoIdAlquiler = id;
    return 0;
}


//SETTER-GETTER ID RELACION


/*static int getNewIdRelacion()
{
   // return proximoIdRelacion++;
}*/

/*static int setNewIdRelacion(int idRelacion)
{
    //proximoIdRelacion = idRelacion;
    return 0;
}*/


