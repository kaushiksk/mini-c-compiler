/* 
* Compiler Design Project 1 : Lexical Analyser
*
* File        : tokens.h
* Description : This file defines tokens and the values associated to them.
*                  
* Authors     : Karthik M - 15CO22, Kaushik S Kalmady - 15CO222
* Date        : 17-1-2018
*/

enum keywords
{
  INT=100,
  LONG,
  LONG_LONG,
  SHORT,
  SIGNED,
  UNSIGNED,
  FOR,
  BREAK,
  CONTINUE,
  RETURN,
  CHAR,
  IF,
  ELSE
};

enum operators
{
  DECREMENT=200,
  INCREMENT,
  PTR_SELECT,
  LOGICAL_AND,
  LOGICAL_OR,
  LS_THAN_EQ,
  GR_THAN_EQ,
  EQ,
  NOT_EQ,
  ASSIGN,
  MINUS,
  PLUS,
  STAR,
  MODULO,
  LS_THAN,
  GR_THAN
};

enum special_symbols
{
  DELIMITER=300,
  OPEN_BRACES,
  CLOSE_BRACES,
  COMMA,
  OPEN_PAR,
  CLOSE_PAR,
  OPEN_SQ_BRKT,
  CLOSE_SQ_BRKT,
  FW_SLASH
};

enum constants
{
  HEX_CONSTANT=400,
  DEC_CONSTANT,
  HEADER_FILE,
  STRING
};

enum IDENTIFIER
{
  IDENTIFIER=500
};
