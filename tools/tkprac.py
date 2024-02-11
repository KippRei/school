import tkinter as tk

master = tk.Tk()
v = tk.IntVar()

tk.Radiobutton(master, text="One", variable=v, value=1).pack()
tk.Radiobutton(master, text="Two", variable=v, value=2).pack()
master.mainloop()