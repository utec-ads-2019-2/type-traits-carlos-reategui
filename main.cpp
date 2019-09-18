#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    //Tester::execute();

    SelfList<int> moveList(SelfList<int>::Move);

    moveList.insert(5);
    moveList.insert(4);
    moveList.insert(3);
    moveList.insert(2);
    moveList.insert(1);

    ASSERT(moveList.operator[](0) == 1,"Move list has problems inserting elements");
    ASSERT(moveList.operator[](1) == 2,"Move list has problems inserting elements");
    ASSERT(moveList.operator[](2) == 3,"Move list has problems inserting elements");
    ASSERT(moveList.operator[](3) == 4,"Move list has problems inserting elements");
    ASSERT(moveList.operator[](4) == 5,"Move list has problems inserting elements");
    ASSERT(moveList.size() == 5,"Move list size has problems");

    moveList.remove(1);

    ASSERT(moveList.operator[](0) == 2,"Move list has problems deleting elements");

    moveList.insert(1);

    moveList.find(4);
    moveList.find(5);

    ASSERT(moveList.operator[](0) == 5,"Move list has problems finding elements");
    ASSERT(moveList.operator[](1) == 4,"Move list has problems finding elements");

/*--------------------------------------------------------------------------------------------------------------------*/

    SelfList<int> transposeList(SelfList<int>::Transpose);

    transposeList.insert(5);
    transposeList.insert(4);
    transposeList.insert(3);
    transposeList.insert(2);
    transposeList.insert(1);

    ASSERT(transposeList.operator[](0) == 1,"Transpose list has problems inserting elements");
    ASSERT(transposeList.operator[](1) == 2,"Transpose list has problems inserting elements");
    ASSERT(transposeList.operator[](2) == 3,"Transpose list has problems inserting elements");
    ASSERT(transposeList.operator[](3) == 4,"Transpose list has problems inserting elements");
    ASSERT(transposeList.operator[](4) == 5,"Transpose list has problems inserting elements");
    ASSERT(transposeList.size() == 5,"Transpose list size has problems");

    transposeList.remove(1);

    ASSERT(transposeList.operator[](0) == 2,"Transpose list has problems deleting elements");

    transposeList.insert(1);

    transposeList.find(4);
    transposeList.find(5);

    ASSERT(transposeList.operator[](3) == 5,"Transpose list has problems finding elements");
    ASSERT(transposeList.operator[](2) == 4,"Transpose list has problems finding elements");

/*--------------------------------------------------------------------------------------------------------------------*/

    SelfList<int> countList(SelfList<int>::Count);

    countList.insert(5);
    countList.insert(4);
    countList.insert(3);
    countList.insert(2);
    countList.insert(1);

    ASSERT(countList.operator[](0) == 1,"Count list has problems inserting elements");
    ASSERT(countList.operator[](1) == 2,"Count list has problems inserting elements");
    ASSERT(countList.operator[](2) == 3,"Count list has problems inserting elements");
    ASSERT(countList.operator[](3) == 4,"Count list has problems inserting elements");
    ASSERT(countList.operator[](4) == 5,"CountCount list has problems inserting elements");
    ASSERT(countList.size() == 5,"Count list size has problems");

    countList.remove(1);

    ASSERT(countList.operator[](0) == 2,"Count list has problems deleting elements");

    countList.insert(1);

    countList.find(2);
    countList.find(3);
    countList.find(3);
    countList.find(4);

    ASSERT(countList.operator[](0) == 3,"Count list has problems finding elements");
    ASSERT(countList.operator[](1) == 4,"Count list has problems finding elements");
    ASSERT(countList.operator[](2) == 2,"Count list has problems finding elements");

    return EXIT_SUCCESS;
}

