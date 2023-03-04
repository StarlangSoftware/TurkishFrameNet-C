//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#ifndef FRAMENET_FRAME_H
#define FRAMENET_FRAME_H

#include <ArrayList.h>

struct frame {
    char *name;
    Array_list_ptr lexical_units;
    Array_list_ptr frame_elements;
};

typedef struct frame Frame;
typedef Frame *Frame_ptr;

Frame_ptr create_frame(char *name);

void free_frame(Frame_ptr frame);

bool frame_lexical_unit_exists(Frame_ptr frame, char *synSetId);

char *get_lexical_unit(Frame_ptr frame, int index);

char *get_frame_element(Frame_ptr frame, int index);

int lexical_unit_size(Frame_ptr frame);

int frame_element_size(Frame_ptr frame);

void add_lexical_unit(Frame_ptr frame, char *lexical_unit);

void add_frame_element(Frame_ptr frame, char *frame_element);

#endif //FRAMENET_FRAME_H
