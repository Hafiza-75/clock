# 🕰️ Digital Clock in C

## Description
This is a **C-based Digital Clock** that displays the following:

- ✅ Current Time (HH:MM:SS)
- ✅ Current Date (DD-MM-YYYY)
- ✅ Current Day (e.g., Monday)
- ✅ **Islamic (Hijri) Date and Month**

It is a simple terminal-based project that continuously updates in real time.

---

## 💡 Features
- Real-time clock display
- Gregorian calendar date
- Day of the week
- Hijri (Islamic) date and month (calculated using approximate algorithm)
- Clean terminal interface
- Cross-platform compatibility (with minor adjustments for Windows/Linux)
## 🎞 Sample Output
![output](https://github.com/user-attachments/assets/809ea131-0d37-4f43-9800-a0fbc08a219b)

---

## 🛠️ Requirements
- C compiler (GCC or any standard C compiler)
- Basic terminal/console

---

## 🧾 How It Works
- Uses `time.h` to get system time and date.
- Converts Gregorian date to Hijri date using a mathematical approximation.
- Continuously refreshes the screen using terminal commands.

---

## 🚀 How to Compile & Run

### Compile:
```bash
gcc digital_clock.c -o digital_clock
