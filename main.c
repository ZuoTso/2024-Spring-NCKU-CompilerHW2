#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)

#define toupper(_char) (_char - (char)32)

const char *objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_STR] = "string",
    [OBJECT_TYPE_FUNCTION] = "function",
};

char *yyInputFileName;
bool compileError;

int indent = 0;
int scopeLevel = -1;
int funcLineNo = 0;
int variableAddress = 0;
int variableIndex[20] = {0};
ObjectType variableIdentType;

int funcAddr = -1;
int numberOfParm = 0;
Object funAndParm[20];

void pushScope()
{
    scopeLevel++;
    printf("> Create symbol table (scope level %d)\n", scopeLevel);
}

void dumpScope()
{
    printf("\n> Dump symbol table (scope level: %d)\n", scopeLevel);
    printf("%-10s%-20s%-10s%-10s%-10s%-10s\n","Index","Name","Type","Addr","Lineno","Func_sig");
    if (scopeLevel > 0){
        for(int i = 0; i < variableIndex[scopeLevel]; i++){
            printf("%-10d%-20s%-10s%-10d%-10d%-10s\n",
                i/* Index */,
                funAndParm[scopeLevel].symbol[i].name,
                objectTypeName[funAndParm[scopeLevel].symbol[i].type],
                funAndParm[scopeLevel].symbol[i].addr,
                funAndParm[scopeLevel].symbol[i].lineno,
                funAndParm[scopeLevel].symbol[i].func_sig);
        }
    }
    if (scopeLevel == 0){
        for(int i = 0; i < variableIndex[scopeLevel]; i++){
            printf("%-10d%-20s%-10s%-10d%-10d%-10s\n",
                i/* Index */,
                funAndParm[scopeLevel].symbol[i].name,
                objectTypeName[funAndParm[scopeLevel].funcType],
                funcAddr,
                funAndParm[scopeLevel].symbol[i].lineno,
                funAndParm[scopeLevel].symbol[i].func_sig);
        }
    }
    variableIndex[scopeLevel] = 0;
    scopeLevel--;
}

//Object *createVariable(ObjectType variableType, char *variableName, int variableFlag)
void createVariable(ObjectType variableType, char *variableName, int variableFlag) 
{
    funAndParm[scopeLevel].funcType = OBJECT_TYPE_FUNCTION;
    funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].name = (char *)malloc(strlen(variableName) + 1);
    if (funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].name == NULL) {
        printf("Error malloc funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].name\n");
    }
    strncpy(funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].name, variableName, strlen(variableName) + 1);
    funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].lineno = yylineno;
    
    /*--------------- 還沒看懂的東西 func_sig --------------*/
    switch (variableName[0]){
        case 'm':
            funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].func_sig = (char *)malloc(strlen("([Ljava/lang/String;)I") + 1);
            strcpy(funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].func_sig, "([Ljava/lang/String;)I");
            break;
        case 'c':
            funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].func_sig = (char *)malloc(strlen("(IILjava/lang/String;B)B") + 1);
            strcpy(funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].func_sig, "(IILjava/lang/String;B)B");
            break;
    }
}

void InsertSymbol(ObjectType variableType, char *variableName, int variableFlag)
{
    funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].type = variableType;
    funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].name = (char *)malloc(strlen(variableName) + 1);
    if (funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].name == NULL) {
        printf("Error malloc funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].name\n");
    }
    strncpy(funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].name, variableName, strlen(variableName) + 1);
    funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].addr = variableAddress;
    funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].lineno = yylineno;
    
    /*--------------- 還沒看懂的東西 func_sig --------------*/
    funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].func_sig = (char *)malloc(strlen("-") + 1);
    strcpy(funAndParm[scopeLevel].symbol[variableIndex[scopeLevel]].func_sig, "-");
}

void pushFunParm(ObjectType variableType, char *variableName, int variableFlag)
{
    InsertSymbol(variableType, variableName, variableFlag);
    printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, variableAddress, scopeLevel);
    variableAddress++;
    variableIndex[scopeLevel]++;
}

void createFunction(ObjectType variableType, char *funcName)
{
    printf("func: %s\n",funcName);
    printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, funcAddr, scopeLevel);
    createVariable(variableType, funcName, -1);
    variableIndex[scopeLevel]++;
    pushScope();
}

void debugPrintInst(char instc, Object *a, Object *b, Object *out)
{
}

bool objectExpression(char op, Object *dest, Object *val, Object *out)
{
    return false;
}

bool objectExpBinary(char op, Object *a, Object *b, Object *out)
{
    return false;
}

bool objectExpBoolean(char op, Object *a, Object *b, Object *out)
{
    return false;
}

bool objectExpAssign(char op, Object *dest, Object *val, Object *out)
{
    return false;
}

bool objectValueAssign(Object *dest, Object *val, Object *out)
{
    return false;
}

bool objectNotBinaryExpression(Object *dest, Object *out)
{
    return false;
}

bool objectNegExpression(Object *dest, Object *out)
{
    return false;
}
bool objectNotExpression(Object *dest, Object *out)
{
    return false;
}

bool objectIncAssign(Object *a, Object *out)
{
    return false;
}

bool objectDecAssign(Object *a, Object *out)
{
    return false;
}

bool objectCast(ObjectType variableType, Object *dest, Object *out)
{
    return false;
}

Object *findVariable(char *variableName)
{
    Object *variable = NULL;
    return variable;
}

void pushFunInParm(Object *variable)
{
}

void stdoutPrint()
{
    printf("cout");
    for (int i = 0; strcmp(objectTypeName[coutObjectType[i]], "undefined") != 0; i++)
    {
        printf(" %s", objectTypeName[coutObjectType[i]]);
        coutObjectType[i] = OBJECT_TYPE_UNDEFINED;
    }
    for (int i = 0; i < 50; i++)
    {
        coutObjectType[i] = OBJECT_TYPE_UNDEFINED;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        yyin = fopen(yyInputFileName = argv[1], "r");
    }
    else
    {
        yyin = stdin;
    }
    if (!yyin)
    {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }

    // Start parsing
    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}