#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Alquiler.h"

Alquiler* alquiler_new(int idAlquiler, int idCliente,int idEquipo,int idOperador,int tiempoEstimado,int tiempoReal,int estado)
{
        Alquiler* this = malloc(sizeof(Alquiler));

        if(this != NULL)
        {

                alquiler_setIdCliente(this,idCliente);
                alquiler_setIdEquipo(this,idEquipo);
                alquiler_setIdOperador(this,idOperador);
                alquiler_setTiempoEstimado(this,tiempoEstimado);
                alquiler_setTiempoReal(this,tiempoReal);
                alquiler_setEstado(this,estado);
        }
        return this;
}

void alquiler_delete(Alquiler* this)
{
        free(this);
}

int alquiler_setIdCliente(Alquiler* this,int idCliente)
{
        this->idCliente = idCliente;
        return 0;
}

int alquiler_setIdEquipo(Alquiler* this,int idEquipo)
{
        this->idEquipo = idEquipo;
        return 0;
}

int alquiler_setIdOperador(Alquiler* this,int idOperador)
{
        this->idOperador = idOperador;
        return 0;
}

int alquiler_setTiempoEstimado(Alquiler* this,int tiempoEstimado)
{
        this->tiempoEstimado = tiempoEstimado;
        return 0;
}

int alquiler_setTiempoReal(Alquiler* this,int tiempoReal)
{
        this->tiempoReal = tiempoReal;
        return 0;
}

int alquiler_setIdAlquiler(Alquiler* this,int idAlquiler)
{
        this->idAlquiler = idAlquiler;
        return 0;
}


int alquiler_setEstado(Alquiler* this,int estado)
{
        this->estado = estado;
        return 0;
}

int alquiler_getIdCliente(Alquiler* this)
{
        return this->idCliente;
}

int alquiler_getIdEquipo(Alquiler* this)
{
        return this->idEquipo;
}

int alquiler_getIdOperador(Alquiler* this)
{
        return this->idOperador;
}

int alquiler_getTiempoEstimado(Alquiler* this)
{
        return this->tiempoEstimado;
}

int alquiler_getTiempoReal(Alquiler* this)
{
        return this->tiempoReal;
}

int alquiler_getIdAlquiler(Alquiler* this)
{
        return this->idAlquiler;
}

int alquiler_getEstado(Alquiler* this)
{
        return this->estado;
}

Alquiler* alquiler_findByIdCliente(ArrayList* pArray,int idCliente)
{

        int i;
        Alquiler* aux;
        Alquiler* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idCliente == alquiler_getIdCliente(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Alquiler* alquiler_findByIdEquipo(ArrayList* pArray,int idEquipo)
{

        int i;
        Alquiler* aux;
        Alquiler* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idEquipo == alquiler_getIdEquipo(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Alquiler* alquiler_findByIdOperador(ArrayList* pArray,int idOperador)
{

        int i;
        Alquiler* aux;
        Alquiler* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idOperador == alquiler_getIdOperador(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Alquiler* alquiler_findByTiempoEstimado(ArrayList* pArray,int tiempoEstimado)
{

        int i;
        Alquiler* aux;
        Alquiler* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(tiempoEstimado == alquiler_getTiempoEstimado(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Alquiler* alquiler_findByTiempoReal(ArrayList* pArray,int tiempoReal)
{

        int i;
        Alquiler* aux;
        Alquiler* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(tiempoReal == alquiler_getTiempoReal(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Alquiler* alquiler_findByEstado(ArrayList* pArray,int estado)
{

        int i;
        Alquiler* aux;
        Alquiler* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(estado == alquiler_getEstado(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}



