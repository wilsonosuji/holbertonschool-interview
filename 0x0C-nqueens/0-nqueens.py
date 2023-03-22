#!/usr/bin/python3
""" The N queens puzzle is the challenge of placing N non-attacking queens
    on an N×N chessboard. This program that solves the N queens problem """
import sys
import math


""" Validation """
if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    number = int(sys.argv[1])

except ValueError:

    print("N must be a number")
    exit(1)

if number < 4:
    print("N must be at least 4")
    exit(1)


def printSolution(board):
    """ all position board is diplayed """
    my_list = list()
    x, y = 0, 0
    for row in board:
        for col in row:
            if col == 1:
                my_list.append([x, y])
            y += 1
        y = 0
        x += 1
    print(my_list)


def isSafe(board, row, col):
    """ Check the rows positions (left - right) """
    for i in range(col):
        if (board[row][i]):
            return False

    i = row
    j = col

    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1

    i = row
    j = col

    while j >= 0 and i < len(board):
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1

    return True


def solveNQUtil(board, col):
    """ base case: If all queens are placed
    then return true """
    if (col == len(board)):
        printSolution(board)
        return True

    """ Consider this column and try placing
    this queen in all rows one by one """
    res = False
    for i in range(len(board)):

        """ Check if queen can be placed on
        board[i][col] """
        if (isSafe(board, i, col)):

            """ Place this queen in board[i][col] """
            board[i][col] = 1

            """ Make result true if any placement is possible """
            res = solveNQUtil(board, col + 1) or res

            """ If placing queen in board[i][col]
            doesn't lead to a solution, then
            remove queen from board[i][col] """
            board[i][col] = 0  # BACKTRACK

            """ If queen can not be place in any row in
            this column col then return false """
    return res


def solveNQ(n):

    board = []

    for i in range(n):
        row = []
        for j in range(n):
            row.append(0)
        board.append(row)

    solveNQUtil(board, 0)


solveNQ(number)
