# MiniGame: Math Quiz Game

Welcome to the MiniGame: Math Quiz Game! This is a simple console-based math quiz game where you can test your arithmetic skills with questions of varying difficulty and operation types.

## Features

- **Difficulty Levels**: Choose from Easy, Medium, Hard, or a mix of difficulties.
- **Operation Types**: Select Addition, Subtraction, Multiplication, Division, or a mix of operations.
- **Randomized Questions**: Questions are generated randomly based on the selected difficulty and operation type.
- **Score Tracking**: Keep track of your correct and incorrect answers.
- **Game Replay**: Option to replay the game after each session.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- Basic understanding of running console applications

### Running the Game

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/MathQuizGame.git
    ```
2. Navigate to the project directory:
    ```bash
    cd MathQuizGame
    ```
3. Compile the game:
    ```bash
    g++ -o MathQuizGame MathQuizGame.cpp
    ```
4. Run the game:
    ```bash
    ./MathQuizGame
    ```

## Game Overview

This console-based math quiz game allows players to test their arithmetic skills by answering a series of randomly generated questions. Players can choose the difficulty level and the type of arithmetic operations to be included in the quiz.

### How to Play

1. **Start the Game**: Run the executable file to start the game.
2. **Choose Number of Questions**: Enter the number of questions you want to answer.
3. **Select Difficulty Level**: Choose the difficulty level (Easy, Medium, Hard, Mix).
4. **Select Operation Type**: Choose the type of arithmetic operations (Addition, Subtraction, Multiplication, Division, Mix).
5. **Answer Questions**: Answer the generated questions by entering your answers.
6. **View Results**: At the end of the quiz, view your score and see if you passed or failed.
7. **Replay Option**: Choose whether to play again.

### Code Structure

The game is structured using the following main components:

- **Structs**: Define the structure for quiz and round information.
- **Enums**: Enumerate the types of difficulties, operations, and game outcomes.
- **Functions**: Include functions for reading user inputs, generating questions, checking answers, and displaying results.

### Notes

- The focus was on learning and integrating different functions, with less emphasis on input validation.
- This project is a great way to understand the basics of C++ programming and conditional logic.

## License

This project is licensed under the MIT License.
