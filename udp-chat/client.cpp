//        CLIENT

#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> //for handeling file discriptors

using namespace std;


#define buflen 512
#define port 1234         //The port in which the connection has to be made to connect with the server.
#define ip "192.168.1.48" //Host address has to be entered here.

int main()
{

	int fd;
	fd= socket(AF_INET,SOCK_DGRAM,0); // Creating a socket with IPv4 protocal (AF_INET) for UDP (SOCK_DGRAM) communication.

	struct sockaddr_in serv,client;

	// Filling the socket address structure with rquired info.
	
	serv.sin_family =AF_INET; //IPv4
	serv.sin_port =htons(port); //host to network short
	serv.sin_addr.s_addr =INADDR_ANY; //Uses any address that is available.


	char buff[buflen];

	socklen_t l=sizeof(client);
	socklen_t m=sizeof(serv);

	while(1)
	{

		cout<<"You:";
		cin.getline(buff,buflen);
	
		sendto(fd,buff,sizeof(buff),0,(struct sockaddr *)&serv,m); //Snding the data through the socket to the server.
	
	
		recvfrom(fd,buff,256,0,(struct sockaddr *)&client,&l); //Recieving data which is being sent to the client.
		cout<<"ghost:"<<buff<<endl;
	}//while()
	
	
	close(fd); //Closing the file discrptor, i.e closing the socket using the file discriptor.

	return 0;

}//main()
