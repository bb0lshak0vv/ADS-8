// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Wagon {
    bool light; // состояние лампочки
    Wagon *next;
    Wagon *prev;
  };
  int countOp; // счетчик шагов (число переходов из вагона в вагон)
  Wagon *first; // точка входа в поезд (первый вагон)
 public:
  Train();
  void addCage(bool light); // добавить вагон с начальным состоянием лампочки
  int getLength();          // вычислить длину поезда
  int getOpCount();         // вернуть число переходов (из вагона в вагон)
};
#endif  // INCLUDE_TRAIN_H_
