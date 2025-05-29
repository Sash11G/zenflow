#ifndef TRANSFER_H
#define TRANSFER_H

int send_text_file(int sock, const char *filename);
int receive_text_file(int sock, const char *filename);
char *get_available_filename(const char *filename);

#endif
