#pragma once

#include<iostream>
#include<string>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
using namespace std;


class Server{
public:
	Server(string _ip = "127.0.0.1" ,short _port = 8080) : port(_port),ip(_ip),sockfd(-1)
	{

	}

	void InitServer()
	{
		sockfd = socket(AF_INTE, SOCK_DGRAM,0); // 创建一个socket
		if(sockfd < 0){
		  cerr<<"socket error..."<<endl;
		  exit(2);
		}

		struct sockaddr_in local;
		local.

	}

	~Server()
	{

	}

private:
	short port; //端口号
	string ip; //IP
	int sockfd;//文件描述符
};


