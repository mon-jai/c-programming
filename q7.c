#include <stdio.h>
#include <string.h>

void input_cards(char player_cards[3][3]) {
  for (int i = 0; i < 3; i++) {
    char card[3];
    scanf(" %s", player_cards[i]);
  }
}

float calculate_score(char cards[3][3]) {
  float score = 0;
  for (int i = 0; i < 3; i++) {
    char* card = cards[i];

    switch (card[0]) {
    case 'A': {
      score += 1;
      break;
    }
    case 'J':
    case 'Q':
    case 'K': {
      score += 0.5;
      break;
    }
    case '1': {
      if (card[1] == '0') {
        score += 10;
        break;
      }
    }
    default: {
      score += card[0] - '0';
    }
    }
  }

  return score <= 10.5 ? score : 0;
}

int main() {
  char player_a_cards[3][3];
  char player_b_cards[3][3];

  input_cards(player_a_cards);
  input_cards(player_b_cards);

  float player_a_score = calculate_score(player_a_cards);
  float player_b_score = calculate_score(player_b_cards);
  char* message = player_a_score == player_b_score ? "It's a tie." : player_a_score > player_b_score ? "A wins."
                                                                                                     : "B wins.";

  printf("%.1f\n%.1f\n%s", player_a_score, player_b_score, message);
}
