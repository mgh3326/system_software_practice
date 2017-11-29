//<리눅스 클라이언트 프로그램>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFSIZE 1024
void error_handling(char *message);
 
int main(int argc, char* argv[])
{
        int sock;
        char message[BUFSIZE];
        int str_len;
        struct sockaddr_in serv_addr;

        if (argc != 3) {
               printf("Usage : %s <IP> <port>\n", argv[0]);
               exit(1);
        }
 
        sock = socket(PF_INET, SOCK_STREAM, 0); //소켓을 생성
        //소켓을 생성하는 순간에는 서버 소켓과 클라이언트 소켓으로 나누어지지 않는다.
        //bind, listen 함수의 호출이 이어지면 서버 소켓이 되는 것이고, connect 함수의 호출로 이어지면 클라이언트 소켓이 되는 것이다
        if (sock == -1)
               error_handling("socket() error");
 
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
        serv_addr.sin_port = htons(atoi(argv[2]));
 
        if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) //connect 함수호출을 통해서 서버프로그램에 연결을 요청
               error_handling("connect() error!");
        while(1)
        {
            //메세지 입력, 전송
            fputs("전송할 메세지를 입력하세요 (q to quit) : ",stdout);
            fgets(message,BUFSIZE,stdin);

            if(!strcmp(message,"q\n"))break;
            write(sock,message,strlen(message));

            //메세지 수신, 출력
            str_len=read(sock,message,BUFSIZE-1);
            message[str_len]=0;
            printf("서버로부터 전송된 메세지 : %s \n",message);
        }
        close(sock);//q를 받으면 socket을 닫지만 SIGINT로 받으면 소켓을 닫지 않는다는것을 알아두어야겠다.
        return 0;
}
 
void error_handling(char *message)
{
        fputs(message, stderr);
        fputc('\n', stderr);
        exit(1);
}