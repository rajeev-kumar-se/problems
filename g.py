import os

# Define the list of problem IDs
problem_ids = [
    "n-gcd",
    "gcd-sum",
    "range-gcd",
    "range-gcd-point-update",
    "four-target-gcd",
    "max-gcd-subarray",
    "subarray-with-k-gcd",
    "max-gcd-k-size-subarray",
    "max-gcd-subsequence",
    "max-gcd-k-size-subsequence",
    "subsequence-with-k-gcd"
]

# Create folders for each problem
for problem_id in problem_ids:
    folder_name = problem_id
    os.makedirs(folder_name, exist_ok=True)

    # Create empty code.cpp file
    with open(os.path.join(folder_name, 'code.cpp'), 'w'):
        pass

    # Create empty in.txt file
    with open(os.path.join(folder_name, 'in.txt'), 'w'):
        pass

    # Create empty out.txt file
    with open(os.path.join(folder_name, 'out.txt'), 'w'):
        pass
