#pragma once

#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <string>

class Server {
public:
  Server();
  virtual ~Server();

  void run();

protected:
  virtual void create();
  virtual void close_socket();
  void serve();
  void handle(int);
  std::string get_request(int);
  bool send_response(int, std::string);

  int server_;
  int buflen_;
  char* buf_;
};
