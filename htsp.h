#ifndef _HTSP_H
#define _HTSP_H

struct htsp_t 
{
    struct sockaddr_in *remote;
    int sock;
    char* ip;
    char* host;
    int port;
    unsigned char challange[32];
};

struct htsp_message_t
{
    unsigned char* msg;
    int msglen;
};

#define HMF_STREAM_VIDEO 1
#define HMF_STREAM_AUDIO 2
#define HMF_STREAM_SUB 3

#define HMF_VIDEO_CODEC_MPEG2 1
#define HMF_VIDEO_CODEC_H264  2

#define HMF_AUDIO_CODEC_MPEG 1
#define HMF_AUDIO_CODEC_AAC  2

#define HMF_SUB_CODEC_DVBSUB  1

struct htsp_stream_t
{
  int index;
  int type;
  int codec;
  char lang[3];
};

struct htsp_subscription_t
{
  struct htsp_stream_t* streams;
  int numstreams;
  int videostream;
  int audiostream;
};


#define HMF_NULL 0
#define HMF_MAP  1
#define HMF_S64  2
#define HMF_STR  3
#define HMF_BIN  4
#define HMF_LIST 5
#define HMF_DBL  6

void htsp_dump_message(struct htsp_message_t* msg);
void htsp_destroy_message(struct htsp_message_t* msg);
int htsp_connect(struct htsp_t* htsp, char* host, int port);
int htsp_create_message(struct htsp_message_t* msg, ...);
int htsp_send_message(struct htsp_t* htsp, struct htsp_message_t* msg);
int htsp_recv_message(struct htsp_t* htsp, struct htsp_message_t* msg);
int htsp_login(struct htsp_t* htsp);
char* htsp_get_string(struct htsp_message_t* msg, char* name);
int htsp_get_int(struct htsp_message_t* msg, char* name, int* val);
int htsp_get_bin(struct htsp_message_t* msg, char* name, unsigned char** data,int* size);

int htsp_parse_subscriptionStart(struct htsp_message_t* msg, struct htsp_subscription_t*);

#endif
