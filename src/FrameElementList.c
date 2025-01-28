//
// Created by Olcay Taner YILDIZ on 28.01.2025.
//

#include "FrameElementList.h"

#include <stdio.h>
#include <string.h>
#include <StringUtils.h>
#include <Memory/Memory.h>

#include "FrameElement.h"

/**
 * Constructor of frame element list from a string. The frame elements for a word is a concatenated list of
 * frame element separated via '#' character.
 * @param frame_element_list String consisting of frame elements separated with '#' character.
 */
Frame_element_list_ptr create_frame_element_list(const char *frame_element_list) {
    Frame_element_list_ptr result = malloc_(sizeof(struct frame_element_list), "create_argument_list");
    result->frame_elements = create_array_list();
    Array_list_ptr items = str_split(frame_element_list, '#');
    for (int i = 0; i < items->size; i++) {
        array_list_add(result->frame_elements, create_frame_element2(array_list_get(items, i)));
    }
    free_array_list(items, free_);
    return result;
}

void free_frame_element_list(Frame_element_list_ptr frame_element_list) {
    free_array_list(frame_element_list->frame_elements, (void (*)(void *)) free_frame_element);
    free_(frame_element_list);
}

/**
 * Overloaded toString method to convert a frame element list to a string. Concatenates the string forms of all
 * frame element with '#' character.
 * @param frame_element_list Frame element list
 * @return String form of the frame element list.
 */
char * frame_element_list_to_string(Frame_element_list_ptr frame_element_list) {
    char* result;
    char** frame_elements;
    if (frame_element_list->frame_elements->size == 0) {
        result = malloc_(5 * sizeof(char), "frame_element_list_to_string_1");
        strcpy(result, "NONE");
        return result;
    } else {
        frame_elements = malloc_(frame_element_list->frame_elements->size * sizeof(char*), "frame_element_list_to_string_2");
        int size = 0;
        for (int i = 0; i < frame_element_list->frame_elements->size; i++) {
            frame_elements[i] = frame_element_to_string(array_list_get(frame_element_list->frame_elements, i));
            size += strlen(frame_elements[i]);
        }
        result = malloc_(size * sizeof(char), "frame_element_list_to_string_3");
        sprintf(result, "%s", frame_elements[0]);
        for (int i = 1; i < frame_element_list->frame_elements->size; i++) {
            sprintf(result, "%s#%s", result, frame_elements[i]);
            free_(frame_elements[i]);
        }
        free_(frame_elements[0]);
        free_(frame_elements);
        return result;
    }
}

/**
 * Replaces id's of predicates, which have previousId as synset id, with currentId.
 * @param frame_element_list Frame element list
 * @param previous_id Previous id of the synset.
 * @param current_id Replacement id.
 */
void update_connected_id_in_frame_element_list(Frame_element_list_ptr frame_element_list, const char *previous_id,
    const char *current_id) {
    for (int i = 0; i < frame_element_list->frame_elements->size; i++) {
        Frame_element_ptr frame_element = array_list_get(frame_element_list->frame_elements, i);
        if (strcmp(previous_id, frame_element->id) == 0) {
            free_(frame_element->id);
            frame_element->id = str_copy(frame_element->id, current_id);
        }
    }
}

/**
 * Adds a predicate argument to the frame element list of this word.
 * @param frame_element_list Frame element list
 * @param predicate_id Synset id of this predicate.
 */
void add_predicate_to_frame_element_list(Frame_element_list_ptr frame_element_list, const char *predicate_id) {
    if (frame_element_list->frame_elements->size != 0 && strcmp(((Frame_element_ptr)array_list_get(frame_element_list->frame_elements, 0))->frame_element_type, "NONE") == 0) {
        array_list_remove(frame_element_list->frame_elements, 0, (void (*)(void *)) free_frame_element);
    }
    array_list_add(frame_element_list->frame_elements, create_frame_element("PREDICATE", "NONE", predicate_id));
}

/**
 * Removes the predicate with the given predicate id.
 * @param frame_element_list Frame element list
 */
void remove_predicate_from_frame_element_list(Frame_element_list_ptr frame_element_list) {
    for (int i = 0; i < frame_element_list->frame_elements->size; i++) {
        Frame_element_ptr frame_element = array_list_get(frame_element_list->frame_elements, i);
        if (strcmp(frame_element->frame_element_type, "PREDICATE") == 0) {
            array_list_remove(frame_element_list->frame_elements, i, (void (*)(void *)) free_frame_element);
            break;
        }
    }
}

/**
 * Checks if one of the frame elements is a predicate.
 * @param frame_element_list Frame element list
 * @return True, if one of the frame elements is predicate; false otherwise.
 */
bool contains_predicate_in_frame_element_list(Frame_element_list_ptr frame_element_list) {
    for (int i = 0; i < frame_element_list->frame_elements->size; i++) {
        Frame_element_ptr frame_element = array_list_get(frame_element_list->frame_elements, i);
        if (strcmp(frame_element->frame_element_type, "PREDICATE") == 0) {
            return true;
        }
    }
    return false;
}

/**
 * Checks if one of the frame element is a predicate with the given id.
 * @param frame_element_list Frame element list
 * @param predicate_id Synset id to check.
 * @return True, if one of the frame element is predicate; false otherwise.
 */
bool contains_predicate_with_id_in_frame_element_list(Frame_element_list_ptr frame_element_list,
    const char *predicate_id) {
    for (int i = 0; i < frame_element_list->frame_elements->size; i++) {
        Frame_element_ptr frame_element = array_list_get(frame_element_list->frame_elements, i);
        if (strcmp(frame_element->frame_element_type, "PREDICATE") == 0 && strcmp(predicate_id, frame_element->id) == 0) {
            return true;
        }
    }
    return false;
}

/**
 * Returns the frame elements as an array list of strings.
 * @param frame_element_list Frame element list
 * @return Frame elements as an array list of strings.
 */
Array_list_ptr get_frame_elements_in_frame_element_list(Frame_element_list_ptr frame_element_list) {
    Array_list_ptr result = create_array_list();
    for (int i = 0; i < frame_element_list->frame_elements->size; i++) {
        Frame_element_ptr frame_element = array_list_get(frame_element_list->frame_elements, i);
        array_list_add(result, frame_element_to_string(frame_element));
    }
    return result;
}

/**
 * Checks if the given argument with the given type and id exists or not.
 * @param frame_element_list Frame element list
 * @param frame_element_type Type of the frame element to search for.
 * @param frame frame Name of the frame to search for
 * @param id Id of the frame element to search for.
 * @return True if the frame element exists, false otherwise.
 */
bool contains_argument_in_frame_element_list(Frame_element_list_ptr frame_element_list, const char *frame_element_type,
    const char* frame,
    const char *id) {
    for (int i = 0; i < frame_element_list->frame_elements->size; i++) {
        Frame_element_ptr frame_element = array_list_get(frame_element_list->frame_elements, i);
        if (strcmp(frame_element->frame_element_type, frame_element_type) == 0 && strcmp(frame_element->id, id) == 0 && strcmp(frame_element->frame, frame) == 0) {
            return true;
        }
    }
    return false;
}
