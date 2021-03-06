#ifndef _ACODEC_OMX_H
#define _ACODEC_OMX_H

#include "codec.h"
#include "omx_utils.h"

void acodec_omx_init(struct codec_t* codec, struct omx_pipeline_t* pipe);
void acodec_omx_add_to_queue(struct codec_t* codec, struct packet_t* packet);

#endif
