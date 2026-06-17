# Space Station Survival Simulator

**Course:** EIF204 - Programming II
**University:** Universidad Nacional de Costa Rica

## Team Members
- Xiulin D. Reyes Mora
- Fiorella Arce Valverde
- Jose Daniel Brenes Campos
- Bianca Monge Garcia

## Description
A console-based space station survival simulation where an astronaut must survive a
set number of turns while managing health, oxygen, and energy. The station is composed
of interconnected modules loaded from a text file. Random events such as fires, meteor
strikes, oxygen leaks, and power failures threaten the astronaut and the station's
integrity. The player can move between modules, inspect and collect items, and use them
to recover stats.

## Project Structure
```
Proyecto_2_Progra_2/
├── include/
│   ├── astronaut/        # Astronaut, Inventory, Items
│   ├── events/           # Event, Fire, MeteorStrike, OxygenLeak, PowerFailure
│   ├── interface/        # Game, GameUI
│   ├── simulator/        # Simulation, Logger, ReportGenerator
│   └── world/            # Module, SpaceStation, StationLoader
├── src/                  # Implementation files (mirrors include/)
├── station.txt           # Input file with modules, connections and items
├── main.cpp
└── CMakeLists.txt
```

## Compilation
This project uses Cmake and Requires a C++20 compatible compiler (MinGW on Windows).

1. Open the project in CLion
2. CMake will configure automatically
3. Build with **Build > Build Project**

## Execution
1. Go to **Run > Edit Configurations**
2. Set **Working Directory** to `$ProjectFileDir$`
3. Make sure `station.txt` is in the root of the project
4. Run with **Run > Run 'Proyecto_2_Progra_2'**

> If not using CLion, copy `station.txt` to the directory where the binary is executed.

## Input File
`station.txt` defines the initial state of the station. Format:

MODULE;<name>

CONNECTION;<module1>;<module2>

ITEM;<module>;<item_type>

START;<module>

Available item types: `EnergyCell`, `OxygenTank`, `RepairKit`, `RepairTool`

## Output Files
After the simulation ends, two files are generated:
- `report.txt` — event log with all actions taken during the simulation
- `finalReport.txt` — final mission report with astronaut stats and result