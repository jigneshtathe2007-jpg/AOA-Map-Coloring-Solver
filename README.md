# Map Coloring Constraint Solver

## Problem Statement
Build a menu-driven application that assigns at most M colours to graph vertices such that adjacent vertices never receive the same colour.

## Objective
To implement graph coloring using the backtracking algorithm and determine whether M colours are sufficient to color a given graph.

## Features
- Menu-driven console application
- Undirected graph representation
- Adjacency matrix
- User-defined number of vertices and colours
- Backtracking-based graph coloring
- Feasibility checking
- Trial and backtrack count
- Path, cycle, complete and disconnected graph testing
- Detection of insufficient colours

## Algorithm
The program assigns colours to vertices one by one. Before assigning a colour, it checks all adjacent vertices. If the colour is safe, it proceeds to the next vertex. If no colour is possible, it backtracks and changes the previous assignment.

## Complexity
- Time Complexity: O(M^V)
- Space Complexity: O(V² + V)

Where:
- V = Number of vertices
- M = Number of colours

## Language
C

## Project Type
AOA Mini Project - Module 5: Backtracking and Branch and Bound
