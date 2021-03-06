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


class Server{
public:
	Server(string _ip = "127.0.0.1" ,short _port = 8080) : port(_port),ip(_ip),sockfd(-1)
	{

	}

	void InitServer()
	{
		sockfd = socket(AF_INET, SOCK_DGRAM,0); // 创建一个socket
		if(sockfd < 0){
		  cerr<<"socket error..."<<endl;
		  exit(2);
		}

		struct sockaddr_in local;
		//初始化
		bzero(&local,sizeof(local));
		//填充信息
		local.sin_family = AF_INET;
	    local.sin_port = htons(port);
		local.sin_addr.s_addr = inet_addr(ip.c_str());//将10进制点分字符串IP转换成4字节IP

		//绑定
		if(bind(sockfd, (struct sockaddr*)&local, sizeof(local)) == 0){
			cout<<"Server run on"<<ip<<" : "<<port<<"...success."<<endl;
		} else {
		  cerr<<"bind error..."<<endl;
		  exit(3);
		}
	}

	//循环接受信息
	void Run()
	{
		char buf[1024];
		struct sockaddr_in peer;
		for(;;){
			socklen_t len = sizeof(peer);
			ssize_t size = recvfrom(sockfd,buf,sizeof(buf)-1,0,(struct sockaddr*)&peer,&len);
			if(size > 0){
				buf[size] = 0;
				cout<<"客户端#： "<<buf<<endl;
			}
		}
	}


	~Server()
	{
		if(sockfd >= 0)
		  close(sockfd);
	}

private:
	short port; //端口号
	string ip; //IP
	int sockfd;//文件描述符
};


