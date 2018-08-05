#ifndef OBERONSCOMPILER_C_G_CODEGENERATOR_H
#define OBERONSCOMPILER_C_G_CODEGENERATOR_H

#include <stdbool.h>
#include "Structures/Node.h"
#include "Structures/Set.h"
#include "SimpleFunctions/SimpleFunctions.h"
#include "Structures/B_TerminalSymbols.h"
#include "B_LexAnalyzer.h"
#include "R_RISC.h"

#define MAXCODE 10000
#define NUMBER_OF_COMMANDS 16
#define MAXREL 200

////Constants for Node.class
#define HEAD 0
#define VARIABLE 1
#define PAR 2
#define CONST 3
#define FLD 4
#define TYP 5
#define PROC 6
#define S_PROC 7
#define REG 10
#define COND 11

//Constants for
#define BOOLEAN 0
#define INTEGER 1
#define ARRAY 2
#define RECORD 3

//Constants for assembler
#define MOV 0
#define MVN 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIVIDE 5
#define MODULUS 6
#define CMP 7
#define MOVI 16
#define MVNI 17
#define ADDI 18
#define SUBI 19
#define MULI 20
#define DIVI 21
#define MODI 22
#define CMPI 23
#define CHKI 24
#define LDW 32
#define LDB 33
#define POP 34
#define STW 36
#define STB 37
#define PSH 38
#define RD 40
#define WRD 41
#define WRH 42
#define WRL 43
#define BEQ 48
#define BNE 49
#define BLT 50
#define BGE 51
#define BLE 52
#define BGT 53
#define BR 56
#define BSR 57
#define RET 58
#define FP 12
#define SP 13
#define LNK 14
#define PC 15


extern Type intType;
extern Type boolType;
int curlev;
int pc;
int cno;
long entry;
long fixlist;
struct Set *regs;
//W:TextWriter
//long code[MAXCODE];
//comname
//char mnemo[64][5];

void cg_initialize();

void decode(char address[]);

long FixLink(long L);

void IncLevel(int n);

void MakeConstltem(struct Item *x, Type *typ, long val);

void MakeItem(struct Item *x, Node *y);

void Field(struct Item *x, Node *y);

void Index(struct Item *x, struct Item *y);

void Op1(int op, struct Item *x);

void Op2(int op, struct Item *x, struct Item *y);

void Relation(int op, struct Item *x, struct Item *y);

void Store(struct Item *x, struct Item *y);

void Parameter(struct Item *x, Type *ftyp, int class);

void CJump(struct Item *x);

void BJump(long L);

void FJump(long *L);

void Call(struct Item *x);

void IOCall(struct Item *x, struct Item *y);

void Header(long size);

void Enter(long size);

void Return(long size);

void Open();

void Close(long globals);

void EnterCMD(char name[], int nameLength);

void Load(char outputAddress[]);

void Exec(char outputAddress[]);

#endif //OBERONSCOMPILER_C_G_CODEGENERATOR_H
