//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#ifndef FRAMENET_FRAMENET_H
#define FRAMENET_FRAMENET_H

#include <ArrayList.h>
#include "Frame.h"

struct frame_net {
    Array_list_ptr frames;
};

typedef struct frame_net Frame_net;
typedef Frame_net *Frame_net_ptr;

Frame_net_ptr create_frame_net();

void free_frame_net(Frame_net_ptr frame_net);

bool frame_net_lexical_unit_exists(const Frame_net* frame_net, const char *synSetId);

Array_list_ptr get_frames(const Frame_net* frame_net, const char *synSetId);

int frame_size(const Frame_net* frame_net);

Frame_ptr get_frame(const Frame_net* frame_net, int index);

#endif //FRAMENET_FRAMENET_H
