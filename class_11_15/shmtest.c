#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#define KEY 0x10
#define PERM 0660
#define SIZE 20

int main() {  int shmid;
char *memptr;
/* 공유메모리 만들기 */
if((shmid= shmget(KEY, SIZE, PERM|IPC_CREAT|IPC_EXCL)) < 0) {  perror("shmget error");
exit(1);
}
/* 현재 실행프로세스에서 공유메모리로 연결, memptr에는 공유 메모리의 시작 주소 반환 */  if((memptr= shmat(shmid, (char *)0, 0)) == (char *)(-1)) {
perror("shmat error");  exit(1);
}

/* 공유메모리의 주소에 문자열 테스트 */  strcpy(memptr, "Linux is Best!");
printf("shmkey = %d, shmid = %d\n", KEY, shmid);  printf("memptr = %p : %s\n", memptr, memptr);
sleep(1);
printf("\nAfter shmget...\n");
system("ipcs -m");  if(shmdt(memptr) < 0) {
perror("shmdt error");  exit(1);
}
/* 공유메모리 제어 (제거하기) */
if(shmctl(shmid, IPC_RMID, (struct shmid_ds *)0) < 0) {
perror("shmctl error");  exit(1);
}
printf("\nAfter remove...\n");  system("ipcs -m");
}
