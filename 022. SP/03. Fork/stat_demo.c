#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h> 
#include <time.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <sys/sysmacros.h>

int main(int argc, char* argv[]){
    static struct stat stat_buffer; 
    int sys_ret; 

    if(argc != 2){
        printf("UsageError:%s path_name\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    sys_ret = stat(argv[1], &stat_buffer); 
    if(sys_ret == -1){
        printf("stat:%s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    printf("Device Number Containing File:%lx,%lx\n", (long)major(stat_buffer.st_dev), (long)minor(stat_buffer.st_dev)); 
    printf("Inode number of file:%lu\n", stat_buffer.st_ino); 
    printf("Size of file:%lu\n", stat_buffer.st_size); 
    printf("Number of hard links:%lu\n", stat_buffer.st_nlink); 
    printf("Owner UID:%u\n", stat_buffer.st_uid); 
    printf("Owner GID:%u\n", stat_buffer.st_gid); 
    printf("Size in bytes:%lu\n", stat_buffer.st_size); 
    printf("Logical block size:%lu\n", stat_buffer.st_blksize); 
    printf("Number of sectors:%lu\n", stat_buffer.st_blocks); 
    printf("Last access time:%s", ctime(&stat_buffer.st_atim.tv_sec));     
    printf("Last modification time:%s", ctime(&stat_buffer.st_mtim.tv_sec)); 
    printf("Last status change time:%s", ctime(&stat_buffer.st_ctim.tv_sec)); 
    printf("Type of the file\n"); 
    switch(stat_buffer.st_mode & S_IFMT){
        case S_IFREG: 
            puts("Regular file"); 
            break; 
        case S_IFDIR: 
            puts("Directory file"); 
            break; 
        case S_IFCHR: 
            puts("Character special device file"); 
            break; 
        case S_IFBLK: 
            puts("Block special device file"); 
            break; 
        case S_IFLNK: 
            puts("Symbolic link file"); 
            break; 
        case S_IFIFO: 
            puts("FIFO file"); 
            break; 
        case S_IFSOCK: 
            puts("Socket file"); 
            break; 
    }
    printf("Permissions of the file\n"); 
    if(stat_buffer.st_mode & S_IRUSR) 
        puts("Owner read"); 
    if(stat_buffer.st_mode & S_IWUSR) 
        puts("Owner write"); 
    if(stat_buffer.st_mode & S_IXUSR) 
        puts("Owner execute"); 
    if(stat_buffer.st_mode & S_IRGRP) 
        puts("Group read"); 
    if(stat_buffer.st_mode & S_IWGRP) 
        puts("Group write"); 
    if(stat_buffer.st_mode & S_IXGRP) 
        puts("Group execute"); 
    if(stat_buffer.st_mode & S_IROTH) 
        puts("Other read"); 
    if(stat_buffer.st_mode & S_IWOTH) 
        puts("Other write"); 
    if(stat_buffer.st_mode & S_IXOTH) 
        puts("Other execute"); 
    if(stat_buffer.st_mode & S_ISUID) 
        puts("Set UID bit on"); 
    if(stat_buffer.st_mode & S_ISGID) 
        puts("Set GID bit on"); 
    if(stat_buffer.st_mode & S_ISVTX) 
        puts("Sticky bit on"); 
    
    return (EXIT_SUCCESS); 
}

/* 
void test(void){
    dev_t x; 
    ino_t y; 
    nlink_t z; 
    uid_t u1; 
    gid_t u2; 
    off_t u3; 
    blksize_t u4; 
    blkcnt_t u5; 
}
*/ 