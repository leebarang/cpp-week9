CC = g++
CFLAGS = -g -Wall -Werror -std=c++11

# Object files
OBJS = simulator.o object.o echo_service_installer.o service_installer.o link_installer.o manual_router.o message_service_installer.o message_service.o echo_service.o link.o host.o router.o node.o

all: first second third forth

first: first.o $(OBJS)
	$(CC) $(CFLAGS) -o first first.o $(OBJS)

second: second.o $(OBJS)
	$(CC) $(CFLAGS) -o second second.o $(OBJS)

third: third.o $(OBJS)
	$(CC) $(CFLAGS) -o third third.o $(OBJS)

forth: forth.o $(OBJS)
	$(CC) $(CFLAGS) -o forth forth.o $(OBJS)

first.o: scenarios/first.cpp
	$(CC) $(CFLAGS) -c scenarios/first.cpp

second.o: scenarios/second.cpp
	$(CC) $(CFLAGS) -c scenarios/second.cpp

third.o: scenarios/third.cpp
	$(CC) $(CFLAGS) -c scenarios/third.cpp

forth.o: scenarios/forth.cpp
	$(CC) $(CFLAGS) -c scenarios/forth.cpp

simulator.o: simulator.cpp
	$(CC) $(CFLAGS) -c simulator.cpp simulator.h

object.o: object.cpp
	$(CC) $(CFLAGS) -c object.cpp

service_installer.o: service_installer.cpp service_installer.h
	$(CC) $(CFLAGS) -c service_installer.cpp

host.o: host.cpp host.h
	$(CC) $(CFLAGS) -c host.cpp

router.o: router.cpp router.h
	$(CC) $(CFLAGS) -c router.cpp

link.o: link.cpp link.h
	$(CC) $(CFLAGS) -c link.cpp

link_installer.o: link_installer.cpp link_installer.h
	$(CC) $(CFLAGS) -c link_installer.cpp

message_service.o: message_service.cpp message_service.h
	$(CC) $(CFLAGS) -c message_service.cpp

message_service_installer.o: message_service_installer.cpp message_service_installer.h
	$(CC) $(CFLAGS) -c message_service_installer.cpp

echo_service.o: echo_service.cpp echo_service.h
	$(CC) $(CFLAGS) -c echo_service.cpp

echo_service_installer.o: echo_service_installer.cpp echo_service_installer.h
	$(CC) $(CFLAGS) -c echo_service_installer.cpp

manual_router.o: manual_router.cpp manual_router.h
	$(CC) $(CFLAGS) -c manual_router.cpp

node.o: node.cpp node.h
	$(CC) $(CFLAGS) -c node.cpp

clean:
	rm -f *.o *.exe first second third forth