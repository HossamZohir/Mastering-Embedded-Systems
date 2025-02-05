# MISRA C Rule Checker

## Overview

The MISRA C Rule Checker is a simple GUI application that allows you to analyze C source files for compliance with MISRA C rules using `cppcheck`. The application provides an easy-to-use interface for selecting a C file and running the analysis, displaying the results directly within the application.

## Features

- **File Selection**: Choose a C file from your file system.
- **MISRA C Analysis**: Run `cppcheck` with MISRA C rules on the selected file.
- **Result Display**: View the analysis results directly in the application.

## Requirements

- Python 3.x
- Tkinter (usually comes pre-installed with Python)
- `cppcheck` installed on your system

## Installation

1. **Install Python**: Ensure Python 3.x is installed on your system. You can download it from [python.org](https://www.python.org/).

2. **Install cppcheck**:
   - Download and install `cppcheck` from [cppcheck.sourceforge.io](http://cppcheck.sourceforge.io/).
   - Ensure `cppcheck` is installed at the default location `C:\\Program Files\\Cppcheck\\cppcheck.exe` or update the `CPP_CHECK_PATH` variable in the script to point to the correct location.

3. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/misra-c-rule-checker.git
   cd misra-c-rule-checker
   ```

4. **Run the Application**:
   ```bash
   python misra_checker.py
   ```

## Usage

1. **Launch the Application**: Run the script using Python.
2. **Select a C File**: Click the "Select C File" button to choose a C file from your file system.
3. **View Results**: The analysis results will be displayed in the text area below the button.

## Customization

- **Icon**: You can customize the application icon by placing a `.png` file named `misra_checker.png` in the same directory as the script. The icon will be displayed in the application window.

## Troubleshooting

- **cppcheck Not Found**: If you encounter an error indicating that `cppcheck` is not found, ensure that `cppcheck` is installed and the `CPP_CHECK_PATH` variable in the script points to the correct location.
- **Icon Loading Error**: If the icon fails to load, ensure that the `misra_checker.png` file is in the same directory as the script and is a valid PNG file.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [cppcheck](http://cppcheck.sourceforge.io/) for providing a powerful static analysis tool.
- [Tkinter](https://docs.python.org/3/library/tkinter.html) for the GUI framework.

---

Feel free to modify this README to better suit your project's needs!