# so_long 🐬

<div align="center">

<img src="docs/assets/so_long.gif" height=300px> </img>  
*A 2D maze game*  
[![42 School](https://img.shields.io/badge/School-000000?style=flat-square&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![MiniLibX](https://img.shields.io/badge/MiniLibX-Graphics-orange?style=flat-square)](https://github.com/42Paris/minilibx-linux)


</div>

## 📖 About
So Long is 2D maze game in which players must collect all coins on the map while avoiding monsters to open the exit and win the game.  
This is the first graphical project in the 42 curriculum.

## 🎮  Features
- 🖵 Reatime 2D rendering
- 🕹️ player movement with WASD controls
- 🎨 Animations and textures made by me (incredible work I know)
- 🗺️ Map validation with comprehensive error checking

## 🚀 Getting Started

### Download from [latest](https://github.com/ghostyghast/so_long/releases/latest)

### Or

### Compile from source
#### Prerequisites
- **GCC** compiler
- **Make**
- **MiniLibX** library (included for Linux/macOS)
- **X11** development libraries (Linux only)

1. **Clone the repository**
```bash
git clone https://github.com/eth1711/cub3d.git
cd so_long
```

2. **Compile the project**
```bash
make
```

## Usage
```bash
./so_long maps/map.ber
```

## 🎮 How to play

### Controls
- **WASD** to move
- **ESC** to exit

### Objective
Collect all the bones to open the exit, then head there to win!

### Map Configuration

**Rules**
- Must be a .ber file
- Map must be rectangular
- Empty space must be surrounded by wall
- Must have at least 1 coin
- All coins must be reachable

```
111111111111111
1P0010C00010C01
1E000010C100001
111111111111111
```
**Map legend**
- '1' - wall
- '0' - empty space
- 'C' - coin
- 'E' - Exit
- 'X' - Enemy

## 📄 License

This project is part of the 42 School curriculum and follows the school's academic guidelines.
