/*********************************************************************
*
*   MODULE NAME:
*       wrap_malloc.c
*
*   DESCRIPTION:
*       Wraps the memory allocation and deallocation functions to call
*       the FreeRTOS versions so we don't have to maintain two heap
*       spaces.
*
* Copyright 2014 by Garmin Ltd. or its subsidiaries.
*
*********************************************************************/

#include <sys/reent.h>

#include "FreeRTOS.h"

void* __wrap__malloc_r( struct _reent* reent_ptr, size_t c )
{
    return pvPortMalloc( c );
}

void __wrap__free_r( struct _reent* reent_ptr, void* ptr )
{
    return vPortFree( ptr );
}

void* __wrap__realloc_r( struct _reent* reent_ptr, void* ptr, size_t c )
{
    void * rptr = pvPortMalloc( c );
    vPortFree( ptr );
    return rptr;
}

