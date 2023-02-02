//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <stdlib.h>
#include <string.h>
#include <ArrayList.h>
#include "FrameElement.h"
#include "StringUtils.h"

/**
 * Another constructor of {@link FrameElement} class which takes _frameElementType and _id as inputs and initializes corresponding attributes
 *
 * @param frame_element_type  Type of the frameElement
 * @param frame  Frame of the frameElement
 * @param id  Id of the frameElement
 */
Frame_element_ptr create_frame_element(char *frame_element_type, char *frame, char *id) {
    Frame_element_ptr result = malloc(sizeof(Frame_element));
    result->frame_element_type = str_copy(result->frame_element_type, frame_element_type);
    result->frame = str_copy(result->frame, frame);
    result->id = str_copy(result->id, id);
    return result;
}

/**
 * A constructor of {@link FrameElement} class which takes frameElement string which is in the form of frameElementType$id
 * and parses this string into frameElementType and id. If the frameElement string does not contain '$' then the
 * constructor return a NONE type frameElement.
 *
 * @param frame_element  FrameElement string containing the frameElementType and id
 */
Frame_element_ptr create_frame_element2(char *frame_element) {
    Frame_element_ptr result = malloc(sizeof(Frame_element));
    if (strchr(frame_element, '$') != NULL){
        Array_list_ptr items = str_split(frame_element, '$');
        result->frame_element_type = array_list_get(items, 0);
        result->frame = array_list_get(items, 1);
        result->id = array_list_get(items, 2);
        free_array_list(items, NULL);
    } else {
        result->frame_element_type = str_copy(result->frame_element_type, "NONE");
        result->frame = NULL;
        result->id = NULL;
    }
    return result;
}

void free_frame_element(Frame_element_ptr frame_element) {
    free(frame_element->frame_element_type);
    free(frame_element->frame);
    free(frame_element->id);
    free(frame_element);
}
