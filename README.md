# Student Record Manager in C

This is a beginner-friendly systems-level project built in C that demonstrates dynamic memory management and file handling using a simple Student Record Management System.

The system allows:
- Adding new student records
- Displaying all stored records
- Saving records to a binary file (`student.dat`)
- Loading records from the file on program startup

---

## 🔧 Features

- Dynamic memory allocation with `malloc`
- Linked list implementation for storing student records
- File I/O using `fwrite` and `fread` to persist data in binary format
- Prevents saving raw pointers to file (correct memory-safe technique)
- Clean separation of functions (`create`, `add`, `display`, `save`, `load`)

---

## 📁 Project Structure


