# Casse-brique

Casse-brique is a simple brick-breaker game implemented in C++. The project utilizes the CImg library for graphical operations.

## Features

- Classic brick-breaker gameplay
- Basic collision detection between ball, paddle, and bricks
- Simple graphics rendered using the CImg library

## Prerequisites

Before building and running the project, ensure you have the following installed:

- A C++ compiler supporting C++11 or later
- The CImg library

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/EagleOfFire/Casse-brique.git
   ```


2. Navigate to the project directory:

   ```bash
   cd Casse-brique
   ```


3. Ensure the CImg library is available in the project directory. 

## Usage

To build and run the project:

1. Compile the source code:

   ```bash
   g++ -o casse-brique main.cpp Balle.cpp Briques.cpp Mur.cpp Raquette.cpp Rectangle.cpp -O2 -std=c++11 -lpthread -lX11
   ```


2. Run the executable:

   ```bash
   ./casse-brique
   ```


Use the keyboard to control the paddle and break all the bricks to win the game.
