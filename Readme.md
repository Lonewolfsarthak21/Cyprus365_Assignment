# Photomode Plugin - Unreal Engine 5

## Overview

The **Photomode** plugin allows users to capture screenshots and copy the image directly to the clipboard, enabling them to paste it into any Windows-compatible application (e.g., Paint, Word). The feature can be triggered using a keypress (default: `P` key) and works within the character blueprint in your game.

## Features

- **Capture and Clipboard Integration**: Captures a screenshot of the game window at a predefined resolution (default: 256x256) and copies the image data to the clipboard.
- **Cross-platform Clipboard Support**: The plugin uses Unreal Engine’s platform-specific clipboard functions to ensure compatibility with Windows and other platforms.
- **Easy Blueprint Integration**: The component can be easily added to any actor (e.g., character) in the Unreal Editor and controlled via blueprint events.

## How It Works

1. **Photomode_Control Class**: This class extends `UActorComponent` and includes functions to capture the screenshot and copy it to the clipboard.
2. **CaptureScreenshot Function**:
    - Takes a screenshot of the game at the specified resolution using the Unreal Engine high-resolution screenshot system.
    - Saves the screenshot to a temporary file and reads the pixel data.
3. **CopyImageToClipboard Function**:
    - Compresses the image data as a PNG and encodes it in Base64.
    - Copies the Base64-encoded PNG string to the system clipboard.
4. **Blueprint Integration**:
    - The plugin is added as a component to the Character Blueprint.
    - The `P` key press event calls the `CaptureAndCopyToClipboard()` function to trigger the screenshot and clipboard operation.

## Challenges Faced

1. **File Path Handling**: Locating the screenshot file after requesting a capture was tricky due to potential delays in file saving. This was mitigated by ensuring the file path is correctly retrieved and checked before loading the data.
2. **Clipboard Encoding**: Ensuring the image was correctly compressed and converted to Base64 format before copying to the clipboard required attention to data conversion between formats.
3. **Cross-platform Clipboard Support**: Since the project was primarily developed for Windows, conditional platform compilation (`#if PLATFORM_WINDOWS`) was used to ensure the clipboard functionality worked on other platforms as well.

## How to Test

1. **Add Plugin to Your Project**:
    - Ensure the plugin is added to your project and enabled in the Unreal Engine editor.
    - In your character blueprint, add the **Photomode_Control** component.

2. **Trigger the Screenshot**:
    - Create an event for the `P` key press in the blueprint.
    - Call the `CaptureAndCopyToClipboard()` function in response to the `P` key event.

3. **Test the Clipboard**:
    - Run the game and press the `P` key.
    - Open a Windows application like Paint or Word and paste the image (Ctrl + V). The captured screenshot should appear.

## Future Improvements

- Allow users to choose custom resolutions for the screenshot.
- Support for other image formats such as grayscale, RGBA.
- A more responsive file system check to handle the screenshot saving delay more efficiently.

## License

This plugin is open for use in any project. Feel free to modify and improve upon it.

---

This README should explain your logic, challenges, and how others can test your plugin effectively.