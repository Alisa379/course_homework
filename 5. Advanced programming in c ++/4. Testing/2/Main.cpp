#include <iostream>
#include "Source.hpp"
#include "Catch2/catch_test_macros.hpp"
#include "Catch2/catch_session.hpp"

TEST_CASE("Testing method PushBack()", "it's the first test_case") {
    List list;
    list.PushBack(3);
    list.PushBack(7);
    list.PushBack(9);
    INFO("Method PushBack doesn't work!");
    CHECK(list.Size() == 3);
}

TEST_CASE("Testing method PushFront()", "it's the second test_case") {
    List list;
    list.PushFront(2);
    list.PushFront(2);
    INFO("Method PushFront doesn't work!");
    CHECK(list.Size() == 2);
}

TEST_CASE("Testing method PopBack() on empty list", "it's the third test_case") {
    List list;
    list.PopBack();
    INFO("Method PopBack doesn't work!");
    CHECK(list.Size() == 0);
}

TEST_CASE("Testing method PopFront() on empty list", "it's the fourth test_case") {
    List list;
    list.PopFront();
    INFO("Method PopFront doesn't work!");
    CHECK(list.Size() == 0);
}

int main() {
    return Catch::Session().run();
}