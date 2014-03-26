#ifndef VECTORSTUFF_H_INCLUDED_
#define VECTORSTUFF_H_INCLUDED_

#include <vector>

using std::vector;

//------------------------------------------------
//  Returns the maximum value in vector v.
//  The result is undefined if v is empty.
int maximum(const vector<int>& v);

//------------------------------------------------
//  Returns the position of the value seek
//  within vector v.
//  Returns -1 (never a valid position in a
//  C++ vector) if seek is not an element of v.
int find(const vector<int>& v, int seek);

//------------------------------------------------
//  Returns the number of times the value seek
//  appears within vector v.
//  Returns 0 if seek is not an element of v.
int count(const vector<int>& v, int seek);

//------------------------------------------------
//  Returns true if vectors v1 and v2 contain
//  exactly the same elements, regardless of their
//  order; otherwise, the function returns false.
bool equivalent(const vector<int>& v1, const vector<int>& v2);

//------------------------------------------------
//  Given vector v1 of length n and vector v2, the
//  function returns true if the first n elements of v2 are
//  identical to the contents of v1; that is, v1 is a "prefix" of
//  v2.  The function returns false if v1 is not  prefix of v2.
//  Some examples include
//     {2,-5,0} is a prefix of {2,-5,0,11,4}
//            (first three elements match)
//     {2,-5,0} is NOT a prefix of {0,-5,2,11,4}
//            (order matters)
//     {2,-5,0} is NOT a prefix of {11,2,-5,0,4}
//            (matching elements not at beginning)
//  Every sequence is a prefix of itself, and the empty sequence is
//  a prefix of any sequence.
bool prefix(const vector<int>& v1, const vector<int>& v2);

//------------------------------------------------
//  Physically rearranges the elements of v
//  so they appear in order from lowest value
//  to highest value.
void sort(vector<int>& v);

//------------------------------------------------
//  Returns true if the elements of vector v are arranged
//  in ascending order.
bool is_ascending(const vector<int>& v);

//------------------------------------------------
//  Removes the first occurrence of element
//  seek from vector v.  (The first occurrence
//  has the lowest index.)
//  The vector is unaffected if seek is not an
//  element of v.
//  The function returns true if a element is
//  removed; otherwise, it returns false if
//  seek does not appear in v.
bool remove_first(vector<int>& v, int del);

//------------------------------------------------
//  Removes all occurrences of element
//  seek from vector v.
//  The vector is unaffected if seek is not an
//  element of v.
//  The function returns the number of elements
//  removed; it returns zero if seek is not
//  found in the vector (and, therefore, nothing
//  can be removed).
int remove_all(vector<int>& v, int del);


//------------------------------------------------
//  Physically rearranges the elements of v so that
//  all the elements are shifted towards the back
//  by a distance of n. As an element "falls off"
//  the rear, it is placed at the front in the
//  space vacated when the first element was shifted backwards.
//  For example, if list contains the elements
//  1, 2, 3, 4, 5, and 6, the call rotate(list, 2)
//  rearranges list to contain 5, 6, 1, 2, 3, and 4.
//  Notice that if n is equal to the size of the vector,
//  after the rotation all the elements rotate to
//  their original locations.
//  If n is negative, the elements are shifted forward
//  n spots instead of backwards. As an element "falls off"
//  the front it is placed on the rear in the space
//  vacated when the last element was shifted forwards.
//  For example, if list contains the elements
//  1, 2, 3, 4, 5, and 6, the call rotate(list, -2)
//  rearranges list to contain 3, 4, 5, 6, 1, and 2.
//  This function can affect the contents of the vector v.
void rotate(vector<int>& v, int n);

//------------------------------------------------
//  Vectors seq1 and seq2 both represent sequences of integers.
//  The call subsequence(seq1, seq2) returns true, if
//  seq2 is a subsequence of seq1; otherwise, it returns false.
//
//  A subsequence is a sequence of numbers that are part
//  of a potentially larger sequence of numbers.   Given a sequence
//  of numbers, you can produce a subsequence by removing none,
//  some, or all of numbers in the original sequence.  The
//  remaining numbers must appear in same relative order as
//  in the original sequence.
//
//  The concept is best explained by some examples:
//  If seq1 is the sequence
//          23, 4, 19, -4, 0, 3
//  and seq2 is the sequence
//          19, -4, 0
//  seq2 is a subsequence of seq1.
//
//  If seq1 is the sequence
//          23, 4, 19, -4, 0, 3
//  and seq2 is the sequence
//          19, 0
//  seq2 is a subsequence of seq1.
//
//  If seq1 is the sequence
//          23, 4, 19, -4, 0, 3
//  and seq2 is the sequence
//          19, -4, 0, 3, 5
//  seq2 is not a subsequence of seq1, because seq2 contains
//  an element that does not appear in seq1.
//
//  If seq1 is the sequence
//          23, 4, 19, -4, 0, 3
//  and seq2 is the sequence
//          19, 0, -4
//  seq2 is not a subsequence of seq1 even though it contains
//  the same elements as in seq1, since seq2's
//  elements are not in the same relative order as in seq1
//  (0 comes after -4 in seq1 but before -4 in seq2.)
//
//  If seq1 is the sequence
//          23, 4, 19, -4, 0, 3
//  and seq2 is the sequence
//          23, 4, 19, -4, 0, 3
//  seq2 is a subsequence of seq1; thus, any sequence is a subsequence
//  of itself.
//
//  The empty sequence is a subsequence of every sequence.
//
//  Neither vector seq1 nor vector seq2 is affected by this
//  method.
bool subsequence(const vector<int>& seq1, const vector<int>& seq2);

#endif