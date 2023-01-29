# Documentation Organizer

The documentation at my workplace is quite messy, and all the current employees
are acting as walking documentation. As such, I thought it might be a good idea
to make a program that would keep track of documentation in a user-friendly
way.

### Design Goal

In order for anyone to actually be incentivized to use this thing, it must be:

1. Easy to use - this means having some sort of GUI
2. Can import existing documentation somewhat easily
3. Can instantiate existing library of documentation from a file accessible
   from the internet
4. Documentation can be synced with mutiple people somewhat easily


### Implementation

GUI will be built using Qt 6. Since Qt includes networking functionality, I'll
use that as well. `MainWindow`

A "file system"-like data structure will be used to keep track of all the
different documentation entries, with folder structures etc. `DirectoryTree`
