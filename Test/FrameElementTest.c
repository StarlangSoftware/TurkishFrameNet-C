//
// Created by Olcay Taner YILDIZ on 3.02.2023.
//

#include <string.h>
#include <stdio.h>
#include "../src/FrameElement.h"

int main(){
    Frame_element_ptr frameElement = create_frame_element2("Agent$Apply_Heat$TUR10-0100230");
    if (strcmp("Agent", frameElement->frame_element_type) != 0){
        printf("Test Failed in testFrameElement\n");
    }
    if (strcmp("Apply_Heat", frameElement->frame) != 0){
        printf("Test Failed in testFrameElement\n");
    }
    if (strcmp("TUR10-0100230", frameElement->id) != 0){
        printf("Test Failed in testFrameElement\n");
    }
    free_frame_element(frameElement);
}