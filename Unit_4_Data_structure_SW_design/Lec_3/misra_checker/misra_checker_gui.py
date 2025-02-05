import subprocess
import tkinter as tk
from tkinter import filedialog, scrolledtext
from tkinter import PhotoImage
import os

CPP_CHECK_PATH = r"C:\\Program Files\\Cppcheck\\cppcheck.exe"

def run_cppcheck(file_path):
    """Runs cppcheck with MISRA checks on the given file and returns the output."""
    try:
        result = subprocess.run(
            [CPP_CHECK_PATH, "--enable=all", "--addon=misra", file_path],
            capture_output=True, text=True, encoding='utf-8'
        )
        return result.stderr
    except FileNotFoundError:
        return f"Error: cppcheck not found at {CPP_CHECK_PATH}"

def analyze_file():
    """Handles file selection and analysis."""
    file_path = filedialog.askopenfilename(filetypes=[("C files", "*.c")])
    if file_path:
        result = run_cppcheck(file_path)
        text_area.delete('1.0', tk.END)
        text_area.insert(tk.END, result)

def create_gui():
    """Creates the Tkinter GUI."""
    global text_area

    root = tk.Tk()
    root.title("MISRA C Rule Checker")
    root.geometry("700x500")

    # Set the window icon (ensure the .png file is in the same directory)
    try:
        img = PhotoImage(file="misra_checker.png")
        root.iconphoto(False, img)
    except Exception as e:
        print(f"Error loading icon: {e}")

    frame = tk.Frame(root)
    frame.pack(pady=10)

    btn_select = tk.Button(frame, text="Select C File", command=analyze_file)
    btn_select.pack()

    text_area = scrolledtext.ScrolledText(root, wrap=tk.WORD, width=80, height=25)
    text_area.pack(pady=10, padx=10, fill=tk.BOTH, expand=True)

    root.mainloop()

if __name__ == "__main__":
    create_gui()
