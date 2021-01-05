/**
* Taak 2 - Woordpiramide deel 2
* Imperatief Programmeren
* Universiteit Hasselt - Academiejaar 2020-2021
*
* Naam: Abdulkader Hammal
* Studentennummer: 2055522
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#define ALPHABET_SIZE 26

typedef struct Pyramid {
    char** words;
    int numWords;
} Pyramid;

/**
 * Sort the words in a pyramid by ascending word length
 * @param pyramid the word pyramid
 * @post pyramid is an out-parameter and its words will be sorted when this function finishes
 */

void swapArray(const Pyramid* pyramid, int i, int j)
{
    char* tmp;
    tmp = pyramid->words[i];
    pyramid->words[i] = pyramid->words[j];
    pyramid->words[j] = tmp;
}

void sortPyramid(const Pyramid* pyramid)
{
    for (int i = 0; i < pyramid->numWords; i++)
    {
        for (int j = i + 1; j < pyramid->numWords; j++)
        {
            if (strlen(pyramid->words[i]) > strlen(pyramid->words[j]))
                swapArray(pyramid, i, j);
        }
    }
}

/**
 * Create and populate the buckets with the letter occurrences
 *
 * @param word: the letters that need to be counted
 * @param buckets: counters for each letter in the alphabet
 * @pre buckets: are initialized to 0
 */
void populateWordBuckets(const char* word, int buckets[ALPHABET_SIZE])
{    // TODO
    int i = 0;
    for (i = 0; i < ALPHABET_SIZE; i++)
        buckets[i] = 0;
    for (i = 0; i < strlen(word); i++)
        buckets[word[i] - 'a']++;
}

/**
 * Check if a list of words can form a pyramid
 * @param pyramid the word pyramid
 */
bool isWordPyramid(const Pyramid* pyramid)
{    // TODO
    sortPyramid(pyramid);
    int i = 0;
    for (i = 0; i < pyramid->numWords - 1; i++)
    {
        if (strlen(pyramid->words[i]) != strlen(pyramid->words[i + 1]) - 2)
            return false;
    }
    return true;
}

/**
 * Print the words in a word pyramid
 * @param pyramid the word pyramid
 */
void printPyramid(const Pyramid* pyramid)
{
    if (pyramid->numWords > 0)
    {
        printf("%s", pyramid->words[0]);
    }
    for (int i = 1; i < pyramid->numWords; ++i)
    {
        printf(", %s", pyramid->words[i]);
    }
}

/**
 * Unit test helper: Call the isWordPyramid() function and compare the result to the truth
 * @param pyramid the word pyramid
 * @param truth: the expected result of the isWordPyramid() function
 */
void testIsWordPyramidCase(const Pyramid* pyramid, bool truth)
{
    bool result = isWordPyramid(pyramid);
    result == truth ? printf("[PASS] ") : printf("[FAIL] ");
    printPyramid(pyramid);
    printf(" -> %d (expected: %d)\n", result, truth);
}

/**
 * Unit test for the isWordPyramid() function
 */
void testIsWordPyramid()
{
    const char* words1[] = { "macht", "ach", "misacht" };
    Pyramid pyramid1 = { words1 , 3 };
    testIsWordPyramidCase(&pyramid1, true);

    const char* words2[] = { "en", "dekens", "eend" };
    Pyramid pyramid2 = { words2 , 3 };
    testIsWordPyramidCase(&pyramid2, true);

    const char* words3[] = { "AtOmISCHe", "Mosachtiger", "triomfgeschal" };
    Pyramid pyramid3 = { words3 , 3 };
    testIsWordPyramidCase(&pyramid3, true);

    const char* words4[] = { "misacht", "atomisch", "mosachtiger" };
    Pyramid pyramid4 = { words4 , 3 };
    testIsWordPyramidCase(&pyramid4, false);

    const char* words5[] = { "a" };
    Pyramid pyramid5 = { words5 , 1 };
    testIsWordPyramidCase(&pyramid5, false);
    // TODO: Add your own cases
}

/**
 * Check if the console arguments make up a pyramid.
 * If no input is given, execute all unit tests instead
 */
int main(int argc, char** argv) {
    // TODO
    testIsWordPyramid();

    return EXIT_SUCCESS;
}
