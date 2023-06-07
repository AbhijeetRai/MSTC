#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define VENUE_LENGTH    128
#define NAME_LENGTH     128 

struct Stats {

    int score; 
    char highest_score_venue[VENUE_LENGTH];
};

struct player {

    int jersey; 
    char name[NAME_LENGTH];
    struct Stats highest_score;
};

int main(void) {

    struct player jordan; 
    jordan.jersey = 7; 
    strncpy(jordan.name, "Jordan", strlen("JORDAN"));
    jordan.highest_score.score  = 181; 
    strncpy(jordan.highest_score.highest_score_venue, "Sri Lanka", strlen("Sri lanks"));
    printf("%d %s %d %s\n", jordan.jersey, jordan.name, jordan.highest_score.score, jordan.highest_score.highest_score_venue);
    return 0;
}