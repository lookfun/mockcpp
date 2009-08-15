/***
    mockcpp is a generic C/C++ mock framework.
    Copyright (C) <2009>  <Darwin Yuan: darwin.yuan@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#include <cxxtest/TestSuite.h>

#include <mockcpp/MemoryCheckPoint.h>

#include <mockcpp/IsStringStartWith.h>

USING_MOCKCPP_NS

class TestIsStringStartWith: public CxxTest::TestSuite
{
private:

   MemoryCheckPoint checkpoint;

public:

   void setUp()
   {
      checkpoint = mockcppSetCheckPoint();

   }
   void tearDown()
   {
      MOCKCPP_CHECK_POINT_VERIFY(checkpoint);
   }

	/////////////////////////////////////////////////////////

	void testShouldReturnTrueIfTheParameterDoesStartWithSpecifiedString()
	{
       IsStringStartWith constraint;

       std::string input("abcdefg");
       std::string target("abcd");

       TS_ASSERT(constraint.predict(input, target));
	}

	void testShouldReturnFalseIfTheParameterDoesNotStartWithSpecifiedString()
	{
       IsStringStartWith constraint;

       std::string input("abcfefg");
       std::string target("abcd");

       TS_ASSERT(!constraint.predict(input, target));
	}

	void testShouldBeAbleConvertToRequiredFormattedString()
	{
       IsStringStartWith constraint;

       TS_ASSERT_EQUALS(std::string("startWith(\"abcd\")"), constraint.toString("abcd"));
	}
};

