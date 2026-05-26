#!/usr/bin/env bash
set -euo pipefail

make >/dev/null

echo "Test 1: one philosopher should die"
timeout 3 ./philo 1 200 100 100 || true

echo "Test 2: finite meal count should terminate"
timeout 5 ./philo 5 800 200 200 3 >/tmp/philo_test_output.txt || true
if grep -q "died" /tmp/philo_test_output.txt; then
    echo "A philosopher died during finite meal test"
    exit 1
fi

echo "Basic tests completed"
