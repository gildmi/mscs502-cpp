/** \file main.cpp
 *
 * \brief Simple hello world template.
 */

#include "utils.cpp"

using namespace std;

int returnCode = 0;                /**< Application wide return code */
char testString[] = "Hello World"; /**< String to be printed */

/**
 * \brief Hello world main function.
 *
 * This function will print "Hello World" after processing command line
 * arguments.
 *
 * \param argc Argument count from command line call
 * \param argv Command line arguments pointer
 *
 * \return Integer return code, zero for success and non-zero otherwise
 */
int main(int argc, char **argv) {
  processArguments(argc, argv);

  puts(testString);

  return returnCode;
}
