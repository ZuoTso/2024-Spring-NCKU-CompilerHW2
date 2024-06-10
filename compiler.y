/* Definition section */
%{
    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    ObjectType coutBuffer;
    ObjectType coutObjectType[50];
    int numberOfCoutObjectType = 0;
    char address[20][20]; // IDENT address
    int addressIndex = 0;
    
    int int2float = 0;
    int atLastOperator = 0;
    int operatorType[100]; // int:1  float:2  bool:3
    SymbolData tableOfVariableType[20];
    int numberOfVariable = 0;
    int coutCheck = 0;

    typedef struct _arraytable {
        char* name;
        int size;
        int elementValue[2000];
        ObjectType type;
    } arrayTabel;
    arrayTabel arrayTabel_1[20];
    int arraySize = 0;
    int numberOfArray = 0;

%}

/* Variable or self-defined structure */
%union {
    ObjectType var_type;

    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val;
}

/* Token without return */
%token COUT
%token SHR SHL BAN BOR BNT BXO ADD SUB MUL DIV REM NOT GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE

/* Token with return, which need to sepcify type */
%token <var_type> VARIABLE_T
%token <s_var> IDENT
%token <i_var> INT_LIT
%token <f_var> FLOAT_LIT
%token <s_var> STR_LIT
%token <b_var> BOOL_LIT

/* Nonterminal with return, which need to sepcify type */
%type <object_val> Expression

%left ADD SUB
%left MUL DIV REM

%right VAL_ASSIGN
%right ADD_ASSIGN
%right SUB_ASSIGN
%right MUL_ASSIGN
%right DIV_ASSIGN
%right REM_ASSIGN
%right SHR_ASSIGN
%right SHL_ASSIGN
%right BAN_ASSIGN
%right BOR_ASSIGN
%right BXO_ASSIGN

%right INC_ASSIGN
%right DEC_ASSIGN

/* Yacc will start at this nonterminal */
%start Program

%%
/* Grammar section */

Program
    : { pushScope(); } GlobalStmtList { dumpScope(); }
    | /* Empty file */
;

GlobalStmtList 
    : GlobalStmtList GlobalStmt
    | GlobalStmt
;

GlobalStmt
    : DefineVariableStmt
    | FunctionDefStmt
;

DefineVariableStmt
    : VARIABLE_T IDENT VAL_ASSIGN Expression ';'
;

/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT { createFunction($<var_type>1, $<s_var>2); } '(' FunctionParameterStmtList ')' '{' StmtList '}' { dumpScope(); }
;
FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt
    | FunctionParameterStmt
    | /* Empty function parameter */
;
FunctionParameterStmt
    : VARIABLE_T IDENT {    pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT);
                            tableOfVariableType[numberOfVariable].type = $<var_type>1;
                            tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen($<s_var>2) + 1);
                            strcpy(tableOfVariableType[numberOfVariable].name, $<s_var>2);
                            numberOfVariable++;
                            tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;

                            // check address table, if this IDENT in the table find it and print 
                            for (int i = 0; i < 20; i++){
                                if (strcmp(address[i], $<s_var>2) == 0){
                                    break;
                                }
                                if (i == 19){
                                    // if this IDENT NOT in the table print it and add in to table 
                                    strcpy(address[addressIndex], $<s_var>2);
                                    addressIndex++;
                                }
                            }
                       }
    | VARIABLE_T IDENT '[' ']' {    pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT);
                                    tableOfVariableType[numberOfVariable].type = $<var_type>1;
                                    tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen($<s_var>2) + 1);
                                    strcpy(tableOfVariableType[numberOfVariable].name, $<s_var>2);
                                    numberOfVariable++;
                                    tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;

                                    // check address table, if this IDENT in the table find it and print
                                    for (int i = 0; i < 20; i++){
                                        if (strcmp(address[i], $<s_var>2) == 0){
                                            break;
                                        }
                                        if (i == 19){
                                            // if this IDENT NOT in the table print it and add in to table 
                                            strcpy(address[addressIndex], $<s_var>2);
                                            addressIndex++;
                                        }
                                    }
                               }
;

/* Scope */
StmtList 
    : StmtList Stmt
    | Stmt
;
Stmt
    : ';'
    | { coutCheck = 1; } COUT CoutParmListStmt ';' { coutCheck = 0; stdoutPrint(); int2float = 0; numberOfCoutObjectType = 0; }
    | RETURN Expression ';' { printf("RETURN\n"); }
    | assignment
    | IfStmt
    | WhileStmt
    | ForStmt
    | BREAK { printf("BREAK\n"); }
    |
;

IfStmt
    : IF '(' operator14AssignmentType ')' { printf("IF\n"); pushScope(); } '{' StmtList '}' { dumpScope();} ElseStmt
;
ElseStmt
    : ELSE { printf("ELSE\n"); pushScope(); } '{' StmtList '}' { dumpScope(); }
    |
;

WhileStmt
    : WHILE { printf("WHILE\n"); } '(' operator14AssignmentType ')' { pushScope(); } '{' StmtList '}' { dumpScope();}
;
ForStmt
    : FOR { printf("FOR\n"); pushScope(); } Forcond '{' StmtList '}' { dumpScope(); }
;
Forcond
    : '(' ForInitial ';' LogicalExpression ';' assignment ')'
    | '(' ForInitial ')'
;
ForInitial
    : assignment
    | // Empty initial
assignment
    : VARIABLE_T { tableOfVariableType[numberOfVariable].type = $<var_type>1; } mutiAssignment  // Declare variable
    | operator14AssignmentType // Edit value
;
mutiAssignment
    : mutiAssignment ',' mutiAssignment
    | mutiInitialize // include array assigment
;
mutiInitialize
    : IDENT VAL_ASSIGN operator14AssignmentType {   pushFunParm(tableOfVariableType[numberOfVariable].type, $<s_var>1, VAR_FLAG_DEFAULT);
                                                    tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen($<s_var>1) + 1);
                                                    strcpy(tableOfVariableType[numberOfVariable].name, $<s_var>1);
                                                    numberOfVariable++;
                                                    tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;

                                                    /* check address table, if this IDENT in the table find it and print */
                                                    for (int i = 0; i < 20; i++){
                                                        if (strcmp(address[i], $<s_var>1) == 0){
                                                            break;
                                                        }
                                                        if (i == 19){
                                                            /* if this IDENT NOT in the table print it and add in to table */
                                                            strcpy(address[addressIndex], $<s_var>1);
                                                            addressIndex++;
                                                        }
                                                    }
                                                }   // Declare and initialize variable
    | IDENT {   pushFunParm(tableOfVariableType[numberOfVariable].type, $<s_var>1, VAR_FLAG_DEFAULT);
                tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen($<s_var>1) + 1);
                strcpy(tableOfVariableType[numberOfVariable].name, $<s_var>1);
                numberOfVariable++;
                tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;
                
                // check address table, if this IDENT in the table find it and print
                for (int i = 0; i < 20; i++){
                    if (strcmp(address[i], $<s_var>1) == 0){
                        break;
                    }
                    if (i == 19){
                        // if this IDENT NOT in the table print it and add in to table
                        strcpy(address[addressIndex], $<s_var>1);
                        addressIndex++;
                    }
                }
            }   // Declare variable
    | IDENT { arrayTabel_1[numberOfArray].name = $<s_var>1; } '[' INT_LIT { printf("INT_LIT %d\n", $<i_var>4); arrayTabel_1[numberOfArray].size = $<i_var>4; } ']'
        VAL_ASSIGN '{' mutiElement '}'  {   if ( arraySize ){
                                                printf("create array: %d\n", arraySize);
                                            }else{
                                                printf("create array: %d\n", 0);
                                            }
                                            arrayTabel_1[numberOfArray].type = tableOfVariableType[numberOfVariable].type;
                                            pushFunParm(arrayTabel_1[numberOfArray].type, arrayTabel_1[numberOfArray].name, VAR_FLAG_DEFAULT);
                                            // vvvvvvvvvvvvvvvvv   array also variable   vvvvvvvvvvvvvvvvv
                                            tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen($<s_var>1) + 1);
                                            strcpy(tableOfVariableType[numberOfVariable].name, $<s_var>1);
                                            numberOfVariable++;
                                            tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;
                                            // check address table, if this IDENT in the table find it and print
                                            for (int i = 0; i < 20; i++){
                                                        if (strcmp(address[i], $<s_var>1) == 0){
                                                            break;
                                                        }
                                                        if (i == 19){
                                                            // if this IDENT NOT in the table print it and add in to table
                                                            strcpy(address[addressIndex], $<s_var>1);
                                                            addressIndex++;
                                                        }
                                                    }
                                            // ^^^^^^^^^^^^^^^^^   array also variable   ^^^^^^^^^^^^^^^^^
                                            numberOfArray++;
                                            arraySize = 0;
                                            
                                            tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;
                                        } // Declare array
    | IDENT ':' IDENT { if(tableOfVariableType[numberOfVariable].type == OBJECT_TYPE_AUTO){
                            for (int i = 0; i <= numberOfVariable; i++){
                                if (strcmp(tableOfVariableType[i].name, $<s_var>3) == 0){
                                    tableOfVariableType[numberOfVariable].type = tableOfVariableType[i].type;
                                    break;
                                }
                            }
                        }
                        pushFunParm(tableOfVariableType[numberOfVariable].type, $<s_var>1, VAR_FLAG_DEFAULT);
                        tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen($<s_var>1) + 1);
                        strcpy(tableOfVariableType[numberOfVariable].name, $<s_var>1);
                        numberOfVariable++;
                        tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;
                        
                        // check address table, if this IDENT in the table find it and print
                        for (int i = 0; i < 20; i++){
                            if (strcmp(address[i], $<s_var>3) == 0){
                                printf("IDENT (name=%s, address=%d)\n", $<s_var>3, i);
                            }else if (i == 19){
                                // if this IDENT NOT in the table print it and add in to table
                                strcpy(address[addressIndex], $<s_var>1);
                                addressIndex++;
                            }
                        }
                      } // for auto special case
;
mutiElement
    : mutiElement ',' Element
    | Element
;
Element
    : INT_LIT   { printf("INT_LIT %d\n", $<i_var>1);
                  arrayTabel_1[numberOfArray].elementValue[arraySize] = $<i_var>1;
                  arraySize++;
                }
    | BOOL_LIT  { if ($<b_var>1 == 1)
                    printf("BOOL_LIT TRUE\n");
                  if ($<b_var>1 == 0)
                    printf("BOOL_LIT FALSE\n");
                }
    | FLOAT_LIT { printf("FLOAT_LIT %.6f\n", $<f_var>1); }
    | STR_LIT   { printf("STR_LIT \"%s\"\n", $<s_var>1); }
    | // Empty element
;
CoutParmListStmt
    : CoutParmListStmt SHL Expression { pushFunInParm(&$<object_val>3); }
    | SHL Expression { pushFunInParm(&$<object_val>2); }
;
Expression
    : STR_LIT { printf("STR_LIT \"%s\"\n", $<s_var>1);
                coutObjectType[numberOfCoutObjectType] = OBJECT_TYPE_STR;
                numberOfCoutObjectType++;
              }
    | identTerminal {   if(coutBuffer){
                            coutObjectType[numberOfCoutObjectType] = coutBuffer;
                            numberOfCoutObjectType++;
                            coutBuffer = 0;
                        }
                    }
    | operator14AssignmentType { if (coutCheck){
                                    if (operatorType[atLastOperator - 1] == 1){
                                        if (int2float){
                                            coutBuffer = OBJECT_TYPE_FLOAT;
                                        } else{
                                            coutBuffer = OBJECT_TYPE_INT;
                                        }
                                    }else if (operatorType[atLastOperator - 1] == 3){
                                        coutBuffer = OBJECT_TYPE_BOOL;
                                    }
                                    if(coutBuffer){
                                        coutObjectType[numberOfCoutObjectType] = coutBuffer;
                                        numberOfCoutObjectType++;
                                        coutBuffer = 0;
                                    }
                                 }
                                }
        
;

identTerminal
    : IDENT   { if (coutCheck){
                    for (int i = 0; i < numberOfVariable; i++){
                        if (strcmp("endl", $<s_var>1) == 0){
                            coutObjectType[numberOfCoutObjectType] = OBJECT_TYPE_STR;
                            numberOfCoutObjectType++;
                            break;
                        }
                        if (strcmp($<s_var>1, tableOfVariableType[i].name) == 0){
                            coutBuffer = tableOfVariableType[i].type;
                            //numberOfCoutObjectType++;
                            break;
                        }
                    }
                }
                // check address table, if this IDENT in the table find it and print
                for (int i = 0; i < 20; i++){
                    if (strcmp("endl", $<s_var>1) == 0){
                        printf("IDENT (name=%s, address=%d)\n", $<s_var>1, -1);
                        break;
                    }
                    if (strcmp(address[i], $<s_var>1) == 0){
                        printf("IDENT (name=%s, address=%d)\n", $<s_var>1, i);
                        break;
                    }else if (i == 19){
                        // if this IDENT NOT in the table print it and add in to table
                        printf("IDENT (name=%s, address=%d)\n", $<s_var>1, addressIndex);
                        strcpy(address[addressIndex], $<s_var>1);
                        addressIndex++;
                    }
                }
              } // Variable
    | IDENT '[' INT_LIT ']' {   for (int i = 0; i < numberOfArray; i++){
                                    if (strcmp(arrayTabel_1[i].name, $<s_var>1) == 0){
                                        if (arrayTabel_1[i].type == OBJECT_TYPE_INT){
                                            printf("INT_LIT %d\n",$<i_var>3);
                                            for (int j = 0; j <= 20; j++ ){
                                                if (strcmp($<s_var>1, address[i]) == 0){
                                                    printf("IDENT (name=%s, address=%d)\n", $<s_var>1, j );
                                                }
                                            }
                                            if (coutCheck){
                                                coutBuffer = OBJECT_TYPE_INT;
                                                //numberOfCoutObjectType++;
                                            }
                                        }
                                        break;
                                    }
                                }
                                for (int i = 1; i < 20; i++){
                                    if (strcmp("endl", $<s_var>1) == 0){
                                        printf("IDENT (name=%s, address=%d)\n", $<s_var>1, -1);
                                        break;
                                    }
                                    if (strcmp(address[i], $<s_var>1) == 0){
                                        printf("IDENT (name=%s, address=%d)\n", $<s_var>1, i);
                                        break;
                                    }else if (i == 19){
                                        // if this IDENT NOT in the table print it and add in to table
                                        printf("IDENT (name=%s, address=%d)\n", $<s_var>1, addressIndex);
                                        strcpy(address[addressIndex], $<s_var>1);
                                        addressIndex++;
                                    }
                                }
                            }   // Array
;
LogicalExpression
    : numbers1 EQL numbers1 { printf("EQL\n"); }
    | numbers1 NEQ numbers1 { printf("NEQ\n"); }
    | numbers1 GTR numbers1 { printf("GTR\n"); }
    | numbers1 LES numbers1 { printf("LES\n"); }
    | numbers1 GEQ numbers1 { printf("GEQ\n"); }
    | numbers1 LEQ numbers1 { printf("LEQ\n"); }
;
operator14AssignmentType
    : identTerminal VAL_ASSIGN operator12 { printf("EQL_ASSIGN\n"); }
    | identTerminal ADD_ASSIGN operator12 { printf("ADD_ASSIGN\n"); }
    | identTerminal SUB_ASSIGN operator12 { printf("SUB_ASSIGN\n"); }
    | identTerminal MUL_ASSIGN operator12 { printf("MUL_ASSIGN\n"); }
    | identTerminal DIV_ASSIGN operator12 { printf("DIV_ASSIGN\n"); }
    | identTerminal REM_ASSIGN operator12 { printf("REM_ASSIGN\n"); }
    | identTerminal SHR_ASSIGN operator12 { printf("SHR_ASSIGN\n"); }
    | identTerminal SHL_ASSIGN operator12 { printf("SHL_ASSIGN\n"); }
    | identTerminal BAN_ASSIGN operator12 { printf("BAN_ASSIGN\n"); }
    | identTerminal BOR_ASSIGN operator12 { printf("BOR_ASSIGN\n"); }
    | identTerminal BXO_ASSIGN operator12 { printf("BXO_ASSIGN\n"); }
    | identTerminal INC_ASSIGN operator12 { printf("INC_ASSIGN\n"); }
    | identTerminal DEC_ASSIGN operator12 { printf("DEC_ASSIGN\n"); }
    //| operator14AssignmentType VAL_ASSIGN operator12 { printf("EQL_ASSIGN\n"); }
    | identTerminal // test
    | operator12
;
/*operator13
    : // operator13 conditional operator  operator12
    | operator12
;*/
operator12
    : operator12 LOR operator11 { printf("LOR\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | operator11
;
operator11
    : operator11 LAN operator10 { printf("LAN\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | operator10
;
operator10
    : operator10 BOR operator9 { printf("BOR\n"); }
    | operator9
;
operator9
    : operator9 BXO operator8 { printf("BXO\n"); }
    | operator8
;
operator8
    : operator8 BAN operator7 { printf("BAN\n"); }
    | operator7
;
operator7
    : operator7 EQL operator6 { printf("EQL\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | operator7 NEQ operator6 { printf("NEQ\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | operator6
;
operator6
    : operator6 GTR operator5 { printf("GTR\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | operator6 LES operator5 { printf("LES\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | operator6 GEQ operator5 { printf("GEQ\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | operator6 LEQ operator5 { printf("LEQ\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | operator5
;
operator5
    : operator5 SHR operator4 { printf("SHR\n"); }
    //| operator5 SHL operator4 { printf("SHL\n"); }
    | operator4
;
operator4
    : operator4 ADD operator3 { printf("ADD\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
    | operator4 SUB operator3 { printf("SUB\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
    | operator3
;
operator3
    : operator3 MUL operator2 { printf("MUL\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
    | operator3 DIV operator2 { printf("DIV\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
    | operator3 REM operator2 { printf("REM\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
    | operator2
;
operator2
    : SUB numbers1 { printf("NEG\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
    | NOT numbers1 { printf("NOT\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
    | BNT numbers1 { printf("BNT\n"); }
    | numbers1
;
numbers1
    : '(' operator14AssignmentType ')'
    //| '[' operator14AssignmentType ']'
    | identTerminal INC_ASSIGN { printf("INC_ASSIGN\n"); }
    | INT_LIT   { printf("INT_LIT %d\n", $<i_var>1);
                  if (tableOfVariableType[numberOfVariable].type == OBJECT_TYPE_AUTO){
                    tableOfVariableType[numberOfVariable].type = OBJECT_TYPE_INT;
                  }
                }
    | BOOL_LIT  { if ($<b_var>1 == 1)
                    printf("BOOL_LIT TRUE\n");
                  if ($<b_var>1 == 0)
                    printf("BOOL_LIT FALSE\n");
                  if (tableOfVariableType[numberOfVariable].type == OBJECT_TYPE_AUTO){
                    tableOfVariableType[numberOfVariable].type = OBJECT_TYPE_BOOL;
                  }
                }
    | FLOAT_LIT { printf("FLOAT_LIT %.6f\n", $<f_var>1);
                  int2float = 1;
                  if (tableOfVariableType[numberOfVariable].type == OBJECT_TYPE_AUTO){
                    tableOfVariableType[numberOfVariable].type = OBJECT_TYPE_FLOAT;
                  }
                }
    | STR_LIT   { printf("STR_LIT \"%s\"\n", $<s_var>1); }
    | operator14AssignmentType
    | Casting
    | CallFunction
;
CallFunction
    : IDENT '(' mutiFuncPara ')' { printf("IDENT (name=%s, address=%d)\ncall: %s(IILjava/lang/String;B)B\n", $<s_var>1, -1, $<s_var>1); }
;
mutiFuncPara
    : ParaTerminal ',' mutiFuncPara
    | ParaTerminal
;
ParaTerminal
    : INT_LIT  { printf("INT_LIT %d\n", $<i_var>1); }
    | STR_LIT  { printf("STR_LIT \"%s\"\n", $<s_var>1); }
    | BOOL_LIT { if ($<b_var>1 == 1)
                    printf("BOOL_LIT TRUE\n");
                  if ($<b_var>1 == 0)
                    printf("BOOL_LIT FALSE\n");
               }
    //| identTerminal
    | 
;
Casting
    : '(' VARIABLE_T ')' '(' operator14AssignmentType ')' { if ($<var_type>2 == OBJECT_TYPE_INT)
                                                                printf("Cast to int\n");
                                                            if ($<var_type>2 == OBJECT_TYPE_FLOAT)
                                                                printf("Cast to float\n");
                                                          }
    | '(' VARIABLE_T ')' identTerminal {if ($<var_type>2 == OBJECT_TYPE_INT)
                                            printf("Cast to int\n");
                                        if ($<var_type>2 == OBJECT_TYPE_FLOAT)
                                            printf("Cast to float\n");
                                       }
    | '(' VARIABLE_T ')' '(' DataTypeTerminal ')' { if ($<var_type>2 == OBJECT_TYPE_INT)
                                                        printf("Cast to int\n");
                                                    if ($<var_type>2 == OBJECT_TYPE_FLOAT)
                                                        printf("Cast to float\n");
                                                  }
    | '(' VARIABLE_T ')' DataTypeTerminal { if ($<var_type>2 == OBJECT_TYPE_INT)
                                                printf("Cast to int\n");
                                            if ($<var_type>2 == OBJECT_TYPE_FLOAT)
                                                printf("Cast to float\n");
                                          }
;
DataTypeTerminal
    : INT_LIT   { printf("INT_LIT %d\n", $<i_var>1);}
    | BOOL_LIT  { if ($<b_var>1 == 1)
                    printf("BOOL_LIT TRUE\n");
                  if ($<b_var>1 == 0)
                    printf("BOOL_LIT FALSE\n");
                }
    | FLOAT_LIT { printf("FLOAT_LIT %.6f\n", $<f_var>1);
                  int2float = 1;
                }
    | STR_LIT   { printf("STR_LIT \"%s\"\n", $<s_var>1); }
;

%%
/* C code section */