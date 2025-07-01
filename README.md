# winbar-weather

A lightweight C++ plugin for Winbar that provides weather tracking functionality.
![image](https://github.com/user-attachments/assets/ee2ad7e8-4640-46c5-96a1-86149175082a)

# How it works

The plugin performs a simple curl request (every 3 minutes) to the URL https://wttr.in/?format=%f, which returns the current temperature for your location based on your IP address.

## Installation

NOTE: Make sure you have [Winbar](https://github.com/jmanc3/winbar) installed!

```bash
git clone https://github.com/keswel/winbar-weather
cd winbar-weather
./install
```

## Uninstall

```bash
cd ~/.config/winbar/plugins
rm winbar-weather.plugin
```

