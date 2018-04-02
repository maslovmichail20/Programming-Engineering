#include "get_top.h"
#include <iostream>

void swap(Rating* Rat, int i, int j){
  int swap;
  char* swap_s;
  float swap_f;

  swap_s = Rat -> surnames[i];
  Rat -> surnames[i] = Rat -> surnames[j];
  Rat -> surnames[j] = swap_s;

  for (int k = 0; k < 5; k++){
    swap = Rat -> subjects[i][k];
    Rat -> subjects[i][k] = Rat -> subjects[j][k];
    Rat -> subjects[j][k] = swap;
  }

  swap = Rat -> isContract[i];
  Rat -> isContract[i] = Rat -> isContract[j];
  Rat -> isContract[j] = swap;

  swap_f = Rat -> averageRating[i];
  Rat -> averageRating[i] = Rat -> averageRating[j];
  Rat -> averageRating[j] = swap_f;
}

int get_top(Rating* CurRating){
  int num = 0;
  for (int i = 0; i < CurRating -> size; i++){
    int sum = 0;
    if (CurRating -> isContract[i] == 0){
      num++;
      for (int k = 0; k < 5; k++){
        sum += CurRating -> subjects[i][k];
      }
    }
    CurRating -> averageRating[i] = ((int)(sum/5.0 * 1000)) / 1000.0;
  }
  int i = 1;
  while (i != CurRating -> size){
    if (CurRating -> averageRating[i - 1] < CurRating -> averageRating[i]){
      swap(CurRating, i - 1, i);
      if (i > 1) i--;
      else i++;
      continue;
    }
    i++;
  }
  return num * 0.4;
}