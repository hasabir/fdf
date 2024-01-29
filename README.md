# FDF

This project focuses on creating a wireframe model representation of a 3D landscape. The landscape is defined by a set of coordinates stored in a .fdf file, and the program renders the model using isometric projection.
---
## Features
    - Render a wireframe model of a 3D landscape.
    - Use MiniLibX library for graphics programming.
    - Support isometric projection for model representation.
    - Smooth window management with keyboard and mouse events.
    - Bonus features include additional projections, zoom and translation.
## System Compatibility

This project is designed to work with macOS. While it may function on other operating systems, it is optimized and tested for macOS environments. If you encounter issues on other platforms, consider using macOS for the best experience.

### System Requirements

- macOS (Recommended)
- [MiniLibX Library](#link-to-minilibx) (Follow installation instructions for macOS)

### Note for Other Operating Systems

If you intend to run this project on a different operating system, please be aware that certain functionalities may not work as expected. Compatibility with operating systems other than macOS is not guaranteed, and adjustments may be required.

## USAGE

1. Compile project using Makefile:
```go
make
```

2. Run the program with a valid .fdf file as an argument to render the wireframe model.

```bash
./fdf test_maps/<Choose a file>
```
- for bonus features:

```bash
./fdf_bonus test_maps/<Choose a file>
```


## Makefile Commands

- make: Compile the project.
- make clean: Remove object files.
- make fclean: Remove object files and the executable.
- make re: Recompile the project.

## Additional Notes

- Ensure the .fdf file is properly formatted to avoid crashes.

## Language:

<svg width="50" height="50" viewBox="0 0 256 256" fill="none" xmlns="http://www.w3.org/2000/svg">
<rect width="256" height="256" rx="60" fill="#394AAB"/>
<path d="M134.001 33C169.144 33 199.828 52.0863 216.262 80.4561L216.102 80.183L174.753 103.991C166.607 90.1977 151.672 80.8892 134.54 80.6975L134.001 80.6945C107.875 80.6945 86.6945 101.874 86.6945 127.999C86.6945 136.543 88.9723 144.552 92.9335 151.469C101.088 165.704 116.416 175.306 134.001 175.306C151.693 175.306 167.109 165.582 175.222 151.195L175.025 151.54L216.311 175.458C200.057 203.588 169.794 222.615 135.059 222.994L134.001 223C98.746 223 67.9753 203.796 51.582 175.276C43.5791 161.353 39 145.212 39 127.999C39 75.5334 81.5323 33 134.001 33Z" fill="white"/>
</svg>