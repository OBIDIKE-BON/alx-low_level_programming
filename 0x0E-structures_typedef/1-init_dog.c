#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Initializes a dog structure if @d is not null.
 * @d: A dog structure.
 * @name: Pointer to the name of the dog.
 * @age: The age of the dog.
 * @owner: Pointer to the owner of the dog.
 *
 * Return: Nothing
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
