extern int printf(const char*, ...);

struct {
    int jersey; 
    char* name;
    char* team;
}play_arr[] = {{7, "Dhoni", "India"}, {10, "Sachin", "India"}};

int main(void) {

    printf("%d %s %s\n", play_arr[0].jersey, play_arr[1].name, play_arr[0].team);
    return (0);
}