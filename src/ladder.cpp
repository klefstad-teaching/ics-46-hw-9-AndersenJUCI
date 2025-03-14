#include "ladder.h"

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}


void error(string word1, string word2, string msg) {
    cout << "Error: " << msg << endl;
    cout << word1 << " - " << word2 << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int counter = 0;
    if (str1.length() != str2.length()) {
        return false;
    }
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            counter++;
        }
    }
    return (counter <= d);
}

bool is_adjacent(const string& word1, const string& word2) {
    int counter = 0;
    if (word1.length() != word2.length()) {
        return false;
    }
    for (int i = 0; i < word1.length(); i++) {
        if (word1[i] != word2[i]) {
            counter++;
        }
    }
    return (counter == 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<stack<string>> ladders;
    stack<string> init;
    init.push(begin_word);
    ladders.push(init);

    set<string> visited;
    visited.insert(begin_word);

    while (!ladders.empty()) {
        stack<string> ladder = ladders.front();
        ladders.pop();
        string last = ladder.top();

        for (const string & word : word_list) {
            if (is_adjacent(last, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    stack<string> new_lad = ladder;
                    new_lad.push(word);

                    if (word == end_word) {
                        vector<string> final_lad;
                        while (!new_lad.empty()) {
                            final_lad.push_back(new_lad.top());
                            new_lad.pop();
                        }
                        reverse(final_lad.begin(), final_lad.end());
                        return final_lad;
                    }
                    ladders.push(new_lad);
                } 
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream file(file_name);
    string word;
    while (file >> word) {
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder) {
    for (size_t i = 0; i < ladder.size(); i++) {
        cout << ladder[i] << " ";
    }
}

void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}