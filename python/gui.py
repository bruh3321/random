import tkinter as tk
import random


class mainGUI:
    def __init__(self, master):
        self.master = master
        self.master.title("Random Number Generator")
        self.master.geometry("400x200")
        self.master.resizable(False, False)

        self.input = tk.Entry(master, font=("Arial", 20), width=0)
        self.input.pack()

        self.label = tk.Label(master, text="Random Number Generator", font=("Arial", 20))
        self.label.pack()

        self.button = tk.Button(master, text="Generate Random Number", command=self.generate)
        self.button.pack()

        self.result = tk.Label(master, text="", font=("Arial", 20))
        self.result.pack()

    def generate(self):
        self.result.config(text=random.randint(0, int(self.input.get())))

if __name__ == "__main__":
    root = tk.Tk()
    app = mainGUI(root)
    root.mainloop()