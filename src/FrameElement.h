//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#ifndef FRAMENET_FRAMEELEMENT_H
#define FRAMENET_FRAMEELEMENT_H

struct frame_element{
    char* frame_element_type;
    char* frame;
    char* id;
};

typedef struct frame_element Frame_element;
typedef Frame_element* Frame_element_ptr;

Frame_element_ptr create_frame_element(char* frame_element_type, char* frame, char* id);
Frame_element_ptr create_frame_element2(char* frame_element);
void free_frame_element(Frame_element_ptr frame_element);

#endif //FRAMENET_FRAMEELEMENT_H
