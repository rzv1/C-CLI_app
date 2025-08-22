# C-CLI_app

Command-line application in C for managing a small car rental system. 
The project is implemented with a layered architecture (**UI**, **Service**, **Repository**).

## Features
- Add new cars
- Update license, model or category
- Rent and return cars
- Filter cars by model or category
- Sort cars by model or category (ascending/descending)

## Run
```bash
mkdir build && cd build
cmake ..
make
./C_CLI_app
