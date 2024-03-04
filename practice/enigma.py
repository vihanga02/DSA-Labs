import math

# Function to determine whether the number of students attending on day i is even or odd
def attendance_pattern(i):
    # Calculate the number of divisors of i
    divisors = 0
    sqrt_i = int(math.sqrt(i))
    for j in range(1, sqrt_i + 1):
        if i % j == 0:
            divisors += 1
            # If i is a perfect square, we count its square root only once
            if i // j != j:
                divisors += 1
    # Check if the number of divisors is even or odd
    if divisors % 2 == 0:
        return "even"
    else:
        return "odd"

# Input handling
T = int(input())
for _ in range(T):
    i = int(input())
    print(attendance_pattern(i))
