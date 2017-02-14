set(LLVM_LINK_COMPONENTS support)

add_clang_executable(scour
  Scour.cpp
  )
target_link_libraries(scour
  clangTooling
  clangBasic
  clangASTMatchers
  )
