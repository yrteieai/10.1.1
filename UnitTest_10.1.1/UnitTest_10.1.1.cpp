#include "pch.h"
#include "CppUnitTest.h"
#include "../10.1.1/10.1.1.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1011
{
    TEST_CLASS(UnitTest1011)
    {
    public:

        TEST_METHOD(TestFindStudentsWithMark5)
        {
            Student students[3] = {
                {"Kotovych", I, IN, {}, 4, 4},
                {"Strogan", II, ME, {}, 5, 5},
                {"Voloshchuk", III, KN, {}, 3, 3}
            };

            students[0].marks.mark_cs = 5;
            students[1].marks.mark_cs = 5;
            students[2].marks.mark_cs = 3;

            int result = find_students_with_mark_5(students, 3);
            Assert::AreEqual(2, result); 
        }

        

        TEST_METHOD(TestFindStudentsWithMark3)
        {
            Student students[3] = {
                {"Kotovych", I, IN, {}, 3, 3},
                {"Strogan", II, ME, {}, 4, 4},
                {"Voloshchuk", III, KN, {}, 5, 5}
            };

            students[0].marks.mark_cs = 3;
            students[1].marks.mark_cs = 3;
            students[2].marks.mark_cs = 5;

            int result = find_students_with_mark_3(students, 3);
            Assert::AreEqual(2, result); 
        }

    };
}
