/******************************************************************************
 * Module: XO GAME
 *
 * File Name: XO GAME.h
 *
 * Description: Header file for XO GAME
 *
 * Authors: ALI HOSSAM - MOHAMED TOUKHY - ABDULLA KHALED - SHAMS HESHAM
 ******************************************************************************/


/*******************************************************************************
 *                           Function                                     *
 *******************************************************************************/


// Functions' Prototype
void initScreen(void);
void resetGame(void);
void runGame(void);
int checkWinner(char player);
void displayWinner(char player);
void displayDraw(void);
void displayStatus(void);
int CheckPlayAgain(void);
void EndGame(void);
void drawGameCells(void);
void WaitForInterrupt(void);
void handleInvalidSelection(void);
void processNavigationInput(void);
void processCellSelection(void);
void getCellCoordinates(int cellIndex, int *row, int *col);
void makeMove(int row, int col);
void handleWinner(void);
void handleDraw(void);
int checkWinningCondition(char player);
int checkWinner(char player);
void handleWinningFeedback(char player);
void drawStrikeLine(int patternIndex);
void MoveCursorWithPotentiometer(void);
void UARTfunctionX(void);
void UARTfunctionO(void);



