#include<gtk/gtk.h>



void send_email(char email[],char to[],char subject[] ,char body[]);
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp);
struct upload_status{
int lines_read;};
