import numpy as np
from numba import cuda
import time
import math

@cuda.jit
def is_prime_gpu_kernel(numbers, results):
    """
    Numba CUDA kernel to check for primality on the GPU.
    Each thread checks one number.
    
    Args:
        numbers (array): An array of integers to check.
        results (array): An output array where results will be stored. 
                         results[i] will be 1 if numbers[i] is prime, 0 otherwise.
    """
    # Get the unique global index for this thread
    idx = cuda.grid(1)

    # Check if the index is within the bounds of the array
    if idx < numbers.size:
        num = numbers[idx]
        
        # --- Primality Test Logic ---
        if num <= 1:
            results[idx] = 0  # 0 and 1 are not prime
            return
        
        if num == 2:
            results[idx] = 1  # 2 is the only even prime
            return
            
        if num % 2 == 0:
            results[idx] = 0  # All other even numbers are not prime
            return

        # Check for odd divisors from 3 up to the square root of the number
        # We only need to check odd numbers
        limit = int(math.sqrt(num)) + 1
        for i in range(3, limit, 2):
            if num % i == 0:
                results[idx] = 0  # Found a divisor, so not prime
                return
        
        # If no divisors were found, the number is prime
        results[idx] = 1

def find_primes_on_gpu(limit: int) -> list[int]:
    """
    Finds all prime numbers up to a specified limit using the GPU.

    Args:
        limit (int): The upper bound (inclusive) to search for primes.

    Returns:
        list[int]: A list of prime numbers found.
    """
    if limit < 2:
        return []

    # Create an array of numbers to check, from 0 to limit
    numbers_host = np.arange(0, limit + 1, dtype=np.int64)
    # Create an empty array on the host to store results
    results_host = np.empty_like(numbers_host, dtype=np.int8)

    # --- GPU Execution ---
    # 1. Copy data from CPU (host) to GPU (device)
    numbers_device = cuda.to_device(numbers_host)
    results_device = cuda.to_device(results_host)

    # 2. Configure kernel launch parameters
    # Set the number of threads per block (e.g., 256)
    threads_per_block = 256
    # Calculate the number of blocks needed to cover all numbers
    blocks_per_grid = (numbers_host.size + (threads_per_block - 1)) // threads_per_block

    # 3. Launch the kernel on the GPU
    is_prime_gpu_kernel[blocks_per_grid, threads_per_block](numbers_device, results_device)
    
    # 4. Wait for the GPU to finish and copy results back to CPU
    results_host = results_device.copy_to_host()

    # 5. Filter the original numbers to get the primes
    primes = numbers_host[results_host == 1].tolist()
    
    return primes

def find_primes_on_cpu(limit: int) -> list[int]:
    """
    Finds all prime numbers up to a specified limit using the CPU for comparison.
    This is a simple, single-threaded implementation.
    """
    if limit < 2:
        return []
    
    primes = []
    for num in range(2, limit + 1):
        is_prime = True
        if num % 2 == 0 and num > 2:
            is_prime = False
        else:
            # Check for odd divisors from 3 up to the square root
            for i in range(3, int(math.sqrt(num)) + 1, 2):
                if num % i == 0:
                    is_prime = False
                    break
        if is_prime:
            primes.append(num)
            
    return primes

# --- Example Usage ---
if __name__ == "__main__":
    # Set the upper limit for finding primes
    upper_limit = 1000000  # Let's find primes up to one million

    print(f"Finding prime numbers up to {upper_limit} using the GPU...")
    
    try:
        # Run the function
        prime_numbers = find_primes_on_gpu(upper_limit)
        
        print(f"Found {len(prime_numbers)} prime numbers.")
        
        # Print the first 20 and last 20 primes found
        if len(prime_numbers) > 40:
            print("First 20 primes:", prime_numbers[:20])
            print("Last 20 primes:", prime_numbers[-20:])
        else:
            print("Primes:", prime_numbers)

    except Exception as e:
        print("\nAn error occurred. This can happen if you don't have a compatible NVIDIA GPU or the CUDA toolkit is not set up correctly.")
        print(f"Error details: {e}")
