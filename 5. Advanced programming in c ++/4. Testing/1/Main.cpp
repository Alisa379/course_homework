#include <iostream>
#include "Source.hpp"
#include "Catch2/catch_test_macros.hpp"
#include "Catch2/catch_session.hpp"

TEST_CASE("Tetsing method empty()", "it's the first test_case") {
    List list;
    INFO("Method Empty() doesn't work!");
    CHECK(list.Empty() == 1);
}

TEST_CASE("Testing method size()", "it's the second test_case") {
    List list;
    list.PushBack(34);
    list.PushBack(78);
    list.PushBack(93);
    list.PushBack(7);
    INFO("Method Size() doesn't work!");
    CHECK(list.Size() == 4);
}

TEST_CASE("Testing method clear()", "it's the third test_case") {
    List list;
    list.PushBack(1);
    list.PushBack(9);
    list.PushBack(2);
    list.PushBack(8);
    list.PushBack(7);
    list.Clear();
    INFO("Method Clear() doesn't work!");
    CHECK(list.Size() == 0);
}

int main() {
    return Catch::Session().run();
}