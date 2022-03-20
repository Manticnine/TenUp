
Debian
====================
This directory contains files used to package tenupd/tenup-qt
for Debian-based Linux systems. If you compile tenupd/tenup-qt yourself, there are some useful files here.

## tenup: URI support ##


tenup-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install tenup-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your tenup-qt binary to `/usr/bin`
and the `../../share/pixmaps/tenup128.png` to `/usr/share/pixmaps`

tenup-qt.protocol (KDE)

