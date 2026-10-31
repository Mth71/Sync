#ifndef SYNC_CAR_H

#define SYNC_CAR_H

#include <pthread.h>

struct station{
    pthread_mutex_t lock; //lock unico, trava e destrava o lock
    pthread_cond_t carAvailable; // passageiros esperam carros com vaga, passageiro dorme
    pthread_cond_t allBoarded; // onde o carro espera o embarque terminar, carro dorme
    int waitingPassengers; //esperando passageiros
    int freeSeats; // assentos livres
    int boardingPassengers; // passageiros liberados que ainda nao chamaram on_board
};

void station_init(struct station *station);
void station_load_car(struct station *station, int count);
void station_wait_for_car(struct station *station);
void station_on_board(struct station *station);

#endif
