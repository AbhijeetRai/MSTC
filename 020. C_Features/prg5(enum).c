extern int printf(const char* fmt, ...);

typedef enum csk {
    msd = 7,
    raina, 
    bravo = 48
}csk;

int main(void) {
    csk player1 = msd;
    csk player2 = raina; 
    printf("%d %d\n", player1, player2);

    if (player2 == 8) {
        printf("raina is 8");
    }

    return (0);
}