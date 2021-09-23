#include<stdio.h> 
#include<sys/types.h> 
#include<sys/socket.h> 
#include<netdb.h> 
#include<netinet/in.h>
#include<unistd.h> 
#include<time.h> 
#include<string.h> 
intmain(intargc,char*argv[]) 
{ 
intsd,ad; 
charbuff[1024]; 
structsockaddr_incliaddr,servaddr; 
structhostent*h; 
h=gethostbyname(argv[1]); 
bzero(&servaddr,sizeof(servaddr)); 
servaddr.sin_family=AF_INET; 
memcpy((char*)&servaddr.sin_addr.s_addr,h->h_addr_list[0],h->h_length); servaddr.sin_port=htons(1550); 
sd=socket(AF_INET,SOCK_STREAM,0); 
connect(sd,(structsockaddr*)&servaddr,sizeof(servaddr)); recv(sd,buff,sizeof(buff),0); 
printf("Daytimeofserveris:%s\n",buff); 
} 
