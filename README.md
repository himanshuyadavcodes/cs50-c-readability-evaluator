# C Readability Evaluator

A command-line tool written in pure C that calculates the approximate grade level needed to comprehend some text, utilizing the Coleman-Liau index formula.

## How It Works
- Counts letters, words, and sentences in standard input text.
- Applies the Coleman-Liau formula: `index = 0.0588 * L - 0.296 * S - 15.8` 
  - `L` is the average number of letters per 100 words.
  - `S` is the average number of sentences per 100 words.

## Build & Run
```bash
gcc src/main.c -o readability
./readability