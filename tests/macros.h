/* Common macros used by gnulib tests.
   Copyright (C) 2006-2009 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */


/* This file contains macros that are used by many gnulib tests.
   Put here only frequently used macros, say, used by 10 tests or more.  */

#include <stdio.h>
#include <stdlib.h>

/* ASSERT (condition);
   verifies that the specified condition is fulfilled.  If not, a message
   is printed to stderr and the program is terminated with an error code.

   This macro has the following properties:
     - The programmer specifies the expected condition, not the failure
       condition.  This simplifies thinking.
     - The condition is tested always, regardless of compilation flags.
       (Unlike the macro from <assert.h>.)
     - On Unix platforms, the tester can debug the test program with a
       debugger (provided core dumps are enabled: "ulimit -c unlimited").
     - For the sake of platforms where no debugger is available (such as
       some mingw systems), an error message is printed on stderr that
       includes the source location of the ASSERT invocation.
 */
#define ASSERT(expr) \
  do                                                                         \
    {                                                                        \
      if (!(expr))                                                           \
        {                                                                    \
          fprintf (stderr, "%s:%d: assertion failed\n", __FILE__, __LINE__); \
          fflush (stderr);                                                   \
          abort ();                                                          \
        }                                                                    \
    }                                                                        \
  while (0)

/* SIZEOF (array)
   returns the number of elements of an array.  It works for arrays that are
   declared outside functions and for local variables of array type.  It does
   *not* work for function parameters of array type, because they are actually
   parameters of pointer type.  */
#define SIZEOF(array) (sizeof (array) / sizeof (array[0]))