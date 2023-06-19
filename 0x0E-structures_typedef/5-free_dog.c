#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Releases space used by a dog struct.
 * @d: A dog struct to be freed from memomry.
 *
 * Return: Nothing.
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->owner);
		free(d->name);
		free(d);
		d->owner = NULL;
		d->name = NULL;
		d = NULL;
	}
}
