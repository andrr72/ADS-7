// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    newCar->next = newCar;
    newCar->prev = newCar;
  } else {
    Car* last = first->prev;
    newCar->next = first;
    newCar->prev = last;
    first->prev = newCar;
    last->next = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;
  if (first->next == first) return 1;
  
  Car* current = first;
  current->light = false;
  int length = 1;
  bool firstCycle = true;
  
  while (true) {
    current = current->next;
    countOp++;
    if (!current->light) {
      if (current == first && !firstCycle) {
        return length;
      }
      current->light = false;
      length++;
      firstCycle = false;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
