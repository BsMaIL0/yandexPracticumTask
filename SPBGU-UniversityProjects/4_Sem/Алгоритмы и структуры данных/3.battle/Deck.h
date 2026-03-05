#ifndef DECK_H
#define DECK_H

int cardToValue(const char* card);
bool firstWins(int card1, int card2);

class Deck {
 public:
  Deck(int a = 104);
  ~Deck();
  void push(int card);
  int pop();
  void print();
  int deckSize() const;

 private:
  int* cards;
  int length;
  int size;
  int upper;
  int lower;
};

#endif
