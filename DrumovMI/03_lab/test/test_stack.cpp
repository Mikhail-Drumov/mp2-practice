#include "stack.h"

#include <gtest\gtest.h>

TEST(TDynamicStack, can_create_stack) {
	ASSERT_NO_THROW(TDynamicStack<int> st);
}
TEST(TDynamicStack, can_push) {
	TDynamicStack<int> st(5);
	ASSERT_NO_THROW(st.Push(1));
}

TEST(TDynamicStack, cant_push_full) {
	TDynamicStack<int> st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	ASSERT_ANY_THROW(st.Push(4));
}

TEST(TDynamicStack, can_pop_from_nonempty_stack) {
	TDynamicStack<int> st(3);
	st.Push(1); st.Push(2); st.Push(3);

	ASSERT_NO_THROW(st.Pop());
}

TEST(TDynamicStack, throws_when_pop_from_empty_stack) {
	TDynamicStack<int> st(3);
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TDynamicStack, throws_when_get_top_from_empty_stack) {
	TDynamicStack<int> st(3);
	ASSERT_ANY_THROW(st.Top());
}

TEST(TDynamicStack, can_get_size) {
	TDynamicStack<int> st(5);
	st.Push(1); st.Push(2); st.Push(3);

	ASSERT_EQ(st.size(), 3);
}

TEST(TDynamicStack, empty_stack_is_empty) {
	TDynamicStack<int> st(3);
	ASSERT_TRUE(st.IsEmpty());
}

TEST(TDynamicStack, nonempty_stack_is_nonempty) {
	TDynamicStack<int> st(3);
	st.Push(1);
	ASSERT_FALSE(st.IsEmpty());
}

TEST(TDynamicStack, full_stack_is_full) {
	TDynamicStack<int> st(3);
	st.Push(1); st.Push(2); st.Push(3);

	ASSERT_TRUE(st.IsFull());
}

TEST(TDynamicStack, nonfull_stack_is_nonfull) {
	TDynamicStack<int> st(3);
	st.Push(1);

	ASSERT_FALSE(st.IsFull());
}