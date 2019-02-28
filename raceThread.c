#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <pthread.h>

void* raceTortoise(void *arg);
void* raceHare(void *arg);

 typedef struct {
    int id;
    int tInterval;
    double tMin;
    double tMax;
    double raceLength;
} tortoiseArgs;


int isWinner = 0;
pthread_mutex_t winnerLock = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char * argv[]) {
    // check argument number
    if(argc != 11) {
        printf("%s takes 10 paramters\n", argv[0]);
        return 1;
    }

    // parse the parameters 
    int tNum = atoi(argv[1]);
    double tMin = atof(argv[2]);
    double tMax = atof(argv[3]);
    int tInterval = atoi(argv[4]);
    int hNum = atoi(argv[5]);
    double hProb = atof(argv[6]);
    double hInterval = atof(argv[7]);
    double hMin = atof(argv[8]);
    double hMax = atof(argv[9]);
    double raceLength = atof(argv[10]);

    int racerCount = tNum + hNum;
    
    // check the min/max

    tortoiseArgs tArg[tNum];
    for(int i=0; i < tNum; i++) {
        tArg[i].id = i + 1;
        tArg[i].tMin = tMin;
        tArg[i].tMax = tMax;
        tArg[i].tInterval = tInterval;
        tArg[i].raceLength = raceLength;
    }

    printf("Racer\t\tSpeed\tDist.\tTotal Dist.\n");

    pthread_t threads[racerCount];
    for( int i = 0; i < racerCount; i++) {
        if( i < tNum ) {
            pthread_create( &threads[i], NULL, raceTortoise, (void *) &tArg[i]); )
        }
        else {
            pthread_create( &threads[i], NULL, raceHare, (void *)argument); )

        }
    }

    for( int = 0;i < racerCount; i++) {
        pthread_join( threads[i], NULL);
    }

    // 

    pthread_kill();


}


void* raceTortoise(void *arg) {

    // extract args

    //tortoiseArgs tArg =  *((tortoiseArgs*)arg);

    tortoiseArgs* tArg = (tortoiseArgs*)arg;

    double raceLength = tArg->raceLength;

    double totalDistance= 0;
    double rate;
    double distance;
    
    struct timespec ts;
    ts.tv_nsec = 1000000 * tInterval;

    while( totalDistance < raceLength ) {
        
        // sleep tInterval
        
        nanosleep( &ts, NULL );
        // update distance traveled
        // compute rate (random number bewteen tMin and tMax)
        // compute distance = rate * time 
        // add distance to totalDistance

        //print status
        printf("Tortoise %d\t\t%f\t%f\t%f\n", racerId, speed, distance, totalDistance);

    }

}

void* raceHare(void *arg){


}