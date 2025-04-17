# C for Windows

C for Windows is a free C interpreter that uses `cl.exe` (Microsoft C/C++ Compiler). It is written entirely in C++. To use C for Windows, you will need the Visual Studio C++ Redistributable installed on your system, as well as Visual Studio itself.

## Features

- Lightweight and easy-to-use C interpreter for Windows.
- Built upon the power of `cl.exe`, enabling compatibility with the Microsoft compiler.
- Written in C++ for performance and reliability.

---

## Prerequisites

1. **Visual Studio C++ Redistributable**: Ensure that the appropriate Visual Studio C++ Redistributable is installed on your system.
2. **Visual Studio Installed**: You will need Visual Studio installed to access the `cl.exe` compiler.

---

## How to Install

1. Navigate to the [Releases](https://github.com/ZohanHaqu/C/releases) page.
2. Click on the **latest version** release.
3. Download one of the following:
   - `CLanguage-x64.msi` (Windows Installer): Follow the setup wizard to install.
   - `CLanguage-x64.exe` (Bundle Installer): Run the executable and select **Install** or **Options** as needed.
4. Once the installation completes, the `c` interpreter will be added to your system's PATH.

---

## How to Run C Scripts

1. Open **Visual Studio Developer Command Prompt** or **PowerShell** as an administrator.
2. Use the following command to run a C script:
   ```bash
   c <your_script_path>
