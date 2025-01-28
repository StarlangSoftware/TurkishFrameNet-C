//
// Created by Olcay Taner YILDIZ on 28.01.2025.
//

#ifndef FRAMEELEMENTLIST_H
#define FRAMEELEMENTLIST_H

#include <ArrayList.h>

struct frame_element_list {
    Array_list_ptr frame_elements;
};

typedef struct frame_element_list Frame_element_list;
typedef Frame_element_list *Frame_element_list_ptr;

Frame_element_list_ptr create_frame_element_list(const char* frame_element_list);

void free_frame_element_list(Frame_element_list_ptr frame_element_list);

char* frame_element_list_to_string(Frame_element_list_ptr frame_element_list);

void update_connected_id_in_frame_element_list(Frame_element_list_ptr frame_element_list, const char *previous_id, const char *current_id);

void add_predicate_to_frame_element_list(Frame_element_list_ptr frame_element_list, const char *predicate_id);

void remove_predicate_from_frame_element_list(Frame_element_list_ptr frame_element_list);

bool contains_predicate_in_frame_element_list(Frame_element_list_ptr frame_element_list);

bool contains_predicate_with_id_in_frame_element_list(Frame_element_list_ptr frame_element_list, const char *predicate_id);

Array_list_ptr get_frame_elements_in_frame_element_list(Frame_element_list_ptr frame_element_list);

bool contains_argument_in_frame_element_list(Frame_element_list_ptr frame_element_list, const char* frame_element_type, const char* frame, const char *id);

#endif //FRAMEELEMENTLIST_H
