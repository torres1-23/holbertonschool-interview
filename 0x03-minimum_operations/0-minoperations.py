#!/usr/bin/python3
"""
Provides a function to compute the minimum number of copy-paste operations
to produce a given number of characters. Algorithm used is based on sieve
of erathostenes.
"""


def minOperations(n):
    """Calculate the minimum number of operations to produce n characters."""
    ops = 0
    while n > 1:
        for prime in range(2, n + 1):
            if n % prime == 0:
                ops += prime
                n //= prime
                break
    return ops
