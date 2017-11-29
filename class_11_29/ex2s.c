//<리눅스 서버 프로그램>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFSIZE 1024
void error_handling(char *message)
{
        fputs(message, stderr);
        fputc('\n', stderr);
        exit(1);
}
int main(int argc, char *argv[])
{
        int serv_sock;
        int clnt_sock;
		char message[BUFSIZE];
		int str_len;

        struct sockaddr_in serv_addr;
	    struct sockaddr_in clnt_addr;
        int clnt_addr_size;
 
 
        if (argc != 2) {
               printf("Usage : %s <port>\n", argv[0]);
               exit(1);
        }
       serv_sock = socket(PF_INET, SOCK_STREAM, 0); //socket 함수호출을 통해서 소켓을 생성
		if (serv_sock == -1)
               error_handling("socket() error");        
 
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_addr.sin_port = htons(atoi(argv[1]));
 
        if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) //bind 함수호출을 통해서 IP주소와 PORT번호를 할당
               error_handling("bind() error");
 
        if (listen(serv_sock, 5) == -1) //listen 함수를 호출, 이로써 소켓은 연결요청을 받아들일 수 있는 상태
               error_handling("listen() error");
		while(1)
		{
			clnt_addr_size = sizeof(clnt_addr);
			clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size); //연결요청의 수락을 위한 accept함수 호출
			//연결요청이 없는 상태에서 이함수가 호출되면, 연결요청이 있을 때까지 함수는 반환하지 않는다
			if (clnt_sock == -1)
				error_handling("accept() error");
	
			//데이터 수신 및 전송
			while((str_len=read(clnt_sock,message,BUFSIZE))!=0){
				write(clnt_sock,message,str_len);
				write(1,message,str_len);
			}
			close(clnt_sock);
		}
        
        return 0;
}
 
