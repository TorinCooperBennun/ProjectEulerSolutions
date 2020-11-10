# Problem 60

# The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes
# and concatenating them in any order the result will always be prime. For
# example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these
# four primes, 792, represents the lowest sum for a set of four primes with
# this property.

# Find the lowest sum for a set of five primes for which any two primes
# concatenate to produce another prime.

import numpy as np
import time


def primes_up_to(N):
    if N % 2:
        N += 1

    sieve = np.ones(N//2 - 1, dtype=bool)
    primes = [2]

    check_max = int(np.ceil((np.sqrt(N) - 3) / 2))

    for i in range(check_max):
        if not sieve[i]:
            continue

        x = 2*i + 3
        j_0 = 3*(x - 1) // 2
        sieve[np.arange(j_0, len(sieve), x)] = False
    
    prime_idxs = np.where(sieve == True)[0]
    primes = np.ndarray(len(prime_idxs) + 1, int)
    primes[0] = 2
    primes[1:] = 3 + 2*prime_idxs

    return sieve, primes


t0 = time.time()

sieve, primes = primes_up_to(100000000)
t1 = time.time()

print(f"{len(primes)} primes generated in {t1-t0:.1f} seconds")


def is_prime(x):
    if type(x) is np.ndarray:
        result = np.zeros_like(x, bool)
        result[x % 2 == 0] = False
        result[x == 2] = True
        X = x[x % 2 != 0]
        result[x % 2 != 0] = sieve[(X - 3) // 2]
    else:
        result = False
        if x == 2: return True
        if x % 2 == 0: return False
        return sieve[(x - 3) // 2]
    return result


def concat_and_check(x, y):
    x_l = np.log10(x).astype(int) + 1
    y_l = np.log10(y).astype(int) + 1
    concat1 = x * 10 ** y_l + y
    concat2 = y * 10 ** x_l + x
    p1 = is_prime(concat1)
    p2 = is_prime(concat2)
    return p1 * p2


p_max = 10000
primes_subset = primes[primes < p_max]

pairing_dict = {}
unpaired = []

for i, p in enumerate(primes_subset):
    check = concat_and_check(p, primes_subset[i+1:])
    paired = primes_subset[i+1:][check == True]
    if len(paired):
        pairing_dict[p] = paired
    else:
        unpaired.append(p)

t2 = time.time()
print(f"all pairs found in {t2-t1:.1f} seconds")

print(unpaired)
