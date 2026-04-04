# CLI Time Tracker (C++)

## tick v2.0.0 Summary

**tick v1.0.0** was implemented as a monolithic program in a single file. In **tick v2.0.0**, the source code was refactored and modularized. Each module now exposes a API and communicates with other modules through well-defined interfaces. Additionally, time formatting was improved. In **tick v1.0.0**, timer calculations were limited to **24 hours**. In **tick v2.0.0**, the time conversion system was expanded to support **large durations—from seconds up to centuries**.


The core architectural improvement in **v2** is the separation of execution modes:

* **Default Path Mode** – uses a predefined project path
* **User Path Mode** – allows the user to specify a custom directory path

This allows users to either work with the default timer storage or run timers in any custom directory.

---

## Modules

| Module Name           | Core functionality                                           |
| --------------------- | ------------------------------------------------------------ |
| All_file_names        | Stores required file names used by the tool                  |
| Conditional_Argument  | Parses CLI arguments and commands                            |
| File_Checking_Process | Ensures required files exist and auto-generates missing ones |
| File_Operations       | File APIs for read, write, and append operations             |
| Program_boot          | Entry validation process that checks module readiness        |
| Utility               | Reusable utility functions used across the project           |
| Write_TT              | Calculates elapsed seconds and writes total time             |
| cpp.cpp               | Program entry point                                          |

---

## Utilities

| Utility Name                   | Core functionality                                                 |
| ------------------------------ | ------------------------------------------------------------------ |
| DEFAULT_PATH_UTILITY           | Returns the default project directory path                         |
| Dir_Permission_Checker_Utility | Checks directory permissions                                       |
| Exists_PK_Utility              | Checks if a path/key already exists in the directory file          |
| LOAT_Utility                   | Prints currently active timers                                     |
| Print_Timer_Utility            | Converts elapsed seconds into formatted time                       |
| RCFV_Utility                   | Reads content into a vector for file processing                    |
| REMOVE_SLASH_UTILITY           | Normalizes file paths for Windows and Linux                        |
| RMR_Utility                    | Reads, modifies, and rewrites file content using key/value targets |

---

## Tests

| Test Name              | Result   |
| ---------------------- | -------- |
| file_operation_tests   | **Pass** |
| Utility_function_tests | **Pass** |
| Stress Testing         | **Pass** |

---

## Compilation

Version **v1** did not include a build system.
Version **v2** introduces **CMake** for easier compilation and modular builds.

```
mkdir build
cd build
cmake ..
cmake --build .
```

You may still use a manual compiler command if preferred.

---

## Project Structure

```
tick
 ├── docs
 ├── src
 ├── test
 ├── .gitignore
 ├── CMakeLists.txt
 ├── LICENSE
 └── README.md
```

---

## Tool commands

|  Commands                   | Description                                        |
|-----------------------------|----------------------------------------------------|
|  cpp.exe                    | Start / Stop timer                                 |
|  cpp.exe status             | Show running status at default path                |
|  cpp.exe clear/reset        | Reset all time data at default path                |
|  cpp.exe default            | Set default path                                   |
|  cpp.exe new_ <path> <key>  | Set user path                                      |
|  cpp.exe status <path>      | Show running status at user path                   |
|  cpp.exe clear/reset <path> | Reset all time data at user path                   |
|  cpp.exe list               | List of active timers                              |
|  cpp.exe session            | Show default path session time with out timer stop |
|  cpp.exe session <path>     | Show user path session time with out timer stop    |
|  cpp.exe help               | Show this help                                     |
|  cpp.exe version            | Print the tool current version                     |
|  cpp.exe search             | Search specific timer path in directory file       |

---

## ⚠️ Caution

The program generates several internal files to store session and time data.

**Do not modify or delete these generated files manually.**

If any generated file is modified or deleted, the program may:
- Crash
- Produce unexpected behavior
- Lose previously stored time data

This happens because the program depends on the structure of these generated files.

### Recovery

If this situation occurs accidentally:

1. Go to the directory where the compiled program exists.
2. Manually delete all generated files created by the program.
3. Start the program again so it can regenerate the required files.

---