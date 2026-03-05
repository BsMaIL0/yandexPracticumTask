#include "Deck.h"

#include <iostream>

int Deck::deckSize() const { return size; }

Deck::Deck(int a) : length(a), size(0), upper(0), lower(0) {
  cards = new int[length];
}

Deck::~Deck() { delete[] cards; }

void Deck::push(int card) {
  if (size < length) {
    cards[lower] = card;
    lower = (lower + 1) % length;
    size++;
  }
}

int Deck::pop() {
  if (size > 0) {
    int card = cards[upper];
    upper = (upper + 1) % length;
    size--;
    return card;
  }
  return -1;
}

void Deck::print() {
  int current = upper;
  for (int i = 0; i < size; i++) {
    std::cout << cards[current] << " ";
    current = (current + 1) % length;
  }
  std::cout << std::endl;
}

int cardToValue(const char* card) {
  if (card[0] == 'A') {
    return 14;
  }
  if (card[0] == 'K') {
    return 13;
  }
  if (card[0] == 'Q') {
    return 12;
  }
  if (card[0] == 'J') {
    return 11;
  }
  if (card[0] == '1' && card[1] == '0') {
    return 10;
  }
  int value = card[0] - '0';
  if (value >= 2 && value <= 9) {
    return value;
  }
  return 0;
}

bool firstWins(int card1, int card2) {
  if (card1 == 2 && card2 == 14) {
    return true;
  }
  if (card1 == 14 && card2 == 2) {
    return false;
  }
  return card1 > card2;
}