//
// Created by Olcay Taner YILDIZ on 2.02.2023.
//

#include "FrameNet.h"
#include "XmlDocument.h"
#include "Frame.h"
#include "Memory/Memory.h"

/**
 * A constructor of FrameNet class which reads all frame files inside the files2.txt file. For each
 * filename inside that file, the constructor creates a FrameNet.Frame and puts in inside the frames array.
 */
Frame_net_ptr create_frame_net() {
    Frame_net_ptr result = malloc_(sizeof(Frame_net), "create_frame_net");
    result->frames = create_array_list();
    Xml_document_ptr xml_document = create_xml_document("framenet.xml");
    parse(xml_document);
    Xml_element_ptr rootNode = xml_document->root;
    Xml_element_ptr frameNode = rootNode->first_child;
    while (frameNode != NULL) {
        Frame_ptr currentFrame = create_frame(get_attribute_value(frameNode, "NAME"));
        Xml_element_ptr lexicalUnits = frameNode->first_child;
        Xml_element_ptr lexicalUnit = lexicalUnits->first_child;
        while (lexicalUnit != NULL) {
            add_lexical_unit(currentFrame, lexicalUnit->pcData);
            lexicalUnit = lexicalUnit->next_sibling;
        }
        Xml_element_ptr frameElements = lexicalUnits->next_sibling;
        Xml_element_ptr frameElement = frameElements->first_child;
        while (frameElement != NULL) {
            add_frame_element(currentFrame, frameElement->pcData);
            frameElement = frameElement->next_sibling;
        }
        array_list_add(result->frames, currentFrame);
        frameNode = frameNode->next_sibling;
    }
    free_document(xml_document);
    return result;
}

/**
 * Destructor of frame net. Frames array list is deallocated.
 * @param frame_net Frame net to be destroyed.
 */
void free_frame_net(Frame_net_ptr frame_net) {
    free_array_list(frame_net->frames, (void (*)(void *)) free_frame);
    free_(frame_net);
}

/**
 * Checks if the given lexical unit exists in any frame in the frame set.
 * @param frame_net Current frame net.
 * @param synSetId Id of the lexical unit
 * @return True if any frame contains the given lexical unit, false otherwise.
 */
bool frame_net_lexical_unit_exists(const Frame_net* frame_net, const char *synSetId) {
    for (int i = 0; i < frame_net->frames->size; i++) {
        Frame_ptr frame = array_list_get(frame_net->frames, i);
        if (frame_lexical_unit_exists(frame, synSetId)) {
            return true;
        }
    }
    return false;
}

/**
 * Returns an array of frames that contain the given lexical unit in their lexical units
 * @param frame_net Current frame net
 * @param synSetId Id of the lexical unit.
 * @return An array of frames that contains the given lexical unit.
 */
Array_list_ptr get_frames(const Frame_net* frame_net, const char *synSetId) {
    Array_list_ptr result = create_array_list();
    for (int i = 0; i < frame_net->frames->size; i++) {
        Frame_ptr frame = array_list_get(frame_net->frames, i);
        if (frame_lexical_unit_exists(frame, synSetId)) {
            array_list_add(result, frame);
        }
    }
    return result;
}

/**
 * Returns number of frames in the frame set.
 * @param frame_net Current frame net
 * @return Number of frames in the frame set.
 */
int frame_size(const Frame_net* frame_net) {
    return frame_net->frames->size;
}

/**
 * Returns the element at the specified position in the frame list.
 * @param frame_net Current frame net
 * @param index index of the element to return
 * @return The element at the specified position in the frame list.
 */
Frame_ptr get_frame(const Frame_net* frame_net, int index) {
    return array_list_get(frame_net->frames, index);
}
