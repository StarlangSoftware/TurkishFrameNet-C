//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include <StringUtils.h>
#include <HashMap/HashMap.h>
#include <Memory/Memory.h>
#include "Frame.h"

/**
 * Constructor of Frame class which takes file name as input and reads the frame
 *
 * @param name  Name of the frame
 */
Frame_ptr create_frame(const char *name) {
    Frame_ptr result = malloc_(sizeof(Frame), "create_frame");
    result->name = str_copy(result->name, name);
    result->frame_elements = create_array_list();
    result->lexical_units = create_array_list();
    return result;
}

/**
 * Destructor of frame.
 * @param frame Frame to be destroyed.
 */
void free_frame(Frame_ptr frame) {
    free_array_list(frame->frame_elements, free_);
    free_array_list(frame->lexical_units, free_);
    free_(frame->name);
    free_(frame);
}

/**
 * Checks if the given lexical unit exists in the current frame
 * @param frame Current frame
 * @param synSetId Lexical unit to be searched.
 * @return True if the lexical unit exists, false otherwise.
 */
bool frame_lexical_unit_exists(const Frame* frame, const char *synSetId) {
    return array_list_contains(frame->lexical_units, synSetId, (int (*)(const void *, const void *)) compare_string);
}

/**
 * Accessor for a given index in the lexicalUnit array.
 * @param frame Current frame
 * @param index Index of the lexical unit
 * @return The lexical unit at position index in the lexicalUnit array
 */
char *get_lexical_unit(const Frame* frame, int index) {
    return array_list_get(frame->lexical_units, index);
}

/**
 * Accessor for a given index in the frameElements array.
 * @param frame Current frame
 * @param index Index of the frame element
 * @return The frame element at position index in the frameElements array
 */
char *get_frame_element(const Frame* frame, int index) {
    return array_list_get(frame->frame_elements, index);
}

/**
 * Returns number of lexical units in the current frame
 * @param frame Current frame
 * @return Number of lexical units in the current frame
 */
int lexical_unit_size(const Frame* frame) {
    return frame->lexical_units->size;
}

/**
 * Returns number of frame elements in the current frame
 * @param frame Current frame
 * @return Number of frame elements in the current frame
 */
int frame_element_size(const Frame* frame) {
    return frame->frame_elements->size;
}

/**
 * Adds a new lexical unit to the current frame
 * @param frame Current frame
 * @param lexicalUnit Lexical unit to be added
 */
void add_lexical_unit(Frame_ptr frame, const char *lexical_unit) {
    char* added = str_copy(added, lexical_unit);
    array_list_add(frame->lexical_units, added);
}

/**
 * Adds a new frame element to the current frame
 * @param frame Current frame
 * @param frameElement Frame element to be added
 */
void add_frame_element(Frame_ptr frame, const char *frame_element) {
    char* added = str_copy(added, frame_element);
    array_list_add(frame->frame_elements, added);
}
