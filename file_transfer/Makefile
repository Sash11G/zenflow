
CC = gcc
CFLAGS = -Wall -Iinclude -pthread
SRC = server
OBJ = obj

OBJS = common/transfer.c $(SRC)/linux_socket_utils.c $(SRC)/server_menu.c $(SRC)/server.c $(SRC)/linux_socket_utils.h $(SRC)/server_menu.h include/config.h include/server_menu.h 

server: $(OBJS)
	$(CC) $(CFLAGS) -o server_exe $(OBJS)

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC)/*.o server
