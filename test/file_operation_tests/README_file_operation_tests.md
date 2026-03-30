# Tick CLI Timer Tool

CLI timer tool written in C++.

## Features
| Operation Name | Core functionality |
|----------------|--------------------|
| File read      | This operation given file path according read the file content, push file content in vector |
| File write     | This operation given file path according write the given file content as a type of string or integer |
| File append    | This operation given file path according append the given file content to end of the previous file content |

## Tests
| File names           | Results      |
|----------------------|--------------|
| test_append_file.cpp | **Pass**     |
| test_read_file.cpp   | **Pass**     |
| test_write_file.cpp  | **Pass**     |

## Run tests

```
g++ test_read_file.cpp ../../src/File_Operations/file_operations.cpp -o ./Test_exe_file/test_read
g++ test_write_file.cpp ../../src/File_Operations/file_operations.cpp -o ./Test_exe_file/test_write
g++ test_append_file.cpp ../../src/File_Operations/file_operations.cpp -o ./Test_exe_file/test_append
```
