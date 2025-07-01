#!/bin/bash

set -e  # Exit on error
# set -x  # Print each command before executing

PLUGIN_NAME="winbar-weather.plugin"
SRC_FILE="winbar-weather.plugin.cpp"
TARGET_DIR="$HOME/.config/winbar/plugins"

echo "🔧 Compiling $SRC_FILE..."
g++ "$SRC_FILE" -o "$PLUGIN_NAME" -lcurl

echo "📁 Ensuring plugin directory exists at: $TARGET_DIR"
mkdir -p "$TARGET_DIR"

echo "📦 Installing plugin..."
mv -f "$PLUGIN_NAME" "$TARGET_DIR/"

echo "✅ Installation complete! Plugin placed at: $TARGET_DIR/$PLUGIN_NAME"
