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
<p align="left">
  <img src="https://user-images.githubusercontent.com/25181517/192106070-46255bcf-65e6-4c6b-a296-bf8d0d8fb2a7.png" alt="C" width="40" height="40"/>
</p>
 	
