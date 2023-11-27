/**
 * To run this code, compile sender as "sudo su": gcc sender.c -o sender 
 * gcc receriver.c -o receiver 
 * Run sender (wait for it to finish the run). Then ./receiver
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include "command.h" 
//--------------------------------

#define 	PROJECT_ID	5
#define 	FILE_NAME	"common.txt" //this must exist on disk, even if empty
#define 	SLEEP_TIME	5 

struct command cmd; 

int main(void) {
	key_t key; 
	int msgid; 
	int ret_send; 
	
	//a key will be generated using the filename and the project id
	key = ftok(FILE_NAME, PROJECT_ID);
	msgid = msgget(key, IPC_CREAT);
	if(msgid == -1) {
		fprintf(stderr, "msgget:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	cmd.cmd_type = CMD_FILE_CREATE;
	memset(cmd.path_name, 0, MAX_PATH_LENGTH);
	strncpy(cmd.path_name, "test.txt", strlen("test.txt"));
	cmd.open_flag = O_RDWR | O_CREAT | O_TRUNC;
	cmd.permissions = 06444;

	ret_send = msgsnd(msgid, (void*)&cmd, sizeof(struct command), 0);
	if(ret_send == -1) {
		fprintf(stderr, "msgsnd:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	sleep(SLEEP_TIME);

	memset(&cmd, 0, sizeof(struct command)); 
	cmd.cmd_type = CMD_FILE_WRITE; 
	strncpy(cmd.path_name, "test.txt", strlen("test.txt")); 
	cmd.offset = 0; 
	cmd.size = 32; 

	ret_send = msgsnd(msgid, (void*)&cmd, sizeof(struct command), 0);
	if(ret_send == -1) {
		fprintf(stderr, "msgsnd:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	sleep(SLEEP_TIME);

	memset(&cmd, 0, sizeof(struct command)); 
	cmd.cmd_type = CMD_FILE_READ; 
	strncpy(cmd.path_name, "test.txt", strlen("test.txt")); 
	cmd.offset = 0; 
	cmd.size = 32;	

	ret_send = msgsnd(msgid, (void*)&cmd, sizeof(struct command), 0);
	if(ret_send == -1) {
		fprintf(stderr, "msgsnd:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	sleep(SLEEP_TIME);

	memset(&cmd, 0, sizeof(struct command)); 
	cmd.cmd_type = CMD_TERMINATE; 

	ret_send = msgsnd(msgid, (void*)&cmd, sizeof(struct command), 0);
	if(ret_send == -1) {
		fprintf(stderr, "msgsnd:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	sleep(SLEEP_TIME);
	
	if((msgid, IPC_RMID, NULL) == -1) {
		fprintf(stderr, "msgctl:%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}	

	exit(EXIT_SUCCESS);
}
