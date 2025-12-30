# ⏱️ CLI Time Tracker (C++)

A lightweight **C++ command-line time tracking tool** built to measure **real development time** spent on projects — originally created for tracking work on a **VR CPU project**, but usable for **any focused task**.

No GUI.  
No internet.  
No database.  
Just an executable and plain text files.

---

## ✨ Features

- Start / stop timer with a single command
- Tracks **session time** and **total accumulated time**
- Persistent storage using text files (survives restarts)
- Works completely **offline**
- Cross-session accumulation
- Simple CLI interface
- Zero dependencies

---

## 🧠 Why This Tool Exists

While working on a low-level **VR CPU architecture project**, I often lost track of how much **real time** I spent coding.

Manual tracking failed.

So I built this tool to:
- Measure **actual effort**
- Maintain discipline
- Track long-term consistency

---

## 📂 Files Used

| File | Purpose |
|----|----|
| `t1.txt` | Session start time (seconds) |
| `t2.txt` | Session end time (seconds) |
| `tt.txt` | Total accumulated time (seconds) |
| `bool.txt` | Timer state (0 = stopped, 1 = running) |
| `format_time.txt` | Human-readable total time (HH:MM:SS) |

All files are auto-created if missing.

---

## 🚀 Usage

### ▶ Start / Stop Timer
```bash
cpp.exe
