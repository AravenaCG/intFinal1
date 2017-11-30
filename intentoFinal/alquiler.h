#include "ArrayList.h"

#ifndef _ALQUILER_H_INCLUDED
#define _ALQUILER_H_INCLUDED
typedef struct
{
        int idCliente;
        int idEquipo;
        int idOperador;
        int tiempoEstimado;
        int tiempoReal;
        int estado;
        int idAlquiler;
}Alquiler;
#endif// _ALQUILER_H_INCLUDED
#define ALQUILER_ESTADO_INACTIVO 0
#define ALQUILER_ESTADO_ACTIVO 1
#define ARCHIVO_ALQUILERES "alquileres.txt"



Alquiler* alquiler_new(int idAlquiler, int idCliente,int idEquipo,int idOperador,int tiempoEstimado,int tiempoReal,int estado);
void alquiler_delete(Alquiler* this);
int alquiler_getIdAlquiler(Alquiler* this);
int alquiler_setIdAlquiler(Alquiler* this, int idAlquiler);
int alquiler_setIdCliente(Alquiler* this,int idCliente);
int alquiler_setIdEquipo(Alquiler* this,int idEquipo);
int alquiler_setIdOperador(Alquiler* this,int idOperador);
int alquiler_setTiempoEstimado(Alquiler* this,int tiempoEstimado);
int alquiler_setTiempoReal(Alquiler* this,int tiempoReal);
int alquiler_setEstado(Alquiler* this,int estado);
int alquiler_getIdCliente(Alquiler* this);
int alquiler_getIdEquipo(Alquiler* this);
int alquiler_getIdOperador(Alquiler* this);
int alquiler_getTiempoEstimado(Alquiler* this);
int alquiler_getTiempoReal(Alquiler* this);
int alquiler_getEstado(Alquiler* this);
Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente);
Alquiler* alquiler_findByIdEquipo(ArrayList* pArray,int idEquipo);
Alquiler* alquiler_findByIdOperador(ArrayList* pArray,int idOperador);
Alquiler* alquiler_findByTiempoEstimado(ArrayList* pArray,int tiempoEstimado);
Alquiler* alquiler_findByTiempoReal(ArrayList* pArray,int tiempoReal);
Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado);



