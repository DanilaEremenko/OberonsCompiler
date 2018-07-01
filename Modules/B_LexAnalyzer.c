#include "B_LexAnalyzer.h"

int numberOfLine = 1;

int readNextToken(FILE *file, Token *token) {
    int tokenLength = 0;
    char firstSymbol, lastSymbol;

    token->line = numberOfLine;

    if (fscanf(file, "%c", &firstSymbol) == EOF)
        return 0;

    while (firstSymbol == ' ' || firstSymbol == '\n') {
        if (firstSymbol == '\n')
            numberOfLine++;
        if (fscanf(file, "%c", &firstSymbol) == EOF)
            return 0;

    }


    if (fscanf(file, "%c", &lastSymbol) == EOF) {
        token_initialize(token, 1);
        token->length = 1;
        token->symbols[0] = firstSymbol;
        token->type = token_defineType(*token, terminalSymbols);

        return 1;

    } else if (bothCharIsMathSymbol(firstSymbol, lastSymbol)) {

        tokenLength = 2;
        fseek(file, 1, SEEK_CUR);


    } else if (bothCharIsDigit(firstSymbol, lastSymbol)) {

        tokenLength = 1;
        while (charIsDigit(lastSymbol)) {
            fscanf(file, "%c", &lastSymbol);
            tokenLength++;
        }

    } else if (charIsASeparatingTerminalSymbol(terminalSymbols, firstSymbol)) {

        tokenLength = 1;

    } else {

        tokenLength = 1;
        while (lastSymbol != '\n' && lastSymbol != ' ' &&
               !charIsASeparatingTerminalSymbol(terminalSymbols, lastSymbol)) {
            tokenLength++;
            fscanf(file, "%c", &lastSymbol);
        }

    }

    token_initialize(token, tokenLength);


    if (lastSymbol == '\n')
        fseek(file, -1, SEEK_CUR);

    fseek(file, -tokenLength - 1, SEEK_CUR);


    for (int i = 0; i < tokenLength; ++i)
        token->symbols[i] = (char) getc(file);


    token->type = token_defineType(*token, terminalSymbols);


    return 1;


}

void lexAnalysis(char *fileName) {

    tf_initialize(&tokensFlow);
    tss_initialize(&terminalSymbols);
    FILE *file = fopen(fileName, "r");

    Token token;
    int result = 1;
    while (result == 1) {
        result = readNextToken(file, &token);
        if (result != 0)
            tf_addToken(&tokensFlow, &token);
    }


    if (tokensFlow.size == 0)
        printf("Probably wrong path");

}

void Mark(char msg[]) {
    printf("Error in line number%d\n", tokensFlow.current->line);
    printf("%s", msg);
}