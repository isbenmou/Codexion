#include "Codexion.h"

void *function(void *ptr)
{
    
}

t_data create_threads(t_data data)
{
    t_coders *coders = malloc(sizeof(t_coders) * data.number_of_coders);
    int i = 0;
    while (i < data.number_of_coders)
    {
        pthread_create(&coders[i]->id, NULL, function, NULL);
        i++;
    }
    return data;
}
