#include <gtest/gtest.h>
#include <llvm/ADT/ArrayRef.h>
#include "Scour.h"
 
TEST(BannedTest, Banned) { 
	testing::internal::CaptureStdout();
	std::string output = testing::internal::GetCapturedStdout();
    //ASSERT_EQ(0, squareRoot(0.0));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    std::vector<std::stringe> ArgsTy;
    ArgsTy.push_back("Sample.c");
    llvm::ArrayRef<std::string> source(ArgsTy);
    CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
    ClangTool Tool(OptionsParser.getCompilations(),
    source);
    MatchFinder * Finder = Initialize();
    Tool.run(newFrontendActionFactory(&Finder).get());
    return RUN_ALL_TESTS();
}

