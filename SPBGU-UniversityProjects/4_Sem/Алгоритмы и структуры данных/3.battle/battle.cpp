#include <fstream>
#include <iostream>

#include "Deck.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Wrong input!" << std::endl;
    return 1;
  }

  std::ifstream in(argv[1]);

  if (!in) {
    std::cerr << "Can't open input file!" << std::endl;
    return 1;
  }

  Deck player1;
  Deck player2;
  Deck table;

  char card[3];
  char suit;
  int cardCount = 0;

  while (in >> card >> suit) {
    int value = cardToValue(card);
    if (cardCount < 26) {
      player1.push(value);
    } else {
      player2.push(value);
    }
    ++cardCount;
  }

  if (cardCount != 52) {
    std::cerr << "Invalid number of cards: " << cardCount << std::endl;
    return 1;
  }

  for (int move = 0; move < 1000000; ++move) {
    if (player1.deckSize() == 0) {
      std::cout << "second" << std::endl;
      return 0;
    }
    if (player2.deckSize() == 0) {
      std::cout << "first" << std::endl;
      return 0;
    }

    int player1Card = player1.pop();
    int player2Card = player2.pop();

    table.push(player1Card);
    table.push(player2Card);

    if (firstWins(player1Card, player2Card)) {
      while (table.deckSize() > 0) {
        player1.push(table.pop());
      }
      continue;
    }
    if (firstWins(player2Card, player1Card)) {
      while (table.deckSize() > 0) {
        player2.push(table.pop());
      }
      continue;
    }

    while (player1Card == player2Card) {
      if (player1.deckSize() == 0 || player2.deckSize() == 0) {
        std::cout << "draw" << std::endl;
        return 0;
      }

      player1Card = player1.pop();
      player2Card = player2.pop();

      table.push(player1Card);
      table.push(player2Card);

      if (player1.deckSize() == 0 || player2.deckSize() == 0) {
        std::cout << "draw" << std::endl;
        return 0;
      }
    }

    if (firstWins(player1Card, player2Card)) {
      while (table.deckSize() > 0) {
        player1.push(table.pop());
      }
    } else {
      while (table.deckSize() > 0) {
        player2.push(table.pop());
      }
    }
  }

  std::cout << "unknown" << std::endl;
  return 0;
}