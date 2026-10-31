#include "sync_car.h"

void station_init(struct station *station){
    pthread_mutex_init(&station->lock, NULL);
    pthread_cond_init(&station->carAvailable, NULL);
    pthread_cond_init(&station->allBoarded, NULL);

    station->waitingPassengers = 0;
    station->freeSeats = 0;
    station->boardingPassengers = 0;


}


void station_load_car(struct station *station, int count){


}


void station_wait_for_car(struct station *station){


}


void station_on_board(struct station *station){
    
}