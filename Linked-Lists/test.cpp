/************************************************************
 * You can use this file to test if your code is working
 * properly by designing your own test case and test code.
 *
 * We will only be providing test cases for Lab 1.1.
 *
 * To grade, we will compile your code and run it against
 * our own test suite. You should design your own tests in
 * this file to ensure that your code does what you expect.
 ************************************************************/

#include <iostream>
#include <string>

// Uncomment the .h files when you're ready to start testing
#include "sequential-list.h"
#include "doubly-linked-list.h"
#include "polynomial.h"

// Once uncommented, you will need to modify the CMakeLists.txt
// to add the .cpp file to be able to compile again.

// Note: This may require you to "rebuild" or "Reload CMake Project"

using namespace std;


#define ASSERT_TRUE(T) \
    if (!(T))          \
        return false;
#define ASSERT_FALSE(T) \
    if ((T))            \
        return false;


string get_status_str(bool status) {
    return status ? "TEST PASSED" : "TEST FAILED";
}

class SequentialListTest {
public:
    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
    bool test6();
    bool test7();
    bool test8();
    bool test9();
    bool test10();
};

class DoublyLinkedListTest
{
public:
    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
    bool test6();
    bool test7();
    bool test8();
    bool test9();
    bool test10();
    bool test11();
};

class PolynomialTest
{
public:
    bool test1();
    bool test2();
    bool test3();
    bool test4();
    bool test5();
    bool test6();
    bool test7();
    bool test8();
    bool test9();
    bool test10();
    bool test11();
    bool test12();
    bool test13();
};
void polynomialPrintManualTest();

unsigned int sequentialListTest();
unsigned int doublyLinkedListTest();
unsigned int polynomialTest();

int main() {

    sequentialListTest();
    doublyLinkedListTest();
    polynomialTest();

    return 0;
}

unsigned int sequentialListTest()
{
    unsigned int grade = 0;
    const unsigned int TEST_COUNT = 10;
    SequentialListTest seq_test;

    // Some feedback about the tests.
    string seq_test_descriptions[TEST_COUNT] = {
            "Test1: New empty list is valid",
            "Test2: insert_front() and insert_back() on zero-element list",
            "Test3: select() and search() work properly",
            "Test4: remove_front() and remove_back() on one-element list",
            "Test5: Inserting too many elements should fail",
            "Test6: insert_front() keeps moving elements forward",
            "Test7: inserting at different positions in the list",
            "Test8: try to remove too many elements, then add a few elements",
            "Test9: lots of inserts and deletes, all of them valid",
            "Test10: lots of inserts and deletes, some of them invalid"
    };

    bool seq_test_results[TEST_COUNT];
    seq_test_results[0] = seq_test.test1();
    seq_test_results[1] = seq_test.test2();
    seq_test_results[2] = seq_test.test3();
    seq_test_results[3] = seq_test.test4();
    seq_test_results[4] = seq_test.test5();
    seq_test_results[5] = seq_test.test6();
    seq_test_results[6] = seq_test.test7();
    seq_test_results[7] = seq_test.test8();
    seq_test_results[8] = seq_test.test9();
    seq_test_results[9] = seq_test.test10();

    cout << "SEQUENTIAL LIST TESTING RESULTS \n";
    cout << "******************************* \n";
    for (int i = 0; i < TEST_COUNT; ++i) {

        cout << seq_test_descriptions[i] << endl
             << get_status_str(seq_test_results[i]) << endl;

        if (seq_test_results[i])
            grade += 3;
    }
    grade += 10;
    cout << endl
         << "Sub-total grade: " << grade << "/" << TEST_COUNT * 3 + 10 << endl << endl;

    return grade;
}

unsigned int doublyLinkedListTest()
{
    unsigned int grade = 0;
    unsigned const int TEST_COUNT = 11;
    DoublyLinkedListTest doubly_linked_list_test;

    // Some feedback about the tests.
    string doubly_linked_list_test_descriptions[TEST_COUNT] = {
            "Test1: New empty list is valid",
            "Test2: insert_front() and insert_back() on zero-element list",
            "Test3: select() and search() work properly",
            "Test4: remove_front() and remove_back() on one-element list",
            "Test5: Inserting too many elements should fail",
            "Test6: insert_front() keeps moving elements forward",
            "Test7: inserting at different positions in the list",
            "Test8: try to remove too many elements, then add a few elements",
            "Test9: lots of inserts and deletes, all of them valid",
            "Test10: lots of inserts and deletes, some of them invalid",
            "Test11: Checking order of linking"
    };

    bool doubly_linked_list_test_results[TEST_COUNT];
    doubly_linked_list_test_results[0] = doubly_linked_list_test.test1();
    doubly_linked_list_test_results[1] = doubly_linked_list_test.test2();
    doubly_linked_list_test_results[2] = doubly_linked_list_test.test3();
    doubly_linked_list_test_results[3] = doubly_linked_list_test.test4();
    doubly_linked_list_test_results[4] = doubly_linked_list_test.test5();
    doubly_linked_list_test_results[5] = doubly_linked_list_test.test6();
    doubly_linked_list_test_results[6] = doubly_linked_list_test.test7();
    doubly_linked_list_test_results[7] = doubly_linked_list_test.test8();
    doubly_linked_list_test_results[8] = doubly_linked_list_test.test9();
    doubly_linked_list_test_results[9] = doubly_linked_list_test.test10();
    doubly_linked_list_test_results[10] = doubly_linked_list_test.test11();

    cout << "DOUBLY LINKED LIST TESTING RESULTS \n";
    cout << "******************************* \n";
    for (int i = 0; i < TEST_COUNT; ++i) {

        cout << doubly_linked_list_test_descriptions[i] << endl
             << get_status_str(doubly_linked_list_test_results[i]) << endl;

        if (doubly_linked_list_test_results[i])
            grade += 3;
    }
    grade += 10;
    cout << endl
         << "Sub-total grade: " << grade << "/" << TEST_COUNT * 3 + 10 << endl << endl;

    return grade;
}

unsigned int polynomialTest()
{
    unsigned int grade = 0;
    unsigned const int TEST_COUNT = 13;
    PolynomialTest polynomial_test;

    // Some feedback about the tests.
    string polynomial_test_descriptions[TEST_COUNT] = {
            "Test1: New polynomial is valid",
            "Test2: Operations between empty (0) polynomials results in empty polynomial",
            "Test3: Addition does not modify original polynomials",
            "Test4: Adding 0 results in the original polynomial",
            "Test5: Addition works",
            "Test6: Subtraction does not modify original polynomials",
            "Test7: Subtracting 0 results in the original polynomial",
            "Test8: Subtracting from 0 results in the negative polynomial",
            "Test9: Subtraction works",
            "Test10: Multiplication does not modify original polynomials",
            "Test11: Multiplying by 0 results in empty polynomial",
            "Test12: Multiplying by value 1 results in the original polynomial",
            "Test13: Multiplication works"
    };

    bool polynomial_test_results[TEST_COUNT];
    polynomial_test_results[0] = polynomial_test.test1();
    polynomial_test_results[1] = polynomial_test.test2();
    polynomial_test_results[2] = polynomial_test.test3();
    polynomial_test_results[3] = polynomial_test.test4();
    polynomial_test_results[4] = polynomial_test.test5();
    polynomial_test_results[5] = polynomial_test.test6();
    polynomial_test_results[6] = polynomial_test.test7();
    polynomial_test_results[7] = polynomial_test.test8();
    polynomial_test_results[8] = polynomial_test.test9();
    polynomial_test_results[9] = polynomial_test.test10();
    polynomial_test_results[10] = polynomial_test.test11();
    polynomial_test_results[11] = polynomial_test.test12();
    polynomial_test_results[12] = polynomial_test.test13();

    cout << "POLYNOMIAL TESTING RESULTS \n";
    cout << "******************************* \n";
    for (int i = 0; i < TEST_COUNT; ++i) {

        cout << polynomial_test_descriptions[i] << endl
             << get_status_str(polynomial_test_results[i]) << endl;

        if (polynomial_test_results[i])
            grade += 3;
    }
    grade += 10;
    cout << endl
         << "Sub-total grade: " << grade << "/" << TEST_COUNT * 3 + 10 << endl << endl;

    polynomialPrintManualTest();
    return grade;
}


// New empty list is valid
bool SequentialListTest::test1() {

    unsigned int capacity = 5;
    SequentialList list(capacity);

    ASSERT_TRUE(list.size() == 0)
    ASSERT_TRUE(list.capacity() == capacity)
    ASSERT_TRUE(list.empty() == true)
    ASSERT_TRUE(list.full() == false)

    return true;
}


// insert_front() and insert_back() on zero-element list
bool SequentialListTest::test2() {

    unsigned int capacity = 5;
    SequentialList list1(capacity);
    SequentialList list2(capacity);

    ASSERT_TRUE(list1.insert_front(100))
    ASSERT_TRUE(list2.insert_back(100))

    ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
    ASSERT_TRUE(list1.data_ != NULL)
    ASSERT_TRUE(list2.data_ != NULL)
    ASSERT_TRUE(list1.select(0) == list2.select(0) && list1.select(0) == 100)

    return true;
}


// select() and search() work properly
bool SequentialListTest::test3() {

    unsigned int capacity = 5;
    SequentialList list(capacity);

    for (unsigned int i = 0; i < capacity; i++) {
        ASSERT_TRUE(list.insert_back(i * 100))
    }

    unsigned int idx = 3;
    ASSERT_TRUE(list.search(list.select(idx)) == idx)
    ASSERT_TRUE(list.select(capacity + 1) == list.select(capacity))
    ASSERT_TRUE(list.search(1000) == list.size())

    for (unsigned int i = 0; i < capacity; i++) {
        ASSERT_TRUE(list.select(i) == i * 100 && list.data_[i] == i * 100)
    }

    return true;
}


// remove_front() and remove_back() on one-element list
bool SequentialListTest::test4() {

    unsigned int capacity = 5;
    SequentialList list1(capacity);
    SequentialList list2(capacity);

    ASSERT_TRUE(list1.insert_front(100))
    ASSERT_TRUE(list2.insert_front(100))
    ASSERT_TRUE(list1.remove_front())
    ASSERT_TRUE(list2.remove_back())

    ASSERT_TRUE(list1.size_ == list2.size_ && list1.size_ == 0)
    ASSERT_TRUE(list1.empty() == true && list2.empty() == true)

    return true;
}


// Inserting too many elements should fail
bool SequentialListTest::test5() {

    unsigned int capacity = 5;
    SequentialList list(capacity);

    // Fill up the list.
    for (unsigned int i = 0; i < capacity; i++) {
        ASSERT_TRUE(list.insert_back(i))
    }

    // Try overfilling (they should all return false with no modifications).
    int val_not_inserted = 100;
    ASSERT_FALSE(list.insert_back(val_not_inserted))
    ASSERT_FALSE(list.insert_front(val_not_inserted))
    ASSERT_FALSE(list.insert(val_not_inserted, 3))

    // Check size is correct.
    ASSERT_TRUE(list.full() == true && list.empty() == false)
    ASSERT_TRUE(list.size_ == list.capacity_ && list.capacity_ == capacity)

    return true;
}


// insert_front() keeps moving elements forward
bool SequentialListTest::test6() {

    unsigned int capacity = 5;
    SequentialList list(capacity);

    for (unsigned int i = 0; i < capacity; i++) {

        ASSERT_TRUE(list.insert_front(i))
        ASSERT_TRUE(list.size_ == (i + 1))

        for (int j = 0; j <= i; j++) {
            SequentialList::DataType expected_value = i - j;
            ASSERT_TRUE(list.data_[j] == expected_value)
        }
    }
    return true;
}


// inserting at different positions in the list succeeds
bool SequentialListTest::test7() {

    unsigned int capacity = 10;
    SequentialList list(capacity);

    for (int i = 0; i < 4; i++) {
        ASSERT_TRUE(list.insert_back(i))
    }

    ASSERT_TRUE(list.insert(4, 1))
    ASSERT_TRUE(list.insert(5, 1))
    ASSERT_TRUE(list.insert(6, 5))
    ASSERT_TRUE(list.insert(7, 7))

    // Check that the list has the right values.
    int expected_values[] = {0, 5, 4, 1, 2, 6, 3, 7};
    ASSERT_TRUE(list.size_ == 8)
    for (int i = 0; i < list.size_; i++) {
        ASSERT_TRUE(list.data_[i] == expected_values[i])
    }

    return true;
}


// try to remove too many elements, then add a few elements
bool SequentialListTest::test8() {

    unsigned int capacity = 5;
    const int num_elems = 4;
    SequentialList list(capacity);

    for (int i = 0; i < num_elems; i++) {
        ASSERT_TRUE(list.insert_back(i))
    }

    for (int i = 0; i < num_elems; i++) {
        ASSERT_TRUE(list.remove_back())
    }

    // Try a bunch of invalid commands.
    ASSERT_FALSE(list.remove_front())
    ASSERT_FALSE(list.remove_front())
    ASSERT_FALSE(list.remove(0))
    ASSERT_TRUE(list.empty() && list.size_ == 0)

    int expected_value = 1234;
    ASSERT_TRUE(list.insert(expected_value, 0))
    ASSERT_TRUE(list.data_[0] == expected_value)

    return true;
}


// lots of inserts and deletes, all of them valid
bool SequentialListTest::test9() {

    unsigned int capacity = 5;
    SequentialList list(capacity);

    ASSERT_TRUE(list.insert_back(32))
    ASSERT_TRUE(list.insert_front(44))
    ASSERT_TRUE(list.insert(12, 2))
    ASSERT_TRUE(list.remove_back())
    ASSERT_TRUE(list.remove_front())
    ASSERT_TRUE(list.insert_back(88))
    ASSERT_TRUE(list.remove(1))
    ASSERT_TRUE(list.insert(99, 0))

    // Check that the list has the right values
    ASSERT_TRUE(list.select(0) == 99 && list.data_[0] == 99)
    ASSERT_TRUE(list.select(1) == 32 && list.data_[1] == 32)

    return true;
}


// lots of inserts and deletes, some of them invalid
bool SequentialListTest::test10() {

    unsigned int capacity = 5;
    SequentialList list(capacity);

    ASSERT_FALSE(list.remove(0))
    ASSERT_TRUE(list.insert_back(32))
    ASSERT_TRUE(list.insert_front(44))
    ASSERT_FALSE(list.insert(12, 3))
    ASSERT_TRUE(list.insert(12, 2))
    ASSERT_TRUE(list.remove_back())
    ASSERT_FALSE(list.remove(5))
    ASSERT_TRUE(list.remove_front())
    ASSERT_TRUE(list.insert_back(88))
    ASSERT_FALSE(list.insert(12345, 6))
    ASSERT_TRUE(list.remove(1))
    ASSERT_TRUE(list.insert(99, 0))

    // Check that the list has the right values
    ASSERT_TRUE(list.select(0) == 99 && list.data_[0] == 99)
    ASSERT_TRUE(list.select(1) == 32 && list.data_[1] == 32)

    return true;
}

// New empty list is valid
bool DoublyLinkedListTest::test1() {

    DoublyLinkedList list;
    ASSERT_TRUE(list.size() == 0)
    ASSERT_TRUE(list.empty() == true)
    ASSERT_TRUE(list.full() == false)
    ASSERT_TRUE(list.head_ == nullptr)
    ASSERT_TRUE(list.tail_ == nullptr)
    return true;
}


// insert_front() and insert_back() on zero-element list
bool DoublyLinkedListTest::test2() {

    DoublyLinkedList list1;
    DoublyLinkedList list2;

    ASSERT_TRUE(list1.insert_front(100))
    ASSERT_TRUE(list2.insert_back(100))

    ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
    ASSERT_TRUE(list1.head_ != NULL && list1.head_ == list1.tail_)
    ASSERT_TRUE(list2.head_ != NULL && list2.head_ == list2.tail_)
    ASSERT_TRUE(list1.select(0) == list2.select(0) && list1.select(0) == 100)
    return true;
}


// select() and search() work properly
bool DoublyLinkedListTest::test3() {

    int capacity = 5;
    DoublyLinkedList list;

    for (unsigned int i = 0; i < capacity; i++)
        ASSERT_TRUE(list.insert_back(i * 100))

    unsigned int idx = 3;
    ASSERT_TRUE(list.search(list.select(idx)) == idx)
    ASSERT_TRUE(list.select(capacity + 1) == list.select(capacity))
    ASSERT_TRUE(list.select(capacity) == list.select(capacity-1))
    ASSERT_TRUE(list.search(1000) == list.size())

    for (unsigned int i = 0; i < capacity; i++) {
        ASSERT_TRUE(list.select(i) == i * 100)
    }

    return true;
}


// remove_front() and remove_back() on one-element list
bool DoublyLinkedListTest::test4() {

    unsigned int capacity = 5;
    DoublyLinkedList list1;
    DoublyLinkedList list2;

    ASSERT_TRUE(list1.insert_front(100))
    ASSERT_TRUE(list2.insert_front(100))
    ASSERT_TRUE(list1.remove_front())
    ASSERT_TRUE(list2.remove_back())

    ASSERT_TRUE(list1.head_ == nullptr && list1.tail_ == nullptr);
    ASSERT_TRUE(list2.head_ == nullptr && list2.tail_ == nullptr);
    ASSERT_TRUE(list1.size_ == list2.size_ && list1.size_ == 0)
    ASSERT_TRUE(list1.empty() == true && list2.empty() == true)

    return true;
}


// Inserting too many elements should fail
bool DoublyLinkedListTest::test5() {

    DoublyLinkedList list;

    // Fill up the list.
    for (unsigned int i = 0; i < list.capacity(); i++) {
        ASSERT_TRUE(list.insert_back(i))
    }

    // Try overfilling (they should all return false with no modifications).
    int val_not_inserted = 100;
    ASSERT_FALSE(list.insert_back(val_not_inserted))
    ASSERT_FALSE(list.insert_front(val_not_inserted))
    ASSERT_FALSE(list.insert(val_not_inserted, 3))

    // Check size is correct.
    ASSERT_TRUE(list.full() == true && list.empty() == false)
    ASSERT_TRUE(list.size_ == list.capacity())
    return true;
}


// insert_front() keeps moving elements forward
bool DoublyLinkedListTest::test6() {

    unsigned int capacity = 5;
    DoublyLinkedList list;

    for (int i = 0; i < capacity; i++) {

        ASSERT_TRUE(list.insert_front(i))
        ASSERT_TRUE(list.size_ == (i + 1))

        for (int j = 0; j <= i; j++) {
            SequentialList::DataType expected_value = i - j;
            ASSERT_TRUE(list.select(j) == expected_value)
        }
    }
    return true;
}


// inserting at different positions in the list succeeds
bool DoublyLinkedListTest::test7() {

    DoublyLinkedList list;

    for (int i = 0; i < 4; i++) {
        ASSERT_TRUE(list.insert_back(i))
    }

    ASSERT_TRUE(list.insert(4, 1))
    ASSERT_TRUE(list.insert(5, 1))
    ASSERT_TRUE(list.insert(6, 5))
    ASSERT_TRUE(list.insert(7, 7))

    // Check that the list has the right values.
    int expected_values[] = {0, 5, 4, 1, 2, 6, 3, 7};
    ASSERT_TRUE(list.size_ == 8)
    for (int i = 0; i < list.size_; i++)
        ASSERT_TRUE(list.select(i) == expected_values[i])

    return true;
}


// try to remove too many elements, then add a few elements
bool DoublyLinkedListTest::test8() {

    const int num_elems = 4;
    DoublyLinkedList list;

    for (int i = 0; i < num_elems; i++) {
        ASSERT_TRUE(list.insert_back(i))
    }

    for (int i = 0; i < num_elems; i++) {
        ASSERT_TRUE(list.remove_back())
    }

    // Try a bunch of invalid commands.
    ASSERT_FALSE(list.remove_front())
    ASSERT_FALSE(list.remove_front())
    ASSERT_FALSE(list.remove(0))
    ASSERT_TRUE(list.empty() && list.size_ == 0)

    int expected_value = 1234;
    ASSERT_TRUE(list.insert(expected_value, 0))
    ASSERT_TRUE(list.head_->value == expected_value)

    return true;
}


// lots of inserts and deletes, all of them valid
bool DoublyLinkedListTest::test9() {

    DoublyLinkedList list;

    ASSERT_TRUE(list.insert_back(32))
    ASSERT_TRUE(list.insert_front(44))
    ASSERT_TRUE(list.insert(12, 2))
    ASSERT_TRUE(list.remove_back())
    ASSERT_TRUE(list.remove_front())
    ASSERT_TRUE(list.insert_back(88))
    ASSERT_TRUE(list.remove(1))
    ASSERT_TRUE(list.insert(99, 0))

    // Check that the list has the right values
    ASSERT_TRUE(list.select(0) == 99 && list.head_->value == 99)
    ASSERT_TRUE(list.select(1) == 32 && list.head_->next->value == 32)

    return true;
}


// lots of inserts and deletes, some of them invalid
bool DoublyLinkedListTest::test10() {

    DoublyLinkedList list;

    ASSERT_FALSE(list.remove(0))
    ASSERT_TRUE(list.insert_back(32))
    ASSERT_TRUE(list.insert_front(44))
    ASSERT_FALSE(list.insert(12, 3))
    ASSERT_TRUE(list.insert(12, 2))
    ASSERT_TRUE(list.remove_back())
    ASSERT_FALSE(list.remove(5))
    ASSERT_TRUE(list.remove_front())
    ASSERT_TRUE(list.insert_back(88))
    ASSERT_FALSE(list.insert(12345, 6))
    ASSERT_TRUE(list.remove(1))
    ASSERT_TRUE(list.insert(99, 0))

    // Check that the list has the right values
    ASSERT_TRUE(list.select(0) == 99 && list.head_->value == 99)
    ASSERT_TRUE(list.select(1) == 32 && list.head_->next->value == 32)

    return true;
}

bool DoublyLinkedListTest::test11()
{
    int values[10] = {0, 5, 2, 4, 7, 1, 13, 82, 12, 18};

    DoublyLinkedList list;

    for (int i = 0; i < 10; i++)
        list.insert_back(values[i]);

    DoublyLinkedList::Node * current = list.head_;
    for (int i = 0; i < 10; i++)
    {
        ASSERT_TRUE(current->value == values[i])
        current = current->next;
    }

    ASSERT_TRUE(current == nullptr)

    current = list.tail_;
    for (int i = 9; i >= 0; i--)
    {
        ASSERT_TRUE(current->value == values[i])
        current = current->prev;
    }

    ASSERT_TRUE(current == nullptr)

    return true;
}

// New polynomial is valid
bool PolynomialTest::test1()
{

    int c1[5] = {0};
    int c2[5] = {1, 5, 9, 1,2};

    //Polynomial p1(nullptr, 5);
    Polynomial p2(c1, 0);
    //Polynomial p3(nullptr, 0);
    Polynomial p4(c1, 5);
    Polynomial p5(c2, 5);

    //ASSERT_TRUE(p1.list->size() == 0)
    ASSERT_TRUE(p2.list->size() == 0)
    //ASSERT_TRUE(p3.list->size() == 0)
    ASSERT_TRUE(p4.list->size() == 5)

    for (int i = 0; i < 5; i++)
        ASSERT_TRUE(p4.list->select(i) == 0)

    ASSERT_TRUE(p5.list->size() == 5)

    for (int i = 0; i < 5; i++)
        ASSERT_TRUE(p5.list->select(i) == c2[i])

    return true;
}

// Operations between empty (0) polynomials results in empty polynomial
bool PolynomialTest::test2()
{
    const unsigned int SIZE = 5;
    int zC[SIZE] = {0};
    int zD[0];

    Polynomial p(zC, SIZE);

    Polynomial emptyP1(zC, SIZE);
    //Polynomial emptyP2(zC, 1);
    Polynomial emptyP3(zD, 0);

    Polynomial * result1 = p.add(&emptyP1);
    Polynomial * result2 = emptyP1.sub(&p);
    //Polynomial * result3 = p.mul(&emptyP2);
    //Polynomial * result4 = emptyP2.add(&p);
    Polynomial * result5 = p.sub(&emptyP3);
    Polynomial * result6 = emptyP3.mul(&p);

    for (int i = 0; i < SIZE; i++)
    {
        ASSERT_TRUE(result1->list->select(i) == 0)
        ASSERT_TRUE(result1->list->select(i) == 0)
        ASSERT_TRUE(result2->list->select(i) == 0)
        //ASSERT_TRUE(result3->list->select(i) == 0)
        //ASSERT_TRUE(result4->list->select(i) == 0)
        ASSERT_TRUE(result5->list->select(i) == 0)
        ASSERT_TRUE(result6->list->select(i) == 0)
    }

    return true;
}

// Addition does not modify original polynomials
bool PolynomialTest::test3()
{
    const unsigned int SIZE = 5;
    int c1[SIZE] = {1, -5, 7, 2, 9};
    int c2[SIZE]= {1, 9, -2, 9, 3};

    Polynomial p1(c1, SIZE);
    Polynomial p2(c2, SIZE);

    //Polynomial * result1 = p1.add(&p2);
    //Polynomial * result2 = p2.add(&p1);

    for (int i = 0; i < SIZE; ++i)
   {
        ASSERT_TRUE(p1.list->select(i) == c1[i])
        ASSERT_TRUE(p2.list->select(i) == c2[i])
    }

    return true;
}

// Adding 0 results in the original polynomial
bool PolynomialTest::test4()
{
    const unsigned int SIZE = 5;
    int c[SIZE] = {2, 6, 1, 8, 2};
    int zC[SIZE] = {0};

    Polynomial p(c, SIZE);

    Polynomial emptyP1(zC, SIZE);
    Polynomial emptyP2(zC, 1);
    Polynomial emptyP3(nullptr, 0);

    Polynomial* result1 = p.add(&emptyP1);
    Polynomial* result2 = emptyP1.add(&p);
    Polynomial* result3 = p.add(&emptyP2);
    Polynomial* result4 = emptyP2.add(&p);
    Polynomial* result5 = p.add(&emptyP3);
    Polynomial* result6 = emptyP3.add(&p);

    for (int i = 0; i < SIZE; i++)
    {
        ASSERT_TRUE(p.list->select(i) == c[i])
        ASSERT_TRUE(result1->list->select(i) == c[i])
        ASSERT_TRUE(result2->list->select(i) == c[i])
        ASSERT_TRUE(result3->list->select(i) == c[i])
        ASSERT_TRUE(result4->list->select(i) == c[i])
        ASSERT_TRUE(result5->list->select(i) == c[i])
        ASSERT_TRUE(result6->list->select(i) == c[i])
    }

    return true;
}

// Addition works
bool PolynomialTest::test5()
{
    const unsigned int SIZE1 = 5;
    const unsigned int SIZE2 = 10;
    int c1[SIZE1] = {2, 3, 1, 9, -8};
    int c2[SIZE2] = {2, 9, -10, 2, 7, 1, 0, 4, -5, 46};

    Polynomial p1(c1, SIZE1);
    Polynomial p2(c2, SIZE2);

    Polynomial * result1 = p1.add(&p2);
    Polynomial * result2 = p2.add(&p1);

    unsigned int maxSize = std::max(SIZE1, SIZE2);

    for (int i = 0; i < maxSize; i++)
    {
        int c1v = (i < SIZE1) ? c1[i] : 0;
        int c2v = (i < SIZE2) ? c2[i] : 0;

        ASSERT_TRUE(result1->list->select(i) == result2->list->select(i))
        ASSERT_TRUE(result1->list->select(i) == c1v + c2v)
    }

    return true;
}

// Subtraction does not modify original polynomials
bool PolynomialTest::test6()
{
    const unsigned int SIZE = 5;
    int c1[SIZE] = {1, -5, 7, 2, 9};
    int c2[SIZE]= {1, 9, -2, 9, 3};

    Polynomial p1(c1, SIZE);
    Polynomial p2(c2, SIZE);

    Polynomial * result1 = p1.sub(&p2);
    Polynomial * result2 = p2.sub(&p1);

    for (int i = 0; i < SIZE; ++i)
    {
        ASSERT_TRUE(p1.list->select(i) == c1[i])
        ASSERT_TRUE(p2.list->select(i) == c2[i])
    }

    return true;
}

// Subtracting 0 results in the original polynomial
bool PolynomialTest::test7()
{
    const unsigned int SIZE = 5;
    int c[SIZE] = {-2, 6, 1, -8, 2};
    int zC[SIZE] = {0};

    Polynomial p(c, SIZE);

    Polynomial emptyP1(zC, SIZE);
    Polynomial emptyP2(zC, 1);
    Polynomial emptyP3(nullptr, 0);

    Polynomial* result1 = p.sub(&emptyP1);
    Polynomial* result2 = p.sub(&emptyP2);
    Polynomial* result3 = p.sub(&emptyP3);


    for (int i = 0; i < SIZE; i++)
    {
        ASSERT_TRUE(p.list->select(i) == c[i])
        ASSERT_TRUE(result1->list->select(i) == c[i])
        ASSERT_TRUE(result2->list->select(i) == c[i])
        ASSERT_TRUE(result3->list->select(i) == c[i])
    }

    return true;
}

// Subtracting from 0 results in the negative polynomial
bool PolynomialTest::test8()
{
    const unsigned int SIZE = 5;
    int c[SIZE] = {-2, 6, 1, -8, 2};
    int zC[SIZE] = {0};

    Polynomial p(c, SIZE);

    Polynomial emptyP1(zC, SIZE);
    Polynomial emptyP2(zC, 1);
    Polynomial emptyP3(nullptr, 0);

    Polynomial* result1 = emptyP1.sub(&p);
    Polynomial* result2 = emptyP2.sub(&p);
    Polynomial* result3 = emptyP3.sub(&p);

    for (int i = 0; i < SIZE; i++)
    {
        ASSERT_TRUE(p.list->select(i) == c[i])
        ASSERT_TRUE(result1->list->select(i) == -c[i])
        ASSERT_TRUE(result2->list->select(i) == -c[i])
        ASSERT_TRUE(result3->list->select(i) == -c[i])
    }

    return true;
}

// Subtraction works
bool PolynomialTest::test9()
{
    const unsigned int SIZE1 = 5;
    const unsigned int SIZE2 = 10;
    int c1[SIZE1] = {2, 3, 1, 9, 8};
    int c2[SIZE2] = {2, -9, 10, 2, 7, -1, 0, 4, 5, 46};

    Polynomial p1(c1, SIZE1);
    Polynomial p2(c2, SIZE2);

    Polynomial * result1 = p1.sub(&p2);
    Polynomial * result2 = p2.sub(&p1);

    for (int i = 0; i < result1->list->size(); i++)
    {
        int c1v = (i < SIZE1) ? c1[i] : 0;
        int c2v = (i < SIZE2) ? c2[i] : 0;

        ASSERT_TRUE(result1->list->select(i) == c1v - c2v)
        ASSERT_TRUE(result2->list->select(i) == c2v - c1v)
    }

    return true;
}

// Multiplication does not modify original polynomials
bool PolynomialTest::test10()
{
    const unsigned int SIZE = 5;
    int c1[SIZE] = {1, -5, 7, 2, 9};
    int c2[SIZE]= {1, 9, -2, 9, 3};

    Polynomial p1(c1, SIZE);
    Polynomial p2(c2, SIZE);

    Polynomial * result1 = p1.mul(&p2);
    Polynomial * result2 = p2.mul(&p1);

    for (int i = 0; i < SIZE; ++i)
    {
        ASSERT_TRUE(p1.list->select(i) == c1[i])
        ASSERT_TRUE(p2.list->select(i) == c2[i])
    }

    return true;
}

// Multiplying by 0 results in empty polynomial
bool PolynomialTest::test11()
{
    const unsigned int SIZE = 5;
    int c[SIZE] = {-2, 6, 1, -8, 2};
    int zC[SIZE] = {0};

    Polynomial p(c, SIZE);

    Polynomial emptyP1(zC, SIZE);
    Polynomial emptyP2(zC, 1);
    Polynomial emptyP3(nullptr, 0);

    Polynomial* result1 = p.mul(&emptyP1);
    Polynomial* result2 = emptyP1.mul(&p);
    Polynomial* result3 = p.mul(&emptyP2);
    Polynomial* result4 = emptyP2.mul(&p);
    Polynomial* result5 = p.mul(&emptyP3);
    Polynomial* result6 = emptyP3.mul(&p);

    for (int i = 0; i < result1->list->size(); i++)
    {
        ASSERT_TRUE(result1->list->select(i) == 0)
        ASSERT_TRUE(result2->list->select(i) == 0)
        ASSERT_TRUE(result3->list->select(i) == 0)
        ASSERT_TRUE(result4->list->select(i) == 0)
        ASSERT_TRUE(result5->list->select(i) == 0)
        ASSERT_TRUE(result6->list->select(i) == 0)
    }

    return true;
}

// Multiplying by 1 results in same polynomial
bool PolynomialTest::test12()
{
    const unsigned int SIZE = 5;
    int c[SIZE] = {-2, 6, 1, -8, 2};
    int oPC[1] = {1};

    Polynomial p(c, SIZE);
    Polynomial oP(oPC, 1);

    Polynomial* result1 = p.mul(&oP);
    Polynomial* result2 = oP.mul(&p);

    for (int i = 0; i < result1->list->size(); i++)
    {
        ASSERT_TRUE(p.list->select(i) == c[i])
        ASSERT_TRUE(result1->list->select(i) == c[i])
        ASSERT_TRUE(result2->list->select(i) == c[i])
    }

    return true;
}

// Multiplication works
bool PolynomialTest::test13()
{
    const unsigned int SIZE1 = 5;
    const unsigned int SIZE2 = 8;
    int c1[SIZE1] = {-2, 6, 1, -8, 2};
    int c2[SIZE2] = {3, 1, 7, 4, -5, 8, 125, -2};
    int resultC[] = {-6, 16, -5, 11, 39, -96, -225, 810, 39, -986, 266, -4};

    Polynomial p1(c1, SIZE1);
    Polynomial p2(c2, SIZE2);

    Polynomial * result1 = p1.mul(&p2);
    Polynomial * result2 = p2.mul(&p1);

    ASSERT_TRUE(result1->list->size() == result2->list->size())
    ASSERT_TRUE(result1->list->size() == (sizeof(resultC)/sizeof(int)))

    for (int i = 0; i < result1->list->size(); i++)
    {
        ASSERT_TRUE(result1->list->select(i) == resultC[i])
        ASSERT_TRUE(result1->list->select(i) == result2->list->select(i))
    }

    return true;
}

//  Test print
void polynomialPrintManualTest()
{
    int c1[] = {2, 3, 2, -2, 0};
    int c2[] = {0};
    int c3[] = {-3, 0, 0, 0, 0, 0, -8};

    Polynomial p1(c1, sizeof(c1)/sizeof(int));
    Polynomial p2(c2, sizeof(c2)/sizeof(int));
    Polynomial p3(c3, sizeof(c3)/sizeof(int));
    Polynomial p4(nullptr, 25);
    Polynomial p5(c1, 0);
    Polynomial p6(nullptr, 0);

    cout << "Print Manual Test" << endl;
    cout << "*****************" << endl << endl;
    cout << "For each statement below, check that the LHS matches the RHS EXACTLY" << endl;

    std::cout << "1. (-2)x^3 + 2x^2 + 3x^1 + 2x^0 = ";
    p1.print();

    std::cout << "2. empty = ";
    p2.print();

    std::cout << "3. (-8)x^6 + (-3)x^0 = ";
    p3.print();

    std::cout << "4. empty = ";
    p4.print();

    std::cout << "5. empty = ";
    p5.print();

    std::cout << "6. empty = ";
    p6.print();
}