//Code to understand command line arguments 

/*int main(int argc, char* argv[]) {

    for(int i = 0; i < argc; i+=1) 
        printf("%s\n", argv[i]);
}*/

int main(int argc, char** argv) {

    for(int i = 0; i < argc; i+=1) 
        printf("%s\n", argv[i]);
}