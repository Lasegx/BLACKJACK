# CMakeList.txt : CMake project for BLACKJACK, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("BLACKJACK")

# Add source to this project's executable.
add_executable (BLACKJACK "BLACKJACK.cpp" "BLACKJACK.h" "Card.cpp" "Deck.cpp" "Hand.cpp")

# --- Tests ---
enable_testing()

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests
    tests/CardTests.cpp
    Card.cpp
    tests/DeckTests.cpp
    Deck.cpp
    tests/HandTests.cpp
    Hand.cpp
)
if (MSVC)
  target_compile_options(tests PRIVATE /Zc:preprocessor)
endif()
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(tests)