# AlarmTimer

A Qt-based alarm timer application

## 📋 Overview

AlarmTimer is a cross-platform alarm timer application developed using the Qt Framework. It provides a simple and intuitive interface for users to set desired alarm times and receive notifications.

## ✨ Key Features

- Qt-based GUI interface
- Alarm time setting and management
- Cross-platform support (Windows, macOS, Linux)

## 🛠️ Tech Stack

- **Language**: C++20
- **GUI Framework**: Qt 5.15.2
- **Build System**: CMake 3.20+
- **Compiler**: MSVC 2019 (Windows)

## 📁 Project Structure

```
AlarmTimer/
├── CMakeLists.txt          # Main CMake configuration file
├── MainApp/                # Main application directory
│   ├── main.cpp           # Application entry point
│   ├── CMakeLists.txt     # MainApp CMake configuration
│   ├── Core/              # Core logic
│   │   ├── TimeSave.h     # Time save class header
│   │   └── TimeSave.cpp   # Time save class implementation
│   └── QWidgets/          # Qt widget UI
│       ├── mainwindow.h   # Main window header
│       ├── mainwindow.cpp # Main window implementation
│       └── mainwindow.ui  # UI design file
└── build/                 # Build output directory
```

## 🚀 Installation & Usage

### Prerequisites

- CMake 3.20 or higher
- Qt 5.15.2 or Qt 6.x
- C++20 compatible compiler
- Windows: Visual Studio 2019 or later

### Qt Installation Path

The project looks for Qt in the following default path:
```
C:/Qt/5.15.2/msvc2019_64
```

If Qt is installed in a different location, modify the `QT_ROOT` variable in `MainApp/CMakeLists.txt`.

### Build Instructions

1. **Clone the repository**
```bash
git clone https://github.com/ngee044/AlarmTimer.git
cd AlarmTimer
```

2. **Create build directory**
```bash
mkdir build
cd build
```

3. **Configure CMake**
```bash
cmake ..
```

4. **Build the project**
```bash
cmake --build . --config Release
```

5. **Run the application**
```bash
./out/MainApp.exe  # Windows
./out/MainApp      # Linux/macOS
```

### Building with Visual Studio

1. Open the project root directory with "Open Folder" in Visual Studio
2. CMake will automatically configure
3. Run `Build` > `Build All`

## 🔧 Development Environment Setup

### IDE Configuration

- **Visual Studio**: Enable CMake support
- **Qt Creator**: Open as CMake project
- **CLion**: Import as CMake project

### Qt Designer

UI files (`mainwindow.ui`) can be edited with Qt Designer.

## 📂 Core Components

### MainWindow Class
Manages the main application window.
- **Files**: `MainApp/QWidgets/mainwindow.h`, `mainwindow.cpp`
- **Function**: Qt main window UI management

### TimeSave Class
Core class for storing and managing time-related data.
- **Files**: `MainApp/Core/TimeSave.h`, `TimeSave.cpp`
- **Namespace**: `MainCore`

## 🤝 Contributing

1. Fork this repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Create a Pull Request

## 📝 License

This project is distributed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## 👤 Author

**ngee044**

- GitHub: [@ngee044](https://github.com/ngee044)

## 🐛 Bug Reports & Feature Requests

If you find a bug or want to suggest a new feature, please use the [Issues](https://github.com/ngee044/AlarmTimer/issues) page.

## 📊 Version Information

- **Current Version**: 1.0.0.0
- **Qt Version**: 5.15.2
- **Minimum CMake Version**: 3.20
- **C++ Standard**: C++20

---

⭐ If you find this project useful, please give it a star!
