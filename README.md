# escape_from_scary_rooms
# Text Adventure Game

## Table of Contents

•⁠  ⁠[Introduction](#introduction)
•⁠  ⁠[Features](#features)
•⁠  ⁠[Project Structure](#project-structure)
•⁠  ⁠[Installation](#installation)
  - [Prerequisites](#prerequisites)
  - [Setup Instructions](#setup-instructions)
•⁠  ⁠[Usage](#usage)
•⁠  ⁠[Building the Project](#building-the-project)
•⁠  ⁠[Cleaning Up](#cleaning-up)
•⁠  ⁠[Contributing](#contributing)
•⁠  ⁠[Author](#author)
•⁠  ⁠[License](#license)

## Introduction

*Text Adventure Game* is an immersive text-based adventure where players navigate through interconnected rooms, collect items, and engage in battles with various creatures. Developed in C, this game offers a blend of exploration, inventory management, and combat mechanics, providing an engaging experience for enthusiasts of classic adventure games.

## Features

•⁠  ⁠*Room Navigation:* Move between rooms in four directions—north, south, east, and west—each with unique descriptions and items.
•⁠  ⁠*Inventory System:* Collect and manage items with a limited inventory capacity.
•⁠  ⁠*Combat Mechanics:* Encounter and battle creatures, managing your health and strength to survive.
•⁠  ⁠*Dynamic Room Descriptions:* Room descriptions are loaded from external files, allowing for easy expansion of the game world.
•⁠  ⁠*Modular Design:* Organized codebase with separate modules for creatures, players, and rooms, facilitating maintenance and scalability.

## Project Structure

The project is organized into the following files and directories:

•⁠  ⁠*Source Files:*
  - ⁠ main.c ⁠: The entry point of the game, handling the game loop and user interactions.
  - ⁠ creature.c ⁠: Contains functions related to creature creation, display, and combat.
  - ⁠ player.c ⁠: Manages player initialization, inventory, movement, and interactions.
  - ⁠ room.c ⁠: Handles room creation, item management, and connections between rooms.

•⁠  ⁠*Header Files:*
  - ⁠ creature.h ⁠: Defines the ⁠ Creature ⁠ structure and related function prototypes.
  - ⁠ player.h ⁠: Defines the ⁠ Player ⁠ structure and related function prototypes.
  - ⁠ room.h ⁠: Defines the ⁠ Room ⁠ structure and related function prototypes.

•⁠  ⁠*Other Files:*
  - ⁠ Makefile ⁠: Automates the build process.
  - ⁠ README.md ⁠: Provides an overview and instructions for the project.

## Installation

### Prerequisites

Ensure you have the following tools installed on your system:

•⁠  ⁠*C Compiler:* ⁠ gcc ⁠ is recommended.
•⁠  ⁠*Make:* To utilize the provided ⁠ Makefile ⁠ for building the project.
•⁠  ⁠*Unix-Based Environment:* macOS or Linux is preferred. Windows users can use Git Bash or Windows Subsystem for Linux (WSL).

### Setup Instructions

1.⁠ ⁠*Clone the Repository:*

   ```bash
   git clone https://github.com/yourusername/text-adventure-game.git
   cd text-adventure-game
