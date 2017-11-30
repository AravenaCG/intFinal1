
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eCliente.h"
#include "alquiler.h"
#include "DataManager.h"


int dm_saveAllClientes(ArrayList* pArrayClientes)
{
    int i;
    int retorno=-1;
    FILE* pArchivoClientes=fopen(ARCHIVO_CLIENTES,"wb");
    void* pCliente=NULL;
    if(pArrayClientes!=NULL)
    {
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            pCliente=al_get(pArrayClientes,i);
            fwrite(pCliente,sizeof(eCliente),1,pArchivoClientes);
            retorno=0;
        }

    }
    fclose(pArchivoClientes);
    return retorno;
}



int dm_readAllClientes(ArrayList* pArrayAlquileres)
{
    int retorno=-1;
    Alquiler* auxAlquiler;
    int maxId=0;
    Alquiler* pAlquiler=NULL;
    FILE* pArchivoAlquileres=fopen(ARCHIVO_ALQUILERES,"rb");

    if(pArchivoAlquileres!=NULL)
    {
        do{
            if(fread(&auxAlquiler,sizeof(Alquiler),1,pArchivoAlquileres)==1)
            {
                pAlquiler=soc_new(auxAlquiler.nombre,auxAlquiler.apellido,auxAlquiler.dni,auxAlquiler.id,auxAlquiler.estado);
                al_add(pArraySocios,pAlquiler);
                if(auxAlquiler.id>maxId)
                {
                    maxId=auxAlquiler.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoAlquileres));
        fclose(pArchivoAlquileres);
    }
    return retorno;
}





int dm_saveAllServicios(ArrayList* pArrayServicios)
{
    int i;
    int retorno=-1;
    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"wb");
    void* pServicio=NULL;
    if(pArchivoServicios!=NULL)
    {
        for(i=0;i<al_len(pArrayServicios);i++)
        {
            pServicio=al_get(pArrayServicios,i);
            fwrite(pServicio,sizeof(Servicio),1,pArchivoServicios);
            retorno=0;
        }

    }
    fclose(pArchivoServicios);
    return retorno;
}



int dm_readAllServicios(ArrayList* pArrayServicios)
{
    int retorno=-1;
    Servicio auxServicio;
    int maxId=0;
    Servicio* pServicio=NULL;
    FILE* pArchivoServicio=fopen(ARCHIVO_SERVICIOS,"rb");

    if(pArchivoServicio!=NULL)
    {
        do{
            if(fread(&auxServicio,sizeof(Servicio),1,pArchivoServicio)==1)
            {
                pServicio=serv_new(auxServicio.descripcion,auxServicio.id,auxServicio.estado);
                al_add(pArrayServicios,pServicio);
                if(auxServicio.id>maxId)
                {
                    maxId=auxServicio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoServicio));
        fclose(pArchivoServicio);
    }
    return retorno;
}

