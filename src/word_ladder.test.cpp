#include "word_ladder.h"

#include <catch2/catch.hpp>

TEST_CASE("word_ladder::read_lexicon works as expected")
{
    const std::string test_filename = "./english.txt";
    auto lexicon = word_ladder::read_lexicon(test_filename);

    REQUIRE(lexicon.size() == 127142);
    REQUIRE(lexicon.find("aa") != lexicon.end());
    REQUIRE(lexicon.find("zyzzyvas") != lexicon.end());
    CHECK(lexicon.find("hhhhhhhhhhhhhhh") == lexicon.end());
    CHECK(lexicon.find("zygosities") != lexicon.end());
    CHECK(lexicon.find("agitatedly") != lexicon.end());
}

TEST_CASE("at -> it")
{
    auto const lexicon = std::unordered_set<std::string> {
            "at",
            "it"
    };

    const auto expected = std::vector<std::vector<std::string>> {
            { "at", "it" }
    };

    auto const ladders = word_ladder::generate("at", "it", lexicon);

    REQUIRE(ladders.empty() == false);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate the same 'from' (at -> at)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "at", "it", "in", "on", "me", "my", "no", "hi", "he", "am", "as"
    };

    const auto expected = std::vector<std::vector<std::string>> {
            { "at" }
    };

    auto const ladders = word_ladder::generate("at", "at", lexicon);

    REQUIRE(ladders.empty() == false);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate no path (hot -> dog)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "hot", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "dog"
    };

    const auto expected = std::vector<std::vector<std::string>> {};

    auto const ladders = word_ladder::generate("hot", "dog", lexicon);

    CHECK(ladders.empty() == true);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate 'to' not in lexicon (hot -> log)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "hot", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx"
    };

    const auto expected = std::vector<std::vector<std::string>> {};

    auto const ladders = word_ladder::generate("hot", "log", lexicon);

    CHECK(ladders.empty() == true);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate 'from' not in lexicon (dig -> dog)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "dog"
    };

    const auto expected = std::vector<std::vector<std::string>> {};

    auto const ladders = word_ladder::generate("hot", "log", lexicon);

    CHECK(ladders.empty() == true);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate empty lexicon (come -> make)")
{
    auto const lexicon = std::unordered_set<std::string> {};

    const auto expected = std::vector<std::vector<std::string>> {};

    auto const ladders = word_ladder::generate("come", "make", lexicon);

    CHECK(ladders.empty() == true);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate empty 'from' (  -> make)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "come", "cove", "cave", "gave", "make"
    };

    const auto expected = std::vector<std::vector<std::string>> {};

    auto const ladders = word_ladder::generate("", "make", lexicon);

    CHECK(ladders.empty() == true);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate empty 'to' (come -> )")
{
    auto const lexicon = std::unordered_set<std::string> {
            "come", "cove", "cave", "gave", "make"
    };

    const auto expected = std::vector<std::vector<std::string>> {};

    auto const ladders = word_ladder::generate("come", "", lexicon);

    CHECK(ladders.empty() == true);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate different length (love -> hit)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "love", "come", "cove", "cave", "gave", "make",
            "hot", "hit", "dig", "dog", "do"
    };

    const auto expected = std::vector<std::vector<std::string>> {};

    auto const ladders = word_ladder::generate("love", "hit", lexicon);

    CHECK(ladders.empty() == true);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate not in cycle (a -> c)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "a", "b", "c"
    };

    const auto expected = std::vector<std::vector<std::string>> {
            { "a", "c" }
    };

    const auto unexpected = std::vector<std::vector<std::string>> {
            { "a", "c", "a" }
    };

    auto const ladders = word_ladder::generate("a", "c", lexicon);

    REQUIRE(ladders != unexpected);
    CHECK(ladders.empty() == false);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate easy lexicon (b -> f)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "a", "b", "c", "e", "f", "g", "h"
    };

    const auto expected = std::vector<std::vector<std::string>> {
            { "b", "f" }
    };

    auto const ladders = word_ladder::generate("b", "f", lexicon);

    CHECK(ladders.empty() == false);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate complex lexicon (love -> core)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "amyl", "analanan", "anasance", "ands", "anes", "anew", "anga", "anil", "anis", "ankh", "annaannoanns", "anoa",
            "anonanow", "ansa", "anta", "ante", "anti", "ants", "anusapay", "aped", "aper", "apes", "apex", "apod",
            "apos", "apps", "apseapsoapts", "aqua", "arakarararba", "arbs", "arch", "arco", "arcsards", "areaaredareg",
            "aresaretarew", "arfs", "aria", "arid", "arilaris", "arksarle", "arms", "armyarnaarowarpa", "arsearsyarti", "arts", "arty", "arum",
            "arvo", "arylasar", "asci", "asea", "ashy", "asks", "asps", "atap", "ates", "atmaatocatok", "atom", "atopatuaaufs",
            "auks", "auldaune", "aunt", "aura", "autoavalavasavel", "aver", "aves", "avid", "avos", "avow", "awayawdl", "awed",
            "awee", "awes", "awls", "awns", "awny", "awol", "awry", "axal", "axed", "axel", "axes", "axil",
            "axis", "axle", "axon", "ayah", "ayes", "ayinayreayus", "azan", "azonazym", "baal", "baas", "baba", "babe",
            "babu", "baby", "bach", "backbacs", "bade", "badsbael", "baffbaftbagh", "bags", "baht", "bail", "baitbaju", "bake",
            "bald", "bale", "balk", "ball", "balm", "balsbalu", "bamsbanc", "band", "bane", "bang", "bani", "bank",
            "bansbant", "bapsbapu", "barb", "bard", "bare", "barf", "bark", "barm", "barnbarp", "bars", "base", "bash",
            "bask", "bass", "bast", "bate", "bath", "bats", "batt", "baudbaukbaur", "bawd", "bawlbawnbawrbaye", "baysbayt", "bead",
            "beak", "beam", "bean", "bear", "beat", "beau", "beckbede", "beds", "bedu", "beef", "been", "beep",
            "beer", "bees", "beetbego", "begsbein", "bell", "bels", "belt", "bema", "bend", "benebenibenj", "bens", "bentbere",
            "berg", "berk", "berm", "best", "betabete", "beth", "bets", "bevy", "beysbhatbhel", "bhut", "bias", "bibb",
            "bibs", "bice", "bide", "bidi", "bidsbien", "bier", "biffbigabigg", "bigs", "cone", "bone", "bore", "bake", "lake", "like", "live", "lave", "cave",
            "bike", "bile", "bilk", "bill", "bima", "bind", "binebingbink", "bins", "bint", "biog", "bios", "bird", "birk", "birl", "biro", "birr",
            "bisebish", "biskbist", "bitebito", "bits", "bitt", "bize", "blabblad", "blaeblag", "blah", "blam", "blat", "blawblay",
            "bleb", "bledblee", "blet", "blewbley", "blin", "blip", "blob", "bloc", "blog", "blot", "blow", "blub",
            "blue", "blurboabboak", "boar", "boas", "boatboba", "bobs", "bock", "bode", "bods", "bodyboepboet", "boff", "bogs",
            "bogy", "bohobohs", "boilboisbokebokoboks", "bola", "lore", "bold", "bole", "boll", "bolo", "boltboma", "bombbona", "bond", "bone",
            "bong", "bonk", "bony", "boobbooh", "bookbool", "boom", "boon", "boor", "boos", "boot", "bops", "borabord",
            "bore", "borkborm", "bornbors", "bort", "bosh", "bosk", "boss", "bota", "both", "bots", "bottboukboun", "bout",
            "bowlbowr", "bows", "boxyboyfboyg", "boyo", "boys", "bozo", "brad", "brae", "bragbrak", "bran", "bras", "brat",
            "braw", "bray", "bred", "breebrei", "brenbrer", "brewbrey", "brie", "brigbrik", "brim", "brin", "brio", "bris",
            "britbrodbrog", "broo", "bros", "brow", "brrrbrus", "brut", "bruxbuatbuba", "bubo", "bubs", "bubu", "buckbudabudibudo", "buds",
            "buffbufo", "bugs", "buhl", "buhrbuikbuke", "bulb", "bulk", "core", "bull", "bumf", "bump", "bums", "buna", "bund",
            "bung", "bunk", "bunn", "buns", "bunt", "buoy", "bura", "burb", "burd", "burgburk", "burl", "burn",
            "burp", "burr", "burs", "bury", "bush", "busk", "buss", "bust", "busy", "bute", "buts", "butt",
            "buys", "buzzbyde", "byesbyke", "byre", "byrl", "bytecaascaba", "cabs", "caca", "cade", "cadi", "cads", "cafe",
            "caff", "cagecags", "cagy", "caid", "cain", "cake", "caky", "calf", "calk", "call", "calm", "calocalp",
            "calxcama", "came", "camo", "camp", "cams", "canecangcann", "cans", "cantcanycapa", "cape", "caphcapi", "capo", "caps",
            "carb", "card", "care", "cark", "carl", "carn", "carp", "carr", "cars", "cart", "casa", "case",
            "cash", "cask", "cast", "cate", "catscaufcauk", "caulcaumcaupcava", "cave", "cavycawk", "caws", "caysceas", "ceca", "cede",
            "cedi", "cees", "ceil", "cell", "cels", "celtcens", "cent", "cepe", "ceps", "cere", "cerocert", "cess",
            "cete", "chad", "chaichal", "cham", "chao", "chap", "charchas", "chatchav", "chaw", "chay", "chefcher", "chew",
            "chez", "chiachib", "chic", "chidchik", "chin", "chip", "chis", "chitchivchizchocchog", "chon", "chopchou", "chow", "chub",
            "chug", "chumchut", "ciaocidecidsciel", "cigscill", "cine", "cion", "cirecirl", "cist", "citecitocits", "citycive", "clad", "clag",
            "clam", "clan", "clapclat", "claw", "clay", "clefclegclem", "clew", "clip", "clod", "clog", "clon", "clop",
            "clotclouclow", "cloy", "club", "clue", "coal", "coat", "coax", "cobb", "cobs", "cocacoch", "cock", "coco",
            "coda", "code", "cods", "coed", "coff", "coft", "cogs", "coho", "coif", "coil", "coin", "love", "hair", "goat"
    };

    const auto expected = std::vector<std::vector<std::string>> {
            { "love", "lore", "core" }
    };

    auto const ladders = word_ladder::generate("love", "core", lexicon);

    CHECK(ladders.empty() == false);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate many paths (bug -> cat)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "bug", "bag", "bat", "cat", "but", "cut", "cot", "cog", "bog", "bot",
            "dog", "dot", "fog", "log", "lot", "lug", "mug", "nag", "rag", "rat",
            "sat", "sit", "tag", "tap", "tip", "top", "tug", "wig", "wit", "zag",
            "lag", "lap", "lip", "lit", "mad", "man", "mat", "map", "nap", "nip",
            "nod", "not", "pad", "pan", "pat", "pit", "pot", "rad", "rap", "rid",
            "rig", "rip", "rod", "rot", "sad", "sap", "sip", "sop", "tab", "tan",
            "tap", "tip", "top", "wag", "wig", "wit", "zap", "zig", "zip"
    };

    const auto expected = std::vector<std::vector<std::string>> {
            { "bug", "bag", "bat", "cat" },
            { "bug", "but", "bat", "cat" },
            { "bug", "but", "cut", "cat" }
    };

    auto const ladders = word_ladder::generate("bug", "cat", lexicon);

    REQUIRE(ladders.empty() == false);
    REQUIRE(ladders.size() == 3);
    CHECK(ladders == expected);
}

TEST_CASE("word_ladder::generate performance with four-letter words and many paths (code -> gold)")
{
    auto const lexicon = std::unordered_set<std::string> {
            "code", "cold", "gold", "bold", "told", "fold", "sold", "hold", "mold", "boat", "coat", "goat",
            "moat", "roat", "root", "toot", "boot", "foot", "hoot", "loot", "moat", "moan", "loan", "loon",
            "moon", "soon", "soot", "foot", "food", "good", "hood", "rood", "road", "load", "toad", "goad",
            "boar", "soar", "roar", "bear", "tear", "wear", "gear", "fear", "sear", "hear", "dear", "near",
            "rear", "lear", "gear", "veer", "beer", "seer", "peer", "jeer", "tier", "lier", "bore", "core",
            "fore", "gore", "more", "pore", "sore", "tore", "wore", "yore", "bark", "dark", "lark", "mark",
            "park", "shark", "spark", "clerk", "jerk", "perk", "work", "fork", "cork", "dork", "pork", "gork",
            "walk", "balk", "talk", "hulk", "bulk", "sulk", "calk", "bald", "cold", "bold", "fold", "gold",
            "hold", "sold", "mold", "told", "wold", "yold", "bore", "core", "more", "fore", "gore", "pore",
            "sore", "tore", "wore", "yore", "bark", "dark", "lark", "mark", "park", "clerk", "shark", "spark",
            "jerk", "perk", "work", "fork", "cork", "dork", "pork", "gork", "talk", "walk", "balk", "hulk",
            "bulk", "sulk", "calk", "bald"
    };

    auto const from = "code";
    auto const to = "gold";
    auto const ladders = word_ladder::generate(from, to, lexicon);

    REQUIRE(!ladders.empty());

    const auto expected = std::vector<std::vector<std::string>> {
            { "code", "core", "cork", "dork", "dark", "bark", "balk", "bald", "bold", "gold" },
            { "code", "core", "cork", "pork", "park", "bark", "balk", "bald", "bold", "gold" },
            { "code", "core", "pore", "pork", "park", "bark", "balk", "bald", "bold", "gold" }
    };

    CHECK(ladders == expected);
}

TEST_CASE("pickle -> cheese") {
    // in this large case, more ladders with longer range generated
    auto const lexicon = std::unordered_set<std::string>{"handle","handed","tackle","tickle","choker","cooker",
                                                         "hocker","sacked","shares","charry","hackle","cherry","cheesy","cocker","charrs","shared","chares","hooker",
                                                         "chores","choked","clever","hacker","cocked","soared","socked","chored","cheery","soaked","hackee","hocked",
                                                         "hacker","hacked","hooked","cooked","cooker","soccer","chared","mickle","chokes","cheese","mackle","pickle",
                                                         "picked","packed","battle"};

    auto const ladders = ::word_ladder::generate("pickle", "cheese", lexicon);

    REQUIRE(ladders.size() == 24);

    const std::vector<std::vector<std::string>> expected = {
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "hocked", "cocked", "cooked", "choked",
                    "chokes", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "hocked", "cocked", "cooked", "choked",
                    "chored", "chared", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "hocked", "cocked", "cooked", "choked",
                    "chored", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "hocked", "hooked", "cooked", "choked",
                    "chokes", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "hocked", "hooked", "cooked", "choked",
                    "chored", "chared", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "hocked", "hooked", "cooked", "choked",
                    "chored", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "hocked", "socked", "soaked", "soared",
                    "shared", "chared", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "hocked", "socked", "soaked", "soared",
                    "shared", "shares", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "sacked", "socked", "soaked", "soared",
                    "shared", "chared", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacked", "sacked", "socked", "soaked", "soared",
                    "shared", "shares", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacker", "hocker", "cocker", "cooker", "choker",
                    "chokes", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "mickle", "mackle", "hackle", "hackee", "hacker", "hocker", "hooker", "cooker", "choker",
                    "chokes", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "hocked", "cocked", "cooked", "choked",
                    "chokes", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "hocked", "cocked", "cooked", "choked",
                    "chored", "chared", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "hocked", "cocked", "cooked", "choked",
                    "chored", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "hocked", "hooked", "cooked", "choked",
                    "chokes", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "hocked", "hooked", "cooked", "choked",
                    "chored", "chared", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "hocked", "hooked", "cooked", "choked",
                    "chored", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "hocked", "socked", "soaked", "soared",
                    "shared", "chared", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "hocked", "socked", "soaked", "soared",
                    "shared", "shares", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "sacked", "socked", "soaked", "soared",
                    "shared", "chared", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacked", "sacked", "socked", "soaked", "soared",
                    "shared", "shares", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacker", "hocker", "cocker", "cooker", "choker",
                    "chokes", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
            {
                    "pickle", "tickle", "tackle", "hackle", "hackee", "hacker", "hocker", "hooker", "cooker", "choker",
                    "chokes", "chores", "chares", "charrs", "charry", "cherry", "cheery", "cheesy", "cheese",
            },
    };

    REQUIRE(ladders[0].size() == 19);

    REQUIRE(ladders[ladders.size()-1].size() == 19);

    CHECK(ladders == expected);
}