#include "ladder.h"

int main() {
    string start =;
    string end =;
    cout << "Enter Start Word: ";
    cin >> start;
    cout << "Enter End Word: ";
    cin >> end;
    if (start == end) {
        error(start, end, "Words Must Be Different");
        return -1;
    }
    if (word_list.find(start) == word_list.end() || word_list.find(end) == word_list.end()) {
        error(start, end, "Start And End Words Must Start In Dictionary");
        return -1;
    }
    set<string> word_list;
    load_words(word_list, "./words.txt");
    vector<string> ladder = generate_word_ladder(start, end, word_list);
    print_word_ladder(ladder);
    return 0;
}