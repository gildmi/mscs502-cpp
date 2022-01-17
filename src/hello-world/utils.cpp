/** \file utils.cpp
 *
 * \brief Various utility and helper functions.
 *
 */

#include <ctype.h>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <stdarg.h>
#include <string.h>

using namespace std;

static bool verbose_flag = false; /**< Verbose flag */
static char version[] = "0.0.1";  /**< Application version number*/

/**
 * \brief Print error message and exit.
 *
 * Function to print error message to stderr and exit.  Will exit with return
 * code of -1 by default.
 *
 * \param msg Pointer to char array message to print.
 * \param returnCode Integer return code to exit with, default -1.
 */
void error(const char *msg, int returnCode = -1) {
  // cout << msg << endl;
  cerr << msg << endl;
  exit(returnCode);
}

/**
 * \brief Help text function.
 *
 * Prints the help text to stdout and exits with a retrun code of zero.
 */
void help() {
  cout << "hello-world" << endl;
  cout << "Simple hello world template." << endl;
  cout << "Version: " << version << endl;
  cout << endl;
  printf("%-10s %-1s\n", "-h", "Print this help text");
  printf("%-10s %-1s\n", "-v", "Verbose mode");
  exit(0);
}

/**
 * \brief Print parameters like printf only if verbose is on.
 *
 * Function behaves like printf if verbose is on otherwise no output.
 * See https://www.cplusplus.com/reference/cstdio/printf/ for more information.
 *
 * \param format Pointer to char array to print.
 */
void verboseprintf(const char *format, ...) {
  if (verbose_flag) {
    va_list vl;
    va_start(vl, format);
    vprintf(format, vl);
    va_end(vl);
  }
}

/**
 * \brief Process command line arguments using getopt.
 *
 * Function to process command line arguments using long options.
 *
 * \param argc Argument count from command line call
 * \param argv Command line arguments pointer
 */
void processArguments(int argc, char **argv) {
  while (true) {
    static struct option long_options[] = {
        /* These options set a flag. */
        {"verbose", no_argument, 0, 'v'},
        /* These options don’t set a flag.
           We distinguish them by their indices. */
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}};
    /* getopt_long stores the option index here. */
    int option_index = 0;

    int c = getopt_long(argc, argv, "hv", long_options, &option_index);

    /* Detect the end of the options. */
    if (c == -1)
      break;

    switch (c) {
    case 0:
      /* If this option set a flag, do nothing else now. */
      if (long_options[option_index].flag != 0)
        break;
      verboseprintf("option %s", long_options[option_index].name);
      if (optarg)
        printf(" with arg %s", optarg);
      verboseprintf("\n");
      break;

    case 'v':
      verbose_flag = true;
      break;

    case 'h':
      help();
      break;

    case '?':
      /* getopt_long already printed an error message. */
      break;

    default:
      error("Unrecognized command line arguments.");
    }
  }

  if (verbose_flag)
    printf("Verbose mode\n");

  /* Print any remaining command line arguments (not options). */
  if (optind < argc) {
    verboseprintf("Non-option ARGV-elements: ");
    while (optind < argc)
      verboseprintf("%s ", argv[optind++]);
    verboseprintf("\n");
  }
}

/**
 * \brief Convert char array to lowercase.
 *
 * Function to convert character array to lowercase in place.
 *
 * \param inputtext Char array pointer to convert to lowercase
 */
void toLower(char *inputText) {
  for (unsigned int i = 0; i < strlen(inputText); i++) {
    inputText[i] = tolower(inputText[i]);
  }
}

/**
 * \brief Process command line arguments.
 *
 * Function to manually process command line arguments without getopt.
 *
 * \param argc Argument count from command line call
 * \param argv Command line arguments pointer
 */
void processArguments2(int argc, char **argv) {
  if (argc == 2) {
    cout << argv[1] << endl;
    char arg[] = "";
    strcpy(arg, argv[1]);
    toLower(arg);
    if (strcmp("help", arg) == 0) {
      help();
    }
  } else if (argc > 2) {
    error("Too many arguments...");
  }
}
