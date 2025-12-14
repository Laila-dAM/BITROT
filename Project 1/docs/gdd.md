# Game Design Document (GDD)

## Project Title

Interactive Programming Learning Platform (ASCII Web Game)

## Game Summary

A web-based ASCII game where the player is trapped in a strange digital camp by a morally ambiguous professor and must learn programming concepts to escape. Learning stabilizes the world. Errors are part of progress.

## Target Audience

* Beginners in programming
* Students and self-learners
* Players curious about systems and logic

No prior programming knowledge is required.

## Core Experience

* Type commands in an ASCII terminal
* Solve programming challenges
* Learn by doing, failing, and retrying
* Progress through areas of the camp
* Escape using only acquired knowledge

## Core Gameplay Loop

1. Talk to the Professor
2. Choose a mission
3. Enter the Terminal
4. Type commands / solve logic
5. Receive feedback (error or success)
6. Gain XP
7. Unlock new areas
8. Return to the Camp (HUB)

This loop repeats until the final escape.

## Game World (MVP Areas)

### 1. Digital Forest (Intro)

* First contact with the terminal
* Simple interaction and curiosity

### 2. Camp Hub

* Central navigation area
* Mission selection
* Player status display

### 3. Command Tent

* Basic terminal commands
* Input / output concepts

### 4. Algorithm Campfire

* Step-by-step logic
* Ordering actions

### 5. Exploration Trail

* Conditional logic (if / else)

### Final Area: Escape

* Multi-step challenge
* Uses only learned concepts

## Player Character

* Represented only by ASCII
* Emotional states shown visually
* No spoken dialogue

## Main Characters

### The Professor

* Intelligent and sarcastic
* Treats captivity as normal
* Encourages learning in strange ways

### The Terminal

* Acts like a simple character
* Gives feedback and emotional responses
* Never judges the player

## Challenge Design

### Challenge Template

Each challenge contains:

* Name
* Area
* Concept taught
* Expected command or solution
* Progressive hints
* Correct solution
* Narrative feedback

## Error & Feedback System

* Errors are expected and safe
* 1st error: light hint
* 3rd error: direct hint
* 5th error: challenge reset with reduced XP

No punishment for curiosity.

## Progression System

### Experience (XP)

* Basic challenge: +10 XP
* Perfect completion: bonus XP
* Errors still grant minimal XP

### Levels

* Levels unlock new areas
* Some areas require performance conditions

## Difficulty Adjustment (Optional)

* Player struggling: simpler challenges
* Player succeeding easily: optional extra challenges

## Game Rules

* No fail state for the full game
* Only challenges can reset
* The player can always retry

## Systems Overview

### Terminal System

* Command-based input
* Case-sensitive commands
* Limited valid commands per area

### Save System

* Local save (ID-based)
* Progress resets after long inactivity

### Anti-Cheating (Basic)

* Detect copy/paste
* Limit attempts per challenge
* Sanitize all input

## User Interface

* Text-only ASCII interface
* Monospace font
* Minimal UI frames and boxes

## Audio

* Optional minimal sound
* Silence used intentionally

## Narrative Layers

* Main story through gameplay
* Optional secret logs (.logs/)
* Logs never affect gameplay

## Ending

* Single ending
* The player escapes using knowledge
* No escape button exists

## MVP Scope

Included:

* Camp Hub
* 3 playable areas
* 15–20 challenges
* XP and leveling
* One complete ending

Excluded (Future Expansions):

* Rankings
* Advanced analytics
* Additional areas
* Multiple endings

## Success Criteria

The game is successful if:

* Players understand basic programming concepts
* Players feel safe making mistakes
* The project can be finished and presented as a portfolio

## Design Rule

If a feature does not help the player feel more capable, it does not belong in the game.
