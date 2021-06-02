#include <stdio.h>
#include <stdlib.h>
#include "dintegerarray.h"

void init_intarray(IntegerArray* array)
{
    array->int_array = (int*)malloc(sizeof(int) * 1);
	array->capacity = 1;
    array->size = 0;
    
}

void add_element_intarray(IntegerArray* a, int value)
{
    if(a != NULL)
    {
    	if(a->size == a->capacity)
    	{
    		a->capacity = a->capacity * 2;
        	a->int_array = realloc(a->int_array, a->capacity * sizeof(int));
        }
        a->size++;
        a->int_array[a->size-1] = value;
    }
}

void remove_element_intarray(IntegerArray* a, int value)
{
    if(a->size>0)
    {
    	int i = 0;
    	while(a->int_array[i] != value)
    		i++;
    	for(i = i; i < a->size - 1; i++)
    		a->int_array[i] = a->int_array[i+1];
        a->size--;
    }

}

void clean_intarray(IntegerArray* a)
{
    a->int_array = NULL;
    free(a->int_array);
}
