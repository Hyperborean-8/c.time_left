# c.time_left

A CLI-tool that calculates and displays the time remaining between two dates, using the ncurses library.

# Project progress

- Configuration
    - [ ] Allow it to read any file
    - [ ] Parcing TOML file
    - [ ] Standard file location
    - [ ] Generating basic config
    - [ ] Adding new countdowns through the TUI
- Rendering
    - [ ] List mode
        - Shows all countdowns in a simple compact list.
        - Should be resizable
    - [ ] Extra information mode
        - Opens when pressing ENTER on selected countdown in a list mode.
        - Shows a lot more information about only one countdown.
        - Should be resizible
