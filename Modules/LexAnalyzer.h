#ifndef OBERONSCOMPILER_B_LEKSANALYZER_H
#define OBERONSCOMPILER_B_LEKSANALYZER_H

#include <stdio.h>
#include "Structures/Tokens.h"
#include "Structures/TerminalSymbols.h"

#ifdef _WIN32
#define OS_TYPE WINDOWS
#elif __linux__
#define OS_TYPE LINUX
#else
#define OS_TYPE UNSUPPORTED
#endif

int syntaxError;
extern struct TerminalSymbols terminalSymbols; //need to be initialised with ts_initialise
extern struct TokensFlow lexTokensFlow; //need to be created with lexAnalysis

int readNextToken(FILE *file, Token *token);

void lexAnalysis(FILE *inputFile, FILE *outputFile);

int charIsDigit(char c);

void Mark(char msg[], int line);

int charIsDigit(char c);
#endif //OBERONSCOMPILER_B_LEKSANALYZER_H
