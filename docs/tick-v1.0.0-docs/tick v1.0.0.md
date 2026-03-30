# CLI Time Tracker (C++)

## tick v1.0.0 Summary

**tick v1.0.0** was implemented as a **monolithic program in a single file**.
All timer operations (start and stop) were executed in the **program's current directory**.

### Limitations in v1.0.0

* The tool required placing the executable (`cpp.exe`) inside each directory where the timer was used.
* This created a **duplicate executable problem** when users wanted to track time in multiple directories.
* The timer calculation was limited to **24-hour cycles**, because the tool was mainly designed for **daily time tracking**, not long-term accumulation.

Because of these limitations, **tick v2.0.0** introduced a redesigned architecture with:

* **Default Path Mode**
* **User Path Mode**

This allows a **single executable to manage timers across multiple directories** without duplication.

---

## Project Structure

```
tick
 ├── cpp.cpp
 ├── cpp.exe
 ├── .gitignore
 ├── LICENSE
 └── README.md
```

---

## Tool Commands

| Command          | Description                           |
| ---------------- | ------------------------------------- |
|  cpp.exe         | Start or stop the timer               |
|  cpp.exe status  | Show the current running timer status |
|  cpp.exe clear   | Reset all stored time data            |
|  cpp.exe help    | Display help information              |