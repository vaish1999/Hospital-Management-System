#include "fun.h"
#include "unity.h"
#include "unity_internals.h"

void setUp(){}
void tearDown(){}


void test_div(void)
{
  TEST_ASSERT_EQUAL(1, 1);
  TEST_ASSERT_EQUAL(0, 0);
}
void test_FileAvailability(void)
{
  FILE *fptr;
  fptr = fopen("User.txt", "a+");

  TEST_ASSERT_MESSAGE(fptr, "Program cannot access FILE");
}

void test_preprocessors(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(100, MAX, "!!!IMP /Dont change max value");
}
void test_generate_neg(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1, generate(1,2,3), "It worked, Thats why this error");
}
void test_generate_pos(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, generate(0,0,0), "Check out the parameters you gave");
}


void test_print(void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, print(), "Printing broke!! Maybe Rerun.");
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_preprocessors);
    RUN_TEST(test_FileAvailability);
    RUN_TEST(test_div);
    RUN_TEST(test_generate_neg);
    RUN_TEST(test_generate_pos);
    RUN_TEST(test_print);

    return UNITY_END();
}