#include "Codexion.h"

int shared = 0;
pthread_mutex_t mutex;

void    *routine(void *tmp)
{
    t_coders *coder = tmp;
    printf("coder%d started\n", coder->id);
    int i = 0;
    while (i++ < 1000000)
    {
        pthread_mutex_lock(&mutex);
        shared++;
        pthread_mutex_unlock(&mutex);
    }
    mssleep(1000);
    printf("coder%d finished\n", coder->id);
}

void attend(t_coders *coders, int nb)
{
    int i = 0;
    while (i < nb)
        pthread_join(coders[i++].t, NULL);
}

void    create_threads(t_data data)
{
    t_coders *coders = malloc(sizeof(t_coders) * data.number_of_coders);
    pthread_mutex_init(&mutex, NULL);
    int i = 0;
    while (i < data.number_of_coders)
    {
        coders[i].id = i+1;
        pthread_create(&coders[i].t, NULL, routine, &coders[i]);
        i++;
    }
    attend(coders, data.number_of_coders);
    printf("%d\n", shared);
}
