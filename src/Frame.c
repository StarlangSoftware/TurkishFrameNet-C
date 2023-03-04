//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <HashMap/HashMap.h>
#include "Frame.h"

Frame_ptr create_frame(char *name) {
    Frame_ptr result = malloc(sizeof(Frame));
    result->name = str_copy(result->name, name);
    result->frame_elements = create_array_list();
    result->lexical_units = create_array_list();
    return result;
}

void free_frame(Frame_ptr frame) {
    free_array_list(frame->frame_elements, free);
    free_array_list(frame->lexical_units, free);
    free(frame->name);
    free(frame);
}

bool frame_lexical_unit_exists(Frame_ptr frame, char *synSetId) {
    return array_list_contains(frame->lexical_units, synSetId, (int (*)(void *, void *)) compare_string);
}

char *get_lexical_unit(Frame_ptr frame, int index) {
    return array_list_get(frame->lexical_units, index);
}

char *get_frame_element(Frame_ptr frame, int index) {
    return array_list_get(frame->frame_elements, index);
}

int lexical_unit_size(Frame_ptr frame) {
    return frame->lexical_units->size;
}

int frame_element_size(Frame_ptr frame) {
    return frame->frame_elements->size;
}

void add_lexical_unit(Frame_ptr frame, char *lexical_unit) {
    array_list_add(frame->lexical_units, lexical_unit);
}

void add_frame_element(Frame_ptr frame, char *frame_element) {
    array_list_add(frame->frame_elements, frame_element);
}
