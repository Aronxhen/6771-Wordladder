#include "word_ladder.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iterator>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

auto word_ladder::read_lexicon(const std::string& path) -> std::unordered_set<std::string>
{
    std::unordered_set<std::string> lexicon;
    std::ifstream file_words;

    // associate file_words with a file
    file_words.open(path);
    // check file is opened
    assert(file_words.is_open() == true);

    // insert word into lexicon
    std::istream_iterator<std::string> start(file_words), end;
    lexicon.insert(start, end);
    assert(!lexicon.empty());

    // close file
    file_words.close();
    // check file is closed
    assert(file_words.is_open() == false);

    return lexicon;
}

bool find_word(const std::string& cur_w, const std::unordered_set<std::string>& lexicon)
{
    if (lexicon.find(cur_w) != lexicon.end()) {
        return true;
    }
    return false;
}

bool check_visited(const std::string& cur_w, std::unordered_set<std::string>& visited_words)
{
    if (visited_words.find(cur_w) != visited_words.end()) {
        return true;
    }
    return false;
}

auto word_ladder::generate(const std::string& from,
                           const std::string& to,
                           const std::unordered_set<std::string>& lexicon) -> std::vector<std::vector<std::string>>
{

    if (lexicon.empty()) {
        return {};
    }

    // remove not length of from in lexicon
    std::unordered_set<std::string> new_lexicon;
    for (const std::string& s : lexicon) {
        if (s.size() == from.size()) {
            new_lexicon.insert(s);
        }
    }

    // init the list of pred
    std::unordered_map<std::string, std::vector<std::string>> pred;

    // init the list of visited words
    std::unordered_set<std::string> visited_words = { from };

    // init the queue
    std::queue<std::string> check_line;
    check_line.push(from);

    // init paths - answer
    std::vector<std::vector<std::string>> paths;
    // init path
    std::vector<std::string> path = { to };

    if (!find_word(from, new_lexicon) || !find_word(to, new_lexicon)) {
        return {};
    }

    if (from == to) {
        paths.push_back(path);
        return paths;
    }

    if (from.empty() || to.empty()) {
        return {};
    }

    if (from.length() != to.length()) {
        return {};
    }

    bool goal = false;
    while (!check_line.empty() && !goal) {
        // save the possible words from the first word by one step
        std::queue<std::string> level_line;
        std::unordered_set<std::string> current_level_visited;

        while (!check_line.empty()) {
            std::string cur_word = check_line.front();
            check_line.pop();
            auto length_cur = cur_word.length();

            // find a way from start to end
            if (cur_word == to) {
                goal = true;
                break;
            }

            // depends on length of current word to traverse every char in string
            // and from a to z to change
            std::string pre_word = cur_word;
            for (std::string::size_type i = 0; i < length_cur; i++) {
                char original_char = cur_word[i];
                for (char al = 'a'; al <= 'z'; al++) {
                    // pass the same al
                    if (al == original_char)
                        continue;
                    // changed
                    cur_word[i] = al;
                    // find changed word is it in lexicon and check visited
                    if (find_word(cur_word, new_lexicon)) {
                        // not in visited and not in current level visited
                        if (!check_visited(cur_word, visited_words) && !check_visited(cur_word, current_level_visited)) {
                            // put changed word in pred map
                            // pred[changed word] is previous word means that from previous to changed word
                            pred[cur_word].push_back(pre_word);

                            // put changed word in visited words
                            current_level_visited.insert(cur_word);

                            // put changed word in level_line
                            // prepare to next step
                            level_line.push(cur_word);

                            // in current level visited
                        } else if (check_visited(cur_word, current_level_visited)) {
                            pred[cur_word].push_back(pre_word);
                        }
                    }
                }
                cur_word[i] = original_char;
            }
        }
        // put all same level key word in visited
        visited_words.insert(current_level_visited.begin(), current_level_visited.end());
        // find next step unless goal
        check_line = level_line;
    }

    if (!goal) {
        return {};
    }

    // generate all paths from 'to' to 'from' by stack
    // init one stack
    std::stack<std::vector<std::string>> stack;
    stack.push(path);

    while (!stack.empty()) {
        // update path
        path = stack.top();
        // after each find pred step
        // and pop this path and check last word equal to from
        stack.pop();
        // update last word
        std::string last_word = path.back();

        // find a path and reserve push in paths
        if (last_word == from) {
            std::reverse(path.begin(), path.end());
            paths.push_back(path);
        } else {
            // for pred of last word
            // create a new path add their next word and push into stack
            for (const auto& pred_word : pred[last_word]) {
                // create a new path
                std::vector<std::string> new_path = path;
                // add next word
                new_path.push_back(pred_word);
                // push into stack
                stack.push(new_path);
            }
        }
    }

    // sorted paths
    std::sort(paths.begin(), paths.end());
    return paths;
}