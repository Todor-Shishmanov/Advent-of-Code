# Advent-of-Code

Uploading my solutions and setup scripts for the yearly aoc event!

## General workflow

I commit to my branch `my_solutions`. Whoever wants to join the party can create their own branch. Any language is allowed, might just have to mod the bash scripts.

## Prerequisites
1. Linux installed (WSL2 is a common windows workaround)
2. C++ compiler. Example install of the [GNU](https://gcc.gnu.org/) compiler collection for `apt` based linux distros:
```bash
sudo apt update
sudo apt install build-essential
```
## Using the utilities

Before we use the bash scripts we must first give them executable rights.

```bash
sudo chmod +x /path-to-repo/Advent-of-Code/utility/aoc_setup.sh
sudo chmod +x /path-to-repo/Advent-of-Code/utility/aoc_compile_run.sh
sudo chmod +x /path-to-repo/Advent-of-Code/utility/aoc_alias.sh
```

### Setup and downloading inputs

Script for setting up your directories so you don't waste time.
The `aoc_download.sh` requires some configuration as it requires unique cookie number. Different people get different inputs and the cookie can ID the user.

1. Go to the [advent of code website](https://adventofcode.com/)
2. Open up dev tools and click the Application tab to open the Application tool
3. Find the cookie with name `session` and copy it's value. It should be a long number

[optional] Check the `template_solution.cpp` and modify it to your liking. It will be coppied automatically via the script for every new day or year you create.

### Compiling solutions

A simple script for compiling and running is provided as a timesaver.

### Example usage

[optional] Setting up alliaces for convenience.
```bash
source ./utility/aoc_alias.sh
```
You can even add those the your `~/.bashrc` or `~/.profile` to make them permanent.

Now let's download and compile our first AoC code!

```bash
aoc_setup 2023 1
aoc_run 2023 1
```
Yes it's that simple! You're ready to go!
