#pragma once

#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
using namespace std;

class Client{
public:
	Client(string _peer_ip= "127.0.0.1",short _peer_port=8080)
		:sockfd(-1),peer_ip(_peer_ip),peer_port(_peer_port)
	{}

    void InitClient()
	{
		sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd < 0){
			cerr<<"socket error..."<<endl;
			exit(2);
		}
	}

	void Run()
	{
		string msg;
		struct sockaddr_in server;
		server.sin_family = AF_INET;
		server.sin_port = htons(peer_port);
		server.sin_addr.s_addr = inet_addr(peer_ip.c_str());

		socklen_t len = sizeof(server);

		while(1)
		{
			cout<<"请输入你要发送的消息："<<endl;
			cin>>msg;
			sendto(sockfd, msg.c_str(), msg.size(), 0, (struct sockaddr*)&server,len);
		}
	}

	~Client()
	{
		if(sockfd >= 0){
			close(sockfd);
		}
	}
private:
	int sockfd;
	string peer_ip;
	short peer_port;
};
