# AlarmTimer ⏰  
Qt-based cross-platform alarm & stopwatch application
<!-- Badges -->
![license](https://img.shields.io/badge/license-MIT-blue.svg)
![platform](https://img.shields.io/badge/platform-Windows%20%7C%20macOS%20%7C%20Linux-green)

> **AlarmTimer** lets you run an always-on stopwatch and set a target time that
> triggers a custom MP3 alarm.  
> Built with modern **Qt 5 / Qt 6**, C++17 and CMake.

---

## ✨ Features
| Category | Details |
|----------|---------|
| **Stopwatch** | Start / Stop / Reset controls with 1 s resolution |
| **Lap list** | Up to 10 laps are displayed in rotating order |
| **Target Time Dialog** | Set an exact `hh:mm:ss` goal; alarm fires at or after the target |
| **Custom alarm sound** | Plays an MP3 from `Res/AlarmBgm.mp3` (can be replaced) |
| **JSON settings** | User preferences are saved to `Res/configuration.json` |
| **Cross-platform build** | Works on Windows, macOS and Linux with the same CMake script |

---

## 🔧 Build & Run

### Prerequisites
| Tool | Minimum |
|------|---------|
| **Qt** | 5.15.2 (or 6.x) |
| **CMake** | 3.24 |
| **Compiler** | • MSVC 2019 / 2022<br>• GCC 8+ or Clang 8+ |

### Steps (command-line, out-of-source build)

```bash
git clone https://github.com/ngee044/AlarmTimer.git
cd AlarmTimer
cmake -B build -G "Visual Studio 17 2022" -A x64 ^
      -DQT_ROOT="C:/Qt/5.15.2" -DQT_COMPILER="msvc2019_64"
cmake --build build --config Release
# Run
build\out\Release\MainApp.exe
````

> On Linux/macOS replace the generator with `-G Ninja` (or leave default)
> and make sure `qtbase` & `qtmultimedia` dev packages are in your `PATH`.

---

## 📁 Project Layout

```
AlarmTimer/
├─ CMakeLists.txt          # top-level build script
├─ MainApp/
│  ├─ CMakeLists.txt
│  ├─ main.cpp
│  ├─ Core/
│  │  └─ TimeConfiguration.*# JSON load / save
│  ├─ QWidgets/
│  │  ├─ mainwindow.*(.ui)
│  │  └─ TargetTimeDialog.*(.ui)
│  └─ Res/                 # resources copied after build
│     ├─ AlarmBgm.mp3
│     └─ configuration.json
└─ build/                  # created by CMake
```

---

## 🖥️ Screenshots

*(add your screenshots here)* <img src="docs/screenshot_main.png" width="640">

---

## 🚀 Using a Custom Alarm

1. Place an MP3 file in `MainApp/Res/` (e.g. `MyAlarm.mp3`).
2. Update `alarm_sound_path_` in `mainwindow.cpp` **or** rename your file to `AlarmBgm.mp3`.
3. Re-build (the CMake post-build step will copy it to `audioeffect`).

---

## 🤝 Contributing

Pull-requests and issues are welcome!
Please follow the existing code style (Clang-Format) and commit with clear messages.

---

## 📜 License

AlarmTimer is released under the **MIT License**; see [`LICENSE`](LICENSE) for details.

---
