//
// Created by Olcay Taner YILDIZ on 3.02.2023.
//

#include "../src/FrameNet.h"
#include "HashMap/HashSet.h"
#include <stdio.h>

void testFrameSize(Frame_net_ptr frame_net){
    if (frame_size(frame_net) != 139){
        printf("Test Failed in testFrameSize\n");
    }
}

void testLexicalUnitSize(Frame_net_ptr frame_net){
    int count = 0;
    for (int i = 0; i < frame_size(frame_net); i++){
        count += lexical_unit_size(get_frame(frame_net, i));
    }
    if (2561 != count){
        printf("Test Failed in testLexicalUnitSize\n");
    }
}

void testFrameElementSize(Frame_net_ptr frame_net){
    int count = 0;
    for (int i = 0; i < frame_size(frame_net); i++){
        count += frame_element_size(get_frame(frame_net, i));
    }
    if (1665 != count){
        printf("Test Failed in testFrameElementSize\n");
    }
}

void testDistinctFrameElements(Frame_net_ptr frame_net){
    Hash_set_ptr elements;
    elements = create_hash_set((int (*)(void *, int)) hash_function_string, (int (*)(void *, void *)) compare_string);
    for (int i = 0; i < frame_size(frame_net); i++){
        for (int j = 0; j < frame_element_size(get_frame(frame_net, i)); j++){
            hash_set_insert(elements, get_frame_element(get_frame(frame_net, i), j));
        }
    }
    if (289 != elements->hash_map->count){
        printf("Test Failed in testDistinctFrameElements\n");
    }
    free_hash_set(elements, NULL);
}

int main(){
    Frame_net_ptr frame_net = create_frame_net();
    testFrameSize(frame_net);
    testLexicalUnitSize(frame_net);
    testFrameElementSize(frame_net);
    testDistinctFrameElements(frame_net);
    free_frame_net(frame_net);
}