def solve():
    t = int(input())  # Number of test cases
    for _ in range(t):
        # Read the inputs for each test case
        n, k, l = map(int, input().split())  # n: number of scarecrows, k: teleportation distance, l: target position
        a = list(map(int, input().split()))  # Positions of the scarecrows
        
        # The maximum time to reach l is limited by how the scarecrows move
        max_time = 0  # This will store the minimum time required to reach or exceed l
        
        # Iterate over each scarecrow
        for i in range(n):
            # Calculate the time required for the crow to reach l from position a[i]
            time = (l - a[i] + k - 1) // k  # This is the ceiling of (l - a[i]) / k
            
            # The maximum time required is the maximum of all scarecrow's movement delays
            max_time = max(max_time, time)
        
        # Output the twice the minimum time required
        print(2 * max_time)

solve()