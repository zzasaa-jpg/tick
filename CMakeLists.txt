cmake_minimum_required(VERSION 3.10)

project(CLI_TIMER)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/EXE)

add_executable(cpp
    src/cpp.cpp
    src/All_file_names/All_file_names.cpp
    src/Program_boot/program_boot.cpp
    src/File_Operations/file_operations.cpp
    src/Write_TT/write_tt.cpp
    src/File_Checking_Process/file_checking_process.cpp
    src/Conditional_Argument/conditional_argument.cpp
    src/Utility/RMR_Utility/RMR.cpp
    src/Utility/RCFV_Utility/RCFV_Utility.cpp
    src/Utility/DEFAULT_PATH_UTILITY/DEFAULT_PATH.cpp
    src/Utility/Exists_PK_Utility/Exists_pk.cpp
    src/Utility/LOAT_Utility/LOAT.cpp
    src/Utility/Dir_Permission_Checker_Utility/dir_permission.cpp
    src/Utility/REMOVE_SLASH_UTILITY/Remove_Slash.cpp
    src/Utility/Print_Timer_Utility/Print_Timer.cpp
    src/Utility/Decide_du_path_utility/decide_du_path.cpp
    src/Utility/Trim_Spaces_Utility/Trim_spaces.cpp
    src/Conditional_Argument/commands/Status/status.cpp
    src/Conditional_Argument/commands/Clear/Clear.cpp
    src/Conditional_Argument/commands/Help/Help.cpp
    src/Conditional_Argument/commands/Default/Default.cpp
    src/Conditional_Argument/commands/Search/Search.cpp
    src/Conditional_Argument/commands/New/New.cpp
    src/Conditional_Argument/commands/List/List.cpp
    src/Conditional_Argument/commands/Session/Session.cpp
    src/Conditional_Argument/commands/Version/Version.cpp
)
