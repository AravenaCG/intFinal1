#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "eCliente.h"

eCliente* eCliente_new(int id,char* nombre,char* apellido,int estado,char* dni)
{
        eCliente* this = malloc(sizeof(eCliente));

        if(this != NULL)
        {

                eCliente_setId(this,id);
                eCliente_setNombre(this,nombre);
                eCliente_setApellido(this,apellido);
                eCliente_setEstado(this,estado);
                eCliente_setDni(this,dni);
        }
        return this;
}

void eCliente_delete(eCliente* this)
{
        free(this);
}

int eCliente_setId(eCliente* this,int id)
{
        this->id = id;
        return 0;
}

int eCliente_setNombre(eCliente* this,char* nombre)
{
        strcpy(this->nombre,nombre);
        return 0;
}

int eCliente_setApellido(eCliente* this,char* apellido)
{
        strcpy(this->apellido,apellido);
        return 0;
}

int eCliente_setEstado(eCliente* this,int estado)
{
        this->estado = estado;
        return 0;
}

int eCliente_setDni(eCliente* this,char* dni)
{
        strcpy(this->dni,dni);
        return 0;
}

int eCliente_getId(eCliente* this)
{
        return this->id;
}

char* eCliente_getNombre(eCliente* this)
{
        return this->nombre;
}

char* eCliente_getApellido(eCliente* this)
{
        return this->apellido;
}

int eCliente_getEstado(eCliente* this)
{
        return this->estado;
}

char* eCliente_getDni(eCliente* this)
{
        return this->dni;
}

eCliente* eCliente_findById(ArrayList* pArray,int id)
{

        int i;
        eCliente* aux;
        eCliente* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(id == eCliente_getId(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

eCliente* eCliente_findByNombre(ArrayList* pArray,char* nombre)
{

        int i;
        eCliente* aux;
        eCliente* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(nombre,eCliente_getNombre(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

eCliente* eCliente_findByApellido(ArrayList* pArray,char* apellido)
{

        int i;
        eCliente* aux;
        eCliente* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(apellido,eCliente_getApellido(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

eCliente* eCliente_findByEstado(ArrayList* pArray,int estado)
{

        int i;
        eCliente* aux;
        eCliente* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(estado == eCliente_getEstado(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

eCliente* eCliente_findByDni(ArrayList* pArray,char* dni)
{

        int i;
        eCliente* aux;
        eCliente* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(dni,eCliente_getDni(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}



********************* eCliente.c ************************
