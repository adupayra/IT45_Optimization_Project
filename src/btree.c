#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "btree.h"
#include "constants.h"

void add_child(Arbre *arbre, Solution value, int side)
{
	if(arbre != NULL)
	{
		Arbre *child = NULL;
		if(side == 0)
			child = &((*arbre)->leftchild);
		else
			child = &((*arbre)->rightchild);
		
		(*child) = malloc(sizeof(Node));
		(*child)->solution = NULL;
		(*child)->leftchild = NULL;
		(*child)->rightchild = NULL;
		create_from_solution(&(*child)->solution, value);

	}
}

void delete_arbre(Arbre arbre)
{
	if(arbre == NULL)
	{
		return;
	}
	delete_arbre(arbre->leftchild);
	delete_arbre(arbre->rightchild);
	for(int i = 0; i < NBR_INTERFACES; i++)
	{
		for(int j = 0; j < 6; j++)
		{

		    clean_intarray(&arbre->solution->interface[i].formation[j]);
		}

	}


	free(arbre->solution);
	free(arbre);

}


int find_last_floor(Arbre arbre, Solution *pop, int index)
{
	if(arbre->leftchild == NULL)
	{
		pop[index] = *(arbre->solution);
		for(int i = 0; i < NBR_INTERFACES; i++)
		{
			for(int j = 0; j < 6; j++)
			{
				init_intarray(&(pop[index].interface[i].formation[j]));
				if(arbre->solution->interface[i].formation[j].size > 0)
				{
					
					pop[index].interface[i].formation[j].size = arbre->solution->interface[i].formation[j].size;
			    		pop[index].interface[i].formation[j].int_array = malloc(arbre->solution->interface[i].formation[j].size * sizeof(int));
			    		for(int p = 0; p < pop[index].interface[i].formation[j].size; p++)
					{
		    				pop[index].interface[i].formation[j].int_array[p] = arbre->solution->interface[i].formation[j].int_array[p];
					}
				}
			}
		}
		index++;
		return index;
	}
	index = find_last_floor(arbre->leftchild, pop, index);
	index = find_last_floor(arbre->rightchild, pop, index);
	return index;

}

void print_arbre(Arbre arbre)
{
	if(arbre == NULL)
		return;
	print_solution(*(arbre->solution));
	print_arbre(arbre->leftchild);
	print_arbre(arbre->rightchild);
}
