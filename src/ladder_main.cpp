#include "ladder.h"

int main() {
    string start = "cat";
    string end = "bag";
    set<string> word_list;
    load_words(word_list, "./words.txt");
    vector<string> ladder = generate_word_ladder(start, end, word_list);
    print_word_ladder(ladder);
    return 0;
}