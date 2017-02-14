#ifndef _SCOUR
#define SCOUR
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "colors.h"
#include <iostream>
#include <set>
#include <map>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace llvm;
static llvm::cl::OptionCategory MyToolCategory("my-tool options");
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);
static cl::extrahelp MoreHelp("\nMore help text...");

static const std::set<std::string> banned = {"IsBadCodePtr","IsBadHugeReadPtr","IsBadHugeWritePtr","IsBadReadPtr","IsBadStringPtr","IsBadWritePtr","StrCat","StrCatA","StrCatBuff","StrCatBuffA","StrCatBuffW","StrCatChainW","StrCatN","StrCatNA","StrCatNW","StrCatW","StrCpy","StrCpyA","StrCpyN","StrCpyNA","StrCpyNW","StrCpyW","StrNCat","StrNCatA","StrNCatW","StrNCpy","StrNCpyA","StrNCpyW","_ftcscat","_ftcscpy","_getts","_gettws","_mbccat","_mbccpy","_mbscat","_mbscpy","_mbsnbcat","_mbsnbcpy","_mbsncat","_mbsncpy","_stprintf","_tccat","_tccpy","_tcscat","_tcscpy","_tcsncat","_tcsncpy","_vstprintf","gets","lstrcat","lstrcatA", "lstrcatW","lstrcatn","lstrcatnA","lstrcatnW","lstrcpy","lstrcpyA","lstrcpyW","lstrcpyn","lstrcpynA","lstrcpynW","lstrncat","sprintf","sprintfA","sprintfW","strcat","strcatA","strcatW","strcpy","strcpyA","strcpyW","strcpynA","strerror","strncat","strncpy","swprintf","vsprintf","vswprintf","wcscat","wcscpy","wcsncat","wcsncpy","wprintf","wsprintf","wsprintfA","wsprintfW","wvsprintf","wvsprintfA","wvsprintfW"};

static const std::set<std::string> fyi = { "CreateProcess","ZeroMemory","_putenv_s","allocs","calloc","execve","exit","fputs","fread","fwrite","getenv","localeconv","malloc","memset","realloc","reallocf","setenv","sigaction","sigaltstack","signal","strcmp","system","va_arg","valloc"};

static const std::set<std::string> obsolescent = { "GetFileType","asctime","atof","atoi","atol","atoll","bsearch","ctime","fopen","fprintf","fprintf","freopen","fscanf","fwprintf","fwscanf","getenv","gmtime","localtime","mbsrtowcs","mbstowcs","memcpy","memmove","printf","qsort","rewind","setbuf","setbuf","sscanf","strtok","swscanf","syslog","vfprintf","vfscanf","vfwprintf","vfwscanf","vprintf","vscanf","vsnprintf","vsprintf","vsscanf","vswprintf","vswscanf","vwprintf","vwscanf","wcrtomb","wcscat","wcscpy","wcsncat","wcsncpy","wcsrtombs","wcstok","wcstombs","wctomb","wmemcpy","wmemmove","wscanf"};

static std::string getFileLocation(const clang::Stmt* s, const clang::ASTContext* Context) {
     return  s-> getLocStart().printToString(Context -> getSourceManager());
 }


class obsolescentPrinter : public MatchFinder::MatchCallback {
 public :
     virtual void run(const MatchFinder::MatchResult &Result);
 };

 class fyiPrinter : public MatchFinder::MatchCallback {
 public :
     virtual void run(const MatchFinder::MatchResult &Result); 
 };

class BannedPrinter : public MatchFinder::MatchCallback {
 public :
     virtual void run(const MatchFinder::MatchResult &Result); 
     
 };

class SCOUR {
    public :
	    MatchFinder Initalize(void);
};
#endif
