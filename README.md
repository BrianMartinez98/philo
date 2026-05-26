# philosophers

Dining Philosophers concurrency project implemented in C as part of the 42 curriculum.

## Overview

This project simulates the classic dining philosophers problem using POSIX threads and mutexes. The goal is to coordinate philosophers that alternate between eating, sleeping, and thinking while avoiding data races and deadlocks.

## Features

- Thread-based philosopher simulation
- Mutex-protected fork handling
- Death monitoring thread
- Optional meal limit
- Timestamped status output
- Basic input validation

## Build

```bash
make
```

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

Example with a finite meal count:

```bash
./philo 5 800 200 200 7
```

## Basic tests

```bash
./tests/basic_test.sh
```

## Notes

This repository is a cleaned public version of my original 42 project. The implementation has been kept close to the original while removing generated files and adding minimal documentation for review.
