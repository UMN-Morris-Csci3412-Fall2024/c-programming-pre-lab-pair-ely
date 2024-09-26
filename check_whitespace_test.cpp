#include <gtest/gtest.h>

#include "check_whitespace.h"

// Helper function to assert strip results and free memory
void assert_strip(const char* input, const char* expected) {
    char* result = strip(input);
    ASSERT_STREQ(expected, result);
    free(result);
}

TEST(strip, EmptyString) {
    assert_strip("", "");
}

TEST(strip, NoWhitespace) {
    assert_strip("frog", "frog");
}

TEST(strip, WhitespaceOnFront) {
    assert_strip("   frog", "frog");
}

TEST(strip, WhitespaceOnBack) {
    assert_strip("frog  ", "frog");
}

TEST(strip, WhitespaceOnBothEnds) {
    assert_strip("  frog     ", "frog");
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}