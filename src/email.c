#include "email.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <curl/curl.h>

#define from "Esprit.Smart.SP@gmail.com"
#define pw "cH#dCCqP[*@y}}2H"

char subjectg[1000],tog[1000],bodyg[2000];
char *payload_text[] = {

  tog,
  "From: " "Esprit Smart" "\r\n",
  "Cc: " "service esprit mail" "\r\n",
  subjectg ,
  "\r\n",
};

int j=0;
/*
struct upload_status {
  int lines_read;
};*/

  char flag[100];
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;

  if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
    return 0;
  }
if (j == 5){

    strcpy(flag,bodyg);
  payload_text[5] = flag;
  }
if (j == 6){
  payload_text[6] = NULL;}
  data = payload_text[j];
  if(data) {
    size_t len = strlen(data);
    memcpy(ptr, data, len);
    upload_ctx->lines_read++;
    j++;

    return len;
  }

  return 0;
}


void send_email(char email[],char to[],char subject[] ,char body[])
{
strcpy(tog,to);
strcpy(bodyg,body);
strcpy(subjectg,subject);
j=0;
  CURL *curl;
  CURLcode res = CURLE_OK;
  struct curl_slist *recipients = NULL;
  struct upload_status upload_ctx;
  upload_ctx.lines_read = 0;

  curl = curl_easy_init();
  if(curl) {

    curl_easy_setopt(curl, CURLOPT_USERNAME, from);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, pw);

    curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");

    curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);

    recipients = curl_slist_append(recipients, email);

    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

    curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);

    curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);
/*
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
    else
*/

    curl_slist_free_all(recipients);

    curl_easy_cleanup(curl);
  }
}
