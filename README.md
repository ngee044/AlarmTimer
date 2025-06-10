# AlarmTimer

A Qt-based cross-platform alarm timer application with multimedia support

## 📋 Overview

AlarmTimer is a feature-rich alarm timer application built with Qt Framework. It provides an intuitive interface for setting multiple alarms with custom sound effects, making it perfect for reminders, timers, and scheduling tasks.

## ✨ Key Features

- 🔔 Multiple alarm management with custom sounds
- 🎵 Built-in alarm sound (MP3 support)
- ⏰ Target time dialog for precise alarm setting
- 🖥️ Modern Qt-based GUI interface
- 🔧 JSON-based configuration system
- 🎯 Cross-platform support (Windows, macOS, Linux)
- 📱 Responsive UI design

## 🛠️ Tech Stack

- **Language**: C++17/C++20
- **GUI Framework**: Qt 5.15.2 (Qt5/Qt6 compatible)
- **Build System**: CMake 3.20+
- **Audio**: Qt Multimedia
- **Configuration**: JSON
- **Compiler**: MSVC 2019 (Windows)

## 📁 Project Structure

```
AlarmTimer/
├── CMakeLists.txt              # Root CMake configuration
├── MainApp/                    # Main application directory
│   ├── CMakeLists.txt         # MainApp CMake configuration
│   ├── main.cpp               # Application entry point
│   ├── Core/                  # Core business logic
│   │   ├── TimeConfiguration.h     # Time configuration header
│   │   └── TimeConfiguration.cpp   # Time configuration implementation
│   ├── QWidgets/              # Qt UI components
│   │   ├── mainwindow.h            # Main window header
│   │   ├── mainwindow.cpp          # Main window implementation
│   │   ├── mainwindow.ui           # Main window UI design
│   │   ├── TargetTimeDialog.h      # Time setting dialog header
│   │   ├── TargetTimeDialog.cpp    # Time setting dialog implementation
│   │   └── TargetTimeDialog.ui     # Time setting dialog UI
│   └── Res/                   # Resources
│       ├── AlarmBgm.mp3           # Default alarm sound
│       └── configuration.json     # App configuration file
└── build/                     # Build output directory
```

## 🚀 Installation & Usage

### Prerequisites

- **CMake**: 3.20 or higher
- **Qt**: 5.15.2 or Qt 6.x
- **Compiler**: C++17/C++20 compatible
  - Windows: Visual Studio 2019 or later
  - Linux: GCC 8+ or Clang 8+
  - macOS: Xcode 10+

### Qt Installation Path

The project is configured to find Qt at:
```
C:/Qt/5.15.2/msvc2019_64
```

To use a different Qt installation, modify the `QT_ROOT` and `QT_COMPILER` variables in [`MainApp/CMakeLists.txt`](MainApp/CMakeLists.txt):

````cmake
set(QT_ROOT "C:/Qt/5.15.2")
set(QT_COMPILER "msvc2019_64")

Build Instructions
Clone the repository
Create build directory
Configure with CMake
Build the project
Run the application
The application will automatically copy alarm sound files to the alarmeffect/ directory in the executable location.

Building with Visual Studio
Open Visual Studio and select "Open Folder"
Navigate to the project root directory
CMake will automatically configure the project
Build using Build > Build All (Ctrl+Shift+B)
🎯 Core Components
MainWindow Class
The primary application window that manages the user interface.

Files: MainApp/QWidgets/mainwindow.h, mainwindow.cpp
Features:
Timer display and management
Alarm controls and status
Integration with Qt Multimedia for audio playback
TimeConfiguration Class
Core class for managing time settings and alarm configurations.

Files: MainApp/Core/TimeConfiguration.h, TimeConfiguration.cpp
Function: Handles time calculations, alarm scheduling, and configuration persistence
TargetTimeDialog Class
Dialog window for setting specific alarm times.

Files: MainApp/QWidgets/TargetTimeDialog.h, TargetTimeDialog.cpp
Function: Provides intuitive time selection interface
🔧 Configuration
The application uses a JSON configuration file (configuration.json) for storing:

Alarm settings
Audio preferences
UI preferences
Default timer values
🎵 Audio Features
Default Sound: AlarmBgm.mp3 included
Format Support: MP3, WAV, and other Qt Multimedia supported formats
Custom Sounds: Place audio files in the alarmeffect/ directory
🛠️ Development
IDE Setup
Visual Studio

Install "C++ CMake tools for Visual Studio"
Open folder and let CMake configure automatically
Qt Creator

Open as CMake project
Qt Creator will handle UI file editing automatically
CLion

Import as CMake project
Configure Qt paths if needed
UI Development
UI files (.ui) can be edited with:

Qt Designer (standalone)
Qt Creator (integrated)
Visual Studio Qt tools
🤝 Contributing
Fork the repository
Create a feature branch (git checkout -b feature/amazing-feature)
Commit your changes (git commit -m 'Add some amazing feature')
Push to the branch (git push origin feature/amazing-feature)
Open a Pull Request
Development Guidelines
Follow C++17/C++20 standards
Use Qt coding conventions
Include unit tests for new features
Update documentation for API changes
📝 License
This project is licensed under the MIT License - see the LICENSE file for details.

👤 Author
ngee044

GitHub: @ngee044
🐛 Issues & Support
Found a bug or need help? Please check our Issues page.

📊 Version Information
Version: 1.0.0.0
Qt Compatibility: Qt 5.15.2+ / Qt 6.x
CMake Minimum: 3.20
C++ Standard: C++17 (MainApp), C++20 (Root)
🙏 Acknowledgments
Qt Framework for the excellent GUI toolkit
Qt Multimedia for audio playback capabilities
