
#include <time.h>
#include <stdio.h>
#include "cmu_tcp.h"

/*
 * Param: sock - used for reading and writing to a connection
 *
 * Purpose: To provide some simple test cases and demonstrate how 
 *  the sockets will be used.
 *
 */
    struct timeval time1;
    struct timeval time2;
void functionality(cmu_socket_t  * sock){
    char buf[9898];
    FILE *fp;
    int n;

    printf("[DEBUG] server start reading data from socket.\n");
    n = cmu_read(sock, buf, 200, NO_FLAG);
    printf("R: %s\n", buf);
    printf("N: %d\n", n);
    cmu_write(sock, "hi there", 9);
    cmu_read(sock, buf, 200, NO_FLAG);
    cmu_write(sock, "hi there", 9);

    sleep(5);
    n = cmu_read(sock, buf, 9898, NO_FLAG);
    printf("N: %d\n", n);
    fp = fopen("./test/file.c", "w+");
    fwrite(buf, 1, n, fp);
    // char buf[9898];
    // FILE *file_for_write;
    // // FILE *file_for_read;
    // int n;
 
    // int read = 1;
    // int total = 0;
    // file_for_read = fopen("./test/random.input","rb");
    // fseek(file_for_read,0,SEEK_END);
    // int len = ftell(file_for_read);
    // fseek(file_for_read,0,SEEK_SET);
    // cmu_write(sock,&len,4);

    // while(read > 0 ){
    //     read = fread(buf, 1, 2000, file_for_read);
    //     total = total + read;
    //     //printf("read from file  is %d total = %d len = %d\n", read,total,len);
    //     if(read > 0)
    //         cmu_write(sock, buf, read);
    // }
    // printf("read total = %d\n", total);
    // close(file_for_read);
    // total = 0;

    // gettimeofday(&time1,NULL);
    // long len2;
    // long total = 0;
    // n = 1;
    // cmu_read(sock,(char*) &len2,8,NO_FLAG);
    // printf("len = %d\n", (int)len2);
    // file_for_write = fopen("./test/f1.txt", "w+");
    // while(total  < len2 && n != 0){
    //     n = cmu_read(sock, buf, 2000, NO_FLAG);
    //     total = total + n;
    //     printf("n = %d,total = %d\n", n, (int)total);
    //     fwrite(buf, 1, n, file_for_write);
    // }
    // gettimeofday(&time2,NULL);

    // printf("get total = %d time = %d \n", (int)total,(int)(time1.tv_sec-time2.tv_sec + (time1.tv_usec-time2.tv_usec)/1000000));
    // close(file_for_write); 
}


/*
 * Param: argc - count of command line arguments provided
 * Param: argv - values of command line arguments provided
 *
 * Purpose: To provide a sample listener for the TCP connection.
 *
 */
int main(int argc, char **argv) {
	int portno;
    char *serverip;
    char *serverport;
    cmu_socket_t socket;
    
    serverip = getenv("server15441");
    if (serverip) ;
    else {
        serverip = "10.0.0.1";
    }

    serverport = getenv("serverport15441");
    if (serverport) ;
    else {
        serverport = "15441";
    }
    portno = (unsigned short)atoi(serverport);


    if(cmu_socket(&socket, TCP_LISTENER, portno, serverip) < 0)
        exit(EXIT_FAILURE);

    functionality(&socket); 
    if(cmu_close(&socket) < 0)
        exit(EXIT_FAILURE);

    return EXIT_SUCCESS;
}
