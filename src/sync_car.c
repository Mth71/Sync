#include "sync_car.h"

void station_init(struct station *station){
    pthread_mutex_init(&station->lock, NULL);
    pthread_cond_init(&station->carAvailable, NULL);
    pthread_cond_init(&station->allBoarded, NULL);

    station->waitingPassengers = 0;
    station->freeSeats = 0;
    station->boardingPassengers = 0;
}

void station_wait_for_car(struct station *station){
    pthread_mutex_lock(&station->lock);

    station->waitingPassengers += 1;

    while(station->freeSeats <= 0){
        pthread_cond_wait(&station->carAvailable, &station->lock);
    }

    station->waitingPassengers -= 1;
    station->freeSeats -= 1;
    station->boardingPassengers += 1;

    pthread_mutex_unlock(&station->lock);
}

void station_load_car(struct station *station, int count){


}




void station_on_board(struct station *station){
    
}