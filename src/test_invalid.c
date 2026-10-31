#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "sync_car.h"
#include <string.h>

volatile int passengersReleased = 0;

void alarmWarning(int sig){ 
    fprintf(stderr, "travou: station_load_car não retornou (Sinal: %d)\n", sig);
    exit(1);
}

void *passageiro(void *arg){
    struct station *st = (struct station *) arg;
    station_wait_for_car(st);
    __sync_add_and_fetch(&passengersReleased, 1);
    return NULL;
}

int main(void){
    struct station station;
    station_init(&station);

    signal(SIGALRM, alarmWarning);

    // ---- Cenário 1: count negativo, estação vazia ----

    alarm(2);

    station_load_car(&station, -2); 

    alarm(0);

    printf("Cenário 1 (count negativo, estação vazia): OK\n");

    // ---- Cenário 2: count negativo, passageiros esperando ----

    pthread_t v[3];
    for(int i = 0;  i< 3; i++){
        int ret = pthread_create(&v[i], NULL, passageiro, &station);
        if(ret != 0){
            fprintf(stderr, "cenário 2: falha ao criar thread de passageiro: %s\n", strerror(ret));
            return 1;
        }
    }

    int esperando;
    do{
        pthread_mutex_lock(&station.lock);
        esperando = station.waitingPassengers;
        pthread_mutex_unlock(&station.lock);
        if(esperando < 3){
            usleep(1000);
        }
    }while(esperando < 3);

    alarm(2);
    station_load_car(&station, -5);
    alarm(0);

    usleep(100000);

    if(passengersReleased != 0){
        fprintf(stderr, "cenário 2: %d passageiro(s) embarcaram indevidamente\n", passengersReleased);
        return 1;
    }else{
        printf("Cenário 2 (count negativo, passageiros esperando): OK\n");
    }
    return 0;
}