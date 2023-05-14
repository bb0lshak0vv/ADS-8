// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addWagon(bool light) {
    if (first == nullptr) {
        first = new Wagon;
        first->prev = nullptr;
        first->next = nullptr;
        first->light = true;
    } else if (first != nullptr) {
        Wagon* wagon = new Wagon;
        wagon->next = nullptr;
        wagon->prev = nullptr;
        wagon->light = light;
        Wagon* tmp;
        if (first->next == nullptr) {
            wagon->next = first;
            wagon->prev = first;
            first->next = wagon;
            first->prev = wagon;
        } else {
            tmp = first;
            while (tmp->next != first) {
                tmp = tmp->next;
            }
            tmp->next = wagon;
            wagon->next = first;
            wagon->prev = tmp;
            first->prev = wagon;
        }
    }
}

int Train::getLength() {
    Wagon* tmp = first;
    int count = 0;
    while (tmp) {
        tmp = tmp->next;
        countOp++;
        count++;
        if (tmp->light == 1) {
            tmp->light = 0;
            for (int i = 0; i < count; i++) {
                tmp = tmp->prev;
                countOp++;
            }
        if (tmp->light == 0) {
            return count;
        }
            count = 0;
        }
    }
    return 0;
}
int Train::getOpCount() {
      if (countOp == 0)
          getLength();
    return countOp;
}
