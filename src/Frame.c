//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <HashMap/HashMap.h>
#include <Memory/Memory.h>
#include "Frame.h"

Frame_ptr create_frame(const char *name) {
    Frame_ptr result = malloc_(sizeof(Frame), "create_frame");
    result->name = str_copy(result->name, name);
    result->frame_elements = create_array_list();
    result->lexical_units = create_array_list();
    return result;
}

void free_frame(Frame_ptr frame) {
    free_array_list(frame->frame_elements, free_);
    free_array_list(frame->lexical_units, free_);
    free_(frame->name);
    free_(frame);
}

bool frame_lexical_unit_exists(const Frame* frame, const char *synSetId) {
    return array_list_contains(frame->lexical_units, synSetId, (int (*)(const void *, const void *)) compare_string);
}

char *get_lexical_unit(const Frame* frame, int index) {
    return array_list_get(frame->lexical_units, index);
}

char *get_frame_element(const Frame* frame, int index) {
    return array_list_get(frame->frame_elements, index);
}

int lexical_unit_size(const Frame* frame) {
    return frame->lexical_units->size;
}

int frame_element_size(const Frame* frame) {
    return frame->frame_elements->size;
}

void add_lexical_unit(Frame_ptr frame, const char *lexical_unit) {
    char* added = str_copy(added, lexical_unit);
    array_list_add(frame->lexical_units, added);
}

void add_frame_element(Frame_ptr frame, const char *frame_element) {
    char* added = str_copy(added, frame_element);
    array_list_add(frame->frame_elements, added);
}
