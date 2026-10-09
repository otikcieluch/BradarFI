# Introducing the Bradar File Info or `bradarwatisdis`.

A lightweight, standalone file info tool written in C.
Only works on Linux.
--------------------

**Clone:**

- `git clone https://github.com/otikcieluch/BradarFI.git`

**Make:**

- `cd BradarFI`
- `make`
- `make install` (requires sudo or doas)

**Dependencies:**

- `make`
- `gcc`
- `glibc` (or `musl`)
- `git` (optionally for cloning the source)
- Preferably the latest versions.

**Run:**

- `bradarwatisdis <filename> [flags]` or `--help` if you need info/flags

**Flags:**

- Disable specific file information. Multiple flags can be used at the same time. (a file named as one of the flags won't work) 

---

- `--no-file` | File name line
- `--no-file-content` | Content line
- `--no-filetype` | Type line
- `--no-filesize` | Size line
- `--no-permissions` | The `rwx` string (octal still shown)
- `--no-octal` | The octal mode (`rwx` string still shown)
- `--no-owner-name` | Owner line
- `--no-birth-time` | Created line
- `--no-modified` | Modified line
- `--no-access-time` | Accessed line

<img width="432" height="390" alt="image" src="https://github.com/user-attachments/assets/99cf957f-ec08-4189-aa3f-05c72d288390" /> <img width="329" height="390" alt="Tux" src="https://github.com/user-attachments/assets/f90a9e3d-d49b-4282-9ee1-098c10bd6fff" />



><sup> If you have any issues, want to suggest a feature, or just want to let me know something, contact me at otikcieluch@gmail.com or open an issue on [GitHub](https://github.com/otikcieluch/BradarFI/issues). </sup>
