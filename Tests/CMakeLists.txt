Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        b9853b4
)

FetchContent_MakeAvailable(Catch2)

add_executable(Tests AlgoVector_tests.cpp AlgoList_tests.cpp)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)