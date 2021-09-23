#include<time.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<string.h> 
#include<netinet/in.h> 
#include<netdb.h>
intmain(intargc,char*argv[]) 
{ 
intsd,ad; 
charbuff[1024]; 
structsockaddr_inservaddr,cliaddr; 
time_tt1; 
bzero(&servaddr,sizeof(servaddr)); 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=htonl(INADDR_ANY); servaddr.sin_port=htons(1550); 
sd=socket(AF_INET,SOCK_STREAM,0); 
bind(sd,(structsockaddr*)&servaddr,sizeof(servaddr)); listen(sd,5); 
printf("Serverisrunning…\n"); 
while(1) 
{ 
ad=accept(sd,(structsockaddr*)NULL,NULL); bzero(&buff,sizeof(buff)); 
t1=time(NULL); 
snprintf(buff,sizeof(buff),"%24s\r\n",ctime(&t1)); send(ad,buff,sizeof(buff),0); 
} 
}
