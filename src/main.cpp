#include "word_ladder.h"
#include <unordered_set>

#include <iostream>

// Please note: it's not good practice to test your code via a main function that does
//  printing. Instead, you should be using your test folder. This file should only really
//  be used for more "primitive" debugging as we know that working solely with test
//  frameworks might be overwhelming for some.

auto main() -> int {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");
    auto const ladders = word_ladder::generate("Pickle", "Cheese", english_lexicon);
	// debug here

//    std::unordered_set<std::string> english_lexicon = {"a", "b", "c", "d", "e"};
//    auto const ladders = word_ladder::generate("b", "c", english_lexicon);

    for (const auto &path : ladders) {
        for (const auto &word : path) {
            if (word == path.back()){
                std::cout << word;
                break;
            }
            std::cout << word << "->";
        }
        std::cout << std::endl;
    }
}
