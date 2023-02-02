//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#ifndef FRAMENET_FRAMENET_H
#define FRAMENET_FRAMENET_H

#include <ArrayList.h>
#include "Frame.h"

struct frame_net{
    Array_list_ptr frames;
};

typedef struct frame_net Frame_net;
typedef Frame_net* Frame_net_ptr;

Frame_net_ptr create_frame_net();
void free_frame_net(Frame_net_ptr frame_net);
int frame_net_lexical_unit_exists(Frame_net_ptr frame_net, char* synSetId);
Array_list_ptr get_frames(Frame_net_ptr frame_net, char* synSetId);
int frame_size(Frame_net_ptr frame_net);
Frame_ptr get_frame(Frame_net_ptr frame_net, int index);

#endif //FRAMENET_FRAMENET_H
