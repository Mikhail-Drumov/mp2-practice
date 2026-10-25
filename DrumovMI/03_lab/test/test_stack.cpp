#include "stack.h"

#include <gtest\gtest.h>

TEST(TVectorStack, can_create_stack) {
	ASSERT_NO_THROW(TVectorStack<int> st);
}

TEST(TVectorStack, can_push) {
	TVectorStack<int> st;
	ASSERT_NO_THROW(st.Push(1));
}

TEST(TVectorStack, can_push_many) {
	TVectorStack<int> st;
	for (int i = 0; i < (1 << 20); i++)
		EXPECT_NO_THROW(st.Push(i));
}

TEST(TVectorStack, can_pop_from_nonempty_stack) {
	TVectorStack<int> st;
	st.Push(1); st.Push(2); st.Push(3);

	ASSERT_NO_THROW(st.Pop());
}

TEST(TVectorStack, throws_when_pop_from_empty_stack) {
	TVectorStack<int> st;
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TVectorStack, can_get_top_from_nonempty_stack) {
	TVectorStack<int> st;
	st.Push(1);

	int top = 0;
	EXPECT_NO_THROW(top = st.Top());
	ASSERT_EQ(top, 1);
}

TEST(TVectorStack, throws_when_get_top_from_empty_stack) {
	TVectorStack<int> st;
	ASSERT_ANY_THROW(st.Top());
}

TEST(TVectorStack, can_get_size) {
	TVectorStack<int> st;
	st.Push(1); st.Push(2); st.Push(3);

	ASSERT_EQ(st.size(), 3);
}

TEST(TVectorStack, empty_stack_is_empty) {
	TVectorStack<int> st;
	ASSERT_TRUE(st.IsEmpty());
}

TEST(TVectorStack, nonempty_stack_is_nonempty) {
	TVectorStack<int> st;
	st.Push(1);
	ASSERT_FALSE(st.IsEmpty());
}