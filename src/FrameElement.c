//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <string.h>
#include <ArrayList.h>
#include <stdio.h>
#include <Memory/Memory.h>
#include "FrameElement.h"
#include "StringUtils.h"

/**
 * Another constructor of FrameElement class which takes _frameElementType and _id as inputs and initializes corresponding attributes
 *
 * @param frame_element_type  Type of the frameElement
 * @param frame  Frame of the frameElement
 * @param id  Id of the frameElement
 */
Frame_element_ptr create_frame_element(const char *frame_element_type, const char *frame, const char *id) {
    Frame_element_ptr result = malloc_(sizeof(Frame_element), "create_frame_element");
    result->frame_element_type = str_copy(result->frame_element_type, frame_element_type);
    result->frame = str_copy(result->frame, frame);
    result->id = str_copy(result->id, id);
    return result;
}

/**
 * A constructor of FrameElement class which takes frameElement string which is in the form of frameElementType$id
 * and parses this string into frameElementType and id. If the frameElement string does not contain '$' then the
 * constructor return a NONE type frameElement.
 *
 * @param frame_element  FrameElement string containing the frameElementType and id
 */
Frame_element_ptr create_frame_element2(const char *frame_element) {
    Frame_element_ptr result = malloc_(sizeof(Frame_element), "create_frame_element2");
    if (strchr(frame_element, '$') != NULL) {
        Array_list_ptr items = str_split(frame_element, '$');
        result->frame_element_type = str_copy(result->frame_element_type, array_list_get(items, 0));
        result->frame = str_copy(result->frame, array_list_get(items, 1));
        result->id = str_copy(result->id, array_list_get(items, 2));
        free_array_list(items, free_);
    } else {
        result->frame_element_type = str_copy(result->frame_element_type, "NONE");
        result->frame = NULL;
        result->id = NULL;
    }
    return result;
}

/**
 * Destructor of frame element.
 * @param frame_element Frame element to destroy.
 */
void free_frame_element(Frame_element_ptr frame_element) {
    free_(frame_element->frame_element_type);
    free_(frame_element->frame);
    free_(frame_element->id);
    free_(frame_element);
}

/**
 * to_string converts an FrameElement to a string. If the frameElementType is "NONE" returns only "NONE", otherwise
 * it returns frameElement string which is in the form of frameElementType$id
 *
 * @return string form of frameElement
 */
char *frame_element_to_string(Frame_element_ptr frame_element) {
    char* result;
    if (strcmp(frame_element->frame_element_type, "NONE") == 0){
        result = malloc_(5 * sizeof(char), "frame_element_to_string_1");
        strcpy(result, "NONE");
        return result;
    } else {
        result = malloc_((strlen(frame_element->frame_element_type) + 3 + strlen(frame_element->id) + strlen(frame_element->frame)) * sizeof(char), "frame_element_to_string_2");
        sprintf(result, "%s$%s$%s", frame_element->frame_element_type, frame_element->frame, frame_element->id);
        return result;
    }
}
