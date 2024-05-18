#pragma once

/*
         ALL MACRO HERE WILL USE PREFIX 'AKL' (AOUES KADDA LIBRARY)

*/


//  this macro taken from mozilla-central/mfbt/MacroArgs.h

// variadic macro

// Concatenates pre-processor tokens in a way that can be used with __line__.
#define	 AKL_CONCAT2(x,y)              x##y
#define  AKL_CONCAT(x,y)			   CONCAT2(x,y)


/*
* ARG_COUNT(...)	count the number of variadic arguments.
* you must pass in between 0 and 50 (include) variadic arguments.
* For example:
* 
*       ARG_COUNT()            expands to 0
*       ARG_COUNT(a)           expands to 1
*		ARG_COUNT(a,b)		   expands to 2
* 
* Implementation notes :
*   The ##__VA_ARGS__ form is a GCC extension that removes the comma if 
*   __VA_ARGS__ is empty. It is supported by Clang too. MSVC ignores ##, and 
* its default behavior is already to strip the comma when __VA_ARGS__ is empty.
*/

#define AKL_ARG_COUNT(...)              \
        AKL_MACROARGS_ARG_COUNT_HELPER2(AKL_MACROARGS_ARG_COUNT_HELPER(__VA_ARGS__))

#define AKL_MACROARG_ARG_COUNT_HELPER(...)                                    \
 (_, ##__VA_ARGS__, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37,   \
  36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, \
  17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3 ,2, 1, 0)

#define AKL_MACROARGS_ARG_COUNT_HELPER2(aArgs) \
  AKL_MACROARGS_ARG_COUNT_HELPER3  aArgs

#define AKL_MACROARGS_ARG_COUNT_HELPER3(                                        \
   a0 ,a1 ,a2 ,a3 ,a4 ,a5 ,a6 ,a7 ,a8 ,a9 ,a10 ,a11 ,a12 ,a13 ,a14 ,a15 ,a16 ,  \
   a17 ,a18 ,a19 ,a20 ,a21 ,a22 ,a23 ,a24 ,a25 ,a26 ,a27 ,a28 ,a29 ,a30 ,a31 ,  \
   a32 ,a33 ,a34 ,a35 ,a36 ,a37 ,a38 ,a39 ,a40 ,a41 ,a42 ,a43 ,a44 ,a45 ,a46 ,  \
   a47 ,a48 ,a49 ,a50, a51, ... )                                               \
a51

// AKL_ARG_N expands to its |N|th argument.

#define AKL_ARG_1(a1, ...)    a1
#define AKL_ARG_2(a1, a2, ...)    a2
#define AKL_ARG_3(a1, a2, a3, ...)    a3
#define AKL_ARG_4(a1, a2, a3, a4, ...)    a4
#define AKL_ARG_5(a1, a2, a3, a4, a5, ...)    a5
#define AKL_ARG_6(a1, a2, a3, a4, a5, a6, ...)    a6
#define AKL_ARG_7(a1, a2, a3, a4, a5, a6, a7, ...)    a7
#define AKL_ARG_8(a1, a2, a3, a4, a5, a6, a7, a8, ...)    a8
#define AKL_ARG_9(a1, a2, a3, a4, a5, a6, a7, a8, a9, ...)    a9
